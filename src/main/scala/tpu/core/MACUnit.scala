// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import tpu.{MACInterconnect, TPUConfig}

/**
  * Multiply-Accumulate (MAC) Unit for Systolic Array
  *
  * This module implements a single MAC cell used in the systolic array.
  * It performs the operation: accumulator = accumulator + (upIn × leftIn)
  *
  * Systolic data flow:
  * - Input data flows from top (upIn) and left (leftIn)
  * - Data is registered and forwarded to next cells (upOut, leftOut)
  * - Accumulation continues until systolic reset
  *
  * Timing (from Verilog):
  * {{{
  *   always @(posedge clk or posedge reset) begin
  *     if (reset) begin
  *       up_out <= 0; left_out <= 0; mat_out <= 0;
  *     end else begin
  *       up_out <= up_in;
  *       left_out <= left_in;
  *       mat_out <= mat_out + (up_in * left_in);
  *     end
  *   end
  * }}}
  *
  * @param config TPU configuration parameters
  */
class MACUnit(config: TPUConfig) extends Module {
  val io = IO(new Bundle {
    val interconnect = new MACInterconnect(config.dataWidth)
    val matOut       = Output(SInt(config.accWidth.W))
    val sysReset     = Input(Bool())
    // Debug outputs
    val debug_accReg  = Output(SInt(config.accWidth.W))
    val debug_upReg   = Output(SInt(config.dataWidth.W))
    val debug_leftReg = Output(SInt(config.dataWidth.W))
  })

  // Registers for systolic data flow
  val upReg   = RegInit(0.S(config.dataWidth.W))
  val leftReg = RegInit(0.S(config.dataWidth.W))

  // Accumulator register
  val accReg = RegInit(0.S(config.accWidth.W))

  // Systolic reset control
  when(io.sysReset) {
    upReg   := 0.S
    leftReg := 0.S
    accReg  := 0.S
  }.otherwise {
    // Forward inputs to outputs (one cycle delay)
    upReg   := io.interconnect.upIn
    leftReg := io.interconnect.leftIn

    // MAC operation: accumulate product
    val product = io.interconnect.upIn * io.interconnect.leftIn
    accReg := accReg + product
  }

  // Connect outputs
  io.interconnect.upOut   := upReg
  io.interconnect.leftOut := leftReg
  io.matOut               := accReg

  // Debug outputs
  io.debug_accReg  := accReg
  io.debug_upReg   := upReg
  io.debug_leftReg := leftReg
}
