#ifndef CYCLIC_SHIFT_H
#define CYCLIC_SHIFT_H

#include <stdbool.h>
#include <stdint.h>

/**
 * Находит максимальное число циклического сдвига (версия с массивом)
 * - param: arr Массив битов (младший бит - arr[0])
 *          n Длина массива (1 <= n <= 32)
 *          max_value Указатель для записи максимального значения
 * - return: Количество позиций сдвига для получения максимума
 */
int max_cyclic_shift_array(const bool arr[], int n, uint32_t *max_value);

/**
 * Преобразует массив битов в целое число
 * - param: arr Массив битов (младший бит - arr[0])
 *          n Длина массива
 * - return: Число в десятичной системе
 */
uint32_t binary_array_to_uint(const bool arr[], int n);

/**
 * Преобразует число в массив битов
 * - param: value Число для преобразования
 *          arr Массив для записи битов (должен быть достаточно большим)
 *          n Количество битов для преобразования
 */
void uint_to_binary_array(uint32_t value, bool arr[], int n);

/**
 * Выполняет циклический сдвиг массива влево на k позиций
 * - param: src Исходный массив
 *          dst Результирующий массив
 *          n Длина массива
 *          k Количество позиций сдвига
 */
void cyclic_shift_array(const bool src[], bool dst[], int n, int k);

/**
 * Печатает массив битов
 * - param: arr Массив битов
 *          n Длина массива
 */
void print_binary_array(const bool arr[], int n);

#endif // CYCLIC_SHIFT_H
