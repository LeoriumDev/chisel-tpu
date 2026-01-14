// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import chisel3.util._
import tpu.{SyncFIFOIO, TPUConfig}

/**
  * Synchronous FIFO for systolic array data buffering
  *
  * This FIFO buffers data flowing into the systolic array, providing
  * timing decoupling between global buffer reads and MAC operations.
  *
  * Implementation notes:
  * - Circular buffer with read/write pointers
  * - Synchronous read (data available one cycle after read enable)
  * - Full when (wr_ptr + 1) == rd_ptr
  * - Empty when wr_ptr == rd_ptr
  *
  * Verilog reference timing:
  * {{{
  *   always @(posedge clk or posedge rst) begin
  *     if (w_en && !full) buffer[wr_ptr] <= data_in;
  *     if (r_en && !empty) data_out <= buffer[rd_ptr];
  *   end
  * }}}
  *
  * @param config TPU configuration parameters
  */
class SyncFIFO(config: TPUConfig) extends Module {
  val io = IO(new Bundle {
    // Normal FIFO interface
    val wrEn    = Input(Bool())
    val rdEn    = Input(Bool())
    val dataIn  = Input(SInt(config.dataWidth.W))
    val dataOut = Output(SInt(config.dataWidth.W))
    val empty   = Output(Bool())
    val full    = Output(Bool())
    // Debug outputs
    val debug_wrPtr = Output(UInt(log2Ceil(config.fifoDepth).W))
    val debug_rdPtr = Output(UInt(log2Ceil(config.fifoDepth).W))
    val debug_count = Output(UInt(config.fifoAddrWidth.W))
  })

  // FIFO storage
  val buffer = Mem(config.fifoDepth, SInt(config.dataWidth.W))

  // Read and write pointers
  val wrPtr = RegInit(0.U(log2Ceil(config.fifoDepth).W))
  val rdPtr = RegInit(0.U(log2Ceil(config.fifoDepth).W))

  // Count of elements in FIFO
  val count = RegInit(0.U(config.fifoAddrWidth.W))

  // Data output register
  val dataOutReg = RegInit(0.S(config.dataWidth.W))

  // Write logic
  when(io.wrEn && !io.full) {
    buffer(wrPtr) := io.dataIn
    wrPtr := Mux(wrPtr === (config.fifoDepth - 1).U, 0.U, wrPtr + 1.U)
  }

  // Read logic
  when(io.rdEn && !io.empty) {
    dataOutReg := buffer(rdPtr)
    rdPtr := Mux(rdPtr === (config.fifoDepth - 1).U, 0.U, rdPtr + 1.U)
  }

  // Count management
  when(io.rdEn && !io.empty && !io.wrEn) {
    count := count - 1.U
  }.elsewhen(io.wrEn && !io.full && !io.rdEn) {
    count := count + 1.U
  }

  // Status signals
  io.empty := (wrPtr === rdPtr) && (count === 0.U)
  io.full  := (wrPtr + 1.U === rdPtr) || ((wrPtr === (config.fifoDepth - 1).U) && (rdPtr === 0.U))
  io.dataOut := dataOutReg

  // Debug outputs
  io.debug_wrPtr := wrPtr
  io.debug_rdPtr := rdPtr
  io.debug_count := count
}
