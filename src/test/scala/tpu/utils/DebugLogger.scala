// SPDX-License-Identifier: MIT

package tpu.utils

import chisel3._
import chiseltest._
import tpu.{TPUConfig, TPUTestHarness}
import java.io.{File, PrintWriter}
import scala.collection.mutable.ArrayBuffer

/**
 * Cycle-by-cycle debug logger for TPU systolic array debugging.
 * Outputs NDJSON (Newline-delimited JSON) format for AI readability.
 *
 * @param config TPU configuration
 * @param outputPath Path to write the debug log file
 */
class DebugLogger(config: TPUConfig, outputPath: String) {
  private val entries = ArrayBuffer[String]()

  // FSM state names for human-readable output
  private val stateNames = Array("sIdle", "sIdle2", "sCalculate", "sWrite", "sFinish")

  /**
   * Log the current cycle's state from the DUT
   *
   * @param dut The TPUTestHarness under test
   * @param cycle Current cycle number
   */
  def logCycle(dut: TPUTestHarness, cycle: Int): Unit = {
    val json = captureStateAsJson(dut, cycle)
    entries += json
  }

  /**
   * Capture all debug state and format as JSON
   */
  private def captureStateAsJson(dut: TPUTestHarness, cycle: Int): String = {
    val sb = new StringBuilder
    sb.append("{")

    // Cycle number
    sb.append(s""""cycle":$cycle,""")

    // FSM state
    val stateIdx = dut.io.debug_state.peek().litValue.toInt
    val stateName = if (stateIdx < stateNames.length) stateNames(stateIdx) else s"Unknown($stateIdx)"
    sb.append(s""""state":"$stateName",""")

    // Control signals
    sb.append(s""""cnt":${dut.io.debug_cnt.peek().litValue},""")
    sb.append(s""""control":{""")
    sb.append(s""""stopRead":${dut.io.debug_stopRead.peek().litToBoolean},""")
    sb.append(s""""startFifo":${dut.io.debug_startFifo.peek().litToBoolean},""")
    sb.append(s""""stopFifo":${dut.io.debug_stopFifo.peek().litToBoolean},""")
    sb.append(s""""cntEnd":${dut.io.debug_cntEnd.peek().litToBoolean},""")
    sb.append(s""""addrA":${dut.io.debug_addrA.peek().litValue},""")
    sb.append(s""""addrB":${dut.io.debug_addrB.peek().litValue},""")
    sb.append(s""""addrC":${dut.io.debug_addrC.peek().litValue},""")
    sb.append(s""""writeCnt":${dut.io.debug_writeCnt.peek().litValue}""")
    sb.append("},")

    // Read enables
    sb.append(""""rdEnA":[""")
    sb.append((0 until config.n).map(i => dut.io.debug_rdEnADelayed(i).peek().litToBoolean).mkString(","))
    sb.append("],")
    sb.append(""""rdEnB":[""")
    sb.append((0 until config.n).map(i => dut.io.debug_rdEnBDelayed(i).peek().litToBoolean).mkString(","))
    sb.append("],")

    // FIFO A state
    sb.append(""""fifosA":[""")
    sb.append((0 until config.n).map { i =>
      val wrPtr = dut.io.debug_fifosA_wrPtr(i).peek().litValue
      val rdPtr = dut.io.debug_fifosA_rdPtr(i).peek().litValue
      val count = dut.io.debug_fifosA_count(i).peek().litValue
      val dataOut = dut.io.debug_fifosA_dataOut(i).peek().litValue
      val empty = dut.io.debug_fifosA_empty(i).peek().litToBoolean
      val full = dut.io.debug_fifosA_full(i).peek().litToBoolean
      s"""{"wrPtr":$wrPtr,"rdPtr":$rdPtr,"count":$count,"dataOut":$dataOut,"empty":$empty,"full":$full}"""
    }.mkString(","))
    sb.append("],")

    // FIFO B state
    sb.append(""""fifosB":[""")
    sb.append((0 until config.n).map { i =>
      val wrPtr = dut.io.debug_fifosB_wrPtr(i).peek().litValue
      val rdPtr = dut.io.debug_fifosB_rdPtr(i).peek().litValue
      val count = dut.io.debug_fifosB_count(i).peek().litValue
      val dataOut = dut.io.debug_fifosB_dataOut(i).peek().litValue
      val empty = dut.io.debug_fifosB_empty(i).peek().litToBoolean
      val full = dut.io.debug_fifosB_full(i).peek().litToBoolean
      s"""{"wrPtr":$wrPtr,"rdPtr":$rdPtr,"count":$count,"dataOut":$dataOut,"empty":$empty,"full":$full}"""
    }.mkString(","))
    sb.append("],")

    // MAC grid accumulators
    sb.append(""""macGrid":{""")
    sb.append(""""acc":[""")
    sb.append((0 until config.n).map { i =>
      "[" + (0 until config.n).map { j =>
        dut.io.debug_macAccReg(i)(j).peek().litValue.toString
      }.mkString(",") + "]"
    }.mkString(","))
    sb.append("],")

    // MAC upReg
    sb.append(""""up":[""")
    sb.append((0 until config.n).map { i =>
      "[" + (0 until config.n).map { j =>
        dut.io.debug_macUpReg(i)(j).peek().litValue.toString
      }.mkString(",") + "]"
    }.mkString(","))
    sb.append("],")

    // MAC leftReg
    sb.append(""""left":[""")
    sb.append((0 until config.n).map { i =>
      "[" + (0 until config.n).map { j =>
        dut.io.debug_macLeftReg(i)(j).peek().litValue.toString
      }.mkString(",") + "]"
    }.mkString(","))
    sb.append("]},")

    // Systolic topNet (first 2 layers only to keep log size manageable)
    sb.append(""""topNet":[""")
    sb.append((0 until Math.min(config.n + 1, 3)).map { i =>
      "[" + (0 until config.n).map { j =>
        dut.io.debug_topNet(i)(j).peek().litValue.toString
      }.mkString(",") + "]"
    }.mkString(","))
    sb.append("],")

    // Systolic leftNet (first 2 layers only)
    sb.append(""""leftNet":[""")
    sb.append((0 until Math.min(config.n + 1, 3)).map { i =>
      "[" + (0 until config.n).map { j =>
        dut.io.debug_leftNet(i)(j).peek().litValue.toString
      }.mkString(",") + "]"
    }.mkString(","))
    sb.append("],")

    // matOut (final results)
    sb.append(""""matOut":[""")
    sb.append((0 until config.n).map { i =>
      "[" + (0 until config.n).map { j =>
        dut.io.debug_matOut(i)(j).peek().litValue.toString
      }.mkString(",") + "]"
    }.mkString(","))
    sb.append("]")

    sb.append("}")
    sb.toString()
  }

  /**
   * Write all logged entries to the output file
   */
  def writeToFile(): Unit = {
    // Create output directory if needed
    val file = new File(outputPath)
    file.getParentFile.mkdirs()

    val writer = new PrintWriter(file)
    try {
      entries.foreach(writer.println)
    } finally {
      writer.close()
    }
    println(s"Debug log written to: $outputPath (${entries.size} cycles)")
  }

  /**
   * Get the number of logged cycles
   */
  def cycleCount: Int = entries.size

  /**
   * Clear all logged entries
   */
  def clear(): Unit = entries.clear()
}
