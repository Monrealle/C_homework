#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


OBJ* stack_new(void)
{
    return NULL;
}

OBJ* stack_push(OBJ* top, char data)
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;

    return ptr;
}

// Взять элемент со стека
OBJ* stack_pop(OBJ* top)
{
    if(top == NULL)
    {
        printf("Стек пуст\n");
        return top;
    }

    OBJ* ptr_next = top->next;
    free(top);

    return ptr_next;
}

OBJ* stack_delete(OBJ* top)
{
    OBJ* current = top;
    while (current != NULL)
    {
        OBJ* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}

// Функция для просмотра элемента сверху
int stack_peek(const OBJ* top)
{
    if(top == NULL)
    {
        printf("Стек пуст\n");
        return -1;
    }

    return top->data;
}

void show(const OBJ* top)
{
    const OBJ* current = top;
    if(top == NULL)
    {
        printf("Стек пуст\n");
        return;
    }

    while(current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
