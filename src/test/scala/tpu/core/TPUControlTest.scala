// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import tpu.TPUConfig

class TPUControlTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "TPUControl"

  it should "transition through FSM states correctly" in {
    val config = TPUConfig(n = 4)
    test(new TPUControl(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      // Initialize inputs
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(4.U)
      dut.io.n.poke(1.U)

      // Provide dummy matOut data
      for (i <- 0 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke(0.S)
        }
      }

      // Initial state should be IDLE, done = false
      dut.io.done.expect(false.B)
      dut.io.sysReset.expect(true.B)
      dut.clock.step(1)

      // Assert start signal
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Should be in IDLE2 state now
      dut.io.done.expect(false.B)
      dut.clock.step(1)

      // Should transition to CALCULATE state
      dut.io.sysReset.expect(false.B)
      dut.io.done.expect(false.B)

      // Wait for calculation to complete (k + 7 cycles)
      // For k=4, should be 4+7=11 cycles
      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 50) {
        dut.clock.step(1)
        cycleCount += 1
      }

      // Should reach FINISH state and assert done
      dut.io.done.expect(true.B)

      // After FINISH, should return to IDLE
      dut.clock.step(1)
      dut.io.done.expect(false.B)
    }
  }

  it should "generate correct timing control signals" in {
    val config = TPUConfig(n = 4)
    test(new TPUControl(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(5.U)
      dut.io.n.poke(1.U)

      for (i <- 0 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke(0.S)
        }
      }

      dut.clock.step(1)

      // Start execution
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // IDLE2 state (cnt = 0)
      dut.clock.step(1)

      // CALCULATE state begins (cnt = 1)
      // During calculation, stopRead and FIFO enables should change
      var foundEnables = false
      var foundStopRead = false

      // Check over several cycles that enables are asserted at some point
      for (_ <- 0 until 10) {
        if (dut.io.rdEnA(0).peek().litToBoolean) {
          foundEnables = true
        }
        if (dut.io.stopRead.peek().litToBoolean) {
          foundStopRead = true
        }
        dut.clock.step(1)
      }

      assert(foundEnables, "FIFO enables should be asserted during calculation")
      assert(foundStopRead, "stopRead should be asserted at some point")

      // Wait for completion
      dut.clock.step(10)
    }
  }

  it should "generate correct buffer addresses during calculation" in {
    val config = TPUConfig(n = 4)
    test(new TPUControl(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(4.U)
      dut.io.n.poke(1.U)

      for (i <- 0 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke(0.S)
        }
      }

      dut.clock.step(1)

      // Start execution
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Check initial addresses are 0
      dut.io.bufA.addr.expect(0.U)
      dut.io.bufB.addr.expect(0.U)
      dut.io.bufC.addr.expect(0.U)

      dut.clock.step(2)  // IDLE2 and CALCULATE start

      // Track that addresses increment over time
      var maxAddrA = 0
      var maxAddrB = 0
      var foundWriteEnable = false

      for (_ <- 0 until 20) {
        val addrA = dut.io.bufA.addr.peek().litValue.toInt
        val addrB = dut.io.bufB.addr.peek().litValue.toInt
        if (addrA > maxAddrA) maxAddrA = addrA
        if (addrB > maxAddrB) maxAddrB = addrB
        if (dut.io.bufC.wrEn.peek().litToBoolean) {
          foundWriteEnable = true
        }
        dut.clock.step(1)
      }

      // Addresses should have incremented during calculation
      assert(maxAddrA > 0, s"Buffer A address should increment, max was $maxAddrA")
      assert(maxAddrB > 0, s"Buffer B address should increment, max was $maxAddrB")
      assert(foundWriteEnable, "Buffer C write enable should be asserted")
    }
  }

  it should "generate staggered FIFO read enables correctly" in {
    val config = TPUConfig(n = 4)
    test(new TPUControl(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(6.U)
      dut.io.n.poke(1.U)

      for (i <- 0 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke(0.S)
        }
      }

      // All enables should be false initially
      for (i <- 0 until config.n) {
        dut.io.rdEnA(i).expect(false.B)
        dut.io.rdEnB(i).expect(false.B)
      }

      dut.clock.step(1)

      // Start
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)
      dut.clock.step(1)  // IDLE2
      dut.clock.step(1)  // CALCULATE cnt=1

      // cnt=2: startFifo, rdEn[0] should be true
      dut.clock.step(1)
      assert(dut.io.rdEnA(0).peek().litToBoolean)
      assert(dut.io.rdEnB(0).peek().litToBoolean)
      assert(!dut.io.rdEnA(1).peek().litToBoolean)
      assert(!dut.io.rdEnB(1).peek().litToBoolean)

      // cnt=3: rdEn[0,1] should be true (staggered)
      dut.clock.step(1)
      assert(dut.io.rdEnA(0).peek().litToBoolean)
      assert(dut.io.rdEnB(0).peek().litToBoolean)
      assert(dut.io.rdEnA(1).peek().litToBoolean)
      assert(dut.io.rdEnB(1).peek().litToBoolean)
      assert(!dut.io.rdEnA(2).peek().litToBoolean)

      // cnt=4: rdEn[0,1,2] should be true
      dut.clock.step(1)
      assert(dut.io.rdEnA(2).peek().litToBoolean)
      assert(dut.io.rdEnB(2).peek().litToBoolean)
      assert(!dut.io.rdEnA(3).peek().litToBoolean)

      // cnt=5: All rdEn[0,1,2,3] should be true
      dut.clock.step(1)
      for (i <- 0 until config.n) {
        assert(dut.io.rdEnA(i).peek().litToBoolean)
        assert(dut.io.rdEnB(i).peek().litToBoolean)
      }

      // Continue to stopFifo (cnt = k+3 = 9)
      dut.clock.step(4)

      // After stopFifo, enables should start turning off
      assert(!dut.io.rdEnA(0).peek().litToBoolean)
      assert(!dut.io.rdEnB(0).peek().litToBoolean)
    }
  }

  it should "write results to buffer C correctly" in {
    val config = TPUConfig(n = 4)
    test(new TPUControl(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(2.U)
      dut.io.n.poke(1.U)

      // Provide test data in matOut
      for (i <- 0 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke((i * 16 + j).S)
        }
      }

      dut.clock.step(1)

      // Start
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait for WRITE state and completion
      var foundWrite = false
      var cycleCount = 0

      while (!dut.io.done.peek().litToBoolean && cycleCount < 50) {
        if (dut.io.bufC.wrEn.peek().litToBoolean) {
          foundWrite = true
        }
        dut.clock.step(1)
        cycleCount += 1
      }

      // Should have found write enable at some point
      assert(foundWrite, "Buffer C write enable should be asserted")

      // Should reach FINISH
      assert(dut.io.done.peek().litToBoolean, s"Should complete after $cycleCount cycles")
      assert(dut.io.sysReset.peek().litToBoolean, "sysReset should be true after completion")
    }
  }

  it should "handle different matrix dimensions (m, k, n)" in {
    val config = TPUConfig(n = 4)

    // Test with k=1 (minimal)
    test(new TPUControl(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(1.U)
      dut.io.n.poke(1.U)

      for (i <- 0 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke(0.S)
        }
      }

      dut.clock.step(1)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait for completion
      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 50) {
        dut.clock.step(1)
        cycleCount += 1
      }

      assert(dut.io.done.peek().litToBoolean, "Should complete with k=1")
      assert(cycleCount < 50, "Should complete in reasonable time")
    }

    // Test with larger k
    test(new TPUControl(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(2.U)
      dut.io.k.poke(10.U)
      dut.io.n.poke(2.U)

      for (i <- 0 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke(0.S)
        }
      }

      dut.clock.step(1)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait for completion
      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 100) {
        dut.clock.step(1)
        cycleCount += 1
      }

      assert(dut.io.done.peek().litToBoolean, "Should complete with k=10")
    }
  }

  it should "reset properly between operations" in {
    val config = TPUConfig(n = 4)
    test(new TPUControl(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(2.U)
      dut.io.n.poke(1.U)

      for (i <- 0 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke(0.S)
        }
      }

      // First operation
      dut.clock.step(1)
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      var cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 50) {
        dut.clock.step(1)
        cycleCount += 1
      }

      dut.io.done.expect(true.B)
      dut.clock.step(1)

      // Should return to IDLE
      dut.io.done.expect(false.B)

      // Second operation should work
      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      cycleCount = 0
      while (!dut.io.done.peek().litToBoolean && cycleCount < 50) {
        dut.clock.step(1)
        cycleCount += 1
      }

      dut.io.done.expect(true.B)
    }
  }

  it should "pack matOut into buffer C correctly (4x16-bit to 64-bit)" in {
    val config = TPUConfig(n = 4)
    test(new TPUControl(config)) { dut =>
      dut.io.start.poke(false.B)
      dut.io.m.poke(1.U)
      dut.io.k.poke(2.U)
      dut.io.n.poke(1.U)

      // Set specific values in matOut for row 0
      dut.io.matOut(0)(0).poke(0x1111.S)
      dut.io.matOut(0)(1).poke(0x2222.S)
      dut.io.matOut(0)(2).poke(0x3333.S)
      dut.io.matOut(0)(3).poke(0x4444.S)

      // Other rows
      for (i <- 1 until config.n) {
        for (j <- 0 until config.n) {
          dut.io.matOut(i)(j).poke(0.S)
        }
      }

      dut.clock.step(1)

      dut.io.start.poke(true.B)
      dut.clock.step(1)
      dut.io.start.poke(false.B)

      // Wait for WRITE state
      for (_ <- 0 until 15) {
        dut.clock.step(1)
      }

      // Check that buffer C data is packed correctly
      // Expected: [4444][3333][2222][1111] = 0x4444333322221111
      val expectedPacked = BigInt("4444333322221111", 16)
      dut.io.bufC.wrData.expect(expectedPacked.U)
    }
  }
}
