// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import tpu.core._

/**
 * Test harness for TPU that exposes buffer access for testing
 * This wrapper allows tests to directly load data into buffers
 * while preserving the normal TPU operation
 */
class TPUTestHarness(config: TPUConfig = TPUConfig()) extends Module {
  val io = IO(new Bundle {
    // Normal TPU interface
    val start = Input(Bool())
    val m     = Input(UInt(8.W))  // Widened to support larger matrices (0-255 tiles)
    val k     = Input(UInt(8.W))  // Widened to support larger matrices
    val n     = Input(UInt(8.W))  // Widened to support larger matrices
    val done  = Output(Bool())

    // Test-only buffer access
    val testMode = Input(Bool())  // When true, allow direct buffer access

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
  // Note: Control unit expects 4-bit m/k/n, we truncate the 8-bit test values
  // This limits each dimension to 15 tiles max, but test harness accepts 0-255
  control.io.start := io.start
  control.io.m     := io.m(3, 0)  // Truncate to 4 bits for now
  control.io.k     := io.k(3, 0)  // Truncate to 4 bits for now
  control.io.n     := io.n(3, 0)  // Truncate to 4 bits for now
  io.done          := control.io.done

  // Multiplex buffer access between test mode and normal operation
  // rdData is always available from buffers
  io.bufA_rdData := bufferA.io.rdData
  io.bufB_rdData := bufferB.io.rdData
  io.bufC_rdData := bufferC.io.rdData
  control.io.bufA.rdData := bufferA.io.rdData
  control.io.bufB.rdData := bufferB.io.rdData
  control.io.bufC.rdData := bufferC.io.rdData

  // Multiplex write and address signals
  when(io.testMode) {
    // Test mode: Direct buffer access from test signals
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
    // Normal mode: Control unit manages buffers
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

  // Connect systolic array (always connected)
  systolicArray.io.matrixAData := bufferA.io.rdData
  systolicArray.io.matrixBData := bufferB.io.rdData
  systolicArray.io.sysReset    := control.io.sysReset
  systolicArray.io.stopRead    := control.io.stopRead
  systolicArray.io.rdEnA       := control.io.rdEnA
  systolicArray.io.rdEnB       := control.io.rdEnB
  control.io.matOut            := systolicArray.io.matOut
}
