// TPU Verilator Simulation Testbench for BitNetMCU 8-bit Model
// Extended version with full MNIST dataset testing support

#include <verilated.h>
#include "VTPUTestHarnessGen.h"
#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <random>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <iomanip>

// Include the 8-bit quantized model
#include "../mnist_models/BitNetMCU_model_8bit.h"

// Try to include full MNIST dataset if available, otherwise use small sample
#ifdef USE_FULL_MNIST_DATA
#include "mnist_test_data_full.h"
#else
// Use the 10-sample dataset from Reference
#include "../Reference/BitNetMCU_MNIST_test_data.h"
#define MNIST_TEST_SIZE 10
// Workaround for narrowing conversion warnings - use reinterpret_cast
const int8_t* const mnist_test_data[MNIST_TEST_SIZE] = {
    reinterpret_cast<const int8_t*>(input_data_0),
    reinterpret_cast<const int8_t*>(input_data_1),
    reinterpret_cast<const int8_t*>(input_data_2),
    reinterpret_cast<const int8_t*>(input_data_3),
    reinterpret_cast<const int8_t*>(input_data_4),
    reinterpret_cast<const int8_t*>(input_data_5),
    reinterpret_cast<const int8_t*>(input_data_6),
    reinterpret_cast<const int8_t*>(input_data_7),
    reinterpret_cast<const int8_t*>(input_data_8),
    reinterpret_cast<const int8_t*>(input_data_9)
};
const uint8_t mnist_test_labels[MNIST_TEST_SIZE] = {
    label_0, label_1, label_2, label_3, label_4,
    label_5, label_6, label_7, label_8, label_9
};
#endif

// Configuration structure
struct TestConfig {
    int num_samples = 100;
    bool use_all = false;
    unsigned int seed = 42;
    bool verbose = false;
    bool show_help = false;
};

// Accuracy tracking class
class AccuracyTracker {
private:
    int total_samples;
    int correct_predictions;
    std::vector<int> predictions;
    std::vector<int> ground_truth;
    int per_class_total[10];      // Total samples per class (0-9)
    int per_class_correct[10];    // Correct predictions per class (0-9)

public:
    AccuracyTracker() : total_samples(0), correct_predictions(0) {
        for (int i = 0; i < 10; i++) {
            per_class_total[i] = 0;
            per_class_correct[i] = 0;
        }
    }

    void recordPrediction(int predicted, int actual) {
        predictions.push_back(predicted);
        ground_truth.push_back(actual);
        total_samples++;

        // Track per-class statistics
        if (actual >= 0 && actual <= 9) {
            per_class_total[actual]++;
            if (predicted == actual) {
                per_class_correct[actual]++;
                correct_predictions++;
            }
        }
    }

    double getAccuracy() const {
        return total_samples > 0 ? (100.0 * correct_predictions / total_samples) : 0.0;
    }

    double getClassAccuracy(int class_label) const {
        if (class_label < 0 || class_label > 9 || per_class_total[class_label] == 0) {
            return 0.0;
        }
        return 100.0 * per_class_correct[class_label] / per_class_total[class_label];
    }

    int getCorrect() const { return correct_predictions; }
    int getTotal() const { return total_samples; }
    int getClassTotal(int class_label) const {
        return (class_label >= 0 && class_label <= 9) ? per_class_total[class_label] : 0;
    }
    int getClassCorrect(int class_label) const {
        return (class_label >= 0 && class_label <= 9) ? per_class_correct[class_label] : 0;
    }

    void printSummary() const {
        std::cout << "Correct predictions: " << correct_predictions << " / " << total_samples << std::endl;
        std::cout << "Accuracy: " << std::fixed << std::setprecision(2) << getAccuracy() << "%" << std::endl;
    }

    void printPerClassAccuracy() const {
        std::cout << "\nPer-Class Accuracy:" << std::endl;
        std::cout << "Class | Total | Correct | Accuracy" << std::endl;
        std::cout << "------+-------+---------+---------" << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "  " << i << "   |  "
                      << std::setw(4) << per_class_total[i] << " |   "
                      << std::setw(4) << per_class_correct[i] << "  | "
                      << std::fixed << std::setprecision(2) << std::setw(6)
                      << getClassAccuracy(i) << "%" << std::endl;
        }
    }
};

