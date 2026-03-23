#include <stdio.h>

int main(void)
{
    int number_m;
    int number_n;
    printf("Введите число m (До 10000)\n");
    scanf("%i", &number_m);
    printf("Введите число n (До 10000)\n");
    scanf("%i", &number_n);

    if(number_n < number_m)
    {
        printf("Ошибка: число m больше числа n\n");
    }

    else
    {

        int numbers[10000];
        int total = number_m + number_n;

        for (int i = 0; i <= total; i++) 
        {
            numbers[i] = i;
        }

        for (int i = 0; i <= number_n/2; i++) 
        {
            int temp = numbers[i];
            numbers[i] = numbers[number_n-i];
            numbers[number_n-i] = temp;
        }
    
        int segment_size = number_n - number_m + 1;
        for (int i = 0; i < segment_size/2; i++) 
        {
            int temp = numbers[i];
            numbers[i] = numbers[segment_size-1-i];
            numbers[segment_size-1-i] = temp;
        }
            
        for (int i = 0; i < number_m/2; i++) 
        {
            int temp = numbers[segment_size+i];
            numbers[segment_size+i] = numbers[number_n-i];
            numbers[number_n-i] = temp;
        }
            
        printf("\nПосле: ");
        for (int i = 0; i <= number_n; i++) 
        {
            printf("%d ", numbers[i]);
        }
        
        printf("\n");
    }

    return 0; 


}