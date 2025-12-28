#include <stdio.h>

extern int sort(int* array, int count);

int main(void)
{
    int array[100];
    int count = 0;

    while (count < 100 && scanf("%d", &array[count]) == 1)
    {
        count++;
    }

    int asembler = sort(array, count);

    return asembler;
}
