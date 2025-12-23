#include <stdio.h>

void selection_sort(int array[], int length)
{
    for (int n = 0; n < length - 1; n++)
    {
        int min = n;
        for (int j = n + 1; j < length; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }

        int temp = array[n];
        array[n] = array[min];
        array[min] = temp;
    }
}

int main(void)
{
    int arr[10] = {124, 828, 643, 820, 572, 5735, 5902, 55, 90, 12};
    int l = sizeof(arr) / sizeof(arr[0]);



    selection_sort(arr, l);

    for (int i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
