#include <stdio.h>

int main(void)
{
    char arr[10] = { 1, 2, 3, 4, 15, 22 }; // для проверки
    int length = sizeof(arr) / sizeof(arr[0]);
    int zeros = 0;

    for (int number = 0; number < length; number++)
    {
        if (arr[number] == 0)
        {
            zeros++;
        }
    }

    printf("Количество нулевых элементов: %d\n", zeros);
    return 0;
}
