#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head = NULL;

// Функция для вставки значения
void add_value(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL || head->value >= value) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Функция удаления значения
void remove_value(int value) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    Node* temp;
    if (head->value == value) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Значение %d удалено\n", value);
        return;
    }

    Node* current = head;
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Значение %d не найдено\n", value);
        return;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("Значение %d удалено\n", value);
}

void print_list() {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    Node* current = head;
    printf("Список: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Функция освобождения памяти
void free_list() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    int choice, value;
    int input_count;

    do {
        printf("\nМеню:\n");
        printf("0 - Выйти\n");
        printf("1 - Добавить значение\n");
        printf("2 - Удалить значение\n");
        printf("3 - Распечатать список\n");
        printf("Выбор: ");

        input_count = scanf("%d", &choice);
        
        if (input_count != 1) {
            printf("Ошибка: введите число от 0 до 3\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 0:
                free_list();
                printf("Выход\n");
                break;
            case 1:
                printf("Введите значение для добавления: ");
                if (scanf("%d", &value) != 1) {
                    printf("Ошибка: введите целое число\n");
                    clear_input_buffer();
                } else {
                    add_value(value);
                }
                break;
            case 2:
                printf("Введите значение для удаления: ");
                if (scanf("%d", &value) != 1) {
                    printf("Ошибка: введите целое число\n");
                    clear_input_buffer();
                } else {
                    remove_value(value);
                }
                break;
            case 3:
                print_list();
                break;
            default:
                printf("Введите число от 0 до 3\n");
        }
    } while (choice != 0);

    return 0;
}