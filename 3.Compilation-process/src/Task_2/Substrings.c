#include <stdio.h>
#include <string.h>

int main()
{
    char text_1[100];
    char text_2[100];
    int count = 0;

    printf("Введите строку: ");
    fgets(text_1, sizeof(text_1), stdin);

    // Удаляем символ новой строки
    size_t len1 = strlen(text_1);
    if (len1 > 0 && text_1[len1 - 1] == '\n')
    {
        text_1[len1 - 1] = '\0';
        len1--;
    }

    printf("Введите подстроку: ");
    fgets(text_2, sizeof(text_2), stdin);

    // Удаляем символ новой строки
    size_t len2 = strlen(text_2);
    if (len2 > 0 && text_2[len2 - 1] == '\n')
    {
        text_2[len2 - 1] = '\0';
        len2--;
    }

    // Если подстрока пустая, выводим 0
    if (len2 == 0)
    {
        printf("Количество вхождений: 0\n");
        return 0;
    }

    // Проверяем все возможные позиции начала подстроки
    for (int i = 0; i <= (int)(len1 - len2); i++)
    {
        int match = 1;

        // Сравниваем символы вручную
        for (int j = 0; j < len2; j++)
        {
            if (text_1[i + j] != text_2[j])
            {
                match = 0;
                break;
            }
        }

        if (match)
        {
            count++;
        }
    }

    printf("Количество вхождений: %d\n", count);
    return 0;
}
