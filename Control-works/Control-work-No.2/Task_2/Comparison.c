#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Функция для сравнения двух двоичных чисел
int compare_binary_numbers(bool* num1, int len1, bool* num2, int len2) {
    // Находим первую 1 для каждого числа
    int start1 = 0;
    while (start1 < len1 && !num1[start1]) {
        start1++;
    }

    int start2 = 0;
    while (start2 < len2 && !num2[start2]) {
        start2++;
    }

    // Вычисляем реальную длину числа (без ведущих нулей)
    int real_len1 = len1 - start1;
    int real_len2 = len2 - start2;

    if (real_len1 == 0 && real_len2 == 0) {
        return 0; // 0 == 0
    }

    if (real_len1 == 0) {
        return -1; // num 1 < num2
    }

    if (real_len2 == 0) {
        return 1; // num1 > num2
    }

    if (real_len1 > real_len2) {
        return 1; // num1 > num2
    }

    if (real_len1 < real_len2) {
        return -1; // num1 < num2
    }

    // Если длины равны, сравниваем побитово
    for (int i = 0; i < real_len1; i++) {
        bool bit1 = num1[start1 + i];
        bool bit2 = num2[start2 + i];

        if (bit1 && !bit2) {
            return 1; // num1 > num2
        }

        if (!bit1 && bit2) {
            return -1; // num1 < num2
        }
    }

    return 0; // числа равны
}

// Функция для печати двоичного числа
void print_binary(bool* num, int len) {
    int start = 0;

    while (start < len && !num[start]) {
        start++;
    }

    if (start == len) {
        printf("0");
        return;
    }

    for (int i = start; i < len; i++) {
        printf("%d", num[i]);
    }
}

int main() {

    {
        bool num1[] = {1, 0, 1, 1};  // 1011 = 11
        bool num2[] = {1, 1, 0, 0};  // 1100 = 12

        int result = compare_binary_numbers(num1, 4, num2, 4);

        print_binary(num1, 4);
        printf("\n");
        print_binary(num2, 4);
        printf("\n");
        if (result > 0) {
            printf("Первое больше\n");
        }

        else if (result < 0) {
            printf("Второе больше\n");
        }

        else printf("Равны\n");
    }
}
