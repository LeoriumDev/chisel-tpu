// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import chisel3.stage.ChiselStage
import tpu.core._

object MainTestHarness extends App {
  println("Generating Verilog for TPU Test Harness...")
  val config = TPUConfig(n = 4, dataWidth = 8)
  println(s"  Data width: ${config.dataWidth} bits")
  println(s"  Accumulator width: ${config.accWidth} bits")
  println(s"  Buffer depth: ${config.bufferDepth} words")

  // Move TPUTestHarness to main package temporarily for Verilog generation
  class TPUTestHarnessGen(config: TPUConfig = TPUConfig()) extends Module {
    val io = IO(new Bundle {
      // Normal TPU interface
      val start = Input(Bool())
      val m     = Input(UInt(16.W))
      val k     = Input(UInt(16.W))
      val n     = Input(UInt(16.W))
      val done  = Output(Bool())

      // Test-only buffer access
      val testMode = Input(Bool())

      // Buffer A test access
      val bufA_wrEn   = Input(Bool())
      val bufA_addr   = Input(UInt(config.bufferAddrWidth.W))
      val bufA_wrData = Input(UInt(config.wordWidth.W))
      val bufA_rdData = Output(UInt(config.wordWidth.W))

      // Buffer B test access
      val bufB_wrEn   = Input(Bool())
      val bufB_addr   = Input(UInt(config.bufferAddrWidth.W))
      val bufB_wrData = Input(UInt(config.wordWidth.W))
      val bufB_rdData = Output(UInt(config.wordWidth.W))

      // Buffer C test access
      val bufC_wrEn   = Input(Bool())
      val bufC_addr   = Input(UInt(config.bufferAddrWidth.W))
      val bufC_wrData = Input(UInt(config.extendedWordWidth.W))
      val bufC_rdData = Output(UInt(config.extendedWordWidth.W))
    })

    // Instantiate global buffers
    val bufferA = Module(new GlobalBuffer(config, config.wordWidth))
    val bufferB = Module(new GlobalBuffer(config, config.wordWidth))
    val bufferC = Module(new GlobalBuffer(config, config.extendedWordWidth))

    // Instantiate systolic array
    val systolicArray = Module(new SystolicArray(config))

    // Instantiate control unit
    val control = Module(new TPUControl(config))

    // Connect control to I/O
    control.io.start := io.start
    control.io.m     := io.m
    control.io.k     := io.k
    control.io.n     := io.n
    io.done          := control.io.done

    // Multiplex buffer access
    io.bufA_rdData := bufferA.io.rdData
    io.bufB_rdData := bufferB.io.rdData
    io.bufC_rdData := bufferC.io.rdData
    control.io.bufA.rdData := bufferA.io.rdData
    control.io.bufB.rdData := bufferB.io.rdData
    control.io.bufC.rdData := bufferC.io.rdData

    when(io.testMode) {
      bufferA.io.wrEn   := io.bufA_wrEn
      bufferA.io.addr   := io.bufA_addr
      bufferA.io.wrData := io.bufA_wrData

      bufferB.io.wrEn   := io.bufB_wrEn
      bufferB.io.addr   := io.bufB_addr
      bufferB.io.wrData := io.bufB_wrData

      bufferC.io.wrEn   := io.bufC_wrEn
      bufferC.io.addr   := io.bufC_addr
      bufferC.io.wrData := io.bufC_wrData
    }.otherwise {
      bufferA.io.wrEn   := control.io.bufA.wrEn
      bufferA.io.addr   := control.io.bufA.addr
      bufferA.io.wrData := control.io.bufA.wrData

      bufferB.io.wrEn   := control.io.bufB.wrEn
      bufferB.io.addr   := control.io.bufB.addr
      bufferB.io.wrData := control.io.bufB.wrData

      bufferC.io.wrEn   := control.io.bufC.wrEn
      bufferC.io.addr   := control.io.bufC.addr
      bufferC.io.wrData := control.io.bufC.wrData
    }

    // Connect systolic array
    systolicArray.io.matrixAData := bufferA.io.rdData
    systolicArray.io.matrixBData := bufferB.io.rdData
    systolicArray.io.sysReset    := control.io.sysReset
    systolicArray.io.stopRead    := control.io.stopRead
    systolicArray.io.rdEnA       := control.io.rdEnA
    systolicArray.io.rdEnB       := control.io.rdEnB
    control.io.matOut            := systolicArray.io.matOut
  }

  (new ChiselStage).emitVerilog(
    new TPUTestHarnessGen(config),
    Array("--target-dir", "generated_testharness")
  )

  println("Verilog generation complete! Check generated_testharness/ directory")
}
