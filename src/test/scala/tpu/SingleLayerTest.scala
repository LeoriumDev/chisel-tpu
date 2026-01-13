// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import tpu.utils.{MatrixLoader, MetricsCollector}

/**
 * Simple test for validating matrix multiplication infrastructure
 * Tests basic data loading and matrix multiplication on small matrices
 */
class SingleLayerTest extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "TPU Single Layer Matrix Multiplication"

  it should "multiply 2x2 matrices correctly" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config
      val metrics = MetricsCollector()

      // Test case: A = [[1, 2], [3, 4]], B = [[5, 1], [1, 6]]
      // Expected C = [[7, 13], [19, 27]]
      // IMPORTANT: Matrices must be stored COLUMN-MAJOR for systolic array!
      // A stored column-major (transpose layout) for correct FIFO feeding
      val matrixA = Array(
        1, 3, 0, 0,  // Col 0: [A[0,0], A[1,0], pad, pad] = [1, 3, 0, 0]
        2, 4, 0, 0,  // Col 1: [A[0,1], A[1,1], pad, pad] = [2, 4, 0, 0]
        0, 0, 0, 0,  // Col 2: all padding
        0, 0, 0, 0   // Col 3: all padding
      )

      val matrixB = Array(
        5, 1, 0, 0,  // Col 0: [5, 1, pad, pad]
        1, 6, 0, 0,  // Col 1: [1, 6, pad, pad]
        0, 0, 0, 0,  // Col 2: [pad, pad, pad, pad]
        0, 0, 0, 0   // Col 3: [pad, pad, pad, pad]
      )

      println("\nLoading matrices into GlobalBuffers...")

      // Load matrix A and B using test harness (full 4×4 padded matrices)
      MatrixLoader.loadMatrixA(dut, matrixA, rows = 4, cols = 4, packWidth = 4)
      MatrixLoader.loadMatrixB(dut, matrixB, rows = 4, cols = 4, packWidth = 4)

      println("Starting matrix multiplication...")

      // Disable test mode and configure TPU
      dut.io.testMode.poke(false.B)
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)  // 1 tile in M dimension
      // TESTING: Try k=2 for 2×2 matrix (inner dimension = 2)
      // k = inner dimension in words
      dut.io.k.poke(2.U)  // 2 words for inner dimension of 2
      dut.io.n.poke(1.U)  // 1 tile in N dimension
      dut.clock.step(2)

      // Start execution
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait for completion and count cycles
      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 1000) {
        dut.clock.step(1)
        cycleCount += 1
      }

      metrics.recordCycles("2x2_matmul", cycleCount)
      println(s"Computation completed in $cycleCount cycles")

      assert(dut.io.done.peek().litToBoolean, "TPU did not complete in expected time")

      // Read and verify results from buffer C
      println("Reading results from buffer C...")
      val results = MatrixLoader.readMatrixC(dut, rows = 4, cols = 4, packWidth = 4)

      // Expected C = [[7, 13], [19, 27]] with padding
      val expected = Array(
        7, 13, 0, 0,   // Row 0
        19, 27, 0, 0,  // Row 1
        0, 0, 0, 0,    // Row 2 (padding)
        0, 0, 0, 0     // Row 3 (padding)
      )

      println("Verifying results...")
      for (i <- expected.indices) {
        val row = i / 4
        val col = i % 4
        assert(results(i) == expected(i),
          s"Mismatch at [$row][$col]: expected ${expected(i)}, got ${results(i)}")
      }

      metrics.printSummary()

      println("Test passed: 2x2 matrix multiplication with verified results")
    }
  }

  it should "handle 4x4 matrix multiplication" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config
      val metrics = MetricsCollector()

      // Test case: 4x4 identity-like matrices
      // A = I (identity), B = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
      // Expected C = B (since A*I = B)
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

      println("\nLoading 4x4 matrices...")

      MatrixLoader.loadMatrixA(dut, matrixA, rows = 4, cols = 4, packWidth = 4)
      MatrixLoader.loadMatrixB(dut, matrixB, rows = 4, cols = 4, packWidth = 4)

      println("Starting 4x4 matrix multiplication...")

      // Disable test mode and configure TPU
      dut.io.testMode.poke(false.B)
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)  // 1 tile in M dimension
      // IMPORTANT: io.k is WORD COUNT, not tile count!
      // For 4×4 tile, need k=4 words to give each FIFO 4 elements
      dut.io.k.poke(4.U)  // Read 4 words for complete 4×4 tile
      dut.io.n.poke(1.U)  // 1 tile in N dimension
      dut.clock.step(2)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait for completion
      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 1000) {
        dut.clock.step(1)
        cycleCount += 1
      }

      metrics.recordCycles("4x4_matmul", cycleCount)
      println(s"4x4 multiplication completed in $cycleCount cycles")

      assert(dut.io.done.peek().litToBoolean, "TPU did not complete")

      // Read and verify results from buffer C
      println("Reading results from buffer C...")
      val results = MatrixLoader.readMatrixC(dut, rows = 4, cols = 4, packWidth = 4)

      // Expected: C = A * B = I * B = B
      // So C should be [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
      val expected = Array(
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
      )

      println("Verifying results...")
      var errorCount = 0
      for (i <- expected.indices) {
        val row = i / 4
        val col = i % 4
        if (results(i) != expected(i)) {
          println(s"Mismatch at [$row][$col]: expected ${expected(i)}, got ${results(i)}")
          errorCount += 1
        }
      }

      assert(errorCount == 0, s"Found $errorCount mismatches in results")

      metrics.printSummary()

      println("Test passed: 4x4 matrix multiplication with verified results")
    }
  }

  it should "handle larger tiled matrix multiplication (8x8)" ignore {
    // TODO: Requires tiling implementation (multi-tile FSM logic)
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config
      val metrics = MetricsCollector()

      // Test 8x8 matrix that requires tiling (2x2 tiles of 4x4)
      // Simple test with all 1s
      val matrixA = Array.fill(8 * 8)(1)
      val matrixB = Array.fill(8 * 8)(1)

      println("\nLoading 8x8 matrices (requires tiling)...")

      MatrixLoader.loadMatrixA(dut, matrixA, rows = 8, cols = 8, packWidth = 4)
      MatrixLoader.loadMatrixB(dut, matrixB, rows = 8, cols = 8, packWidth = 4)

      println("Starting tiled 8x8 matrix multiplication...")

      // Disable test mode and configure for tiled execution
      dut.io.testMode.poke(false.B)
      dut.io.start.poke(false.B)
      dut.io.m.poke(2.U)  // 8/4 = 2 tiles
      dut.io.k.poke(2.U)  // 8/4 = 2 tiles
      dut.io.n.poke(2.U)  // 8/4 = 2 tiles
      dut.clock.step(2)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait for completion (tiled execution takes longer)
      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 5000) {
        dut.clock.step(1)
        cycleCount += 1
      }

      metrics.recordCycles("8x8_tiled_matmul", cycleCount)
      println(s"Tiled 8x8 multiplication completed in $cycleCount cycles")

      assert(dut.io.done.peek().litToBoolean, "TPU did not complete tiled multiplication")

      // Read and verify results from buffer C
      println("Reading results from buffer C...")
      val results = MatrixLoader.readMatrixC(dut, rows = 8, cols = 8, packWidth = 4)

      // Expected: C[i][j] = sum of A[i][k] * B[k][j] for k=0..7
      // Since A and B are all 1s: C[i][j] = 8 for all i,j
      val expected = Array.fill(64)(8)

      println("Verifying results...")
      var errorCount = 0
      for (i <- expected.indices) {
        val row = i / 8
        val col = i % 8
        if (results(i) != expected(i)) {
          println(s"Mismatch at [$row][$col]: expected ${expected(i)}, got ${results(i)}")
          errorCount += 1
        }
      }

      assert(errorCount == 0, s"Found $errorCount mismatches in 8x8 tiled results")

      metrics.printSummary()

      println("Test passed: Tiled 8x8 matrix multiplication with verified results")
    }
  }
}
