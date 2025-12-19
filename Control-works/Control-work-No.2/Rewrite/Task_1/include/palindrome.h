#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Функции для работы со списком

/**
 * Создает новый узел списка
 * - param: data Значение для узла
 * - return: Указатель на созданный узел или NULL при ошибке
 */
Node* create_node(int data);

/**
 * Добавляет элемент в конец списка
 * - param: head Указатель на начало списка
 *          data Значение для добавления
 * - return: Указатель на начало списка
 */
Node* append_node(Node* head, int data);

/**
 * Освобождает память, занятую списком
 * - param: head Указатель на начало списка
 */
void free_list(Node* head);

/**
 * Печатает элементы списка
 * - param: head Указатель на начало списка
 */
void print_list(Node* head);

/**
 * Проверяет, является ли список палиндромом
 * - param: head Указатель на начало списка
 * - return: true если список палиндром
 *           false в противном случае
 */
bool is_palindrome(Node* head);

/**
 * Реверсирует список
 * - param: head Указатель на начало списка
 * - return: Указатель на начало реверсированного списка
 */
Node* reverse_list(Node* head);

/**
 * Сравнивает два списка на равенство
 * - param: list1 - первый список
 *          list2 - второй список
 * - return: true если списки равны
 *           false в противном случае
 */
bool compare_lists(Node* list1, Node* list2);

#endif // PALINDROME_H
