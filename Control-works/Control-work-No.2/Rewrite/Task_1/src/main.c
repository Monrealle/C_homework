#include "../include/palindrome.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Node* head = NULL;
    int number;

    printf("=== \"Опять палиндром\"  ===\n");
    printf("Вводите натуральные числа по одному через пробел\n");
    printf("(0 для окончания ввода):\n");

    while (1) {
        printf("> ");
        if (scanf("%d", &number) != 1) {
            printf("Ошибка ввода. Пожалуйста, введите число.\n");

            // Очищаем буфер ввода
            while (getchar() != '\n');
            continue;
        }

        if (number == 0) {
            break;
        }

        if (number < 0) {
            printf("Пожалуйста, вводите только натуральные числа (положительные).\n");
            continue;
        }

        head = append_node(head, number);

        if (head == NULL) {
            printf("Ошибка: не удалось добавить элемент в список.\n");
            return 1;
        }
    }

    if (head == NULL) {
        printf("Список пуст.\n");
        return 0;
    }

    printf("\nПолученный список: ");
    print_list(head);

    if (is_palindrome(head)) {
        printf("Список является палиндромом.\n");
    }

    else {
        printf("Список не является палиндромом.\n");
    }

    // Освобождаем память
    free_list(head);

    return 0;
}