// Performance metrics class
class PerformanceMetrics {
private:
    uint64_t total_cycles;
    int num_inferences;
    std::chrono::steady_clock::time_point start_time;
    std::vector<uint64_t> per_sample_cycles;

public:
    PerformanceMetrics() : total_cycles(0), num_inferences(0) {}

    void startTimer() {
        start_time = std::chrono::steady_clock::now();
    }

    void recordInference(uint64_t cycles) {
        total_cycles += cycles;
        num_inferences++;
        per_sample_cycles.push_back(cycles);
    }

    double getAvgCyclesPerInference() const {
        return num_inferences > 0 ? (double)total_cycles / num_inferences : 0.0;
    }

    uint64_t getMinCycles() const {
        return per_sample_cycles.empty() ? 0 : *std::min_element(per_sample_cycles.begin(), per_sample_cycles.end());
    }

    uint64_t getMaxCycles() const {
        return per_sample_cycles.empty() ? 0 : *std::max_element(per_sample_cycles.begin(), per_sample_cycles.end());
    }

    double getElapsedTime() const {
        auto end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time;
        return elapsed.count();
    }

    double getThroughput() const {
        double elapsed = getElapsedTime();
        return elapsed > 0 ? num_inferences / elapsed : 0.0;
    }

    void printSummary() const {
        std::cout << "\nPerformance Metrics:" << std::endl;
        std::cout << "  Total inferences: " << num_inferences << std::endl;
        std::cout << "  Total cycles: " << total_cycles << std::endl;
        std::cout << "  Avg cycles/inference: " << std::fixed << std::setprecision(0) << getAvgCyclesPerInference() << std::endl;
        std::cout << "  Min cycles: " << getMinCycles() << std::endl;
        std::cout << "  Max cycles: " << getMaxCycles() << std::endl;
        std::cout << "  Simulation time: " << std::fixed << std::setprecision(2) << getElapsedTime() << " seconds" << std::endl;
        std::cout << "  Throughput: " << std::fixed << std::setprecision(1) << getThroughput() << " inferences/sec" << std::endl;
    }
};

// ReLU normalization implementation
extern "C" {
    uint32_t ReLUNorm(int32_t *input, int8_t *output, uint32_t n_input) {
        int32_t max_val = -INT32_MAX;
        int32_t max_pos = 255;
        uint32_t scale, shift;
        int32_t rounding, tmp;

        for (uint32_t i = 0; i < n_input; i++) {
            if (input[i] > max_val) {
                max_val = input[i];
                max_pos = i;
            }
        }

        scale = max_val >> 7;
        shift = 0;
        while (scale > 0) {
            shift++;
            scale >>= 1;
        }
        rounding = (1 << shift) >> 1;

        for (uint32_t i = 0; i < n_input; i++) {
            if (input[i] < 0) {
                output[i] = 0;
            } else {
                tmp = (input[i] + rounding) >> shift;
                output[i] = (tmp > 127) ? 127 : tmp;
            }
        }
        return max_pos;
    }
}

class TPUSimulator {
private:
    VTPUTestHarnessGen* dut;
    uint64_t sim_time;
    uint64_t cycle_count;

public:
    TPUSimulator() {
        dut = new VTPUTestHarnessGen;
        sim_time = 0;
        cycle_count = 0;

        dut->clock = 0;
        dut->reset = 1;
        dut->io_start = 0;
        dut->io_testMode = 1;
        dut->io_bufA_wrEn = 0;
        dut->io_bufB_wrEn = 0;
        dut->io_bufC_wrEn = 0;

        for (int i = 0; i < 10; i++) tick();
        dut->reset = 0;
    }

    ~TPUSimulator() { delete dut; }

    void tick() {
        dut->clock = 0;
        dut->eval();
        sim_time++;
        dut->clock = 1;
        dut->eval();
        sim_time++;
        cycle_count++;
    }

