#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *text = NULL;
    size_t buffer_size = 0;
    int balance = 0;
    int i;

    printf("Введите текст: ");
    size_t chars_read = getline(&text, &buffer_size, stdin);

    if (chars_read <= 0) {
        printf("Ошибка ввода\n");
        free(text);
        return 1;
    }

    // Удаляем символ новой строки
    if (chars_read > 0 && text[chars_read - 1] == '\n') {
        text[chars_read - 1] = '\0';
        chars_read--;
    }

    size_t length = chars_read;

    // Проверяем баланс скобок
    int error = 0;
    for (i = 0; i < length; i++)
    {
        if (text[i] == '(')
        {
            balance++;
        }
        else if (text[i] == ')')
        {
            balance--;
            if (balance < 0)
            {
                error = 1;
                break;
            }
        }
    }

    // Выводим результат
    if (!error && balance == 0)
    {
        printf("Баланс скобок соблюден\n");
    }

    else if (balance > 0)
    {
        printf("Не хватает %d закрывающих скобок\n", balance);
    }

    else
    {
        printf("Нарушена вложенность скобок\n");
    }

    free(text);
    return 0;
}
