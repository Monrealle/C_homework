#include <stdio.h>

int main(void)
{
    char text[100];
    int length = sizeof(text) / sizeof(text[0]);
    int balance = 0;

    printf("Введите текст\n");
    fgets(text, sizeof(text), stdin);

    for (int number = 0; number < length; number++)
    {
        if (text[number] == '(')
        {
            balance++;
        }

        if (text[number] == ')')
        {
            balance--;

            if (balance < 0)
            {
                printf("Нарушена вложенность скобок\n");
                break;
            }
        }
    }

    if (balance == 0)
    {
        printf("Количество скобок одинаково\n");
    }

    else if (balance > 1)
    {
        printf("Нехватает закрывающихся скобок\n");
    }

    return 0;
}
