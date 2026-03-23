#include "../include/palindrome.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    fprintf(stderr, "Ошибка выделения памяти\n");
    return NULL;
  }

  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

Node *append_node(Node *head, int data) {
  Node *new_node = create_node(data);
  if (new_node == NULL) {
    return head;
  }

  if (head == NULL) {
    return new_node;
  }

  Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
  return head;
}

void free_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
}

void print_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

Node *reverse_list(Node *head) {
  Node *prev = NULL;
  Node *current = head;
  Node *next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;
}

bool compare_lists(Node *list1, Node *list2) {
  while (list1 != NULL && list2 != NULL) {
    if (list1->data != list2->data) {
      return false;
    }
    list1 = list1->next;
    list2 = list2->next;
  }

  // Оба списка должны быть пустыми одновременно
  return (list1 == NULL && list2 == NULL);
}

bool is_palindrome(Node *head) {
  if (head == NULL || head->next == NULL) {
    return true; // Пустой список или один элемент - палиндром
  }

  // Находим середину списка
  Node *slow = head;
  Node *fast = head;
  Node *prev_slow = NULL;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    prev_slow = slow;
    slow = slow->next;
  }

  // Если количество элементов нечетное, пропускаем средний элемент
  Node *second_half = slow;
  if (fast != NULL) {
    second_half = slow->next;
  }

  // Разделяем список на две части
  if (prev_slow != NULL) {
    prev_slow->next = NULL;
  }

  // Реверсируем вторую половину
  Node *reversed_second_half = reverse_list(second_half);

  // Сравниваем две половины
  bool result = compare_lists(head, reversed_second_half);

  // Восстанавливаем оригинальный список
  Node *original_second_half = reverse_list(reversed_second_half);
  if (prev_slow != NULL) {
    prev_slow->next = original_second_half;
  }

  return result;
}
