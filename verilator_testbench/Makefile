##################################################
# Verilator Testbench Makefile for TPU Simulation
##################################################

# Verilator configuration
VERILATOR = verilator
VERILATOR_FLAGS = -Wall -Wno-fatal --cc --exe --build
VERILATOR_FLAGS += --trace  # Enable waveform tracing
VERILATOR_FLAGS += -O3      # Optimize for speed
VERILATOR_FLAGS += -CFLAGS "-std=c++11 -O3 -I.. -I. -Wno-narrowing"
VERILATOR_FLAGS += -LDFLAGS "-lm"

# Paths
VERILOG_DIR = ../generated_testharness
VERILOG_SRC = $(VERILOG_DIR)/TPUTestHarnessGen.v
CPP_SRC = tpu_sim.cpp

# MNIST data files
MNIST_DATA = mnist_test_data_full.h

# Output
TARGET = obj_dir/VTPUTestHarnessGen

# Check if full MNIST data exists
HAVE_MNIST_DATA := $(shell test -f $(MNIST_DATA) && echo yes || echo no)

# Default target - build with whatever data is available
all: $(TARGET)
	@echo "=========================================="
	@echo "Build complete!"
	@echo "=========================================="
ifeq ($(HAVE_MNIST_DATA),yes)
	@echo "Using full MNIST dataset (10,000 samples)"
else
	@echo "Using 10-sample dataset from Reference/"
	@echo ""
	@echo "To use full MNIST dataset:"
	@echo "  1. Install PyTorch: pip3 install torch torchvision"
	@echo "  2. Generate data:   make mnist_data"
	@echo "  3. Rebuild:         make clean && make"
endif
	@echo ""
	@echo "Run with: ./$(TARGET) [options]"
	@echo "Try:      ./$(TARGET) --help"
	@echo "=========================================="

# Build with Verilator - add MNIST flag if data exists
$(TARGET): $(VERILOG_SRC) $(CPP_SRC)
ifeq ($(HAVE_MNIST_DATA),yes)
	$(VERILATOR) $(VERILATOR_FLAGS) -CFLAGS "-DUSE_FULL_MNIST_DATA" $(VERILOG_SRC) $(CPP_SRC)
else
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILOG_SRC) $(CPP_SRC)
endif

# Generate MNIST test data (requires PyTorch)
mnist_data: $(MNIST_DATA)

$(MNIST_DATA): generate_mnist_data.py
	@echo "Generating full MNIST test dataset..."
	@echo "This will download MNIST data (~12MB) and generate a ~3-4MB header file"
	python3 generate_mnist_data.py --output $(MNIST_DATA)
	@echo ""
	@echo "Done! Now run 'make clean && make' to rebuild with full dataset"

# Run simulation with default settings (10 samples)
run: $(TARGET)
	./$(TARGET) -n 10 --verbose

# Quick test with all available samples
test: $(TARGET)
	./$(TARGET) --all --verbose

# Medium test with 100 random samples
test-100: $(TARGET)
	./$(TARGET) -n 100

# Large test with 1000 random samples (good for performance benchmarking)
test-1000: $(TARGET)
	./$(TARGET) -n 1000

# Run with waveform generation
run-trace: $(TARGET)
	./$(TARGET) -n 1 --verbose +trace

# Clean build artifacts
clean:
	rm -rf obj_dir/
	rm -f *.vcd

# Deep clean including generated MNIST data
distclean: clean
	rm -f $(MNIST_DATA)
	rm -rf data/  # PyTorch MNIST download directory

# Show help
help:
	@echo "TPU Verilator Testbench Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make              - Build testbench (default)"
	@echo "  make mnist_data   - Generate full MNIST dataset (requires PyTorch)"
	@echo "  make run          - Run quick test (10 samples, verbose)"
	@echo "  make test         - Test all available samples"
	@echo "  make test-100     - Test 100 random samples"
	@echo "  make test-1000    - Test 1000 samples (performance benchmark)"
	@echo "  make run-trace    - Run with waveform tracing (1 sample)"
	@echo "  make clean        - Remove build artifacts"
	@echo "  make distclean    - Remove everything including MNIST data"
	@echo "  make help         - Show this help"
	@echo ""
	@echo "Testbench options:"
	@echo "  ./$(TARGET) --help"

.PHONY: all run test test-100 test-1000 run-trace clean distclean mnist_data help
