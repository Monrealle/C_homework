#include "binary.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int main()
{
    printf("=== Двоичное представление === \n");

    // Ввод чисел
    char char_input_numbers[100];
    int int_input_numbers[100];

    printf("\n");
    printf("Ведите число от 0 до 1023 для перевода в двоичный вид\n");
    printf("Введите два числа, сумма которых не превышает 1023, чтобы получить "
           "их сумму в двоичном представлении\n");
    printf("\n");
    fgets(char_input_numbers, sizeof(char_input_numbers), stdin);
    int len_numbers = strlen(char_input_numbers);

    for (int i = 0; i < len_numbers; i++)
    {
        if (char_input_numbers[i] >= '0' && char_input_numbers[i] <= '9')
        {
            int_input_numbers[i] = char_input_numbers[i] - '0';
        }
        else
        {
            int_input_numbers[i] = -1;
        }
    }

    int num_1 = 0, num_2 = 0;
    int count = 0, operations = 0;

    for (int i = 0; i < len_numbers; i++)
    {
        if (int_input_numbers[i] != -1)
        {
            count++;
        }

        else
        {
            if (count > 0 && num_1 == 0)
            {
                while (count != 0)
                {
                    operations
                        = int_input_numbers[i - count] * power(count - 1, 10);
                    num_1 = num_1 + operations;
                    count--;
                }
                continue;
            }

            else if (count > 0 && num_2 == 0)
            {
                while (count != 0)
                {
                    operations
                        = int_input_numbers[i - count] * power(count - 1, 10);
                    num_2 = num_2 + operations;
                    count--;
                }
            }

            else
            {
                printf("Ошибка. Введите только два числа через пробел\n");
                break;
            }
        }
    }

    printf("\n");
    printf("Введены числа %d и %d \n", num_1, num_2);

    int number_1_translation, number_2_translation, binary_1_translation,
        binary_2_translation, column_addition, column_addition_translation;

    // Перевод чисел в двоичное представление
    if (num_1 < 1024 && num_2 < 1024)
    {
        printf("- Перевод числа в двоичное представление\n");
        number_1_translation = binary_representation(num_1);
        number_2_translation = binary_representation(num_2);
        printf("Число %d в двоичном представлении: %d\n", num_1,
            number_1_translation);
        printf("Число %d в двоичном представлении: %d\n", num_2,
            number_2_translation);
        printf("\n");
    }

    else
    {
        printf("Ошибка. Число больше 1023 будут содержать 11 и более битов, "
               "что выходит за рамки предусмотренного формата\n");
        return 0;
    }

    // Сложение в столбик в двоичном представлении, сумма
    printf("- Сложение в столбик в двоичном представлении\n");
    if (num_1 + num_2 > 1023)
    {
        printf("Ошибка. Числа в сумме дают больше 1023 и будут содержать 11 и "
               "более битов, что выходит за рамки предусмотренного формата\n");
        printf("\n");
    }

    else
    {
        column_addition
            = binary_addition(number_1_translation, number_2_translation);
        printf("Сложение %d и %d в столбик: %d\n", number_1_translation,
            number_2_translation, column_addition);
        printf("\n");
    }

    // Перевод в десятичное число
    printf("- Перевод в десятичное число\n");
    binary_1_translation = decimal_representation(number_1_translation);
    binary_2_translation = decimal_representation(number_2_translation);
    column_addition_translation = decimal_representation(column_addition);
    printf("Число %d в десятичном представлении: %d\n", number_1_translation,
        binary_1_translation);
    printf("Число %d в десятичном представлении: %d\n", number_2_translation,
        binary_2_translation);
    if (num_1 + num_2 < 1023)
    {
        printf("Сумма %d в десятичном представлении: %d\n", column_addition,
            column_addition_translation);
    }

    printf("\n \n");

    return 0;
}

