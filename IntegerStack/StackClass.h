#include <stdbool.h>

#ifndef STACKCLASS_H
#define STACKCLASS_H

typedef struct StackNode{

    int data;
    struct StackNode *next;
} StackNode;

typedef struct Stack{

    StackNode *top;
    int size;

    void (*push)(struct Stack*, int);
    int (*pop)(struct Stack*);
    int (*peek)(struct Stack*);
} Stack;

void push(Stack *stack, int val);

int pop(Stack *stack);

int peek(Stack *stack);

Stack* createEmptyStack();

void destroyStack(Stack *stack);

#endif