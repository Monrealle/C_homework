#include <stdint.h>
#include <stdio.h>

int main()
{
    union
    {
        double d;
        uint64_t u;
    } num;

    printf("Введите число: ");
    scanf("%lf", &num.d);

    // Извлекаем биты
    uint64_t bits = num.u;
    int sign = (bits >> 63) & 1;
    int exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;

    // Специальные случаи
    if (exponent == 0x7FF)
    {
        if (mantissa == 0)
        {
            printf("%cinf\n", sign ? '-' : '+');
        }

        else
        {
            printf("NaN\n");
        }
        return 0;
    }

    // Вычисляем порядок
    int power;
    if (exponent == 0)
    {
        if (mantissa == 0)
        {
            printf("%c0.0*2^0\n", sign ? '-' : '+');
            return 0;
        }
        power = -1022;
        while (!(mantissa & (1ULL << 51)))
        {
            mantissa <<= 1;
            power--;
        }
        mantissa <<= 1;
        mantissa &= 0xFFFFFFFFFFFFF;
    }

    else
    {
        power = exponent - 1023;
        mantissa |= 1ULL << 52;
    }

    // Выводим знак
    printf("%c1.", sign ? '-' : '+');

    // Выводим мантиссу с 20 знаками после запятой
    uint64_t remainder = mantissa & ((1ULL << 52) - 1);
    for (int i = 0; i < 20; i++)
    {
        remainder *= 10;
        printf("%lu", remainder >> 52);
        remainder &= (1ULL << 52) - 1;
    }

    printf("*2^%d\n", power);

    return 0;
}
