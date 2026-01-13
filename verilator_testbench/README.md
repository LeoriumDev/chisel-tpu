# TPU BitNetMCU 8-bit Model Verilator Simulation

This directory contains a Verilator-based simulation testbench for running the BitNetMCU 8-bit quantized model on the Chisel-based TPU hardware accelerator.

**Features:**
- Full MNIST dataset testing support (up to 10,000 samples)
- Random sampling for statistical accuracy validation
- Comprehensive accuracy tracking and reporting
- Performance benchmarking (cycles, throughput)
- Command-line configuration
- Progress reporting

## Overview

The testbench simulates a fully connected neural network (MNIST classifier) running on a 4×4 systolic array TPU. The model uses 8-bit quantized weights and processes matrix multiplications in hardware.

### Model Architecture

The model (`BitNetMCU_model_8bit.h`) contains 4 fully connected layers:

- **Layer L3**: 784 inputs → 256 outputs
- **Layer L5**: 128 inputs → 784 outputs
- **Layer L7**: 16 inputs → 128 outputs
- **Layer L9**: 10 inputs → 16 outputs (classification layer)

Each layer is followed by ReLU activation and normalization to 8-bit values.

## Hardware Architecture

### TPU Configuration

- **Systolic Array Size**: 4×4 MAC units
- **Data Width**: 8 bits (signed)
- **Accumulator Width**: 21 bits (signed)
- **Buffer Depth**: 256 words
- **Word Width**: 32 bits (packs 4×8-bit values)
- **Extended Word Width**: 64 bits (for output buffer, packs 4×16-bit values)

### TPU Components

1. **Global Buffers (3×)**:
   - Buffer A: Input activations
   - Buffer B: Weight matrix
   - Buffer C: Output results

2. **Systolic Array**:
   - 4×4 grid of MAC (Multiply-Accumulate) units
   - Processes matrix tiles in a pipelined fashion
   - Each MAC unit has a 21-bit accumulator

3. **Control Unit (FSM)**:
   - Orchestrates data flow
   - Manages buffer reads/writes
   - Controls systolic array timing

## Files

- `tpu_sim.cpp`: Main C++ testbench for Verilator
- `Makefile`: Build configuration
- `../generated_testharness/TPUTestHarnessGen.v`: Generated Verilog from Chisel
- `../BitNetMCU_model_8bit.h`: 8-bit quantized model weights

## Building

### Prerequisites

- Verilator 5.020 or later
- G++ with C++11 support
- Make
- Python 3 with PyTorch (optional, for full MNIST dataset)

### Quick Start

```bash
# Build with 10-sample dataset (no PyTorch required)
make

# Run quick test
make run

# For full MNIST dataset (requires PyTorch):
pip3 install torch torchvision
make mnist_data      # Generate full dataset
make clean && make   # Rebuild with full dataset
```

### Build Options

```bash
make              # Build testbench
make mnist_data   # Generate full MNIST dataset (requires PyTorch)
make help         # Show all available targets
```

## Running

### Command-Line Options

```bash
./obj_dir/VTPUTestHarnessGen [OPTIONS]

Options:
  -n, --samples N    Test N random samples (default: 100)
  --all              Test all available samples
  --seed S           Set random seed for reproducibility (default: 42)
  -v, --verbose      Print detailed per-sample results
  -h, --help         Show help message
```

### Quick Tests

```bash
# Run with 10 samples (verbose)
make run

# Test all available samples
make test

# Test 100 random samples
make test-100

# Performance benchmark with 1000 samples
make test-1000

# Single inference with waveform tracing
make run-trace
```

### Example Usage

```bash
# Test 50 random samples
./obj_dir/VTPUTestHarnessGen -n 50

# Test all samples with verbose output
./obj_dir/VTPUTestHarnessGen --all --verbose

# Reproducible test with specific seed
./obj_dir/VTPUTestHarnessGen -n 100 --seed 123
```

## Performance Results

From a test run with 10 samples:

```
Accuracy: 20.00% (2/10 correct)

Performance Metrics:
  Avg cycles/inference: 101,680 cycles
  Simulation time: 0.38 seconds
  Throughput: 26.0 inferences/sec
```

