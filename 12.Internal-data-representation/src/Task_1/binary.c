#include "binary.h"
#include <limits.h>
#include <stdio.h>

// Функция для вычисления степени числа
int power(int degree, int number)
{
    int result = 1;

    if (degree == 0)
    {
        return result;
    }

    for (int i = 0; i < degree; i++)
    {
        result = result * number;
    }

    return result;
}

// Функция для нахождения длины переменной типа int
int length_int(int number)
{
    int count = 0;

    if (number == 0)
    {
        return 1;
    }

    while (number != 0)
    {
        number = number / 10;
        count++;
    }

    return count;
}

// Функция для перевода числа в двоичное представление
int binary_representation(int number)
{
    int binary[64];
    int intermediate = 0, result = 0, i = 0;
    int bits = 16;

    // Если число 0
    if (number == 0)
    {
        printf("0");
        return 0;
    }

    if (number > 1023)
    {
        printf("Внимание, число больше 1023, результат неправельный, введите "
               "число меньше либо равное 1023\n");
        return 0;
    }

    int original_number = number;

    // Обрабатываем отрицательные числа
    if (number < 0)
    {
        unsigned int temp = -number;

        i = 0;
        while (temp > 0)
        {
            binary[i] = temp % 2;
            temp = temp / 2;
            i++;
        }

        while (i < bits)
        {
            binary[i] = 0;
            i++;
        }

        for (int j = 0; j < bits; j++)
        {
            if (binary[j] == 0)
            {
                binary[j] = 1;
            }
            else if (binary[j] == 1)
            {
                binary[j] = 0;
            }
        }

        int carry = 1;
        for (int j = 0; j < bits; j++)
        {
            int sum = binary[j] + carry;
            binary[j] = sum % 2;
            carry = sum / 2;
            if (carry == 0)
                break;
        }
    }

    // Обрабатываем положительные числа
    else if (number > 0)
    {
        i = 0;
        while (number > 0)
        {
            binary[i] = number % 2;
            number = number / 2;
            i++;
        }

        while (i < bits)
        {
            binary[i] = 0;
            i++;
        }
    }

    // Собираем результат
    for (int j = i - 1; j >= 0; j--)
    {
        intermediate = binary[j] * power(j, 10);
        result = result + intermediate;
    }

    return result;
}

// Функция для перевода бинарного числа в десятичное
int decimal_representation(int binary)
{
    int result = 0;
    int temp = binary;
    int len = length_int(binary);

    // Проверка на корректность двоичного числа
    for (int i = 0; i < len; i++)
    {
        int digit = temp % 10;
        if (digit > 1)
        {
            printf("Ошибка: число %d не является двоичным!\n", binary);
            return -1;
        }
        temp = temp / 10;
    }

    // Преобразование
    for (int i = 0; i < len; i++)
    {
        int digit = binary % 10;
        result += digit * power(i, 2);
        binary = binary / 10;
    }

    return result;
}

// Функция для сложения в столбик в двоичном представлении
int binary_addition(int binary_1, int binary_2)
{
    int length_1 = length_int(binary_1);
    int length_2 = length_int(binary_2);
    int final_length = 0;

    if (length_1 > length_2)
    {
        final_length = length_1;
    }
    else
    {
        final_length = length_2;
    }

    // Создаем массивы с дополнительным местом для возможного переноса
    int arr_1[final_length + 1];
    int arr_2[final_length + 1];
    int arr_sum[final_length + 2];

    // Инициализируем массивы нулями
    for (int i = 0; i <= final_length; i++)
    {
        arr_1[i] = 0;
        arr_2[i] = 0;
    }

    // Заполняем массивы с конца
    int index_1 = final_length;
    int temp_1 = binary_1;
    while (temp_1 > 0)
    {
        arr_1[index_1] = temp_1 % 10;
        temp_1 /= 10;
        index_1--;
    }

    int index_2 = final_length;
    int temp_2 = binary_2;
    while (temp_2 > 0)
    {
        arr_2[index_2] = temp_2 % 10;
        temp_2 /= 10;
        index_2--;
    }

    // Выполняем сложение с переносом
    int carry = 0;
    int sum_index = final_length + 1;

    for (int i = final_length; i >= 0; i--)
    {
        int bit_sum = arr_1[i] + arr_2[i] + carry;

        if (bit_sum == 0)
        {
            arr_sum[sum_index] = 0;
            carry = 0;
        }
        else if (bit_sum == 1)
        {
            arr_sum[sum_index] = 1;
            carry = 0;
        }
        else if (bit_sum == 2)
        {
            arr_sum[sum_index] = 0;
            carry = 1;
        }
        else
        {
            arr_sum[sum_index] = 1;
            carry = 1;
        }
        sum_index--;
    }

    // Обрабатываем оставшийся перенос
    if (carry == 1)
    {
        arr_sum[sum_index] = 1;
    }
    else
    {
        arr_sum[sum_index] = 0;
    }

    // Преобразуем массив обратно в число
    int result = 0;
    int start_index = (arr_sum[0] == 0 && final_length > 0) ? 1 : 0;

    for (int i = start_index; i <= final_length + 1; i++)
    {
        result = result * 10 + arr_sum[i];
    }

    return result;
}

