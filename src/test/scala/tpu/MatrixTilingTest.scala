// SPDX-License-Identifier: MIT

package tpu

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import tpu.utils.{MatrixLoader, MetricsCollector}

/**
 * Utility functions for software-based matrix tiling.
 * Since hardware multi-tile support isn't implemented (TPUControl m/n parameters are unused),
 * tiling must be orchestrated in test code.
 */
object TilingUtils {

  /**
   * Extract a tileSize×tileSize tile from a larger matrix.
   * Zero-pads if the tile extends beyond matrix boundaries.
   *
   * @param matrix Source matrix in row-major order
   * @param mRows Number of rows in source matrix
   * @param mCols Number of columns in source matrix
   * @param tileRow Tile row index (0-based)
   * @param tileCol Tile column index (0-based)
   * @param tileSize Size of tile to extract (default 4)
   * @return Extracted tile as row-major array
   */
  def extractTile(
    matrix: Array[Int],
    mRows: Int,
    mCols: Int,
    tileRow: Int,
    tileCol: Int,
    tileSize: Int = 4
  ): Array[Int] = {
    val tile = Array.fill(tileSize * tileSize)(0)
    val startRow = tileRow * tileSize
    val startCol = tileCol * tileSize

    for (r <- 0 until tileSize; c <- 0 until tileSize) {
      val srcRow = startRow + r
      val srcCol = startCol + c
      if (srcRow < mRows && srcCol < mCols) {
        tile(r * tileSize + c) = matrix(srcRow * mCols + srcCol)
      }
    }
    tile
  }

  /**
   * Pack a tile for Buffer A (systolic array format).
   * The systolic array expects A stored as transposed columns:
   * Each 32-bit word contains 4 values from the same column of A.
   *
   * For a 4×4 tile:
   *   Word 0: [A[0,0], A[1,0], A[2,0], A[3,0]] (column 0)
   *   Word 1: [A[0,1], A[1,1], A[2,1], A[3,1]] (column 1)
   *   etc.
   *
   * @param tile Row-major tile array
   * @param n Tile dimension (default 4)
   * @return Packed array ready for loadMatrixA
   */
  def packTileForA(tile: Array[Int], n: Int = 4): Array[Int] = {
    val packed = Array.fill(n * n)(0)
    for (col <- 0 until n) {
      for (row <- 0 until n) {
        // Transpose: store column col as row col
        packed(col * n + row) = tile(row * n + col)
      }
    }
    packed
  }

  /**
   * Pack a tile for Buffer B (systolic array format).
   * The systolic array expects B stored as transposed rows:
   * Each 32-bit word contains 4 values from the same row of B.
   *
   * For a 4×4 tile:
   *   Word 0: [B[0,0], B[0,1], B[0,2], B[0,3]] (row 0)
   *   Word 1: [B[1,0], B[1,1], B[1,2], B[1,3]] (row 1)
   *   etc.
   *
   * Actually B is already row-major, so this is essentially identity.
   *
   * @param tile Row-major tile array
   * @param n Tile dimension (default 4)
   * @return Packed array ready for loadMatrixB
   */
  def packTileForB(tile: Array[Int], n: Int = 4): Array[Int] = {
    // B is already in row-major order which matches expected format
    tile.clone()
  }

  /**
   * Software reference matrix multiplication.
   * Computes C = A × B where:
   *   A is m×k matrix
   *   B is k×n matrix
   *   C is m×n matrix
   *
   * @param a Matrix A in row-major order
   * @param b Matrix B in row-major order
   * @param m Rows of A (and C)
   * @param k Columns of A / Rows of B
   * @param n Columns of B (and C)
   * @return Result matrix C in row-major order
   */
  def softwareMatmul(a: Array[Int], b: Array[Int], m: Int, k: Int, n: Int): Array[Int] = {
    val c = Array.fill(m * n)(0)
    for (i <- 0 until m) {
      for (j <- 0 until n) {
        var sum = 0
        for (kk <- 0 until k) {
          sum += a(i * k + kk) * b(kk * n + j)
        }
        c(i * n + j) = sum
      }
    }
    c
  }

