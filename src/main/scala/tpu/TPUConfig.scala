// SPDX-License-Identifier: MIT

package tpu

import chisel3.util.log2Ceil

/**
  * Configuration parameters for the TPU design
  *
  * @param n Systolic array dimension (N×N grid of MAC units)
  * @param dataWidth Input data width in bits (8-bit signed by default)
  * @param accWidth Accumulator width in bits (21-bit for 4×4 array)
  * @param fifoDepth Depth of synchronous FIFOs
  * @param bufferDepth Depth of global buffers (in words)
  * @param wordWidth Word width for global buffers A and B (4 × dataWidth)
  * @param extendedWordWidth Word width for output buffer C (4 × 16-bit results)
  */
case class TPUConfig(
  n:                  Int = 4,
  dataWidth:          Int = 8,
  accWidth:           Int = 21,
  fifoDepth:          Int = 4,
  bufferDepth:        Int = 256,
  wordWidth:          Int = 32,
  extendedWordWidth:  Int = 64
) {
  // Derived parameters
  def bufferAddrWidth: Int = log2Ceil(bufferDepth)
  def fifoAddrWidth:   Int = log2Ceil(fifoDepth + 1)

  // Calculate required accumulator width based on array size
  // For N×N array with 8-bit inputs: worst case is N × (2^8)^2 = N × 2^16
  // Required bits = log2(N × 2^16) = log2(N) + 16
  def requiredAccWidth: Int = dataWidth * 2 + log2Ceil(n) + 1

  // Validate configuration
  require(n > 0 && n <= 16, "Systolic array dimension must be 1-16")
  require(dataWidth > 0 && dataWidth <= 32, "Data width must be 1-32 bits")
  require(accWidth >= requiredAccWidth, s"Accumulator width must be at least $requiredAccWidth bits for ${n}×${n} array")
  require(wordWidth == n * dataWidth, s"Word width must equal n × dataWidth (${n} × ${dataWidth} = ${n * dataWidth})")
}
