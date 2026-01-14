// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import chisel3.util._
import tpu.{GlobalBufferIO, TPUConfig}

/**
  * TPU Control Unit - FSM for orchestrating systolic array computation
  *
  * State machine:
  * - IDLE: Waiting for start signal
  * - IDLE2: One-cycle delay before computation
  * - CALCULATE: Read matrices, feed systolic array
  * - WRITE: Write results back to buffer C
  * - FINISH: Signal completion
  *
  * Timing (from Verilog):
  * - stop_read = (cnt > k || cnt == 0)
  * - start_fifo = (cnt == 2)
  * - stop_fifo = (cnt == k + 3)
  * - cntEnd = (cnt == k + 7)
  *
  * =============================================================================
  * CRITICAL: PARAMETER SEMANTICS
  * =============================================================================
  *
  * io.k: Number of 32-bit WORDS to read from GlobalBuffers A and B
  *   - NOT the number of tiles in k dimension
  *   - Each word contains N packed 8-bit values (one per FIFO)
  *   - For N×N systolic array to compute one tile: k = N
  *
  *   Examples:
  *   - 4×4 tile: k=4 reads 4 words → 4 elements per FIFO
  *   - 2×2 matrix (padded to 4×4): Still k=4 (hardware is 4×4)
  *   - 4×8 @ 8×4 (2 k-tiles): Would need k=8
  *
  * io.m, io.n: Number of tiles in M and N dimensions (for multi-tile)
  *   - Single tile: m=1, n=1
  *   - Multi-tile requires FSM enhancement (not yet implemented)
  *
  * Data Flow:
  *   - Each word from buffer A feeds all N row FIFOs with one element
  *   - Each word from buffer B feeds all N column FIFOs with one element
  *   - For k words: each FIFO accumulates k elements for inner product
  *
  * Reference: reference/tpu_project/src/tpu.v line 39
  *   wire stop_read = (cnt > {1'd0, k} || cnt == 5'd0);
  * =============================================================================
  *
  * @param config TPU configuration
  */
class TPUControl(config: TPUConfig) extends Module {
  val io = IO(new Bundle {
    // Control interface
    val start = Input(Bool())
    val m     = Input(UInt(10.W))
    val k     = Input(UInt(10.W))
    val n     = Input(UInt(10.W))
    val done  = Output(Bool())

    // Systolic array control
    val sysReset = Output(Bool())
    val stopRead = Output(Bool())
    val rdEnA    = Output(Vec(config.n, Bool()))
    val rdEnB    = Output(Vec(config.n, Bool()))

    // Buffer interfaces
    val bufA = Flipped(new GlobalBufferIO(config, config.wordWidth))
    val bufB = Flipped(new GlobalBufferIO(config, config.wordWidth))
    val bufC = Flipped(new GlobalBufferIO(config, config.extendedWordWidth))

    // Matrix output from systolic array
    val matOut = Input(Vec(config.n, Vec(config.n, SInt(config.accWidth.W))))

    // Debug outputs
    val debug_state     = Output(UInt(3.W))
    val debug_cnt       = Output(UInt(12.W))
    val debug_stopRead  = Output(Bool())
    val debug_startFifo = Output(Bool())
    val debug_stopFifo  = Output(Bool())
    val debug_cntEnd    = Output(Bool())
    val debug_addrA     = Output(UInt(config.bufferAddrWidth.W))
    val debug_addrB     = Output(UInt(config.bufferAddrWidth.W))
    val debug_addrC     = Output(UInt(config.bufferAddrWidth.W))
    val debug_writeCnt  = Output(UInt(log2Ceil(config.n + 1).W))
  })

  // FSM states
  object State extends ChiselEnum {
    val sIdle, sIdle2, sCalculate, sWrite, sFinish = Value
  }
  import State._

  val state = RegInit(sIdle)
  val cnt   = RegInit(0.U(12.W))  // Widened to support k up to 1023 (k+7 needs ~11 bits)

  // Address registers
  val addrA = RegInit(0.U(config.bufferAddrWidth.W))
  val addrB = RegInit(0.U(config.bufferAddrWidth.W))
  val addrC = RegInit(0.U(config.bufferAddrWidth.W))

  // Write counter for buffer C (writes N rows, each row is one 64-bit word)
  val writeCnt = RegInit(0.U(log2Ceil(config.n + 1).W))

