#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

typedef struct Queue {
    List* f;  // Прямой порядок
    List* r;   // Обратный порядок
} Queue;

// Создать пустой список
List* list_create() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;

    return list;
}

// Проверить, пуст ли список
int list_is_empty(List* list) {

    return list->head == NULL;
}

// Добавить элемент в начало
List* list_cons(int value, List* list) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = list->head;

    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = node;

    return new_list;
}

// Получить первый элемент
int list_head(List* list) {

    return list->head->value;
}

// Получить хвост списка
List* list_tail(List* list) {
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = list->head->next;

    return new_list;
}

// Перевернуть список
List* list_reverse(List* list) {
    List* reversed = list_create();
    Node* current = list->head;

    while (current != NULL) {
        reversed = list_cons(current->value, reversed);
        current = current->next;
    }

    return reversed;
}

// Создать пустую очередь
Queue* queue_create() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->f = list_create();
    queue->r = list_create();

    return queue;
}

// Проверить, пуста ли очередь
int queue_is_empty(Queue* queue) {

    return list_is_empty(queue->f) && list_is_empty(queue->r);
}

// Добавить элемент в конец очереди
Queue* queue_enqueue(Queue* queue, int value) {
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->f = queue->f;
    new_queue->r = list_cons(value, queue->r);

    return new_queue;
}

// Удалить элемент из начала очереди
Queue* queue_dequeue(Queue* queue, int* value) {
    if (list_is_empty(queue->f)) {
        List* new_front = list_reverse(queue->r);
        *value = list_head(new_front);

        Queue* new_queue = (Queue*)malloc(sizeof(Queue));
        new_queue->f = list_tail(new_front);
        new_queue->r = list_create();

        return new_queue;
    }

    // Если front не пуст, просто берем из него
    *value = list_head(queue->f);

    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->f = list_tail(queue->f);
    new_queue->r = queue->r;

    return new_queue;
}

// Базовые операции со списком
void test_list_basic() {
    printf("Test: Базовые операции со списком\n");

    // Создание пустого списка
    List* empty = list_create();
    assert(list_is_empty(empty));

    // Добавление элемента
    List* one = list_cons(42, empty);
    assert(!list_is_empty(one));
    assert(list_head(one) == 42);

    printf("Test: Пройден\n");
}

// Главная функция
int main() {
    // Запуск тестов
    test_list_basic();

    return 0;
}
