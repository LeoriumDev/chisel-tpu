#!/usr/bin/env python3
"""
Generate MNIST test data header file for TPU Verilator testbench

This script loads the MNIST test dataset (10,000 samples), preprocesses the images
to match the BitNetMCU format (16x16, 8-bit quantized), and exports them to a
C header file for use in the Verilator testbench.

Usage:
    python3 generate_mnist_data.py --output mnist_test_data_full.h
"""

import numpy as np
import argparse
from datetime import datetime
import gzip
import struct
from PIL import Image


def read_mnist_images(filename):
    """
    Read MNIST image file (.gz format).

    Args:
        filename: Path to MNIST image file (e.g., t10k-images-idx3-ubyte.gz)

    Returns:
        numpy array of shape (num_images, 28, 28) with uint8 values
    """
    with gzip.open(filename, 'rb') as f:
        # Read header
        magic, num_images, rows, cols = struct.unpack('>IIII', f.read(16))
        if magic != 2051:
            raise ValueError(f'Invalid magic number {magic} in MNIST image file')

        # Read image data
        buf = f.read(rows * cols * num_images)
        data = np.frombuffer(buf, dtype=np.uint8)
        data = data.reshape(num_images, rows, cols)

    return data


def read_mnist_labels(filename):
    """
    Read MNIST label file (.gz format).

    Args:
        filename: Path to MNIST label file (e.g., t10k-labels-idx1-ubyte.gz)

    Returns:
        numpy array of shape (num_labels,) with uint8 values
    """
    with gzip.open(filename, 'rb') as f:
        # Read header
        magic, num_labels = struct.unpack('>II', f.read(8))
        if magic != 2049:
            raise ValueError(f'Invalid magic number {magic} in MNIST label file')

        # Read label data
        buf = f.read(num_labels)
        labels = np.frombuffer(buf, dtype=np.uint8)

    return labels


def preprocess_mnist_sample(image_array):
    """
    Preprocess a single MNIST image to match BitNetMCU format.

    Args:
        image_array: numpy array [28, 28] with uint8 values (0-255)

    Returns:
        numpy array of 256 int8 values (-128 to 127)
    """
    # Resize to 16x16 using PIL (nearest neighbor to match reference)
    img = Image.fromarray(image_array)
    img_resized = img.resize((16, 16), Image.NEAREST)
    image_data = np.array(img_resized, dtype=np.float32)

    # Normalize to [0, 1]
    image_data = image_data / 255.0

    # Apply MNIST standard normalization
    mean = 0.1307
    std = 0.3081
    image_data = (image_data - mean) / std

    # Flatten to 256 values
    image_data = image_data.flatten()

    # Quantize to 8-bit signed integers
    # Use same quantization as reference implementation
    scale = 127.0 / np.maximum(np.abs(image_data).max(), 1e-5)
    quantized_data = np.round(image_data * scale).clip(-128, 127).astype(np.int8)

    return quantized_data


