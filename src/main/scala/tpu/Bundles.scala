// SPDX-License-Identifier: MIT

package tpu

import chisel3._

/**
  * Interface for MAC unit systolic interconnect
  *
  * Data flows through the systolic array:
  * - upIn/upOut: Vertical data flow (matrix B values)
  * - leftIn/leftOut: Horizontal data flow (matrix A values)
  *
  * @param dataWidth Width of data elements in bits
  */
class MACInterconnect(dataWidth: Int) extends Bundle {
  val upIn    = Input(SInt(dataWidth.W))
  val leftIn  = Input(SInt(dataWidth.W))
  val upOut   = Output(SInt(dataWidth.W))
  val leftOut = Output(SInt(dataWidth.W))
}

/**
  * Interface for global buffer access
  *
  * Single-port synchronous memory interface
  *
  * @param config TPU configuration
  * @param wordWidth Width of each word (32-bit for A/B, 64-bit for C)
  */
class GlobalBufferIO(config: TPUConfig, wordWidth: Int) extends Bundle {
  val wrEn   = Input(Bool())
  val addr   = Input(UInt(config.bufferAddrWidth.W))
  val wrData = Input(UInt(wordWidth.W))
  val rdData = Output(UInt(wordWidth.W))
}

/**
  * Interface for synchronous FIFO
  *
  * @param dataWidth Width of data elements
  */
class SyncFIFOIO(dataWidth: Int) extends Bundle {
  val wrEn    = Input(Bool())
  val rdEn    = Input(Bool())
  val dataIn  = Input(SInt(dataWidth.W))
  val dataOut = Output(SInt(dataWidth.W))
  val empty   = Output(Bool())
  val full    = Output(Bool())
}
