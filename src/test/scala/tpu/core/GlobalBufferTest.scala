// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import tpu.TPUConfig

class GlobalBufferTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "GlobalBuffer"

  it should "perform basic write and read operations" in {
    val config = TPUConfig()
    test(new GlobalBuffer(config, wordWidth = 32)) { dut =>
      // Write data to address 0
      dut.io.wrEn.poke(true.B)
      dut.io.addr.poke(0.U)
      dut.io.wrData.poke(0x12345678L.U)
      dut.clock.step(1)

      // Read from address 0 (synchronous read)
      dut.io.wrEn.poke(false.B)
      dut.io.addr.poke(0.U)
      dut.clock.step(1)
      dut.io.rdData.expect(0x12345678L.U)

      // Write to address 1
      dut.io.wrEn.poke(true.B)
      dut.io.addr.poke(1.U)
      dut.io.wrData.poke(0xABCDEF00L.U)
      dut.clock.step(1)

      // Read from address 1
      dut.io.wrEn.poke(false.B)
      dut.io.addr.poke(1.U)
      dut.clock.step(1)
      dut.io.rdData.expect(0xABCDEF00L.U)

      // Read from address 0 again to verify persistence
      dut.io.addr.poke(0.U)
      dut.clock.step(1)
      dut.io.rdData.expect(0x12345678L.U)
    }
  }

  it should "handle address boundaries correctly" in {
    val config = TPUConfig(bufferDepth = 256)
    test(new GlobalBuffer(config, wordWidth = 32)) { dut =>
      // Test address 0 (boundary)
      dut.io.wrEn.poke(true.B)
      dut.io.addr.poke(0.U)
      dut.io.wrData.poke(0x11111111L.U)
      dut.clock.step(1)

      // Test max address (boundary)
      dut.io.addr.poke(255.U)
      dut.io.wrData.poke(0xFFFFFFFFL.U)
      dut.clock.step(1)

      // Read back address 0
      dut.io.wrEn.poke(false.B)
      dut.io.addr.poke(0.U)
      dut.clock.step(1)
      dut.io.rdData.expect(0x11111111L.U)

      // Read back max address
      dut.io.addr.poke(255.U)
      dut.clock.step(1)
      dut.io.rdData.expect(0xFFFFFFFFL.U)
    }
  }

  it should "have proper read-after-write timing (synchronous read)" in {
    val config = TPUConfig()
    test(new GlobalBuffer(config, wordWidth = 32)) { dut =>
      // Write data
      dut.io.wrEn.poke(true.B)
      dut.io.addr.poke(5.U)
      dut.io.wrData.poke(0xDEADBEEFL.U)
      dut.clock.step(1)

      // Immediately read from same address
      dut.io.wrEn.poke(false.B)
      dut.io.addr.poke(5.U)
      dut.clock.step(1)
      // Should read the written value (synchronous memory)
      dut.io.rdData.expect(0xDEADBEEFL.U)
    }
  }

  it should "support different word widths (32-bit and 64-bit)" in {
    val config = TPUConfig()

    // Test 32-bit buffer (for matrices A and B)
    test(new GlobalBuffer(config, wordWidth = 32)) { dut =>
      dut.io.wrEn.poke(true.B)
      dut.io.addr.poke(0.U)
      dut.io.wrData.poke(0xCAFEBABEL.U)
      dut.clock.step(1)

      dut.io.wrEn.poke(false.B)
      dut.io.addr.poke(0.U)
      dut.clock.step(1)
      dut.io.rdData.expect(0xCAFEBABEL.U)
    }

    // Test 64-bit buffer (for matrix C)
    test(new GlobalBuffer(config, wordWidth = 64)) { dut =>
      dut.io.wrEn.poke(true.B)
      dut.io.addr.poke(0.U)
      dut.io.wrData.poke(BigInt("DEADBEEFCAFEBABE", 16).U)
      dut.clock.step(1)

      dut.io.wrEn.poke(false.B)
      dut.io.addr.poke(0.U)
      dut.clock.step(1)
      dut.io.rdData.expect(BigInt("DEADBEEFCAFEBABE", 16).U)
    }
  }

  it should "maintain data independence across addresses" in {
    val config = TPUConfig()
    test(new GlobalBuffer(config, wordWidth = 32)) { dut =>
      // Write to multiple addresses
      for (i <- 0 until 10) {
        dut.io.wrEn.poke(true.B)
        dut.io.addr.poke(i.U)
        dut.io.wrData.poke((i * 0x1000 + i).U)
        dut.clock.step(1)
      }

      // Read back and verify all addresses
      for (i <- 0 until 10) {
        dut.io.wrEn.poke(false.B)
        dut.io.addr.poke(i.U)
        dut.clock.step(1)
        dut.io.rdData.expect((i * 0x1000 + i).U)
      }
    }
  }

  it should "handle write enable correctly (no write when wrEn is false)" in {
    val config = TPUConfig()
    test(new GlobalBuffer(config, wordWidth = 32)) { dut =>
      // Write initial value
      dut.io.wrEn.poke(true.B)
      dut.io.addr.poke(10.U)
      dut.io.wrData.poke(0x12345678L.U)
      dut.clock.step(1)

      // Try to "write" with wrEn = false
      dut.io.wrEn.poke(false.B)
      dut.io.addr.poke(10.U)
      dut.io.wrData.poke(0xFFFFFFFFL.U)  // Different data
      dut.clock.step(1)

      // Read should still return original value
      dut.io.rdData.expect(0x12345678L.U)

      // Read again to confirm
      dut.io.addr.poke(10.U)
      dut.clock.step(1)
      dut.io.rdData.expect(0x12345678L.U)
    }
  }

  it should "handle sequential writes to adjacent addresses" in {
    val config = TPUConfig()
    test(new GlobalBuffer(config, wordWidth = 32)) { dut =>
      // Simulate loading a matrix row-by-row
      val testData = Seq(0x01020304L, 0x05060708L, 0x090A0B0CL, 0x0D0E0F10L)

      for ((data, addr) <- testData.zipWithIndex) {
        dut.io.wrEn.poke(true.B)
        dut.io.addr.poke(addr.U)
        dut.io.wrData.poke(data.U)
        dut.clock.step(1)
      }

      // Sequential read back
      for ((data, addr) <- testData.zipWithIndex) {
        dut.io.wrEn.poke(false.B)
        dut.io.addr.poke(addr.U)
        dut.clock.step(1)
        dut.io.rdData.expect(data.U)
      }
    }
  }

  it should "initialize read data register to zero" in {
    val config = TPUConfig()
    test(new GlobalBuffer(config, wordWidth = 32)) { dut =>
      // Before any operation, rdData should be initialized to 0
      dut.io.rdData.expect(0.U)

      // Read from unwritten address (behavior depends on memory implementation)
      dut.io.wrEn.poke(false.B)
      dut.io.addr.poke(0.U)
      dut.clock.step(1)

      // After reading unwritten location, behavior is undefined but shouldn't crash
      // We just verify the operation completes
      dut.clock.step(1)
    }
  }
}
