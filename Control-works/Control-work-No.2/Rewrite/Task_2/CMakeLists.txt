cmake_minimum_required(VERSION 3.10)
project(cyclic_shift C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(cyclic_shift
    src/main.c
    src/cyclic_shift.c
)

target_include_directories(cyclic_shift
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(test_cyclic_shift
    tests/test_cyclic_shift.c
    src/cyclic_shift.c
)

target_include_directories(test_cyclic_shift
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(test_cyclic_shift
    PRIVATE TEST_MAIN
)

enable_testing()
add_test(NAME cyclic_shift_tests COMMAND test_cyclic_shift)

message(STATUS "=== 'Циклический сдвиг' ===")
message(STATUS "Доступные цели:")
message(STATUS "  - cyclic_shift (основная программа)")
message(STATUS "  - test_cyclic_shift (тесты)")
message(STATUS "Для сборки: mkdir build && cd build && cmake .. && make")
