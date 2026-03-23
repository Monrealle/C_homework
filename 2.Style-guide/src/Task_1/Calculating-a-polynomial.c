#include <stdio.h>

int main(void)
{
    int number;
    printf("Введите число x: \n");
    scanf("%i", &number);

    int square_x = number * number;
    int result = (square_x + 1) * (square_x + number) + 1;
    printf("Результат: %i\n", result);

    return 0;
}