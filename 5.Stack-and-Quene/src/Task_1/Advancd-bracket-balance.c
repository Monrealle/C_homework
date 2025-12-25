#include <stdio.h>
#include <string.h>
#include "../Stack/stack.h"


char get_matching_opening(char closing) {
    switch(closing) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return '\0';
    }
}

int check_balance(const char* text)
{
    OBJ* stack = stack_new();
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        char current = text[i];

        if(current == '(' || current == '[' || current == '{')
        {
            stack = stack_push(stack, current);
        }

        else if(current == ')' || current == ']' || current == '}')
        {
            if(stack == NULL) 
            {
                stack_delete(stack);
                return 0;
            }

            char expected = get_matching_opening(current);
            char actual = stack_peek(stack);

            if(actual == expected) 
            {
                stack = stack_pop(stack);
            } 
            else 
            {
                stack_delete(stack);
                return 0;
            }
        }
    }

    int result = (stack == NULL);
    stack_delete(stack);

    return result;
}


int main(void)
{
    char text[1000];
    
    printf("Введите текст\n");
    if (fgets(text, sizeof(text), stdin) == NULL) 
    {
        printf("Ошибка ввода!\n");
        return 1;
    }

    if (check_balance(text))
    {
        printf("Скобки сбалансированы\n");
    }

    else
    {
        printf("Скобки не сбалансированны\n");
    }

    return 0;

}