  /**
   * Accumulate partial tile results (element-wise addition).
   *
   * @param accum Accumulator array
   * @param partial Partial result to add
   * @return Updated accumulator
   */
  def accumulateTile(accum: Array[Int], partial: Array[Int]): Array[Int] = {
    accum.zip(partial).map { case (a, p) => a + p }
  }

  /**
   * Store a tile into a larger result matrix.
   *
   * @param result Result matrix to update
   * @param tile Tile to store
   * @param resultCols Number of columns in result matrix
   * @param tileRow Tile row index
   * @param tileCol Tile column index
   * @param tileSize Size of tile
   */
  def storeTileToResult(
    result: Array[Int],
    tile: Array[Int],
    resultCols: Int,
    tileRow: Int,
    tileCol: Int,
    tileSize: Int = 4
  ): Unit = {
    val startRow = tileRow * tileSize
    val startCol = tileCol * tileSize

    for (r <- 0 until tileSize; c <- 0 until tileSize) {
      val dstIdx = (startRow + r) * resultCols + (startCol + c)
      if (dstIdx < result.length) {
        result(dstIdx) = tile(r * tileSize + c)
      }
    }
  }

  /**
   * Print a matrix for debugging.
   */
  def printMatrix(name: String, matrix: Array[Int], rows: Int, cols: Int): Unit = {
    println(s"$name (${rows}x${cols}):")
    for (r <- 0 until rows) {
      val row = (0 until cols).map(c => f"${matrix(r * cols + c)}%4d").mkString(" ")
      println(s"  $row")
    }
  }
}

/**
 * Integration test for software-based matrix tiling.
 * Multiplies matrices larger than the 4×4 systolic array by:
 * 1. Extracting 4×4 tiles from larger matrices
 * 2. Executing each tile multiplication on the TPU
 * 3. Accumulating partial products in software
 */
