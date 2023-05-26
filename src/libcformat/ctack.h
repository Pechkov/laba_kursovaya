#pragma once
#include <stdio.h>

#define MULTIPLIER 2
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102
#define INIT_SIZE 10
typedef struct Stack_tag {
    char *data;
    size_t size;
    size_t top;
} Stack_t;
void push(Stack_t *stack, char value);
char pop(Stack_t *stack);
char peek(const Stack_t *stack);
void resize(Stack_t *stack);
void deleteStack(Stack_t **stack);
Stack_t* createStack();
