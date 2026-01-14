// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import chisel3.util.log2Ceil
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

    // Debug outputs - Systolic Array FIFO A
    val debug_fifosA_wrPtr   = Output(Vec(config.n, UInt(log2Ceil(config.fifoDepth).W)))
    val debug_fifosA_rdPtr   = Output(Vec(config.n, UInt(log2Ceil(config.fifoDepth).W)))
    val debug_fifosA_count   = Output(Vec(config.n, UInt(config.fifoAddrWidth.W)))
    val debug_fifosA_dataOut = Output(Vec(config.n, SInt(config.dataWidth.W)))
    val debug_fifosA_empty   = Output(Vec(config.n, Bool()))
    val debug_fifosA_full    = Output(Vec(config.n, Bool()))

    // Debug outputs - Systolic Array FIFO B
    val debug_fifosB_wrPtr   = Output(Vec(config.n, UInt(log2Ceil(config.fifoDepth).W)))
    val debug_fifosB_rdPtr   = Output(Vec(config.n, UInt(log2Ceil(config.fifoDepth).W)))
    val debug_fifosB_count   = Output(Vec(config.n, UInt(config.fifoAddrWidth.W)))
    val debug_fifosB_dataOut = Output(Vec(config.n, SInt(config.dataWidth.W)))
    val debug_fifosB_empty   = Output(Vec(config.n, Bool()))
    val debug_fifosB_full    = Output(Vec(config.n, Bool()))

    // Debug outputs - MAC grid state
    val debug_macAccReg  = Output(Vec(config.n, Vec(config.n, SInt(config.accWidth.W))))
    val debug_macUpReg   = Output(Vec(config.n, Vec(config.n, SInt(config.dataWidth.W))))
    val debug_macLeftReg = Output(Vec(config.n, Vec(config.n, SInt(config.dataWidth.W))))

    // Debug outputs - Systolic interconnect wires
    val debug_topNet  = Output(Vec(config.n + 1, Vec(config.n, SInt(config.dataWidth.W))))
    val debug_leftNet = Output(Vec(config.n + 1, Vec(config.n, SInt(config.dataWidth.W))))

    // Debug outputs - Delayed read enables
    val debug_rdEnADelayed = Output(Vec(config.n, Bool()))
    val debug_rdEnBDelayed = Output(Vec(config.n, Bool()))

    // Debug outputs - TPU Control
    val debug_state     = Output(UInt(3.W))
    val debug_cnt       = Output(UInt(12.W))
    val debug_stopRead  = Output(Bool())
    val debug_startFifo = Output(Bool())
    val debug_stopFifo  = Output(Bool())
    val debug_cntEnd    = Output(Bool())
    val debug_addrA     = Output(UInt(config.bufferAddrWidth.W))
    val debug_addrB     = Output(UInt(config.bufferAddrWidth.W))
    val debug_addrC     = Output(UInt(config.bufferAddrWidth.W))
    val debug_writeCnt  = Output(UInt(log2Ceil(config.n + 1).W))

    // Debug outputs - matOut (from systolic array)
    val debug_matOut = Output(Vec(config.n, Vec(config.n, SInt(config.accWidth.W))))
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

  // Debug outputs - Systolic Array
  io.debug_fifosA_wrPtr   := systolicArray.io.debug_fifosA_wrPtr
  io.debug_fifosA_rdPtr   := systolicArray.io.debug_fifosA_rdPtr
  io.debug_fifosA_count   := systolicArray.io.debug_fifosA_count
  io.debug_fifosA_dataOut := systolicArray.io.debug_fifosA_dataOut
  io.debug_fifosA_empty   := systolicArray.io.debug_fifosA_empty
  io.debug_fifosA_full    := systolicArray.io.debug_fifosA_full

  io.debug_fifosB_wrPtr   := systolicArray.io.debug_fifosB_wrPtr
  io.debug_fifosB_rdPtr   := systolicArray.io.debug_fifosB_rdPtr
  io.debug_fifosB_count   := systolicArray.io.debug_fifosB_count
  io.debug_fifosB_dataOut := systolicArray.io.debug_fifosB_dataOut
  io.debug_fifosB_empty   := systolicArray.io.debug_fifosB_empty
  io.debug_fifosB_full    := systolicArray.io.debug_fifosB_full

  io.debug_macAccReg  := systolicArray.io.debug_macAccReg
  io.debug_macUpReg   := systolicArray.io.debug_macUpReg
  io.debug_macLeftReg := systolicArray.io.debug_macLeftReg

  io.debug_topNet  := systolicArray.io.debug_topNet
  io.debug_leftNet := systolicArray.io.debug_leftNet

  io.debug_rdEnADelayed := systolicArray.io.debug_rdEnADelayed
  io.debug_rdEnBDelayed := systolicArray.io.debug_rdEnBDelayed

  // Debug outputs - TPU Control
  io.debug_state     := control.io.debug_state
  io.debug_cnt       := control.io.debug_cnt
  io.debug_stopRead  := control.io.debug_stopRead
  io.debug_startFifo := control.io.debug_startFifo
  io.debug_stopFifo  := control.io.debug_stopFifo
  io.debug_cntEnd    := control.io.debug_cntEnd
  io.debug_addrA     := control.io.debug_addrA
  io.debug_addrB     := control.io.debug_addrB
  io.debug_addrC     := control.io.debug_addrC
  io.debug_writeCnt  := control.io.debug_writeCnt

  // Debug outputs - matOut
  io.debug_matOut := systolicArray.io.matOut
}
