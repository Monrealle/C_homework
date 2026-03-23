cmake_minimum_required(VERSION 3.10)

project(Lists)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Task_1
    src/Task_1/main.c
    src/Task_1/sort.c
)

target_compile_options(Task_1 PRIVATE -Wall -Wextra)
