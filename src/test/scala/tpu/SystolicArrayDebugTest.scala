// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import tpu.utils.{DebugLogger, MatrixLoader}

/**
 * Debug test for Systolic Array that logs cycle-by-cycle state
 * to help debug matrix multiplication issues.
 */
class SystolicArrayDebugTest extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "SystolicArray Debug Logging"

  it should "log cycle-by-cycle state during 4x4 identity matrix multiplication" in {
    val config = TPUConfig(n = 4, dataWidth = 8)
    val logger = new DebugLogger(config, "debug_output/matmul_4x4_identity.ndjson")

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config

      println("\n=== 4x4 Identity Matrix Multiplication Debug Test ===")

      // Test case: A = I (identity), B = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
      // Expected C = B (since I * B = B)
      val matrixA = Array(
        1, 0, 0, 0,  // Row 0
        0, 1, 0, 0,  // Row 1
        0, 0, 1, 0,  // Row 2
        0, 0, 0, 1   // Row 3
      )

      val matrixB = Array(
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
      )

      println("Loading matrices into GlobalBuffers...")
      MatrixLoader.loadMatrixA(dut, matrixA, rows = 4, cols = 4, packWidth = 4)
      MatrixLoader.loadMatrixB(dut, matrixB, rows = 4, cols = 4, packWidth = 4)

      // Initial state before starting
      dut.io.testMode.poke(true.B)
      dut.clock.step(1)
      logger.logCycle(dut, 0)
      println("Logged initial state (cycle 0)")

      // Switch to operation mode
      dut.io.testMode.poke(false.B)
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)  // 1 tile in M dimension
      dut.io.k.poke(4.U)  // 4 words for 4x4 tile
      dut.io.n.poke(1.U)  // 1 tile in N dimension
      dut.clock.step(2)
      logger.logCycle(dut, 1)

      println("Starting matrix multiplication...")

      // Start execution
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      logger.logCycle(dut, 2)
      dut.io.start.poke(false.B)

      // Log every cycle until done
      var cycle = 3
      while (!dut.io.done.peek().litToBoolean && cycle < 100) {
        dut.clock.step(1)
        logger.logCycle(dut, cycle)
        cycle += 1
      }

      // Log a few more cycles after done
      for (_ <- 0 until 3) {
        dut.clock.step(1)
        logger.logCycle(dut, cycle)
        cycle += 1
      }

      println(s"Computation completed, logged $cycle cycles total")

      // Write debug log
      logger.writeToFile()

      // Read and print results
      println("\nReading results from buffer C...")
      val results = MatrixLoader.readMatrixC(dut, rows = 4, cols = 4, packWidth = 4)

      // Expected: C = I * B = B
      val expected = Array(
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
      )

      println("\nResults matrix C:")
      for (i <- 0 until 4) {
        println(s"  Row $i: ${results.slice(i * 4, (i + 1) * 4).mkString(", ")}")
      }

      println("\nExpected matrix:")
      for (i <- 0 until 4) {
        println(s"  Row $i: ${expected.slice(i * 4, (i + 1) * 4).mkString(", ")}")
      }

      // Check for mismatches
      var errorCount = 0
      for (i <- expected.indices) {
        val row = i / 4
        val col = i % 4
        if (results(i) != expected(i)) {
          println(s"MISMATCH at [$row][$col]: expected ${expected(i)}, got ${results(i)}")
          errorCount += 1
        }
      }

      if (errorCount == 0) {
        println("\nAll results match expected values!")
      } else {
        println(s"\nFound $errorCount mismatches - check debug_output/matmul_4x4_identity.ndjson for analysis")
      }
    }
  }

  it should "log simple 2x2 matrix multiplication for debugging" in {
    val config = TPUConfig(n = 4, dataWidth = 8)
    val logger = new DebugLogger(config, "debug_output/matmul_2x2_simple.ndjson")

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config

      println("\n=== 2x2 Simple Matrix Multiplication Debug Test ===")

      // Very simple test: A = [[1,0],[0,1]] (2x2 identity padded to 4x4)
      // B = [[2,3],[4,5]] padded to 4x4
      // Expected C = B
      // NOTE: Matrices must be in ROW-MAJOR format for correct systolic array operation
      val matrixA = Array(
        1, 0, 0, 0,  // Row 0: [A[0,0], A[0,1], pad, pad]
        0, 1, 0, 0,  // Row 1: [A[1,0], A[1,1], pad, pad]
        0, 0, 0, 0,  // padding
        0, 0, 0, 0   // padding
      )

      val matrixB = Array(
        2, 3, 0, 0,  // Row 0: [B[0,0], B[0,1], pad, pad]
        4, 5, 0, 0,  // Row 1: [B[1,0], B[1,1], pad, pad]
        0, 0, 0, 0,  // padding
        0, 0, 0, 0   // padding
      )

      println("Loading matrices...")
      MatrixLoader.loadMatrixA(dut, matrixA, rows = 4, cols = 4, packWidth = 4)
      MatrixLoader.loadMatrixB(dut, matrixB, rows = 4, cols = 4, packWidth = 4)

      // Initial state
      dut.io.testMode.poke(true.B)
      dut.clock.step(1)
      logger.logCycle(dut, 0)

      // Switch to operation mode
      dut.io.testMode.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(2.U)  // 2x2 inner dimension
      dut.io.n.poke(1.U)
      dut.clock.step(2)
      logger.logCycle(dut, 1)

      println("Starting computation...")

      // Start
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      logger.logCycle(dut, 2)
      dut.io.start.poke(false.B)

      // Log every cycle
      var cycle = 3
      while (!dut.io.done.peek().litToBoolean && cycle < 100) {
        dut.clock.step(1)
        logger.logCycle(dut, cycle)
        cycle += 1
      }

      // A few more after done
      for (_ <- 0 until 3) {
        dut.clock.step(1)
        logger.logCycle(dut, cycle)
        cycle += 1
      }

      println(s"Logged $cycle cycles")
      logger.writeToFile()

      // Read results
      val results = MatrixLoader.readMatrixC(dut, rows = 4, cols = 4, packWidth = 4)

      println("\nResults (first 2x2):")
      println(s"  [${results(0)}, ${results(1)}]")
      println(s"  [${results(4)}, ${results(5)}]")

      println("\nExpected:")
      println(s"  [2, 3]")
      println(s"  [4, 5]")
    }
  }
}