    void loadMatrixA(const std::vector<int8_t>& data, int rows, int cols) {
        dut->io_testMode = 1;
        dut->io_bufA_wrEn = 0;
        tick();

        int addr = 0;
        if (rows == 1) {
            // For single-row input (vector-matrix multiplication):
            // Replicate each activation value 4 times so all 4 FIFO lanes
            // receive the same data (required for proper systolic array operation)
            for (size_t i = 0; i < data.size(); i++) {
                uint8_t val = (uint8_t)data[i];
                uint32_t word = val | (val << 8) | (val << 16) | (val << 24);
                dut->io_bufA_addr = addr;
                dut->io_bufA_wrData = word;
                dut->io_bufA_wrEn = 1;
                tick();
                addr++;
            }
        } else {
            // Multi-row input: pack 4 values per word (original behavior)
            for (size_t i = 0; i < data.size(); i += 4) {
                uint32_t word = 0;
                for (int j = 0; j < 4 && (i + j) < data.size(); j++) {
                    word |= ((uint8_t)data[i + j] & 0xFF) << (j * 8);
                }
                dut->io_bufA_addr = addr;
                dut->io_bufA_wrData = word;
                dut->io_bufA_wrEn = 1;
                tick();
                addr++;
            }
        }
        dut->io_bufA_wrEn = 0;
        tick();
    }

    void loadWeightsB(const uint32_t* weights, int n_input, int n_output, int start_output = 0, int num_outputs = -1) {
        loadWeightsBTiled(weights, n_input, n_output, start_output, num_outputs, 0, n_input);
    }

    // Load a tile of weights: columns [k_start, k_start+k_size) for rows [start_output, start_output+num_outputs)
    void loadWeightsBTiled(const uint32_t* weights, int n_input, int n_output,
                           int start_output, int num_outputs, int k_start, int k_size) {
        if (num_outputs < 0) num_outputs = n_output;
        dut->io_testMode = 1;
        dut->io_bufB_wrEn = 0;
        tick();

        int addr = 0;
        // For each input column in the k-tile
        for (int col = k_start; col < k_start + k_size; col++) {
            // Collect weights for all outputs in this output tile
            // Pack up to 4 output weights into one word (one per byte position)
            std::vector<uint8_t> column_data;
            for (int row = start_output; row < (start_output + num_outputs); row++) {
                int weight_idx = row * n_input + col;  // Weight at (row, col) in row-major order
                int word_idx = weight_idx / 4;
                int byte_idx = weight_idx % 4;
                // Weights are packed Big-Endian in the word (MSB is first weight)
                uint8_t weight = (weights[word_idx] >> ((3 - byte_idx) * 8)) & 0xFF;
                column_data.push_back(weight);
            }

            // Pack column_data into 32-bit words (up to 4 weights per word, one per output)
            // Each byte position i corresponds to output start_output+i
            for (size_t i = 0; i < column_data.size(); i += 4) {
                uint32_t word = 0;
                for (int j = 0; j < 4 && (i + j) < column_data.size(); j++) {
                    word |= ((uint32_t)column_data[i + j] & 0xFF) << (j * 8);
                }
                dut->io_bufB_addr = addr;
                dut->io_bufB_wrData = word;
                dut->io_bufB_wrEn = 1;
                tick();
                addr++;
            }
        }
        dut->io_bufB_wrEn = 0;
        tick();
    }

    std::vector<int32_t> readMatrixC(int rows, int cols) {
        std::vector<int32_t> result;
        dut->io_testMode = 1;
        dut->io_bufC_wrEn = 0;
        tick();

        int total_values = rows * cols;
        int num_words = (total_values + 3) / 4;

        for (int addr = 0; addr < num_words; addr++) {
            dut->io_bufC_addr = addr;
            tick();
            uint64_t word = dut->io_bufC_rdData;
            for (int i = 0; i < 4 && result.size() < total_values; i++) {
                int16_t val = (word >> (i * 16)) & 0xFFFF;
                result.push_back((int32_t)val);
            }
        }
        return result;
    }

    void runMatMul(int m_tiles, int k_tiles, int n_tiles) {
        dut->io_testMode = 0;
        dut->io_start = 0;
        dut->io_m = m_tiles;
        dut->io_k = k_tiles;
        dut->io_n = n_tiles;
        tick();
        tick();

        dut->io_start = 1;
        tick();
        dut->io_start = 0;

        uint64_t start_cycles = cycle_count;
        while (!dut->io_done && (cycle_count - start_cycles) < 100000) {
            tick();
        }
        tick();
    }

