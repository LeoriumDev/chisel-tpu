// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import tpu.{GlobalBufferIO, TPUConfig}

/**
  * Global Buffer for storing matrices A, B, and C
  *
  * Single-port synchronous memory with configurable word width.
  * - Buffers A and B use 32-bit words (4 × 8-bit elements)
  * - Buffer C uses 64-bit words (4 × 16-bit results)
  *
  * @param config TPU configuration
  * @param wordWidth Width of each word in bits
  */
class GlobalBuffer(config: TPUConfig, wordWidth: Int = 32) extends Module {
  val io = IO(new GlobalBufferIO(config, wordWidth))

  // Memory storage
  val buffer = Mem(config.bufferDepth, UInt(wordWidth.W))

  // Read data register
  val rdDataReg = RegInit(0.U(wordWidth.W))

  // Write operation
  when(io.wrEn) {
    buffer(io.addr) := io.wrData
  }.otherwise {
    // Read operation (synchronous)
    rdDataReg := buffer(io.addr)
  }

  io.rdData := rdDataReg
}
