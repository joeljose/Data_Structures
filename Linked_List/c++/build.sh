#!/bin/bash

# Ask if this should be a clean build
read -p "Do you want a clean build? (y/n): " clean_build

if [ "$clean_build" = "y" ] || [ "$clean_build" = "Y" ]; then
    echo "Performing a clean build..."
    # Remove the build directory if it exists
    rm -rf build
fi

# Create a build directory if it doesn't exist
mkdir -p build

# Navigate to the build directory
cd build

# Run CMake to generate Makefiles
cmake ..

# Build the project
make

# Return to the original directory
cd ..

echo "Build complete. Executable is in the 'build' directory."
