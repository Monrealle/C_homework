#include "../include/cyclic_shift.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_BITS 32

int main() {
    int n;
    bool arr[MAX_BITS];

    printf("=== \"Циклический сдвиг\"  ===\n\n");

    // Ввод длины числа
    while (1) {
        printf("Введите длину двоичного числа (1-%d): ", MAX_BITS);
        if (scanf("%d", &n) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите число.\n");
            while (getchar() != '\n');  // Очистка буфера
            continue;
        }

        if (n >= 1 && n <= MAX_BITS) {
            break;
        }
        printf("Длина должна быть от 1 до %d.\n", MAX_BITS);
    }

    // Ввод битов
    printf("Введите %d битов (через пробел, 0 или 1): ", n);
    for (int i = n - 1; i >= 0; i--) {
        int bit;
        if (scanf("%d", &bit) != 1) {
            printf("Ошибка ввода бита.\n");
            return 1;
        }

        if (bit != 0 && bit != 1) {
            printf("Биты должны быть 0 или 1.\n");
            return 1;
        }

        arr[i] = (bit == 1);
    }

    printf("\nИсходное двоичное число: ");
    print_binary_array(arr, n);

    uint32_t original_value = binary_array_to_uint(arr, n);
    printf(" (%u в десятичной)\n\n", original_value);

    // Алгоритм с массивом
    uint32_t max_array_value;
    int array_shift = max_cyclic_shift_array(arr, n, &max_array_value);

    // Алгоритм с битами
    printf("Результаты:\n");
    printf("1. Алгоритм с массивом: \n");
    printf("   Максимальное число: ");

    bool max_arr[MAX_BITS];
    cyclic_shift_array(arr, max_arr, n, array_shift);
    print_binary_array(max_arr, n);
    printf(" (%u)\n", max_array_value);
    printf("   Сдвиг: %d позиции(й)\n\n", array_shift);

    // Дополнительная информация
    printf("\nВсе циклические сдвиги:\n");
    for (int k = 0; k < n; k++) {
        uint32_t shifted = cyclic_shift_left(original_value, n, k);
        printf("  Сдвиг %2d: ", k);
        uint_to_binary_array(shifted, max_arr, n);
        print_binary_array(max_arr, n);
        printf(" = %u", shifted);

        if (k == array_shift) {
            printf(" ← МАКСИМУМ");
        }
        printf("\n");
    }

    return 0;
}
