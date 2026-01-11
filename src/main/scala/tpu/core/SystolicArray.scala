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

  // Top row inputs from FIFO B
  for (j <- 0 until config.n) {
    topNet(0)(j) := Mux(io.rdEnB(j), fifosB(j).dataOut, 0.S)
  }

  // Left column inputs from FIFO A
  for (i <- 0 until config.n) {
    leftNet(0)(i) := Mux(io.rdEnA(i), fifosA(i).dataOut, 0.S)
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
}
