#include <stdio.h>

int num_digs(int n, int radix)
{
    int c = 0;
    if (n == 0)
        return 1; // Добавим обработку нуля
    while (n > 0)
    {
        c++;
        n = n / radix;
    }
    return c;
}

int main(void)
{
    int number;
    int digits[6];
    printf("Введите шестизначное число:\n");
    scanf("%i", &number);

    if (num_digs(number, 10) != 6)
    {
        printf("Число должно быть шестизначным.\n");
        return 1;
    }

    int temp = number;
    for (int i = 5; i >= 0; i--)
    {
        digits[i] = temp % 10;
        temp /= 10;
    }

    int sum_1 = digits[0] + digits[1] + digits[2];
    int sum_2 = digits[3] + digits[4] + digits[5];

    if (sum_1 == sum_2)
    {
        printf("Билет является счастливым\n");
    }

    else
    {
        printf("Билет не является счастливым\n");
    }

    return 0;
}