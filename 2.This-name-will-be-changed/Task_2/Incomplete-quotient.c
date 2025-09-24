#include <stdio.h>

int main(void)
{
    int number_1, number_2;
    int result = 0;
    printf("Введите делимое: \n");
    scanf("%i", &number_1);
    printf("Введите делитель \n");
    scanf("%i", &number_2);
    int examination = number_1 % number_2;

    if(examination != 0)
    {
        if(number_2 > number_1)
        {
            printf("Делитель больше делимого\n");
        }

        else
        {
            
            while(number_1 >= number_2)
            {
                number_1 = number_1 - number_2;
                result += 1;
            }

            printf("Неполное частное: %d\n", result);
            printf("Остаток от деления %d\n", examination);
        }
    }

    else
    {
        number_1 = number_1 - number_2;
        result += 1;
        printf("Частное: %i\n", result);
    }

    return 0;
}