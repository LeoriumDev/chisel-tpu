// SPDX-License-Identifier: MIT

package tpu

import chisel3.stage.ChiselGeneratorAnnotation
import firrtl.options.TargetDirAnnotation
import firrtl.stage.FirrtlCircuitAnnotation
import chisel3.stage.ChiselStage

/**
  * Main entry point for Verilog generation
  *
  * Generates Verilog for the TPU design.
  * Output directory: generated/
  *
  * Usage: sbt "runMain tpu.Main"
  */
object Main extends App {
  val config = TPUConfig(
    n           = 4,
    dataWidth   = 8,
    accWidth    = 21,
    fifoDepth   = 4,
    bufferDepth = 256
  )

  println(s"Generating Verilog for ${config.n}×${config.n} TPU...")
  println(s"  Data width: ${config.dataWidth} bits")
  println(s"  Accumulator width: ${config.accWidth} bits")
  println(s"  Buffer depth: ${config.bufferDepth} words")

  (new ChiselStage).execute(
    Array("--target-dir", "generated"),
    Seq(
      ChiselGeneratorAnnotation(() => new TPUTop(config))
    )
  )

  println("Verilog generation complete! Check generated/ directory")
}
