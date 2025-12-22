#include <stdio.h>

int main() {
    int lucky_count = 0;
    
    for (int num = 0; num < 1000000; num++) {
        int part1 = num / 1000;        // Первые три цифры
        int part2 = num % 1000;        // Последние три цифры
        
        // Считаем суммы цифр для каждой части
        int sum1 = (part1 / 100) + ((part1 / 10) % 10) + (part1 % 10);
        int sum2 = (part2 / 100) + ((part2 / 10) % 10) + (part2 % 10);
        
        if (sum1 == sum2) {
            lucky_count++;
        }
    }
    
    printf("Общее количество шестизначных счастливых билетов: %d\n", lucky_count);
    
    return 0;
}
