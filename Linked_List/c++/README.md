# LinkedList Implementation in C++

This project implements a LinkedList data structure in C++ with comprehensive unit tests using Google Test.

## Project Structure

- `linked_list.hpp`: Header file for the LinkedList class
- `linked_list.cpp`: Implementation of the LinkedList class
- `linked_list_test.cpp`: Unit tests for the LinkedList class
- `CMakeLists.txt`: CMake configuration file
- `build.sh`: Script to build the project
- `run.sh`: Script to run the tests

## Prerequisites

- CMake (version 3.14 or higher)
- C++ compiler supporting C++14 or later
- Google Test (included as a submodule in the `googletest/` directory)

## Building the Project

1. Make sure you're in the project directory containing `build.sh`.
2. Run the build script:
   ```
   ./build.sh
   ```
3. When prompted, choose whether you want a clean build:
   - Enter 'y' for a clean build (removes previous build artifacts)
   - Enter 'n' for an incremental build

The script will create a `build` directory, run CMake, and build the project.

## Running the Tests

After building the project:

1. Make sure you're in the project directory containing `run.sh`.
2. Run the test script:
   ```
   ./run.sh
   ```

This will execute the LinkedListTest executable and display the test results.

## LinkedList Implementation

The LinkedList class provides the following operations:

- `append`: Add an element to the end of the list
- `prepend`: Add an element to the beginning of the list
- `insert_after`: Insert an element after a given node
- `delete_value`: Remove the first occurrence of a value from the list
- `delete_at_position`: Remove an element at a specific position
- `find`: Find a node with a specific value
- `contains`: Check if a value exists in the list
- `length`: Get the number of elements in the list
- `reverse`: Reverse the order of elements in the list
- `print_list`: Display the contents of the list

## Test Cases

The `linked_list_test.cpp` file contains the following test cases:

1. `AppendAndPrepend`: Tests adding elements to the beginning and end of the list
2. `InsertAfter`: Tests inserting an element after a specific node
3. `DeleteValue`: Tests removing a specific value from the list
4. `DeleteAtPosition`: Tests removing an element at a given position
5. `Reverse`: Tests reversing the order of elements in the list
6. `EmptyList`: Tests operations on an empty list
7. `SingleElementList`: Tests operations on a list with a single element

Each test case verifies the correct behavior of the LinkedList operations, including edge cases and typical usage scenarios.

## Modifying the Project

To add new features or test cases:

1. Implement new methods in `linked_list.cpp` and update `linked_list.hpp` accordingly.
2. Add new test cases in `linked_list_test.cpp`.
3. Rebuild the project using `./build.sh`.
4. Run the updated tests using `./run.sh`.
