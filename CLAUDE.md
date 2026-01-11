# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

chisel-tpu - A TPU (Tensor Processing Unit) hardware design project using Chisel HDL.

## Tech Stack

- **Chisel 3.6.1** - Scala-based hardware description language
- **Scala 2.13.10** - Programming language
- **SBT 1.9.7** - Build tool
- **ChiselTest 0.6.0** - Testing framework
- **FIRRTL 1.6.0** - Intermediate representation compiler

## Build Commands

```bash
make test                    # Run all tests
make test-only TEST=ALUTest  # Run a single test class
make compile                 # Compile the project
make verilog                 # Generate Verilog (runMain tpu.Main)
make format                  # Format Scala code with scalafmt
make clean                   # Clean build artifacts
make distclean               # Deep clean including SBT cache
```

Or use SBT directly:
```bash
sbt compile
sbt test
sbt "testOnly *TestClassName*"
```

## Project Structure

```
src/main/scala/tpu/       # Main TPU source code
  core/                   # Core TPU modules
src/main/resources/       # Binary/hex files for testing
src/test/scala/tpu/       # Test files
```

## Code Style

- Scala: scalafmt with 120 char line limit (see .scalafmt.conf)
- C/C++: clang-format with Chromium style (see .clang-format)
