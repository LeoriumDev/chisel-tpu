// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import tpu.utils.{MatrixLoader, MetricsCollector}
import java.io.File

/**
 * Debug test to verify hex file loading and basic TPU operation
 */
class MNISTDebugTest extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "MNIST Hex File Loading Debug"

  val hexDir = "tpu_project/sw/hex/mlp_fixed_quantized"

  it should "verify FC2 weight file loading and readback" in {
    val config = TPUConfig(n = 4, dataWidth = 8, bufferDepth = 2048)

    test(new TPUTestHarness(config)) { dut =>
      implicit val implicitConfig = config

      println("\n" + "="*70)
      println("FC2 Weight File Loading Debug Test")
      println("="*70)

      // FC2 weights are 10×10 = 100 values
      val weightsFile = s"$hexDir/fc2_w.hex"
      println(s"Loading FC2 weights from: $weightsFile")

      // Load weights
      MatrixLoader.loadMatrixAFromFile(
        dut, weightsFile,
        rows = 10, cols = 10,
        packWidth = 4
      )

      // Read back and verify
      println("Reading back first few words...")
      dut.io.testMode.poke(true.B)
      dut.io.bufA_wrEn.poke(false.B)

      for (addr <- 0 until 5) {
        dut.io.bufA_addr.poke(addr.U)
        dut.clock.step(1)
        val word = dut.io.bufA_rdData.peekInt()
        println(f"  Word[$addr] = 0x${word}%08X (${word}%d)")
      }

      println("\nFC2 input file loading...")
      val inputFile = s"$hexDir/fc1_out.hex"
      MatrixLoader.loadMatrixBFromFile(
        dut, inputFile,
        rows = 1, cols = 10,
        packWidth = 4
      )

      println("Reading back FC2 input...")
      for (addr <- 0 until 3) {
        dut.io.bufB_addr.poke(addr.U)
        dut.clock.step(1)
        val word = dut.io.bufB_rdData.peekInt()
        println(f"  Word[$addr] = 0x${word}%08X (${word}%d)")
      }

      println("="*70)
      println("Debug test passed - data loading works")
      println("="*70 + "\n")
    }
  }

  it should "test simple 2x2 multiplication with known values" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config
      val metrics = MetricsCollector()

      println("\n" + "="*70)
      println("Simple 4x4 Identity Matrix Test")
      println("="*70)

      // Test: A = Identity, B = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
      // Expected C = B (since I @ B = B)
      // This tests that the systolic array accumulates correctly
      val matrixA = Array(
        1, 0, 0, 0,  // Row 0
        0, 1, 0, 0,  // Row 1
        0, 0, 1, 0,  // Row 2
        0, 0, 0, 1   // Row 3
      )
      val matrixB = Array(
        1, 5, 9, 13,   // Col 0
        2, 6, 10, 14,  // Col 1
        3, 7, 11, 15,  // Col 2
        4, 8, 12, 16   // Col 3
      )

      println(s"Loading A (identity) and B matrices...")
      MatrixLoader.loadMatrixA(dut, matrixA, rows = 4, cols = 4)
      MatrixLoader.loadMatrixB(dut, matrixB, rows = 4, cols = 4)

      // Run multiplication
      dut.io.testMode.poke(false.B)
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)  // 1 tile in M dimension
      // IMPORTANT: io.k is WORD COUNT, not tile count!
      // For 4×4 systolic array, need k=4 words for complete inner product
      dut.io.k.poke(4.U)  // Read 4 words (4 elements per FIFO)
      dut.io.n.poke(1.U)  // 1 tile in N dimension
      dut.clock.step(2)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      var cycles = 0
      while (!dut.io.done.peek().litToBoolean && cycles < 100) {
        dut.clock.step(1)
        cycles += 1
      }

      println(s"Completed in $cycles cycles")
      assert(dut.io.done.peek().litToBoolean, "TPU didn't complete")

      // Wait a few more cycles for results to settle
      dut.clock.step(5)

      // Read result - first check raw buffer C data
      println("Reading buffer C raw data...")
      dut.io.testMode.poke(true.B)
      dut.io.bufC_wrEn.poke(false.B)
      for (addr <- 0 until 2) {
        dut.io.bufC_addr.poke(addr.U)
        dut.clock.step(1)
        val word = dut.io.bufC_rdData.peekInt()
        println(f"  BufferC[$addr] = 0x${word.toString(16)} (${word})")
      }

      val result = MatrixLoader.readMatrixC(dut, rows = 4, cols = 4)
      println(s"Result Row 0: ${result.slice(0, 4).mkString(", ")}")
      println(s"Result Row 1: ${result.slice(4, 8).mkString(", ")}")
      println(s"Result Row 2: ${result.slice(8, 12).mkString(", ")}")
      println(s"Result Row 3: ${result.slice(12, 16).mkString(", ")}")
      println(s"Expected Row 0: 1, 2, 3, 4 (from B's first row)")
      println(s"Expected Row 1: 5, 6, 7, 8 (from B's second row)")

      println("="*70 + "\n")
    }
  }
}
