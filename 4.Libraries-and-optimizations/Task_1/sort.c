#include <stdio.h>

int sort(int* array, int count)
{
    int original[100];
    int changed = 0;

    for (int i = 0; i < count; i++)
    {
        original[i] = array[i];
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (array[i] != original[i])
        {
            changed++;
        }
    }

    return changed;
}

