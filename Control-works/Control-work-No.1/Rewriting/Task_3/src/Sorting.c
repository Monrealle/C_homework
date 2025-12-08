#include <stdio.h>

// Функция для обмена двух элементов
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Гномья сортировка
void gnomeSort(int arr[], int n) {
  int i = 1, j = 2;

  while (i < n) {
    if (arr[i - 1] <= arr[i]) { // Если элементы в правильном порядке
      i = j;
      j = j + 1;
    } else { // Если элементы в неправильном порядке
      swap(&arr[i - 1], &arr[i]);
      i = i - 1;
      if (i == 0) {
        i = j;
        j = j + 1;
      }
    }
  }
}

// Функция для вывода массива
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {4, 2, 10, 7, 3, 1, 9, 6, 5, 8};
  int length = sizeof(arr) / sizeof(arr[0]);

  printf("Исходный массив: ");
  printArray(arr, length);

  // Копируем массив для двух разных сортировок
  int arr1[length];
  for (int i = 0; i < length; i++) {
    arr1[i] = arr[i];
  }

  gnomeSort(arr1, length);
  printf("Отсортированый массив: ");
  printArray(arr1, length);

  return 0;
}
