#include <stdio.h>

void reverse(int x[], int left, int right) {
    while (left < right) {
        int temp = x[left];
        x[left] = x[right];
        x[right] = temp;
        left++;
        right--;
    }
}

int main(void) {
    int m, n;
    printf("Введите m и n: ");
    scanf("%d %d", &m, &n);
    
    int size = m + n;
    int x[size]; // Теперь индексация от 0
    
    printf("Введите %d элементов:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &x[i]);
    }
    
    // Развернуть весь массив
    reverse(x, 0, size - 1);
    // Развернуть первые n элементов (бывший конец)
    reverse(x, 0, n - 1);
    // Развернуть последние m элементов (бывшее начало)
    reverse(x, n, size - 1);
    
    printf("Результат: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    
    return 0;
}
