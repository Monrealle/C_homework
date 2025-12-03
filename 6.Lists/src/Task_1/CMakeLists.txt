cmake_minimum_required(VERSION 3.10)
project(5.Stack-and-Quene)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(src/Stack)

add_executable(sorted_list
    src/Task_1/Sorted-list.c
)

add_executable(Counting_rhyme
    src/Task_2/Counting-rhyme.c
)
