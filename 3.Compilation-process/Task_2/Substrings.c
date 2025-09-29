#include <stdio.h>
#include <string.h>

int main(void)
{
    char text_1[100];
    char text_2[100];
    int count = 0;

    printf("Введите строку\n");
    scanf("%99[^\n]", text_1);
    getchar();
    printf("Введите подстроку\n");
    scanf("%99[^\n]", text_2);
    getchar();

    int len_text_1 = strlen(text_1);
    int len_text_2 = strlen(text_2);

    for (int i = 0; i <= len_text_1 - len_text_2; i++) 
    {
        if (strncmp(&text_1[i], text_2, len_text_2) == 0) 
        {
            count++;
        }

    }

    printf("Количество вхождений: %d\n", count);
    return 0;
}
