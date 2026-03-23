#include <stdio.h>
#include <string.h>

int main() {
  char str[1000];
  printf("Введите строку (на английском): ");
  fgets(str, sizeof(str), stdin);

  // Убираем символ новой строки
  str[strcspn(str, "\n")] = '\0';

  int left = 0;
  int right = strlen(str) - 1;
  int is_palindrome = 1;

  while (left < right) {
    // Пропускаем пробелы слева
    while (left < right && str[left] == ' ') {
      left++;
    }

    // Пропускаем пробелы справа
    while (left < right && str[right] == ' ') {
      right--;
    }

    // Если после пропуска пробелов указатели встретились - выходим
    if (left >= right) {
      break;
    }

    // Сравниваем символы с учетом регистра
    if (str[left] != str[right]) {
      is_palindrome = 0;
      break;
    }

    // Двигаем указатели к центру
    left++;
    right--;
  }

  if (is_palindrome) {
    printf("Строка является палиндромом.\n");
  } else {
    printf("Строка не является палиндромом.\n");
  }

  return 0;
}
