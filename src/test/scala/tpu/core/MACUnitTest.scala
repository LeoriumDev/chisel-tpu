// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import tpu.TPUConfig

class MACUnitTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "MACUnit"

  it should "perform multiply-accumulate correctly" in {
    val config = TPUConfig()
    test(new MACUnit(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      dut.io.sysReset.poke(false.B)

      // First cycle: 2 * 3 = 6
      dut.io.interconnect.upIn.poke(2.S)
      dut.io.interconnect.leftIn.poke(3.S)
      dut.clock.step(1)
      dut.io.matOut.expect(6.S)

      // Second cycle: accumulate 4 * 5 = 20, total = 26
      dut.io.interconnect.upIn.poke(4.S)
      dut.io.interconnect.leftIn.poke(5.S)
      dut.clock.step(1)
      dut.io.matOut.expect(26.S)

      // Third cycle: accumulate -3 * 2 = -6, total = 20
      dut.io.interconnect.upIn.poke(-3.S)
      dut.io.interconnect.leftIn.poke(2.S)
      dut.clock.step(1)
      dut.io.matOut.expect(20.S)
    }
  }

  it should "forward inputs through systolic network" in {
    val config = TPUConfig()
    test(new MACUnit(config)) { dut =>
      dut.io.sysReset.poke(false.B)

      // Poke inputs
      dut.io.interconnect.upIn.poke(7.S)
      dut.io.interconnect.leftIn.poke(9.S)
      dut.clock.step(1)

      // Outputs should match previous inputs (one cycle delay)
      dut.io.interconnect.upOut.expect(7.S)
      dut.io.interconnect.leftOut.expect(9.S)

      // Poke new inputs
      dut.io.interconnect.upIn.poke(11.S)
      dut.io.interconnect.leftIn.poke(13.S)
      dut.clock.step(1)

      // Outputs should match previous inputs
      dut.io.interconnect.upOut.expect(11.S)
      dut.io.interconnect.leftOut.expect(13.S)
    }
  }

  it should "reset accumulator on sysReset" in {
    val config = TPUConfig()
    test(new MACUnit(config)) { dut =>
      // Accumulate some value
      dut.io.sysReset.poke(false.B)
      dut.io.interconnect.upIn.poke(5.S)
      dut.io.interconnect.leftIn.poke(5.S)
      dut.clock.step(1)
      dut.io.matOut.expect(25.S)

      // Another accumulation
      dut.io.interconnect.upIn.poke(3.S)
      dut.io.interconnect.leftIn.poke(4.S)
      dut.clock.step(1)
      dut.io.matOut.expect(37.S)

      // Assert systolic reset
      dut.io.sysReset.poke(true.B)
      dut.clock.step(1)
      dut.io.matOut.expect(0.S)
      dut.io.interconnect.upOut.expect(0.S)
      dut.io.interconnect.leftOut.expect(0.S)

      // Deassert reset and verify accumulation restarts from 0
      dut.io.sysReset.poke(false.B)
      dut.io.interconnect.upIn.poke(2.S)
      dut.io.interconnect.leftIn.poke(3.S)
      dut.clock.step(1)
      dut.io.matOut.expect(6.S)
    }
  }

  it should "handle negative numbers correctly" in {
    val config = TPUConfig()
    test(new MACUnit(config)) { dut =>
      dut.io.sysReset.poke(false.B)

      // -5 * 3 = -15
      dut.io.interconnect.upIn.poke(-5.S)
      dut.io.interconnect.leftIn.poke(3.S)
      dut.clock.step(1)
      dut.io.matOut.expect(-15.S)

      // -2 * -4 = 8, total = -7
      dut.io.interconnect.upIn.poke(-2.S)
      dut.io.interconnect.leftIn.poke(-4.S)
      dut.clock.step(1)
      dut.io.matOut.expect(-7.S)
    }
  }

  it should "handle maximum accumulation for 4x4 array" in {
    val config = TPUConfig()
    test(new MACUnit(config)) { dut =>
      dut.io.sysReset.poke(false.B)

      // Worst case for 4x4: 4 multiplications of max values
      // Each: 127 * 127 = 16129
      // Total: 4 * 16129 = 64516 (fits in 21 bits: max 2^20 = 1048576)
      for (_ <- 0 until 4) {
        dut.io.interconnect.upIn.poke(127.S)
        dut.io.interconnect.leftIn.poke(127.S)
        dut.clock.step(1)
      }

      dut.io.matOut.expect(64516.S)
    }
  }
}
