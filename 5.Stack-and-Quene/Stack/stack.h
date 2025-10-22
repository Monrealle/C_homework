#ifndef STACK_H
#define STACK_H

typedef struct tag_obj
{
    char data;
    struct tag_obj* next;
} OBJ;

// Создание нового стека
OBJ* stack_new(void);

// Добавление элемента на стек
OBJ* stack_push(OBJ* top, char data);

// Удаление верхнего элемента
OBJ* stack_pop(OBJ* top);

// Удаление стека
OBJ* stack_delete(OBJ* top);

// Просмотр верхнего элемента
char stack_peek(OBJ* top);

// Вывод содержимого
void stack_show(OBJ* top);

#endif