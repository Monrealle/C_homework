#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

// Вспомогательные функции для тестов
int get_size() {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int has_value(int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void run_tests() {
    printf("Базовые тесты:\n");
    
    free_list();
    
    // Добавление одного элемента
    printf("1. Добавление одного элемента:\n");
    add_value(42);
    assert(get_size() == 1);
    printf("Успешно\n");
    
    // Добавление второго элемента
    printf("2. Добавление второго элемента:\n");
    add_value(10);
    assert(get_size() == 2);
    printf("Успешно\n");
    
    // Проверка сортировки
    printf("3. Проверка сортировки:\n");
    assert(head->value == 10); // 10 должно быть первым
    printf("Успешно\n");
    
    // Удаление элемента
    printf("4. Удаление элемента:\n");
    remove_value(42);
    assert(get_size() == 1);
    assert(!has_value(42)); // 42 не должно быть в списке
    printf("Успешно\n");
    
    // Удаление несуществующего элемента
    printf("5. Удаление несуществующего элемента: ");
    remove_value(999);
    assert(get_size() == 1); // Размер не должен измениться
    printf("Успешно\n\n");

    printf("Граничные случаи:\n");
    
    free_list();
    
    // Пустой список
    printf("6. Пустой список:\n");
    assert(get_size() == 0);
    printf("Успешно\n");
    
    // Удаление из пустого списка
    printf("7. Удаление из пустого списка: ");
    remove_value(10);
    assert(get_size() == 0);
    printf("Успешно\n");
    
    // Добавление одинаковых значений
    printf("8. Добавление одинаковых значений:\n");
    add_value(5);
    add_value(5);
    add_value(5);
    assert(get_size() == 3);
    printf("Успешно\n");
    
    // Удаление всех элементов
    printf("9. Удаление всех элементов:\n");
    remove_value(5);
    remove_value(5);
    remove_value(5);
    assert(get_size() == 0);
    printf("Успешно\n\n");

    printf("Тест сортировки:\n");
    
    free_list();
    
    printf("10. Проверка сортировки:\n");
    add_value(30);
    add_value(10);
    add_value(20);
    add_value(5);
    add_value(25);
    
    // Должно быть: 5, 10, 20, 25, 30
    assert(get_size() == 5);
    
    // Простая проверка: первое значение минимальное
    assert(head != NULL);
    assert(head->value == 5);
    
    // Проверяем, что значения в порядке возрастания
    struct Node* current = head;
    int prev = current->value;
    current = current->next;
    
    while (current != NULL) {
        assert(current->value >= prev); // Следующее >= предыдущего
        prev = current->value;
        current = current->next;
    }
    
    printf("Успешно\n");
}

int main(int argc, char *argv[]) {
    // Проверяем аргументы командной строки
    if (argc > 1) {
        // Если первый аргумент --test, запускаем тесты
        if (strcmp(argv[1], "--test") == 0) {
            run_tests();
            return 0;
        }
    }

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