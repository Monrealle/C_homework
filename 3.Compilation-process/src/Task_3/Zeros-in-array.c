#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    printf("Введите %d элементов массива:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int zeros = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zeros++;
        }
    }

    printf("Количество нулевых элементов: %d\n", zeros);

    free(arr);
    return 0;
}
