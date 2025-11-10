#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Stack/stack.h"


int precedence(char op) 
{
    switch(op) 
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        default:
            return 0;
    }
}

int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

char* infix_to_postfix(const char* infix)
{
    static char output[1000];
    output[0] = '\0';

    OBJ* stack = stack_new();
    int output_index = 0;

    for (int i = 0; infix[i] != '\0'; i++) 
    {
        char token = infix[i];
        
        if (isspace(token)) 
        {
            continue;
        }
        
        if (isdigit(token)) 
        {
            while (isdigit(infix[i])) 
            {
                output[output_index++] = infix[i++];
            }
            
            output[output_index++] = ' ';
            i--;
        }

        else if (token == '(') 
        {
            stack = stack_push(stack, token);
        }

        else if (token == ')') 
        {
            while (stack != NULL && stack_peek(stack) != '(')
            {
                output[output_index++] = stack_peek(stack);
                output[output_index++] = ' ';
                stack = stack_pop(stack);
            }

            if (stack != NULL && stack_peek(stack) == '(')
            {
                stack = stack_pop(stack);
            }
        }

        else if (is_operator(token)) 
        {
            while (stack != NULL && stack_peek(stack) != '(' && 
                   precedence(stack_peek(stack)) >= precedence(token)) 
            {
                output[output_index++] = stack_peek(stack);
                output[output_index++] = ' ';
                stack = stack_pop(stack);
            }

            stack = stack_push(stack, token);
        }
    }

    while (stack != NULL) 
    {
        output[output_index++] = stack_peek(stack);
        output[output_index++] = ' ';
        stack = stack_pop(stack);
    }

    if (output_index > 0 && output[output_index-1] == ' ') 
    {
        output_index--;
    }
    
    output[output_index] = '\0';
    stack_delete(stack);
    return output;
}

int main() {
    char infix[1000];
    
    printf("Введите инфиксное выражение: ");
    scanf("%999[^\n]", infix);
    
    char* postfix = infix_to_postfix(infix);
    printf("Постфиксная запись: %s\n", postfix);
    
    return 0;
}