  // Control signals
  // IMPORTANT: GlobalBuffer has 1-cycle read latency (registered output).
  // Data from addr N appears at rdData in cycle N+1.
  // Therefore, we shift FIFO writes by 1 cycle to align with valid data:
  // - Original: stopRead false at cnt [1, k] -> data arrives at [2, k+1]
  // - Fixed: stopRead false at cnt [2, k+1] -> aligned with data arrival
  //
  // Timing for k=4:
  // - FIFO writes at cnt=2,3,4,5 (k cycles) with data[0,1,2,3]
  // - startFifo at cnt=2 -> rdEnAReg(0) becomes true at cnt=3 (registered)
  // - SystolicArray uses delayed rdEn for gating (rdEnDelayed true at cnt=4)
  // - FIFO outputs valid data at cnt=4,5,6,7 (k cycles)
  // - stopFifo at k+2 -> rdEnAReg false at k+3 -> rdEnDelayed false at k+4
  // - Gated outputs valid at cnt=4,...,k+3 (k cycles)
  val stopRead  = cnt > io.k + 1.U || cnt <= 1.U
  val startFifo = cnt === 2.U  // rdEnAReg becomes true at cnt=3 (registered)
  val stopFifo  = cnt === (io.k + 2.U)  // rdEnDelayed becomes false at cnt=k+3
  // cntEnd must be late enough for all MACs to finish accumulating.
  // Testing with very large margin to debug timing issues.
  val cntEnd    = cnt === (io.k + 20.U)  // Large margin for testing

  // Staggered FIFO read enables
  val rdEnAReg = RegInit(VecInit(Seq.fill(config.n)(false.B)))
  val rdEnBReg = RegInit(VecInit(Seq.fill(config.n)(false.B)))

  // Systolic reset control
  val sysResetReg = RegInit(true.B)

  // FSM logic
  switch(state) {
    is(sIdle) {
      when(io.start) {
        state := sIdle2
        cnt   := 0.U
        addrA := 0.U
        addrB := 0.U
        addrC := 0.U
      }
    }

    is(sIdle2) {
      state       := sCalculate
      cnt         := 1.U
      sysResetReg := false.B
    }

    is(sCalculate) {
      cnt := Mux(cntEnd, 0.U, cnt + 1.U)

      // Update staggered FIFO enables
      when(startFifo) {
        rdEnAReg(0) := true.B
        rdEnBReg(0) := true.B
      }.elsewhen(stopFifo) {
        rdEnAReg(0) := false.B
        rdEnBReg(0) := false.B
      }

      // Stagger enables (each row/col delayed by 1 cycle)
      for (i <- 1 until config.n) {
        rdEnAReg(i) := rdEnAReg(i - 1)
        rdEnBReg(i) := rdEnBReg(i - 1)
      }

      // Increment buffer addresses
      when(cnt < io.k && cnt > 0.U) {
        addrA := addrA + 1.U
        addrB := addrB + 1.U
      }

      when(cntEnd) {
        state := sWrite
        // Do NOT reset sysResetReg here - we need to read matOut first!
      }
    }

    is(sWrite) {
      // Write results to buffer C
      // Write one row per cycle (each row = 4 x 16-bit values = 64 bits)
      writeCnt := writeCnt + 1.U
      addrC    := addrC + 1.U

      when(writeCnt === (config.n - 1).U) {
        state       := sFinish
        writeCnt    := 0.U
        sysResetReg := true.B  // Reset accumulators AFTER writing results
      }
    }

    is(sFinish) {
      // Hold done signal, then return to idle
      state := sIdle
    }
  }

  // Default FIFO enables (reset when not in CALCULATE)
  when(state =/= sCalculate) {
    rdEnAReg := VecInit(Seq.fill(config.n)(false.B))
    rdEnBReg := VecInit(Seq.fill(config.n)(false.B))
  }

  // Output assignments
  io.sysReset := sysResetReg
  io.stopRead := stopRead
  io.rdEnA    := rdEnAReg
  io.rdEnB    := rdEnBReg
  io.done     := state === sFinish

  // Buffer A connections
  io.bufA.wrEn   := false.B
  io.bufA.addr   := addrA
  io.bufA.wrData := 0.U

  // Buffer B connections
  io.bufB.wrEn   := false.B
  io.bufB.addr   := addrB
  io.bufB.wrData := 0.U

  // Buffer C connections - pack matOut row into 64-bit word
  // Each row of matOut has N values, each 21-bit accumulator truncated to 16-bit
  io.bufC.wrEn := state === sWrite
  io.bufC.addr := addrC

  // Pack current row of matOut into 64-bit word (4 x 16-bit values)
  // writeCnt selects which row to write
  val packedRow = Wire(UInt(config.extendedWordWidth.W))
  packedRow := Cat(
    io.matOut(writeCnt)(3)(15, 0),  // Bits 63:48 - element [row][3]
    io.matOut(writeCnt)(2)(15, 0),  // Bits 47:32 - element [row][2]
    io.matOut(writeCnt)(1)(15, 0),  // Bits 31:16 - element [row][1]
    io.matOut(writeCnt)(0)(15, 0)   // Bits 15:0  - element [row][0]
  )
  io.bufC.wrData := packedRow

  // Debug outputs
  io.debug_state     := state.asUInt
  io.debug_cnt       := cnt
  io.debug_stopRead  := stopRead
  io.debug_startFifo := startFifo
  io.debug_stopFifo  := stopFifo
  io.debug_cntEnd    := cntEnd
  io.debug_addrA     := addrA
  io.debug_addrB     := addrB
  io.debug_addrC     := addrC
  io.debug_writeCnt  := writeCnt
}
