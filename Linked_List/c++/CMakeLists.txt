cmake_minimum_required(VERSION 3.14)
project(LinkedListTest)

# Google Test requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Google Test
add_subdirectory(googletest-1.15.2)

# Add your linked list implementation
add_library(linked_list STATIC linked_list.cpp)

# Add the executable
add_executable(LinkedListTest main.cpp linked_list_test.cpp)

# Link the executable to Google Test and your linked list library
target_link_libraries(LinkedListTest PRIVATE gtest gtest_main linked_list)

# Add include directories
target_include_directories(LinkedListTest PRIVATE
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/googletest-1.15.2/googletest/include"
                          )

# Optionally, you can add this to automatically discover and run the tests
include(GoogleTest)
gtest_discover_tests(LinkedListTest)
