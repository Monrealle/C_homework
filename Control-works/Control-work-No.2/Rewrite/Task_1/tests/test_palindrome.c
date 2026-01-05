#include "../include/palindrome.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Вспомогательная функция для создания списка из массива
Node *create_list_from_array(int arr[], int size) {
  Node *head = NULL;
  for (int i = 0; i < size; i++) {
    head = append_node(head, arr[i]);
  }
  return head;
}

void test_empty_list() {
  printf("1. Тест пустого списка: ");
  Node *head = NULL;
  bool result = is_palindrome(head);

  if (result == true) {
    printf("Пройдено.\n");
  }

  else {
    printf("Не пройдено (ожидалось true, получено %s)\n",
           result ? "true" : "false");
  }

  free_list(head);
}

void test_single_element() {
  printf("2. Тест одного элемента: ");
  Node *head = create_node(42);
  bool result = is_palindrome(head);

  if (result == true) {
    printf("Пройдено.\n");
  }

  else {
    printf("Не пройдено.\n");
  }

  free_list(head);
}

void test_even_palindrome() {
  printf("3. Тест четного палиндрома (1 2 2 1): ");
  int arr[] = {1, 2, 2, 1};
  Node *head = create_list_from_array(arr, 4);
  bool result = is_palindrome(head);

  if (result == true) {
    printf("Пройдено.\n");
  }

  else {
    printf("Не пройдено.\n");
  }

  free_list(head);
}

void test_odd_palindrome() {
  printf("4. Тест нечетного палиндрома (1 2 3 2 1): ");
  int arr[] = {1, 2, 3, 2, 1};
  Node *head = create_list_from_array(arr, 5);
  bool result = is_palindrome(head);

  if (result == true) {
    printf("Пройдено.\n");
  }

  else {
    printf("Не пройдено.\n");
  }

  free_list(head);
}

void test_not_palindrome() {
  printf("5. Тест не палиндрома (1 2 3 4): ");
  int arr[] = {1, 2, 3, 4};
  Node *head = create_list_from_array(arr, 4);
  bool result = is_palindrome(head);

  if (result == false) {
    printf("Пройдено.\n");
  }

  else {
    printf("Не прлйдено.\n");
  }

  free_list(head);
}

void test_long_palindrome() {
  printf("6. Тест длинного палиндрома: ");
  int arr[] = {10, 20, 30, 40, 50, 40, 30, 20, 10};
  Node *head = create_list_from_array(arr, 9);
  bool result = is_palindrome(head);

  if (result == true) {
    printf("Прлйдено.\n");
  }

  else {
    printf("Не пройдено.\n");
  }

  free_list(head);
}

void test_not_palindrome2() {
  printf("7. Тест из задания (10 20 30 40 20 10): ");
  int arr[] = {10, 20, 30, 40, 20, 10};
  Node *head = create_list_from_array(arr, 6);
  bool result = is_palindrome(head);

  if (result == false) {
    printf("Пройдено.\n");
  }

  else {
    printf("Не прлйдно.\n");
  }

  free_list(head);
}

void test_all_identical() {
  printf("8. Тест всех одинаковых элементов (5 5 5 5): ");
  int arr[] = {5, 5, 5, 5};
  Node *head = create_list_from_array(arr, 4);
  bool result = is_palindrome(head);

  if (result == true) {
    printf("Пройдено.\n");
  }

  else {
    printf("Не пройдено.\n");
  }

  free_list(head);
}

#ifdef TEST_MAIN
int main() {
  printf("=== Запуск тестов ===\n\n");

  test_empty_list();
  test_single_element();
  test_even_palindrome();
  test_odd_palindrome();
  test_not_palindrome();
  test_long_palindrome();
  test_not_palindrome2();
  test_all_identical();

  printf("\n=== Все тесты завершены ===\n");
  return 0;
}

#endif
