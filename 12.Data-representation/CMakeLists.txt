cmake_minimum_required(VERSION 3.10)
project("12.Internal-data-representation" C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Task 1: Binary representation
add_executable(binary_converter 
    src/Task_1/main.c 
    src/Task_1/binary.c
)

target_include_directories(binary_converter PRIVATE src/Task_1)
set_target_properties(binary_converter PROPERTIES OUTPUT_NAME "Binary_representation")

# Task 2: Double under the microscope
add_executable(double_converter 
    src/Task_2/double.c
)

target_include_directories(double_converter PRIVATE src/Task_2)
set_target_properties(double_converter PROPERTIES OUTPUT_NAME "Double_under_the_microscope")