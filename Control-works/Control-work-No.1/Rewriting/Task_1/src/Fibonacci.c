#include <stdio.h>

int main() {
  int num1 = 1, num2 = 1, result = 0, sum = 0;

  for (int i = 0; result <= 1000000; i++) {
    result = num1 + num2;
    num1 = num2;
    num2 = result;

    if (result % 2 == 0) {
      sum = sum + result;
    }
  }

  printf("Сумма чётных чисел Фибоначчи, не превосходящих миллиона: %d", sum);
}
