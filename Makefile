# Chisel TPU Makefile

.DEFAULT_GOAL := test

# Run all tests
test:
	sbt test

# Run a single test class
# Usage: make test-only TEST=tpu.core.ALUTest
test-only:
	sbt "testOnly *$(TEST)*"

# Compile the project
compile:
	sbt compile

# Generate Verilog
verilog:
	sbt "runMain tpu.Main"

# Format Scala code
format:
	find . -name '*.scala' -not -path "./reference/*" | xargs scalafmt

# Clean build artifacts
clean:
	sbt clean
	rm -rf test_run_dir
	rm -rf generated
	rm -f *.vcd *.fst

# Deep clean including SBT cache
distclean: clean
	rm -rf target
	rm -rf project/target
	rm -rf project/project
	rm -rf .bloop .metals .bsp

.PHONY: test test-only compile verilog format clean distclean
