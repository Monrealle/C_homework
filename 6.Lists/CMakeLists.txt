cmake_minimum_required(VERSION 3.10)

project(Lists)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Task_1 src/Task_1/Sorted-list.c)
add_executable(Task_2 src/Task_2/Counting-rhyme.c)

target_compile_options(Task_1 PRIVATE -Wall -Wextra)
target_compile_options(Task_2 PRIVATE -Wall -Wextra)
