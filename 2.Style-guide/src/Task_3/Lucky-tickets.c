#include <stdio.h>

int main()
{
    // Массив для подсчёта количества трёхзначных чисел с каждой суммой цифр
    int sums[28] = { 0 }; // Индексы от 0 до 27

    // Подсчитываем количество трёхзначных чисел (000-999)
    for (int num = 0; num < 1000; num++)
    {
        int digit1 = num / 100; // Первая цифра
        int digit2 = (num / 10) % 10; // Вторая цифра
        int digit3 = num % 10; // Третья цифра
        int sum = digit1 + digit2 + digit3;

        sums[sum]++;
    }

    int total_lucky = 0;
    for (int i = 0; i <= 27; i++)
    {
        total_lucky += sums[i] * sums[i];
    }

    printf(
        "Общее количество шестизначных счастливых билетов: %d\n", total_lucky);

    return 0;
}
