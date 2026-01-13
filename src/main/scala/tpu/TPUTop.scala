// SPDX-License-Identifier: MIT

package tpu

import chisel3._
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
}