    uint64_t getCycles() const { return cycle_count; }
};

void processFCLayerTPU(TPUSimulator& tpu, int8_t* activations, const uint32_t* weights,
                       int n_input, int n_output, int32_t* output) {
    const int TILE_SIZE = 4;
    const int K_TILE_SIZE = 1;  // Process 1 inputs at a time (fits in buffer with replication)
    int n_tiles = (n_output + TILE_SIZE - 1) / TILE_SIZE;
    int k_tiles_total = (n_input + K_TILE_SIZE - 1) / K_TILE_SIZE;

    // Initialize output to zero for accumulation
    for (int i = 0; i < n_output; i++) {
        output[i] = 0;
    }

    // Tile over K dimension (input) and N dimension (output)
    for (int k_tile = 0; k_tile < k_tiles_total; k_tile++) {
        int k_start = k_tile * K_TILE_SIZE;
        int k_size = std::min(K_TILE_SIZE, n_input - k_start);

        // Create input vector for this k-tile
        std::vector<int8_t> input_chunk(activations + k_start, activations + k_start + k_size);

        for (int out_tile = 0; out_tile < n_tiles; out_tile++) {
            int start_output = out_tile * TILE_SIZE;
            int num_outputs = std::min(TILE_SIZE, n_output - start_output);

            // Load activations for this k-tile (replicated for single row)
            tpu.loadMatrixA(input_chunk, 1, k_size);

            // Load weights for this k-tile and output tile
            // Need to load weights starting at column k_start
            tpu.loadWeightsBTiled(weights, n_input, n_output, start_output, num_outputs, k_start, k_size);

            tpu.runMatMul(1, k_size, 1);

            std::vector<int32_t> results = tpu.readMatrixC(1, TILE_SIZE);

            // Accumulate partial results
            for (int i = 0; i < num_outputs && (start_output + i) < n_output; i++) {
                output[start_output + i] += results[i];
            }
        }
    }
}

uint32_t BitMnistInferenceTPU(TPUSimulator& tpu, int8_t* input, bool verbose = false) {
    int32_t layer_out[MAX_N_ACTIVATIONS];
    int8_t layer_in[MAX_N_ACTIVATIONS];

    if (verbose) std::cout << "  Running inference through TPU..." << std::endl;

    // NOTE: In this model, L*_incoming_weights = input size, L*_outgoing_weights = output size
    // processFCLayerTPU expects (n_input, n_output), so we swap the parameters
#ifdef L3_active
    processFCLayerTPU(tpu, input, L3_weights, L3_incoming_weights, L3_outgoing_weights, layer_out);
    ReLUNorm(layer_out, layer_in, L3_outgoing_weights);
#endif

#ifdef L5_active
    processFCLayerTPU(tpu, layer_in, L5_weights, L5_incoming_weights, L5_outgoing_weights, layer_out);
    ReLUNorm(layer_out, layer_in, L5_outgoing_weights);
#endif

#ifdef L7_active
    processFCLayerTPU(tpu, layer_in, L7_weights, L7_incoming_weights, L7_outgoing_weights, layer_out);
    ReLUNorm(layer_out, layer_in, L7_outgoing_weights);
#endif

#ifdef L9_active
    processFCLayerTPU(tpu, layer_in, L9_weights, L9_incoming_weights, L9_outgoing_weights, layer_out);
    return ReLUNorm(layer_out, layer_in, L9_outgoing_weights);
#endif

    return 0;
}

std::vector<int> selectRandomSamples(int total_samples, int num_to_select, unsigned int seed) {
    std::vector<int> indices(total_samples);
    std::iota(indices.begin(), indices.end(), 0);

    std::mt19937 rng(seed);
    std::shuffle(indices.begin(), indices.end(), rng);

    indices.resize(std::min(num_to_select, total_samples));
    std::sort(indices.begin(), indices.end());
    return indices;
}

