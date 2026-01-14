# GEMINI.md

## Project Overview

**chisel-tpu** is a hardware design project implementing a Tensor Processing Unit (TPU) using Chisel HDL (Scala). The core component is a parameterized N×N systolic array optimized for matrix multiplication.

### Architecture
The design follows a modular architecture:
*   **TPUTop**: Top-level module integrating all components.
*   **TPUControl**: Finite State Machine (FSM) orchestrating the computation pipeline (IDLE, CALCULATE, WRITE, etc.).
*   **Global Buffers**: Three buffers (A, B, C) for storing input matrices and output results.
*   **Systolic Array**: A grid of MAC (Multiply-Accumulate) units that perform the matrix multiplication.
*   **MAC Unit**: The fundamental computation unit performing `acc += a * b`.

### Key Technologies
*   **Language**: Scala 2.13.10
*   **HDL**: Chisel 3.6.1
*   **Build Tool**: SBT 1.9.7
*   **Testing**: ChiselTest 0.6.0
*   **Intermediate Representation**: FIRRTL 1.6.0

## Building and Running

The project uses `make` for common tasks, wrapping standard `sbt` commands.

### Key Commands

| Command | Description |
| :--- | :--- |
| `make test` | Run all tests (via `sbt test`) |
| `make test-only TEST=<Class>` | Run a specific test class (e.g., `make test-only TEST=tpu.core.ALUTest`) |
| `make compile` | Compile the project |
| `make verilog` | Generate Verilog code (runs `tpu.Main`) |
| `make format` | Format Scala code using `scalafmt` |
| `make clean` | Remove build artifacts |

### SBT Usage
You can also use SBT directly:
```bash
sbt compile
sbt test
sbt "runMain tpu.Main"
```

## Directory Structure

*   `src/main/scala/tpu/`: Main source code.
    *   `core/`: Core modules (MACUnit, SystolicArray, GlobalBuffer, etc.).
    *   `TPUTop.scala`: Top-level integration.
    *   `TPUConfig.scala`: Configuration parameters.
*   `src/test/scala/tpu/`: Test specifications.
*   `verilator_testbench/`: C++ testbench for Verilator simulation.
*   `project/`: SBT project configuration.

## Development Conventions

*   **Code Style**: Follows `scalafmt` configuration (120 char line limit).
*   **Testing**: All new features must be accompanied by ChiselTest unit tests.
*   **Configuration**: Use `TPUConfig` case class for parameterizing designs (array size, data width, etc.).
