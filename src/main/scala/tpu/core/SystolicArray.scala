// SPDX-License-Identifier: MIT

package tpu.core

import chisel3._
import chisel3.util._
import tpu.TPUConfig

/**
  * Systolic Array for matrix multiplication
  *
  * N×N grid of MAC units with systolic data flow:
  * - Matrix A data flows horizontally (left to right)
  * - Matrix B data flows vertically (top to bottom)
  * - Each MAC accumulates partial results
  *
  * Architecture:
  * - N FIFOs buffer matrix A data (one per row)
  * - N FIFOs buffer matrix B data (one per column)
  * - N×N MAC units arranged in a grid
  * - Staggered read enables create wave-front data flow
  *
  * @param config TPU configuration
  */
class SystolicArray(config: TPUConfig) extends Module {
  val io = IO(new Bundle {
    val matrixAData = Input(UInt(config.wordWidth.W))  // Packed 4×8-bit values
    val matrixBData = Input(UInt(config.wordWidth.W))
    val stopRead    = Input(Bool())
    val rdEnA       = Input(Vec(config.n, Bool()))
    val rdEnB       = Input(Vec(config.n, Bool()))
    val sysReset    = Input(Bool())
    val matOut      = Output(Vec(config.n, Vec(config.n, SInt(config.accWidth.W))))

    // Debug outputs - FIFO A state
    val debug_fifosA_wrPtr   = Output(Vec(config.n, UInt(log2Ceil(config.fifoDepth).W)))
    val debug_fifosA_rdPtr   = Output(Vec(config.n, UInt(log2Ceil(config.fifoDepth).W)))
    val debug_fifosA_count   = Output(Vec(config.n, UInt(config.fifoAddrWidth.W)))
    val debug_fifosA_dataOut = Output(Vec(config.n, SInt(config.dataWidth.W)))
    val debug_fifosA_empty   = Output(Vec(config.n, Bool()))
    val debug_fifosA_full    = Output(Vec(config.n, Bool()))

    // Debug outputs - FIFO B state
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
  })

  // Instantiate FIFOs for matrix A (one per row)
  val fifosA = VecInit(Seq.fill(config.n)(Module(new SyncFIFO(config)).io))

  // Instantiate FIFOs for matrix B (one per column)
  val fifosB = VecInit(Seq.fill(config.n)(Module(new SyncFIFO(config)).io))

  // Unpack input words into individual bytes
  val aInputs = VecInit((0 until config.n).map { i =>
    io.matrixAData((i + 1) * config.dataWidth - 1, i * config.dataWidth).asSInt
  })
  val bInputs = VecInit((0 until config.n).map { i =>
    io.matrixBData((i + 1) * config.dataWidth - 1, i * config.dataWidth).asSInt
  })

  // Connect FIFOs for matrix A
  for (i <- 0 until config.n) {
    fifosA(i).wrEn   := !io.stopRead
    fifosA(i).rdEn   := io.rdEnA(i)
    fifosA(i).dataIn := aInputs(i)
  }

  // Connect FIFOs for matrix B
  for (i <- 0 until config.n) {
    fifosB(i).wrEn   := !io.stopRead
    fifosB(i).rdEn   := io.rdEnB(i)
    fifosB(i).dataIn := bInputs(i)
  }

  // Create N×N grid of MAC units
  val macGrid = Seq.tabulate(config.n, config.n) { (i, j) =>
    Module(new MACUnit(config))
  }

  // Wire networks for systolic interconnect
  val topNet  = Wire(Vec(config.n + 1, Vec(config.n, SInt(config.dataWidth.W))))
  val leftNet = Wire(Vec(config.n + 1, Vec(config.n, SInt(config.dataWidth.W))))

  // Delayed read enables for output gating
  // FIFO output is registered (1-cycle delay from rdEn), so we delay the gating signal
  // to match. This ensures the gate stays open when valid data appears at FIFO output.
  val rdEnADelayed = RegNext(io.rdEnA, VecInit(Seq.fill(config.n)(false.B)))
  val rdEnBDelayed = RegNext(io.rdEnB, VecInit(Seq.fill(config.n)(false.B)))

  // Top row inputs from FIFO B (gated by delayed rdEnB to match FIFO output timing)
  for (j <- 0 until config.n) {
    topNet(0)(j) := Mux(rdEnBDelayed(j), fifosB(j).dataOut, 0.S)
  }

  // Left column inputs from FIFO A (gated by delayed rdEnA to match FIFO output timing)
  for (i <- 0 until config.n) {
    leftNet(0)(i) := Mux(rdEnADelayed(i), fifosA(i).dataOut, 0.S)
  }

  // Connect MAC grid with systolic interconnect
  for (i <- 0 until config.n) {
    for (j <- 0 until config.n) {
      macGrid(i)(j).io.interconnect.upIn   := topNet(i)(j)
      macGrid(i)(j).io.interconnect.leftIn := leftNet(j)(i)
      macGrid(i)(j).io.sysReset            := io.sysReset

      topNet(i + 1)(j)  := macGrid(i)(j).io.interconnect.upOut
      leftNet(j + 1)(i) := macGrid(i)(j).io.interconnect.leftOut
    }
  }

  // Connect outputs
  io.matOut := VecInit(Seq.tabulate(config.n) { i =>
    VecInit(Seq.tabulate(config.n) { j =>
      macGrid(i)(j).io.matOut
    })
  })

  // Debug outputs - FIFO A
  for (i <- 0 until config.n) {
    io.debug_fifosA_wrPtr(i)   := fifosA(i).debug_wrPtr
    io.debug_fifosA_rdPtr(i)   := fifosA(i).debug_rdPtr
    io.debug_fifosA_count(i)   := fifosA(i).debug_count
    io.debug_fifosA_dataOut(i) := fifosA(i).dataOut
    io.debug_fifosA_empty(i)   := fifosA(i).empty
    io.debug_fifosA_full(i)    := fifosA(i).full
  }

  // Debug outputs - FIFO B
  for (i <- 0 until config.n) {
    io.debug_fifosB_wrPtr(i)   := fifosB(i).debug_wrPtr
    io.debug_fifosB_rdPtr(i)   := fifosB(i).debug_rdPtr
    io.debug_fifosB_count(i)   := fifosB(i).debug_count
    io.debug_fifosB_dataOut(i) := fifosB(i).dataOut
    io.debug_fifosB_empty(i)   := fifosB(i).empty
    io.debug_fifosB_full(i)    := fifosB(i).full
  }

  // Debug outputs - MAC grid
  for (i <- 0 until config.n) {
    for (j <- 0 until config.n) {
      io.debug_macAccReg(i)(j)  := macGrid(i)(j).io.debug_accReg
      io.debug_macUpReg(i)(j)   := macGrid(i)(j).io.debug_upReg
      io.debug_macLeftReg(i)(j) := macGrid(i)(j).io.debug_leftReg
    }
  }

  // Debug outputs - Systolic interconnect
  io.debug_topNet  := topNet
  io.debug_leftNet := leftNet

  // Debug outputs - Delayed read enables
  io.debug_rdEnADelayed := rdEnADelayed
  io.debug_rdEnBDelayed := rdEnBDelayed
}