void printHelp(const char* program_name) {
    std::cout << "Usage: " << program_name << " [OPTIONS]\n\n";
    std::cout << "TPU MNIST Accuracy Validation Testbench\n\n";
    std::cout << "Options:\n";
    std::cout << "  -n, --samples N    Test N random samples (default: 100)\n";
    std::cout << "  --all              Test all available samples (" << MNIST_TEST_SIZE << ")\n";
    std::cout << "  --seed S           Set random seed for reproducibility (default: 42)\n";
    std::cout << "  -v, --verbose      Print detailed per-sample results\n";
    std::cout << "  -h, --help         Show this help message\n\n";
#ifndef USE_FULL_MNIST_DATA
    std::cout << "Note: Using 10-sample dataset. For full 10,000-sample testing,\n";
    std::cout << "      generate mnist_test_data_full.h and recompile with -DUSE_FULL_MNIST_DATA\n\n";
#endif
}

TestConfig parseArgs(int argc, char** argv) {
    TestConfig config;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            config.show_help = true;
        } else if (arg == "-n" || arg == "--samples") {
            if (i + 1 < argc) {
                config.num_samples = std::atoi(argv[++i]);
            }
        } else if (arg == "--all") {
            config.use_all = true;
        } else if (arg == "--seed") {
            if (i + 1 < argc) {
                config.seed = std::atoi(argv[++i]);
            }
        } else if (arg == "-v" || arg == "--verbose") {
            config.verbose = true;
        }
    }

    return config;
}

void printBanner(const TestConfig& config) {
    std::cout << "========================================\n";
    std::cout << "TPU MNIST Accuracy Validation\n";
    std::cout << "========================================\n";
    std::cout << "Model: BitNetMCU_model_8bit.h\n";
    std::cout << "Dataset size: " << MNIST_TEST_SIZE << " samples\n";
    std::cout << "Test samples: " << (config.use_all ? "all" : std::to_string(config.num_samples)) << "\n";
    std::cout << "Random seed: " << config.seed << "\n";
    std::cout << "========================================\n\n";
}

void printFinalResults(const AccuracyTracker& accuracy, const PerformanceMetrics& perf) {
    std::cout << "\n========================================\n";
    std::cout << "TEST RESULTS\n";
    std::cout << "========================================\n";
    accuracy.printSummary();
    accuracy.printPerClassAccuracy();
    perf.printSummary();
    std::cout << "========================================\n";
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    TestConfig config = parseArgs(argc, argv);

    if (config.show_help) {
        printHelp(argv[0]);
        return 0;
    }

    printBanner(config);

    TPUSimulator tpu;
    AccuracyTracker accuracy;
    PerformanceMetrics perf;

    int num_samples = config.use_all ? MNIST_TEST_SIZE : std::min(config.num_samples, MNIST_TEST_SIZE);
    std::vector<int> sample_indices = selectRandomSamples(MNIST_TEST_SIZE, num_samples, config.seed);

    std::cout << "Running inference on " << sample_indices.size() << " samples...\n";
    if (!config.verbose) {
        std::cout << "(Use --verbose to see per-sample results)\n\n";
    }

    perf.startTimer();

    for (size_t i = 0; i < sample_indices.size(); i++) {
        int idx = sample_indices[i];
        int8_t* input = (int8_t*)mnist_test_data[idx];
        uint8_t label = mnist_test_labels[idx];

        uint64_t cycles_before = tpu.getCycles();
        uint32_t predicted = BitMnistInferenceTPU(tpu, input, config.verbose);
        uint64_t cycles_after = tpu.getCycles();

        accuracy.recordPrediction(predicted, label);
        perf.recordInference(cycles_after - cycles_before);

        if (config.verbose) {
            std::cout << "Sample " << std::setw(4) << idx
                      << ": Predicted=" << predicted
                      << ", Actual=" << (int)label
                      << ", " << (predicted == label ? "✓" : "✗")
                      << ", Cycles=" << (cycles_after - cycles_before) << "\n";
        } else if ((i + 1) % 10 == 0) {
            std::cout << "  Progress: " << (i + 1) << "/" << sample_indices.size()
                      << " (" << std::fixed << std::setprecision(1)
                      << (100.0 * (i + 1) / sample_indices.size()) << "%)\n";
        }
    }

    printFinalResults(accuracy, perf);

    return 0;
}
