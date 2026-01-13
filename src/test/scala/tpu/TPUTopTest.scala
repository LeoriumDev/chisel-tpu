// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class TPUTopTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "TPUTop"

  it should "instantiate correctly with default configuration" in {
    val config = TPUConfig()
    test(new TPUTop(config)) { dut =>
      // Basic instantiation test
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.n.poke(1.U)
      dut.clock.step(1)

      // Should be in idle state initially
      dut.io.done.expect(false.B)
    }
  }

  it should "instantiate correctly with custom configuration" in {
    val config = TPUConfig(n = 8, dataWidth = 8, wordWidth = 64, bufferDepth = 512)
    test(new TPUTop(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.n.poke(1.U)
      dut.clock.step(1)

      dut.io.done.expect(false.B)
    }
  }

  it should "respond to start signal and eventually signal done" in {
    val config = TPUConfig(n = 4)
    test(new TPUTop(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      // Initial state
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(2.U)  // Small k for quick test
      dut.io.n.poke(1.U)
      dut.io.done.expect(false.B)
      dut.clock.step(2)

      // Assert start signal
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait for done signal (should eventually complete)
      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 100) {
        dut.clock.step(1)
        cycleCount += 1
      }

      // Verify done is asserted
      assert(dut.io.done.peek().litToBoolean, "TPU did not signal done in expected time")
      assert(cycleCount < 100, s"TPU took too long: $cycleCount cycles")

      // After done, should return to idle
      dut.clock.step(1)
      dut.io.done.expect(false.B)
    }
  }

  it should "maintain stable output when not started" in {
    val config = TPUConfig()
    test(new TPUTop(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.n.poke(1.U)

      // Run for several cycles without starting
      for (_ <- 0 until 20) {
        dut.io.done.expect(false.B)
        dut.clock.step(1)
      }

      // Done should remain false throughout
      dut.io.done.expect(false.B)
    }
  }

  it should "handle multiple consecutive operations" in {
    val config = TPUConfig(n = 4)
    test(new TPUTop(config)) { dut =>
      // First operation
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(2.U)
      dut.io.n.poke(1.U)
      dut.clock.step(1)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 100) {
        dut.clock.step(1)
        cycleCount += 1
      }

      assert(dut.io.done.peek().litToBoolean, "First operation did not complete")
      dut.clock.step(1)

      // Second operation with different parameters
      dut.io.m.poke(1.U)
      dut.io.k.poke(3.U)
      dut.io.n.poke(1.U)
      dut.clock.step(1)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 100) {
        dut.clock.step(1)
        cycleCount += 1
      }

      assert(dut.io.done.peek().litToBoolean, "Second operation did not complete")
    }
  }

  it should "handle different matrix dimension parameters" in {
    val config = TPUConfig(n = 4)

    // Test with m=1, k=1, n=1 (minimal)
    test(new TPUTop(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.n.poke(1.U)
      dut.clock.step(1)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 50) {
        dut.clock.step(1)
        cycleCount += 1
      }

      assert(dut.io.done.peek().litToBoolean, "Failed with m=1, k=1, n=1")
    }

    // Test with larger dimensions
    test(new TPUTop(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(2.U)
      dut.io.k.poke(4.U)
      dut.io.n.poke(2.U)
      dut.clock.step(1)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 100) {
        dut.clock.step(1)
        cycleCount += 1
      }

      assert(dut.io.done.peek().litToBoolean, "Failed with m=2, k=4, n=2")
    }
  }

  it should "not start operation without start signal" in {
    val config = TPUConfig()
    test(new TPUTop(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.n.poke(1.U)

      // Run for many cycles without start
      for (_ <- 0 until 50) {
        dut.clock.step(1)
      }

      // Should never signal done without start
      dut.io.done.expect(false.B)
    }
  }

  it should "ignore start signal glitches when already running" in {
    val config = TPUConfig(n = 4)
    test(new TPUTop(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(5.U)  // Larger k so we have time to test
      dut.io.n.poke(1.U)
      dut.clock.step(1)

      // Start first operation
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait a few cycles
      dut.clock.step(5)

      // Try to start again while running (should be ignored)
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Should still complete the original operation
      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 100) {
        dut.clock.step(1)
        cycleCount += 1
      }

      assert(dut.io.done.peek().litToBoolean, "Operation should complete despite glitch")
    }
  }

  it should "have proper timing for small matrix operations" in {
    val config = TPUConfig(n = 4)
    test(new TPUTop(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(4.U)
      dut.io.n.poke(1.U)
      dut.clock.step(1)

      val startCycle = 0
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 200) {
        dut.clock.step(1)
        cycleCount += 1
      }

      // Expected timing: IDLE2 + (k+7) cycles for CALCULATE + n cycles for WRITE + FINISH
      // = 1 + (k+7) + n + 1 = 1 + (4+7) + 4 + 1 = 17 cycles approximately
      println(s"Completed in $cycleCount cycles for k=4, n=4")
      assert(cycleCount < 30, s"Timing seems incorrect: $cycleCount cycles")
      assert(cycleCount > 10, s"Completed too quickly: $cycleCount cycles")
    }
  }

  it should "correctly integrate all submodules (smoke test)" in {
    val config = TPUConfig(n = 4, dataWidth = 8, bufferDepth = 256)
    test(new TPUTop(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      // This test verifies that all submodules are properly connected
      // by running a complete operation and checking for crashes/hangs

      dut.io.start.poke(false.B)
      dut.io.m.poke(2.U)
      dut.io.k.poke(6.U)
      dut.io.n.poke(2.U)
      dut.clock.step(2)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      var cycleCount = 0
      var maxCycles = 200

      while (!dut.io.done.peek().litToBoolean && cycleCount < maxCycles) {
        dut.clock.step(1)
        cycleCount += 1
      }

      assert(dut.io.done.peek().litToBoolean,
        s"Integration test failed: TPU did not complete in $maxCycles cycles")

      println(s"Integration test passed: completed in $cycleCount cycles")
    }
  }
}
