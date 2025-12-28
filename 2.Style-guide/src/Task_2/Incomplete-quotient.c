#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long a, b;
    
    // Ввод данных
    printf("Введите делимое: ");
    if (scanf("%lld", &a) != 1) {
        printf("Ошибка ввода делимого\n");
        return 1;
    }
    
    printf("Введите делитель: ");
    if (scanf("%lld", &b) != 1) {
        printf("Ошибка ввода делителя\n");
        return 1;
    }
    
    // Проверка деления на ноль
    if (b == 0) {
        printf("Ошибка: деление на ноль\n");
        return 1;
    }
    
    long long quotient = 0;      // Неполное частное
    long long remainder;         // Остаток
    
    // Приведение к случаю с положительным делителем
    // Это упрощает логику вычислений
    if (b < 0) {
        a = -a;
        b = -b;
    }
    
    // Теперь b всегда положительное
    if (a >= 0) {
        // a положительное или ноль
        remainder = a;
        while (remainder >= b) {
            remainder = remainder - b;
            quotient = quotient + 1;
        }
    } else {
        // a отрицательное
        remainder = a;
        while (remainder < 0) {
            remainder = remainder + b;
            quotient = quotient - 1;
        }
    }
    
    // Вывод результата
    printf("Неполное частное: %lld\n", quotient);
    printf("Остаток: %lld\n", remainder);
    
    // Проверка результата (можно закомментировать)
    printf("Проверка: %lld = %lld * %lld + %lld\n", 
           a >= 0 ? a : -a, b, quotient, a >= 0 ? remainder : -remainder);
    
    return 0;
}
