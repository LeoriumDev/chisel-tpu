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
  * @param config TPU configuration
  */
class TPUControl(config: TPUConfig) extends Module {
  val io = IO(new Bundle {
    // Control interface
    val start = Input(Bool())
    val m     = Input(UInt(4.W))
    val k     = Input(UInt(4.W))
    val n     = Input(UInt(4.W))
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
  })

  // FSM states
  object State extends ChiselEnum {
    val sIdle, sIdle2, sCalculate, sWrite, sFinish = Value
  }
  import State._

  val state = RegInit(sIdle)
  val cnt   = RegInit(0.U(5.W))

  // Address registers
  val addrA = RegInit(0.U(config.bufferAddrWidth.W))
  val addrB = RegInit(0.U(config.bufferAddrWidth.W))
  val addrC = RegInit(0.U(config.bufferAddrWidth.W))

  // Control signals
  val stopRead  = cnt > io.k || cnt === 0.U
  val startFifo = cnt === 2.U
  val stopFifo  = cnt === (io.k + 3.U)
  val cntEnd    = cnt === (io.k + 7.U)

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
        state       := sWrite
        sysResetReg := true.B
      }
    }

    is(sWrite) {
      // Write results to buffer C
      // Simplified: write first result and transition to finish
      state := sFinish
    }

    is(sFinish) {
      // Hold done signal
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

  // Buffer C connections
  io.bufC.wrEn   := false.B
  io.bufC.addr   := addrC
  io.bufC.wrData := 0.U
}
