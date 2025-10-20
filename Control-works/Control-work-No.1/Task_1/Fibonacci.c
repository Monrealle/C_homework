#include <stdio.h>



int fibonacci(int count)
{
    int a = 1;
    int b = 1;
    int c = 0;
    int n = 3;

    while(n <= count)
    {
        c = a + b;
       	a = b;
        b = c;
       	n++;
    }

    return c;
}


int main(void)
{
    int number;

    printf("Введите n: ");
    scanf("%d", &number);

    if (number < 0)
    {
	printf("Число n не должно быть отритцательнвм\n");
    }

    else if (number == 0)
    {
	printf("Нулевого числа Фибоначи не существует\n");
    }

    else if (number == 1 | number == 2)
    {
	printf("Число %d: 1\n", number);
    }

    else
    {
	if (number >= 47)
        {
	    printf("Результат ниже может быть аномальным из-за использования типа int:\n");
        }

	int result = fibonacci(number);
	printf("Число %d: %d\n", number, result);
    }

    return 0;
}


