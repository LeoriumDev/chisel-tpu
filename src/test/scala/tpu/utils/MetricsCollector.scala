// SPDX-License-Identifier: MIT

package tpu.utils

import scala.collection.mutable
import java.io.PrintWriter
import java.io.File

/**
 * Utility class for collecting and reporting performance metrics during testing
 */
class MetricsCollector {
  private val timers = mutable.Map[String, Long]()
  private val counters = mutable.Map[String, Long]()
  private val errors = mutable.Map[String, ErrorMetrics]()

  case class ErrorMetrics(
    meanAbsError: Double,
    maxAbsError: Double,
    relativeError: Double,
    sampleCount: Int
  )

  /**
   * Start a timer for measuring cycle counts
   */
  def startTimer(name: String): Unit = {
    timers(name) = 0
  }

  /**
   * Stop a timer and record the cycle count
   */
  def stopTimer(name: String, cycles: Long): Unit = {
    timers(name) = cycles
  }

  /**
   * Record a cycle count directly
   */
  def recordCycles(name: String, cycles: Long): Unit = {
    timers(name) = cycles
  }

  /**
   * Increment a counter
   */
  def incrementCounter(name: String, value: Long = 1): Unit = {
    counters(name) = counters.getOrElse(name, 0L) + value
  }

  /**
   * Record error metrics by comparing hardware output to expected output
   */
  def recordError(name: String, hwOutput: Array[Int], expectedOutput: Array[Int]): Unit = {
    require(hwOutput.length == expectedOutput.length,
      s"Output length mismatch: ${hwOutput.length} vs ${expectedOutput.length}")

    val absErrors = hwOutput.zip(expectedOutput).map { case (hw, exp) =>
      Math.abs(hw - exp).toDouble
    }

    val relErrors = hwOutput.zip(expectedOutput).map { case (hw, exp) =>
      if (exp != 0) Math.abs(hw - exp).toDouble / Math.abs(exp).toDouble else 0.0
    }

    val mae = absErrors.sum / absErrors.length
    val maxErr = absErrors.max
    val relErr = relErrors.sum / relErrors.length

    errors(name) = ErrorMetrics(mae, maxErr, relErr, hwOutput.length)
  }

  /**
   * Record error metrics from single values
   */
  def recordSingleError(name: String, hwValue: Int, expectedValue: Int): Unit = {
    recordError(name, Array(hwValue), Array(expectedValue))
  }

  /**
   * Get cycle count for a named timer
   */
  def getCycles(name: String): Long = {
    timers.getOrElse(name, 0L)
  }

  /**
   * Get counter value
   */
  def getCounter(name: String): Long = {
    counters.getOrElse(name, 0L)
  }

  /**
   * Get error metrics
   */
  def getError(name: String): Option[ErrorMetrics] = {
    errors.get(name)
  }

  /**
   * Print summary of all metrics to console
   */
  def printSummary(): Unit = {
    println("\n" + "=" * 60)
    println("Performance Metrics Summary")
    println("=" * 60)

    if (timers.nonEmpty) {
      println("\nCycle Counts:")
      timers.toSeq.sortBy(_._1).foreach { case (name, cycles) =>
        println(f"  $name%-30s: $cycles%8d cycles")
      }
    }

    if (counters.nonEmpty) {
      println("\nCounters:")
      counters.toSeq.sortBy(_._1).foreach { case (name, value) =>
        println(f"  $name%-30s: $value%8d")
      }
    }

    if (errors.nonEmpty) {
      println("\nError Metrics:")
      errors.toSeq.sortBy(_._1).foreach { case (name, metrics) =>
        println(f"  $name%-30s:")
        println(f"    Mean Absolute Error     : ${metrics.meanAbsError}%10.4f")
        println(f"    Max Absolute Error      : ${metrics.maxAbsError}%10.4f")
        println(f"    Mean Relative Error     : ${metrics.relativeError}%10.4f")
        println(f"    Sample Count            : ${metrics.sampleCount}%10d")
      }
    }

    println("=" * 60 + "\n")
  }

  /**
   * Export metrics to CSV file
   */
  def exportCSV(filePath: String): Unit = {
    val file = new File(filePath)
    file.getParentFile.mkdirs()

    val writer = new PrintWriter(file)
    try {
      // Write header
      writer.println("metric_type,metric_name,value,unit")

      // Write cycle counts
      timers.toSeq.sortBy(_._1).foreach { case (name, cycles) =>
        writer.println(s"cycle_count,$name,$cycles,cycles")
      }

      // Write counters
      counters.toSeq.sortBy(_._1).foreach { case (name, value) =>
        writer.println(s"counter,$name,$value,count")
      }

      // Write error metrics
      errors.toSeq.sortBy(_._1).foreach { case (name, metrics) =>
        writer.println(s"error_mae,$name,${metrics.meanAbsError},absolute")
        writer.println(s"error_max,$name,${metrics.maxAbsError},absolute")
        writer.println(s"error_rel,$name,${metrics.relativeError},relative")
        writer.println(s"error_samples,$name,${metrics.sampleCount},count")
      }

    } finally {
      writer.close()
    }

    println(s"Metrics exported to: $filePath")
  }

  /**
   * Export metrics to markdown table format
   */
  def exportMarkdown(filePath: String, title: String = "Test Results"): Unit = {
    val file = new File(filePath)
    file.getParentFile.mkdirs()

    val writer = new PrintWriter(file)
    try {
      writer.println(s"# $title\n")

      if (timers.nonEmpty) {
        writer.println("## Cycle Counts\n")
        writer.println("| Layer/Operation | Cycles |")
        writer.println("|----------------|--------|")
        timers.toSeq.sortBy(_._1).foreach { case (name, cycles) =>
          writer.println(f"| $name | $cycles |")
        }
        writer.println()
      }

      if (counters.nonEmpty) {
        writer.println("## Counters\n")
        writer.println("| Counter | Value |")
        writer.println("|---------|-------|")
        counters.toSeq.sortBy(_._1).foreach { case (name, value) =>
          writer.println(f"| $name | $value |")
        }
        writer.println()
      }

      if (errors.nonEmpty) {
        writer.println("## Error Metrics\n")
        writer.println("| Layer | MAE | Max Error | Rel Error | Samples |")
        writer.println("|-------|-----|-----------|-----------|---------|")
        errors.toSeq.sortBy(_._1).foreach { case (name, metrics) =>
          writer.println(f"| $name | ${metrics.meanAbsError}%.4f | " +
            f"${metrics.maxAbsError}%.4f | ${metrics.relativeError}%.4f | " +
            f"${metrics.sampleCount} |")
        }
        writer.println()
      }

    } finally {
      writer.close()
    }

    println(s"Markdown report exported to: $filePath")
  }

  /**
   * Clear all metrics
   */
  def clear(): Unit = {
    timers.clear()
    counters.clear()
    errors.clear()
  }
}

/**
 * Companion object for easy creation
 */
object MetricsCollector {
  def apply(): MetricsCollector = new MetricsCollector()
}
