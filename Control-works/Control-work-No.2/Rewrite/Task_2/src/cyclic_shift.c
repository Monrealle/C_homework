#include "../include/cyclic_shift.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

uint32_t binary_array_to_uint(const bool arr[], int n) {
    uint32_t result = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i]) {
            result |= (1u << i);  // Устанавливаем i-й бит
        }
    }

    return result;
}

void uint_to_binary_array(uint32_t value, bool arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (value >> i) & 1u;
    }
}

uint32_t cyclic_shift_left(uint32_t value, int n, int k) {
    if (n == 0) return 0;

    k = k % n;  // Нормализуем сдвиг

    // Маска для n битов
    uint32_t mask = (1u << n) - 1;

    // Циклический сдвиг влево
    uint32_t left_part = (value << k) & mask;
    uint32_t right_part = value >> (n - k);

    return left_part | right_part;
}

void cyclic_shift_array(const bool src[], bool dst[], int n, int k) {
    if (n == 0) return;

    k = k % n;  // Нормализуем сдвиг

    for (int i = 0; i < n; i++) {
        dst[(i + k) % n] = src[i];
    }
}

int max_cyclic_shift_array(const bool arr[], int n, uint32_t *max_value) {
    if (n <= 0 || arr == NULL || max_value == NULL) {
        return -1;
    }

    // Временный массив для хранения сдвинутого значения
    bool *shifted = (bool*)malloc(n * sizeof(bool));
    if (shifted == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return -1;
    }

    uint32_t max_val = 0;
    int best_shift = 0;

    // Проверяем все возможные сдвиги
    for (int k = 0; k < n; k++) {
        cyclic_shift_array(arr, shifted, n, k);
        uint32_t current = binary_array_to_uint(shifted, n);

        if (current > max_val) {
            max_val = current;
            best_shift = k;
        }
    }

    *max_value = max_val;
    free(shifted);
    return best_shift;
}