class MatrixTilingTest extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "TPU Matrix Tiling"

  /**
   * Execute a single 4×4 tile multiplication on the TPU.
   *
   * @param dut TPU test harness
   * @param aTile Tile from matrix A (already packed for systolic format)
   * @param bTile Tile from matrix B (already packed for systolic format)
   * @param k Number of words to read (4 for full 4×4 tile)
   * @param config TPU configuration
   * @return Result tile (4×4) in row-major order
   */
  def executeSingleTile(
    dut: TPUTestHarness,
    aTile: Array[Int],
    bTile: Array[Int],
    k: Int = 4
  )(implicit config: TPUConfig): Array[Int] = {
    // Load tiles into buffers
    MatrixLoader.loadMatrixA(dut, aTile, rows = 4, cols = 4, packWidth = 4)
    MatrixLoader.loadMatrixB(dut, bTile, rows = 4, cols = 4, packWidth = 4)

    // Configure TPU for single tile
    dut.io.testMode.poke(false.B)
    dut.io.start.poke(false.B)
    dut.io.m.poke(1.U)
    dut.io.k.poke(k.U)
    dut.io.n.poke(1.U)
    dut.clock.step(2)

    // Start execution
    dut.io.start.poke(true.B)
    dut.clock.step(1)
    dut.io.start.poke(false.B)

    // Wait for completion
    var cycleCount = 0
    while (!dut.io.done.peek().litToBoolean && cycleCount < 1000) {
      dut.clock.step(1)
      cycleCount += 1
    }

    require(dut.io.done.peek().litToBoolean, s"TPU did not complete tile in $cycleCount cycles")

    // Read result
    MatrixLoader.readMatrixC(dut, rows = 4, cols = 4, packWidth = 4)
  }

  /**
   * Perform tiled matrix multiplication for matrices larger than 4×4.
   *
   * @param dut TPU test harness
   * @param matA Matrix A in row-major order
   * @param aRows Rows of A
   * @param aCols Columns of A
   * @param matB Matrix B in row-major order
   * @param bRows Rows of B (must equal aCols)
   * @param bCols Columns of B
   * @param tileSize Tile size (default 4)
   * @param config TPU configuration
   * @return Result matrix C in row-major order
   */
  def tiledMatmul(
    dut: TPUTestHarness,
    matA: Array[Int],
    aRows: Int,
    aCols: Int,
    matB: Array[Int],
    bRows: Int,
    bCols: Int,
    tileSize: Int = 4
  )(implicit config: TPUConfig): Array[Int] = {
    require(aCols == bRows, s"Matrix dimension mismatch: A cols ($aCols) != B rows ($bRows)")

    val mTiles = (aRows + tileSize - 1) / tileSize
    val kTiles = (aCols + tileSize - 1) / tileSize
    val nTiles = (bCols + tileSize - 1) / tileSize

    println(s"Tiled matmul: ${aRows}x${aCols} * ${bRows}x${bCols}")
    println(s"Tile configuration: mTiles=$mTiles, kTiles=$kTiles, nTiles=$nTiles")
    println(s"Total tile operations: ${mTiles * kTiles * nTiles}")

    val result = Array.fill(aRows * bCols)(0)
    var tileOps = 0

    for (i <- 0 until mTiles) {
      for (j <- 0 until nTiles) {
        var accumulator = Array.fill(tileSize * tileSize)(0)

        for (kt <- 0 until kTiles) {
          // Extract tiles
          val aTile = TilingUtils.extractTile(matA, aRows, aCols, i, kt, tileSize)
          val bTile = TilingUtils.extractTile(matB, bRows, bCols, kt, j, tileSize)

          // Pack for systolic array format
          val aPacked = TilingUtils.packTileForA(aTile, tileSize)
          val bPacked = TilingUtils.packTileForB(bTile, tileSize)

          // Execute on hardware
          val partial = executeSingleTile(dut, aPacked, bPacked, k = tileSize)

          // Accumulate
          accumulator = TilingUtils.accumulateTile(accumulator, partial)
          tileOps += 1
        }

        // Store accumulated result
        TilingUtils.storeTileToResult(result, accumulator, bCols, i, j, tileSize)
      }
    }

    println(s"Completed $tileOps tile operations")
    result
  }

  it should "multiply 8x8 all-ones matrices using software tiling" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config
      val metrics = MetricsCollector()

      // 8×8 matrices filled with 1s
      val matrixA = Array.fill(8 * 8)(1)
      val matrixB = Array.fill(8 * 8)(1)

      println("\n=== 8x8 All-Ones Matrix Multiplication Test ===")

      val startTime = System.nanoTime()
      val result = tiledMatmul(dut, matrixA, 8, 8, matrixB, 8, 8)
      val elapsed = (System.nanoTime() - startTime) / 1e6

      // Expected: C[i][j] = 8 for all elements (sum of 8 ones)
      val expected = Array.fill(64)(8)

      println(s"\nExecution time: ${elapsed}ms")
      TilingUtils.printMatrix("Result", result, 8, 8)

      // Verify
      var errorCount = 0
      var maxError = 0
      for (i <- expected.indices) {
        val err = math.abs(result(i) - expected(i))
        if (err > 0) {
          errorCount += 1
          maxError = math.max(maxError, err)
          val row = i / 8
          val col = i % 8
          println(s"Mismatch at [$row][$col]: expected ${expected(i)}, got ${result(i)}")
        }
      }

      println(s"Errors: $errorCount, Max error: $maxError")
      assert(errorCount == 0, s"Found $errorCount mismatches in 8x8 all-ones test")
      println("Test passed: 8x8 all-ones matrix multiplication")
    }
  }

  it should "multiply 8x8 identity by sequential matrix" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config

      // A = 8×8 identity matrix
      val matrixA = Array.tabulate(64)(i => if (i / 8 == i % 8) 1 else 0)

      // B = 8×8 sequential matrix (1 to 64)
      val matrixB = Array.tabulate(64)(i => i + 1)

      println("\n=== 8x8 Identity × Sequential Matrix Test ===")
      TilingUtils.printMatrix("Matrix A (Identity)", matrixA, 8, 8)
      TilingUtils.printMatrix("Matrix B (Sequential)", matrixB, 8, 8)

      val result = tiledMatmul(dut, matrixA, 8, 8, matrixB, 8, 8)

      // Expected: I × B = B
      val expected = matrixB.clone()

      TilingUtils.printMatrix("Result", result, 8, 8)
      TilingUtils.printMatrix("Expected", expected, 8, 8)

      // Verify
      var errorCount = 0
      for (i <- expected.indices) {
        if (result(i) != expected(i)) {
          errorCount += 1
          val row = i / 8
          val col = i % 8
          println(s"Mismatch at [$row][$col]: expected ${expected(i)}, got ${result(i)}")
        }
      }

      assert(errorCount == 0, s"Found $errorCount mismatches in identity test")
      println("Test passed: 8x8 identity × sequential matrix")
    }
  }

  it should "multiply 8x8 matrices with known values" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config

      // Create test matrices with small values to avoid overflow
      // A[i][j] = (i + j) % 4 + 1  (values 1-4)
      // B[i][j] = (i * 2 + j) % 4 + 1  (values 1-4)
      val matrixA = Array.tabulate(64)(idx => {
        val i = idx / 8
        val j = idx % 8
        (i + j) % 4 + 1
      })

      val matrixB = Array.tabulate(64)(idx => {
        val i = idx / 8
        val j = idx % 8
        (i * 2 + j) % 4 + 1
      })

      println("\n=== 8x8 Known Values Matrix Multiplication Test ===")
      TilingUtils.printMatrix("Matrix A", matrixA, 8, 8)
      TilingUtils.printMatrix("Matrix B", matrixB, 8, 8)

      val result = tiledMatmul(dut, matrixA, 8, 8, matrixB, 8, 8)

      // Compute expected result using software
      val expected = TilingUtils.softwareMatmul(matrixA, matrixB, 8, 8, 8)

      TilingUtils.printMatrix("Result", result, 8, 8)
      TilingUtils.printMatrix("Expected", expected, 8, 8)

      // Verify
      var errorCount = 0
      var totalError = 0
      var maxError = 0
      for (i <- expected.indices) {
        val err = math.abs(result(i) - expected(i))
        totalError += err
        maxError = math.max(maxError, err)
        if (err > 0) {
          errorCount += 1
          val row = i / 8
          val col = i % 8
          println(s"Mismatch at [$row][$col]: expected ${expected(i)}, got ${result(i)}, error=$err")
        }
      }

      val meanError = totalError.toDouble / expected.length
      println(s"Errors: $errorCount, Mean absolute error: $meanError, Max error: $maxError")

      assert(errorCount == 0, s"Found $errorCount mismatches in known values test")
      println("Test passed: 8x8 known values matrix multiplication")
    }
  }

  it should "handle signed values in 8x8 matrices" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config

      // Create matrices with signed values (-3 to 3)
      // A[i][j] = (i + j) % 7 - 3  (values -3 to 3)
      // B[i][j] = (i - j + 8) % 7 - 3  (values -3 to 3)
      val matrixA = Array.tabulate(64)(idx => {
        val i = idx / 8
        val j = idx % 8
        (i + j) % 7 - 3
      })

      val matrixB = Array.tabulate(64)(idx => {
        val i = idx / 8
        val j = idx % 8
        ((i - j + 8) % 7) - 3
      })

      println("\n=== 8x8 Signed Values Matrix Multiplication Test ===")
      TilingUtils.printMatrix("Matrix A (signed)", matrixA, 8, 8)
      TilingUtils.printMatrix("Matrix B (signed)", matrixB, 8, 8)

      val result = tiledMatmul(dut, matrixA, 8, 8, matrixB, 8, 8)

      // Compute expected result using software
      val expected = TilingUtils.softwareMatmul(matrixA, matrixB, 8, 8, 8)

      TilingUtils.printMatrix("Result", result, 8, 8)
      TilingUtils.printMatrix("Expected", expected, 8, 8)

      // Verify
      var errorCount = 0
      for (i <- expected.indices) {
        if (result(i) != expected(i)) {
          errorCount += 1
          val row = i / 8
          val col = i % 8
          println(s"Mismatch at [$row][$col]: expected ${expected(i)}, got ${result(i)}")
        }
      }

      assert(errorCount == 0, s"Found $errorCount mismatches in signed values test")
      println("Test passed: 8x8 signed values matrix multiplication")
    }
  }

  it should "multiply 12x12 matrices for larger tiling test" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config

      // 12×12 matrices (requires 3×3×3 = 27 tile operations)
      // Use small values to avoid overflow
      val matrixA = Array.tabulate(144)(idx => {
        val i = idx / 12
        val j = idx % 12
        (i + j) % 3 + 1  // values 1-3
      })

      val matrixB = Array.tabulate(144)(idx => {
        val i = idx / 12
        val j = idx % 12
        (i * j) % 3 + 1  // values 1-3
      })

      println("\n=== 12x12 Matrix Multiplication Test (27 tile ops) ===")

      val startTime = System.nanoTime()
      val result = tiledMatmul(dut, matrixA, 12, 12, matrixB, 12, 12)
      val elapsed = (System.nanoTime() - startTime) / 1e6

      // Compute expected result using software
      val expected = TilingUtils.softwareMatmul(matrixA, matrixB, 12, 12, 12)

      println(s"\nExecution time: ${elapsed}ms")

      // Just print corners for large matrices
      println("Result (first 4x4 corner):")
      for (r <- 0 until 4) {
        val row = (0 until 4).map(c => f"${result(r * 12 + c)}%4d").mkString(" ")
        println(s"  $row")
      }

      // Verify
      var errorCount = 0
      var maxError = 0
      for (i <- expected.indices) {
        val err = math.abs(result(i) - expected(i))
        maxError = math.max(maxError, err)
        if (err > 0) {
          errorCount += 1
        }
      }

      println(s"Errors: $errorCount / ${expected.length}, Max error: $maxError")

      assert(errorCount == 0, s"Found $errorCount mismatches in 12x12 test")
      println("Test passed: 12x12 matrix multiplication with 27 tile operations")
    }
  }

  it should "handle non-square matrices (6x8 * 8x4)" in {
    val config = TPUConfig(n = 4, dataWidth = 8)

    test(new TPUTestHarness(config)).withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      implicit val implicitConfig = config

      // A is 6×8, B is 8×4, result C is 6×4
      val aRows = 6
      val aCols = 8
      val bRows = 8
      val bCols = 4

      val matrixA = Array.tabulate(aRows * aCols)(idx => {
        val i = idx / aCols
        val j = idx % aCols
        (i + j) % 4 + 1
      })

      val matrixB = Array.tabulate(bRows * bCols)(idx => {
        val i = idx / bCols
        val j = idx % bCols
        (i + j * 2) % 4 + 1
      })

      println("\n=== Non-Square Matrix Multiplication Test (6x8 * 8x4) ===")
      TilingUtils.printMatrix("Matrix A (6x8)", matrixA, aRows, aCols)
      TilingUtils.printMatrix("Matrix B (8x4)", matrixB, bRows, bCols)

      val result = tiledMatmul(dut, matrixA, aRows, aCols, matrixB, bRows, bCols)

      // Compute expected result
      val expected = TilingUtils.softwareMatmul(matrixA, matrixB, aRows, aCols, bCols)

      TilingUtils.printMatrix("Result (6x4)", result, aRows, bCols)
      TilingUtils.printMatrix("Expected (6x4)", expected, aRows, bCols)

      // Verify
      var errorCount = 0
      for (i <- expected.indices) {
        if (result(i) != expected(i)) {
          errorCount += 1
          val row = i / bCols
          val col = i % bCols
          println(s"Mismatch at [$row][$col]: expected ${expected(i)}, got ${result(i)}")
        }
      }

      assert(errorCount == 0, s"Found $errorCount mismatches in non-square test")
      println("Test passed: Non-square matrix multiplication (6x8 * 8x4)")
    }
  }
}
