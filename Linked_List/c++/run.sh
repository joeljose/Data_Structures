#!/bin/bash

# Check if the executable exists
if [ ! -f "./build/LinkedListTest" ]; then
    echo "Executable not found. Please run build.sh first."
    exit 1
fi

# Run the executable
./build/LinkedListTest

echo "Test execution complete."
