#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Введите делимое: ");
    scanf("%d", &a);
    printf("Введите делитель: ");
    scanf("%d", &b);

    if (b == 0)
    {
        printf("Ошибка: деление на ноль\n");
        return 1;
    }

    int quotient = 0;
    int temp_a = a; // Будем работать с этой переменной

    // Вычисляем неполное частное
    if (a >= 0 && b > 0)
    {
        // Оба положительные
        while (temp_a >= b)
        {
            temp_a = temp_a - b;
            quotient = quotient + 1;
        }
    }

    else if (a >= 0 && b < 0)
    {
        // a положительное, b отрицательное
        while (temp_a >= -b)
        {
            temp_a = temp_a
                + b; // вычитаем отрицательное = прибавляем положительное
            quotient = quotient
                - 1; // частное уменьшаем на 1 (результат отрицательный)
        }
    }

    else if (a < 0 && b > 0)
    {
        // a отрицательное, b положительное
        while (temp_a <= -b)
        {
            temp_a
                = temp_a + b; // прибавляем положительное (вычитаем по модулю)
            quotient = quotient - 1; // частное отрицательное
        }
    }

    else
    { // a < 0 && b < 0
        // Оба отрицательные
        while (temp_a <= b)
        {
            temp_a = temp_a
                - b; // вычитаем отрицательное = прибавляем положительное
            quotient = quotient + 1; // частное положительное
        }
    }

    if (temp_a > 0)
    {
        printf("Неполное частное: %d\n", quotient);
        printf("Остаток: %d\n", temp_a);
    }

    else
    {
        printf("Частное: %d\n", quotient);
        printf("Остаток: %d\n", temp_a);
    }

    return 0;
}