**Layer Breakdown:**
- Layer L3: 784 → 256 (majority of computation)
- Layer L5: 128 → 784
- Layer L7: 16 → 128
- Layer L9: 10 → 16

**Note**: Cycle count includes:
- Matrix buffer loading overhead
- Tile-by-tile processing
- Result readback
- ReLU/normalization (software)

## How It Works

### 1. Matrix Loading

For each layer, the testbench:
- Loads input activations into Buffer A (packed as 4×8-bit per 32-bit word)
- Loads weight matrix into Buffer B (transposed for systolic array)
- Processes output in tiles (4×4 elements at a time)

### 2. Hardware Computation

The TPU performs matrix multiplication:
```
C[m×n] = A[m×k] × B[k×n]
```

The systolic array processes data in a wave-like pattern:
- Data flows from top-to-bottom (matrix A)
- Data flows from left-to-right (matrix B)
- Results accumulate in MAC units

### 3. Result Readback

After computation:
- Results are packed in Buffer C (4×16-bit per 64-bit word)
- Testbench reads and unpacks the values
- Values are passed through ReLU+normalization in software

### 4. Layer Chaining

The output of one layer becomes the input to the next, creating a complete neural network inference pipeline.

## Limitations

1. **Tile Size**: Limited to 4×4 tiles, larger matrices require tiling
2. **Buffer Size**: 256 words limits maximum matrix dimensions
3. **8-bit Precision**: Quantized weights may lose some accuracy
4. **Software Activation**: ReLU/normalization done in software (could be accelerated)

## Full MNIST Dataset Testing

### Generating the Dataset

The testbench supports testing with the complete MNIST test dataset (10,000 samples):

```bash
# Install PyTorch
pip3 install torch torchvision

# Generate MNIST data file (~3-4 MB)
make mnist_data

# Rebuild testbench with full dataset support
make clean && make
```

The `generate_mnist_data.py` script:
1. Downloads MNIST test dataset using PyTorch
2. Preprocesses images (resize to 16×16, normalize, quantize to 8-bit)
3. Exports to C header file: `mnist_test_data_full.h`

### Testing Strategy

**Quick Validation (10-100 samples)**
```bash
make test-100
```
- Fast iteration during development
- Statistical sampling provides good confidence
- Runtime: ~1-2 minutes

**Full Accuracy Test (10,000 samples)**
```bash
./obj_dir/VTPUTestHarnessGen --all
```
- Complete accuracy validation
- Matches reference implementation
- Runtime: ~20-30 minutes

**Performance Benchmarking (1000 samples)**
```bash
make test-1000
```
- Balance between speed and statistical significance
- Good for performance characterization
- Runtime: ~5-10 minutes

### Random Sampling

The testbench uses random sampling for efficiency:
- Selects N samples uniformly from the full dataset
- Uses configurable seed for reproducibility
- Provides statistical confidence with faster turnaround

Example:
```bash
# Same samples each time (reproducible)
./obj_dir/VTPUTestHarnessGen -n 100 --seed 42

# Different random samples
./obj_dir/VTPUTestHarnessGen -n 100 --seed 123
```

## Troubleshooting

### Low Accuracy

If you see low accuracy (e.g., 20% or all predictions as 0):
- Verify the model file (`BitNetMCU_model_8bit.h`) is trained correctly
- Check that input data format matches model expectations
- Compare with reference C implementation in `Reference/`

### PyTorch Installation

If `make mnist_data` fails with "No module named 'torch'":
```bash
# CPU-only PyTorch (faster download)
pip3 install torch torchvision --index-url https://download.pytorch.org/whl/cpu
```

### Compilation Issues

If you see narrowing conversion warnings, they're suppressed with `-Wno-narrowing` flag in the Makefile.

## Future Improvements

- [ ] Compare TPU results with software reference implementation
- [ ] Add per-class accuracy metrics (confusion matrix)
- [ ] Implement activation functions in hardware
- [ ] Add support for larger models via streaming
- [ ] Optimize buffer management to reduce overhead
- [ ] Support multiple model files (fp130, etc.)

## References

- BitNetMCU: https://github.com/cpldcpu/BitNetMCU
- Chisel HDL: https://www.chisel-lang.org/
- Verilator: https://www.veripool.org/verilator/
