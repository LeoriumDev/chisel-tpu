// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import tpu.TPUConfig

class SyncFIFOTest extends AnyFlatSpec with ChiselScalatestTester {
  behavior of "SyncFIFO"

  it should "write and read data correctly" in {
    val config = TPUConfig()
    test(new SyncFIFO(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      // Initially empty
      dut.io.empty.expect(true.B)
      dut.io.full.expect(false.B)

      // Write first value
      dut.io.wrEn.poke(true.B)
      dut.io.dataIn.poke(10.S)
      dut.clock.step(1)
      dut.io.empty.expect(false.B)

      // Write second value
      dut.io.dataIn.poke(20.S)
      dut.clock.step(1)

      // Stop writing
      dut.io.wrEn.poke(false.B)
      dut.clock.step(1)

      // Read first value
      dut.io.rdEn.poke(true.B)
      dut.clock.step(1)
      dut.io.dataOut.expect(10.S)

      // Read second value
      dut.clock.step(1)
      dut.io.dataOut.expect(20.S)

      // Should be empty after two reads
      dut.io.rdEn.poke(false.B)
      dut.clock.step(1)
      dut.io.empty.expect(true.B)
    }
  }

  it should "handle full condition correctly" in {
    val config = TPUConfig(fifoDepth = 4)
    test(new SyncFIFO(config)) { dut =>
      dut.io.wrEn.poke(true.B)
      dut.io.rdEn.poke(false.B)

      // Fill the FIFO (depth = 4)
      for (i <- 0 until 4) {
        dut.io.dataIn.poke(i.S)
        dut.io.full.expect((i == 3).B)
        dut.clock.step(1)
      }

      // FIFO should be full
      dut.io.full.expect(true.B)

      // Write should be ignored when full
      dut.io.dataIn.poke(99.S)
      dut.clock.step(1)
      dut.io.full.expect(true.B)

      // Read one element
      dut.io.wrEn.poke(false.B)
      dut.io.rdEn.poke(true.B)
      dut.clock.step(1)
      dut.io.dataOut.expect(0.S)

      // Should no longer be full
      dut.clock.step(1)
      dut.io.full.expect(false.B)
    }
  }

  it should "handle simultaneous read and write" in {
    val config = TPUConfig(fifoDepth = 4)
    test(new SyncFIFO(config)) { dut =>
      // Write initial value
      dut.io.wrEn.poke(true.B)
      dut.io.rdEn.poke(false.B)
      dut.io.dataIn.poke(5.S)
      dut.clock.step(1)

      // Simultaneous read and write
      dut.io.rdEn.poke(true.B)
      dut.io.dataIn.poke(10.S)
      dut.clock.step(1)

      // Should read the first value
      dut.io.dataOut.expect(5.S)

      // Stop writing, continue reading
      dut.io.wrEn.poke(false.B)
      dut.clock.step(1)
      dut.io.dataOut.expect(10.S)

      // Should be empty
      dut.io.rdEn.poke(false.B)
      dut.clock.step(1)
      dut.io.empty.expect(true.B)
    }
  }

  it should "handle wrap-around correctly" in {
    val config = TPUConfig(fifoDepth = 4)
    test(new SyncFIFO(config)) { dut =>
      dut.io.wrEn.poke(true.B)
      dut.io.rdEn.poke(false.B)

      // Fill FIFO
      for (i <- 0 until 3) {
        dut.io.dataIn.poke((i + 1).S)
        dut.clock.step(1)
      }

      // Read all
      dut.io.wrEn.poke(false.B)
      dut.io.rdEn.poke(true.B)
      dut.clock.step(1)
      dut.io.dataOut.expect(1.S)
      dut.clock.step(1)
      dut.io.dataOut.expect(2.S)
      dut.clock.step(1)
      dut.io.dataOut.expect(3.S)

      // FIFO empty
      dut.io.rdEn.poke(false.B)
      dut.clock.step(1)
      dut.io.empty.expect(true.B)

      // Write again (pointers should wrap)
      dut.io.wrEn.poke(true.B)
      for (i <- 0 until 3) {
        dut.io.dataIn.poke((i + 10).S)
        dut.clock.step(1)
      }

      // Read again
      dut.io.wrEn.poke(false.B)
      dut.io.rdEn.poke(true.B)
      dut.clock.step(1)
      dut.io.dataOut.expect(10.S)
      dut.clock.step(1)
      dut.io.dataOut.expect(11.S)
      dut.clock.step(1)
      dut.io.dataOut.expect(12.S)
    }
  }

  it should "preserve data order (FIFO property)" in {
    val config = TPUConfig(fifoDepth = 4)
    test(new SyncFIFO(config)) { dut =>
      val testData = Seq(7.S, -3.S, 15.S)  // Use 3 items to avoid full condition

      // Write data
      dut.io.wrEn.poke(true.B)
      dut.io.rdEn.poke(false.B)
      for (data <- testData) {
        dut.io.dataIn.poke(data)
        dut.clock.step(1)
      }

      // Read data and verify order
      dut.io.wrEn.poke(false.B)
      dut.io.rdEn.poke(true.B)
      for (data <- testData) {
        dut.clock.step(1)
        dut.io.dataOut.expect(data)
      }
    }
  }
}
