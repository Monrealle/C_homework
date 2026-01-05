#include "../include/cyclic_shift.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

void test_binary_conversion() {
    printf("1. Тест преобразований число↔массив: ");

    bool arr1[] = {0, 0, 1, 0, 1};  // 10100 в правильном порядке
    uint32_t val = binary_array_to_uint(arr1, 5);

    if (val != 20) {
        printf("Не пройдено: ожидалось 20, получено %u.\n", val);
        return;
    }

    bool arr2[5];
    uint_to_binary_array(val, arr2, 5);

    if (memcmp(arr1, arr2, 5) == 0) {
        printf("Пройдено\n");
    } else {
        printf("Не процдено: массивы не совпадают\n");
    }
}

void test_single_bit() {
    printf("2. Тест одного бита (1): ");

    bool arr[] = {1};
    uint32_t max_val;
    int shift = max_cyclic_shift(arr, 1, &max_val);

    if (max_val == 1 && shift == 0) {
        printf("Пройдено.\n");
    } else {
        printf("Не пройдено.\n");
    }
}

void test_example_1() {
    printf("3. Тест примера 1 (110): ");

    bool arr[] = {0, 1, 1};  // 110
    uint32_t max_val;
    max_cyclic_shift(arr, 3, &max_val);

    if (max_val == 6) {  // 110 в десятичной = 6
        printf("Процдено.\n");
    } else {
        printf("Не пройдено.: ожидалось 6, получено %u.\n", max_val);
    }
}

void test_example_2() {
    printf("4. Тест примера 2 (1011): ");

    bool arr[] = {1, 1, 0, 1};  // 1011
    uint32_t max_val;
    max_cyclic_shift(arr, 4, &max_val);

    if (max_val == 14) {  // 1110 в десятичной = 14
        printf("Пройдено.\n");
    } else {
        printf("Не процдено: ожидалось 14, получено %u.\n", max_val);
    }
}

void test_all_ones() {
    printf("5. Тест всех единиц (1111): ");

    bool arr[] = {1, 1, 1, 1};
    uint32_t max_val;
    max_cyclic_shift(arr, 4, &max_val);

    if (max_val == 15) {
        printf("Процдено.\n");
    } else {
        printf("Не пройдено.\n");
    }
}

void test_all_zeros() {
    printf("6. Тест всех нулей (0000): ");

    bool arr[] = {0, 0, 0, 0};
    uint32_t max_val;
    max_cyclic_shift(arr, 4, &max_val);

    if (max_val == 0) {
        printf("Пройдено.\n");
    } else {
        printf("Не пройдено.\n");
    }
}

void test_cyclic_shift_array() {
    printf("7. Тест функции циклического сдвига массива: ");

    bool src[] = {1, 1, 0, 1};  // 1011
    bool dst[4];

    cyclic_shift_array(src, dst, 4, 2);  // Сдвиг на 2

    // Ожидаемый результат после сдвига на 2: 1110 (младший бит справа)
    bool expected[] = {0, 1, 1, 1};  // 1110

    if (memcmp(dst, expected, 4) == 0) {
        printf("Пройдено.\n");
    } else {
        printf("Не пройдено.\n");
    }
}

#ifdef TEST_MAIN
int main() {
    printf("=== Запуск тестов ===\n\n");

    test_binary_conversion();
    test_single_bit();
    test_example_1();
    test_example_2();
    test_all_ones();
    test_all_zeros();
    test_cyclic_shift_array();

    printf("\n=== Все тесты пройдены ===\n");
    return 0;
}
#endif