def export_mnist_to_header(output_file, num_samples=10000, images_file=None, labels_file=None):
    """
    Export MNIST test dataset to C header file.

    Args:
        output_file: Path to output header file
        num_samples: Number of samples to export (default: all 10,000)
        images_file: Path to MNIST images file (default: ../t10k-images-idx3-ubyte.gz)
        labels_file: Path to MNIST labels file (default: ../t10k-labels-idx1-ubyte.gz)
    """
    # Default paths to MNIST files in parent directory
    if images_file is None:
        images_file = '../t10k-images-idx3-ubyte.gz'
    if labels_file is None:
        labels_file = '../t10k-labels-idx1-ubyte.gz'

    print(f"Loading MNIST test dataset from {images_file}...")

    # Read MNIST data directly from .gz files
    images = read_mnist_images(images_file)
    labels = read_mnist_labels(labels_file)

    print(f"Loaded {len(images)} images and {len(labels)} labels")

    # Limit to requested number of samples
    num_samples = min(num_samples, len(images))

    print(f"Processing {num_samples} test samples...")

    # Preprocess all samples
    all_data = []
    all_labels = []

    for i in range(num_samples):
        image = images[i]
        label = labels[i]
        quantized_data = preprocess_mnist_sample(image)
        all_data.append(quantized_data)
        all_labels.append(label)

        if (i + 1) % 1000 == 0:
            print(f"  Processed {i + 1}/{num_samples} samples...")

    print(f"\nGenerating C header file: {output_file}")

    # Write to header file
    with open(output_file, 'w') as f:
        # Header
        f.write("// Automatically generated MNIST test data\n")
        f.write(f"// Generated: {datetime.now()}\n")
        f.write(f"// Number of samples: {num_samples}\n")
        f.write("// Format: 16x16 images, 8-bit signed integers (-128 to 127)\n\n")

        f.write("#ifndef MNIST_TEST_DATA_FULL_H\n")
        f.write("#define MNIST_TEST_DATA_FULL_H\n\n")

        f.write("#include <stdint.h>\n\n")

        f.write(f"// Number of test samples\n")
        f.write(f"#define MNIST_TEST_SIZE {num_samples}\n\n")

        # Write test data array
        f.write("// MNIST test images (16x16 = 256 pixels per image)\n")
        f.write(f"const int8_t mnist_test_data[{num_samples}][256] = {{\n")

        for i, data in enumerate(all_data):
            f.write("    {")
            # Write 16 values per line for readability
            for j in range(0, 256, 16):
                chunk = data[j:j+16]
                # Cast to uint8 for hex formatting, then back to int8 interpretation
                hex_values = [f"0x{(val & 0xFF):02X}" for val in chunk]
                if j > 0:
                    f.write("     ")
                f.write(", ".join(hex_values))
                if j + 16 < 256:
                    f.write(",\n")
            f.write("}")
            if i < num_samples - 1:
                f.write(",\n")
            else:
                f.write("\n")

            # Progress indicator
            if (i + 1) % 1000 == 0:
                print(f"  Written {i + 1}/{num_samples} samples...")

        f.write("};\n\n")

        # Write labels array
        f.write("// MNIST test labels (0-9)\n")
        f.write(f"const uint8_t mnist_test_labels[{num_samples}] = {{\n    ")

        for i, label in enumerate(all_labels):
            f.write(f"{label}")
            if i < num_samples - 1:
                f.write(", ")
                if (i + 1) % 20 == 0:  # 20 labels per line
                    f.write("\n    ")
            else:
                f.write("\n")

        f.write("};\n\n")

        f.write("#endif // MNIST_TEST_DATA_FULL_H\n")

    print(f"\nSuccess! Generated {output_file}")
    print(f"  Samples: {num_samples}")
    print(f"  File size: {get_file_size_mb(output_file):.2f} MB")


def get_file_size_mb(filepath):
    """Get file size in megabytes."""
    import os
    size_bytes = os.path.getsize(filepath)
    return size_bytes / (1024 * 1024)


def main():
    parser = argparse.ArgumentParser(
        description='Generate MNIST test data header file for TPU testbench'
    )
    parser.add_argument(
        '--output', '-o',
        type=str,
        default='mnist_test_data_full.h',
        help='Output header file name (default: mnist_test_data_full.h)'
    )
    parser.add_argument(
        '--samples', '-n',
        type=int,
        default=10000,
        help='Number of samples to export (default: 10000)'
    )

    args = parser.parse_args()

    try:
        export_mnist_to_header(args.output, args.samples)
        print("\nTo use this data:")
        print("  1. Include in your C++ code: #include \"mnist_test_data_full.h\"")
        print("  2. Access data: mnist_test_data[index][pixel]")
        print("  3. Access labels: mnist_test_labels[index]")
    except Exception as e:
        print(f"\nError: {e}")
        return 1

    return 0


if __name__ == '__main__':
    exit(main())
