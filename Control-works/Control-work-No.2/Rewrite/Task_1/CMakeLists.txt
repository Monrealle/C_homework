cmake_minimum_required(VERSION 3.10)
project(palindrome_check C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(palindrome_check
    src/main.c
    src/palindrome.c
)

target_include_directories(palindrome_check
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(test_palindrome
    tests/test_palindrome.c
    src/palindrome.c
)

target_include_directories(test_palindrome
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(test_palindrome
    PRIVATE TEST_MAIN
)

enable_testing()
add_test(NAME palindrome_tests COMMAND test_palindrome)

message(STATUS "=== Проект 'Проверка палиндрома' ===")
message(STATUS "Доступные цели:")
message(STATUS "  - palindrome_check (основная программа)")
message(STATUS "  - test_palindrome (тесты)")
message(STATUS "Для сборки: mkdir build && cd build && cmake .. && make")
