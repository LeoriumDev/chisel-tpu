// SPDX-License-Identifier: MIT

package tpu.utils

import scala.io.Source
import chisel3._
import chiseltest._
import tpu.core.GlobalBuffer
import tpu.{TPUConfig, TPUTestHarness}

/**
 * Utility object for loading matrices from hex files into GlobalBuffer for testing
 */
object MatrixLoader {

  /**
   * Load a matrix from a hex file into GlobalBuffer memory.
   *
   * The hex file should contain one value per line in hexadecimal format (e.g., "FFEF", "000C").
   * Values are packed into words according to packWidth parameter.
   *
   * @param hexFilePath Path to .hex file (one value per line)
   * @param buffer GlobalBuffer module to write to
   * @param rows Matrix rows (informational, used for validation)
   * @param cols Matrix columns (informational, used for validation)
   * @param packWidth Number of 8-bit values per word (default 4 for 32-bit word)
   * @param config TPU configuration
   */
  def loadMatrix(
    hexFilePath: String,
    buffer: GlobalBuffer,
    rows: Int,
    cols: Int,
    packWidth: Int = 4
  )(implicit config: TPUConfig): Unit = {
    // Read hex file
    val source = Source.fromFile(hexFilePath)
    val values = try {
      source.getLines()
        .map(_.trim)
        .filter(_.nonEmpty)
        .map(hex => Integer.parseInt(hex, 16).toShort)
        .toArray
    } finally {
      source.close()
    }

    val expectedSize = rows * cols
    require(values.length == expectedSize,
      s"File $hexFilePath has ${values.length} values, expected $expectedSize (${rows}x${cols})")

    // Pack values into words (4 values per 32-bit word for 8-bit data)
    val words = values.grouped(packWidth).map { group =>
      group.zipWithIndex.foldLeft(0) { case (acc, (v, i)) =>
        acc | ((v & 0xFF) << (i * 8))
      }
    }.toArray

    // Write packed words to buffer sequentially
    buffer.io.wrEn.poke(false.B)
    buffer.clock.step(1)

    words.zipWithIndex.foreach { case (word, addr) =>
      buffer.io.wrEn.poke(true.B)
      buffer.io.addr.poke(addr.U)
      buffer.io.wrData.poke(word.U)
      buffer.clock.step(1)
    }

    // Disable write after loading
    buffer.io.wrEn.poke(false.B)
  }

  /**
   * Read matrix values from GlobalBuffer memory.
   *
   * @param buffer GlobalBuffer to read from
   * @param rows Matrix rows
   * @param cols Matrix columns
   * @param packWidth Number of 8-bit values per word
   * @param config TPU configuration
   * @return Array of unpacked values
   */
  def readMatrix(
    buffer: GlobalBuffer,
    rows: Int,
    cols: Int,
    packWidth: Int = 4
  )(implicit config: TPUConfig): Array[Int] = {
    val totalValues = rows * cols
    val numWords = (totalValues + packWidth - 1) / packWidth

    // Disable write mode
    buffer.io.wrEn.poke(false.B)

    val words = (0 until numWords).map { addr =>
      buffer.io.addr.poke(addr.U)
      buffer.clock.step(1)
      buffer.io.rdData.peekInt().toInt
    }

    // Unpack words into individual values
    words.flatMap { word =>
      (0 until packWidth).map { i =>
        ((word >> (i * 8)) & 0xFF).toByte.toInt
      }
    }.take(totalValues).toArray
  }

  /**
   * Load a simple test matrix (4x4 or smaller) directly from an array.
   * Useful for quick unit tests.
   *
   * @param values Array of values to load (row-major order)
   * @param buffer GlobalBuffer to write to
   * @param rows Number of rows
   * @param cols Number of columns
   * @param packWidth Number of values per word
   */
  def loadFromArray(
    values: Array[Int],
    buffer: GlobalBuffer,
    rows: Int,
    cols: Int,
    packWidth: Int = 4
  )(implicit config: TPUConfig): Unit = {
    require(values.length == rows * cols,
      s"Array has ${values.length} values, expected ${rows * cols}")

    // Pack values into words (ensure unsigned)
    val words = values.grouped(packWidth).map { group =>
      group.zipWithIndex.foldLeft(0L) { case (acc, (v, i)) =>
        acc | (((v & 0xFF).toLong) << (i * 8))
      }.toInt & 0xFFFFFFFF
    }.toArray

    // Write to buffer
    buffer.io.wrEn.poke(false.B)
    buffer.clock.step(1)

    words.zipWithIndex.foreach { case (word, addr) =>
      buffer.io.wrEn.poke(true.B)
      buffer.io.addr.poke(addr.U)
      buffer.io.wrData.poke((word & 0xFFFFFFFFL).U)
      buffer.clock.step(1)
    }

    buffer.io.wrEn.poke(false.B)
  }

