// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import chisel3.util.log2Ceil
import tpu.core._

/**
  * Top-level TPU module integrating all components
  *
  * This module connects:
  * - 3× Global Buffers (A, B, C)
  * - 1× Systolic Array (N×N MAC grid)
  * - 1× TPU Control (FSM)
  *
  * Data flow:
  * 1. Matrices A and B stored in global buffers
  * 2. Control FSM reads from buffers, feeds systolic array
  * 3. Systolic array computes matrix multiplication
  * 4. Results written back to buffer C
  *
  * @param config TPU configuration
  */
class TPUTop(config: TPUConfig = TPUConfig()) extends Module {
  val io = IO(new Bundle {
    val start = Input(Bool())
    val m     = Input(UInt(16.W))
    val k     = Input(UInt(16.W))
    val n     = Input(UInt(16.W))
    val done  = Output(Bool())

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
  control.io.start := io.start
  control.io.m     := io.m
  control.io.k     := io.k
  control.io.n     := io.n
  io.done          := control.io.done

  // Connect global buffers
  bufferA.io <> control.io.bufA
  bufferB.io <> control.io.bufB
  bufferC.io <> control.io.bufC

  // Connect systolic array
  systolicArray.io.matrixAData := control.io.bufA.rdData
  systolicArray.io.matrixBData := control.io.bufB.rdData
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