  /**
   * Load matrix A into TPUTestHarness from an array
   */
  def loadMatrixA(
    harness: TPUTestHarness,
    values: Array[Int],
    rows: Int,
    cols: Int,
    packWidth: Int = 4
  )(implicit config: TPUConfig): Unit = {
    require(values.length == rows * cols,
      s"Array has ${values.length} values, expected ${rows * cols}")

    // Pack values into words (ensure unsigned by using Long intermediate)
    val words = values.grouped(packWidth).map { group =>
      group.zipWithIndex.foldLeft(0L) { case (acc, (v, i)) =>
        acc | (((v & 0xFF).toLong) << (i * 8))
      }.toInt & 0xFFFFFFFF  // Mask to 32-bit unsigned
    }.toArray

    // Enable test mode
    harness.io.testMode.poke(true.B)
    harness.io.bufA_wrEn.poke(false.B)
    harness.clock.step(1)

    // Write words
    words.zipWithIndex.foreach { case (word, addr) =>
      harness.io.bufA_wrEn.poke(true.B)
      harness.io.bufA_addr.poke(addr.U)
      harness.io.bufA_wrData.poke((word & 0xFFFFFFFFL).U)
      harness.clock.step(1)
    }

    harness.io.bufA_wrEn.poke(false.B)
  }

  /**
   * Load matrix B into TPUTestHarness from an array
   */
  def loadMatrixB(
    harness: TPUTestHarness,
    values: Array[Int],
    rows: Int,
    cols: Int,
    packWidth: Int = 4
  )(implicit config: TPUConfig): Unit = {
    require(values.length == rows * cols,
      s"Array has ${values.length} values, expected ${rows * cols}")

    // Pack values into words (ensure unsigned by using Long intermediate)
    val words = values.grouped(packWidth).map { group =>
      group.zipWithIndex.foldLeft(0L) { case (acc, (v, i)) =>
        acc | (((v & 0xFF).toLong) << (i * 8))
      }.toInt & 0xFFFFFFFF  // Mask to 32-bit unsigned
    }.toArray

    // Enable test mode
    harness.io.testMode.poke(true.B)
    harness.io.bufB_wrEn.poke(false.B)
    harness.clock.step(1)

    // Write words
    words.zipWithIndex.foreach { case (word, addr) =>
      harness.io.bufB_wrEn.poke(true.B)
      harness.io.bufB_addr.poke(addr.U)
      harness.io.bufB_wrData.poke((word & 0xFFFFFFFFL).U)
      harness.clock.step(1)
    }

    harness.io.bufB_wrEn.poke(false.B)
  }

  /**
   * Read matrix C from TPUTestHarness
   */
  def readMatrixC(
    harness: TPUTestHarness,
    rows: Int,
    cols: Int,
    packWidth: Int = 4
  )(implicit config: TPUConfig): Array[Int] = {
    val totalValues = rows * cols
    val numWords = (totalValues + packWidth - 1) / packWidth

    // Enable test mode
    harness.io.testMode.poke(true.B)
    harness.io.bufC_wrEn.poke(false.B)

    // Buffer C has extendedWordWidth (64-bit)
    val words = (0 until numWords).map { addr =>
      harness.io.bufC_addr.poke(addr.U)
      harness.clock.step(1)
      harness.io.bufC_rdData.peekInt()  // Returns BigInt, can handle 64 bits
    }

    // Unpack words - each word contains 4×16-bit values
    words.flatMap { word =>
      (0 until packWidth).map { i =>
        val shifted = (word >> (i * 16)) & BigInt(0xFFFF)
        // Convert from unsigned 16-bit to signed 16-bit
        if (shifted > 0x7FFF) {
          (shifted.toInt - 0x10000)
        } else {
          shifted.toInt
        }
      }
    }.take(totalValues).toArray
  }

  /**
   * Load matrix A from a hex file into TPUTestHarness
   */
  def loadMatrixAFromFile(
    harness: TPUTestHarness,
    hexFilePath: String,
    rows: Int,
    cols: Int,
    packWidth: Int = 4
  )(implicit config: TPUConfig): Unit = {
    // Read hex file
    val source = Source.fromFile(hexFilePath)
    val values = try {
      source.getLines()
        .map(_.trim)
        .filter(_.nonEmpty)
        .map(hex => Integer.parseInt(hex, 16).toShort.toInt)
        .toArray
    } finally {
      source.close()
    }

    val expectedSize = rows * cols
    require(values.length == expectedSize,
      s"File $hexFilePath has ${values.length} values, expected $expectedSize (${rows}x${cols})")

    loadMatrixA(harness, values, rows, cols, packWidth)
  }

  /**
   * Load matrix B from a hex file into TPUTestHarness
   */
  def loadMatrixBFromFile(
    harness: TPUTestHarness,
    hexFilePath: String,
    rows: Int,
    cols: Int,
    packWidth: Int = 4
  )(implicit config: TPUConfig): Unit = {
    // Read hex file
    val source = Source.fromFile(hexFilePath)
    val values = try {
      source.getLines()
        .map(_.trim)
        .filter(_.nonEmpty)
        .map(hex => Integer.parseInt(hex, 16).toShort.toInt)
        .toArray
    } finally {
      source.close()
    }

    val expectedSize = rows * cols
    require(values.length == expectedSize,
      s"File $hexFilePath has ${values.length} values, expected $expectedSize (${rows}x${cols})")

    loadMatrixB(harness, values, rows, cols, packWidth)
  }

  /**
   * Load expected output from hex file for verification
   */
  def loadExpectedOutput(hexFilePath: String, size: Int): Array[Int] = {
    val source = Source.fromFile(hexFilePath)
    val values = try {
      source.getLines()
        .map(_.trim)
        .filter(_.nonEmpty)
        .map(hex => Integer.parseInt(hex, 16).toShort.toInt)
        .toArray
    } finally {
      source.close()
    }

    require(values.length == size,
      s"Expected output file has ${values.length} values, expected $size")

    values
  }
}
