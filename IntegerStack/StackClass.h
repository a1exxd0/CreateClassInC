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

/**
 * \brief       Push a value onto the stack. Dynamic stack so no theoretical maximum.
 * \param       stack: pointer to the stack
 * \param       val: value you want to add
*/
void push(Stack *stack, int val);

/**
 * \brief       Pop a value off the stack. Returns 0 and prints error if there is
 *              nothing to pop.
 * \param       stack: pointer to stack
 * \return      Value popped or 0
*/
int pop(Stack *stack);

/**
 * \brief       Looks at top value on stack. Returns 0 and prints error if there
 *              is nothing to peek.
 * \param       stack: pointer to stack
 * \return      Value at the top of the stack or 0
*/
int peek(Stack *stack);

/**
 * \brief       Creates empty stack
 * \return      Pointer to allocated stack in memory
*/
Stack* createEmptyStack();

/**
 * \brief       Removes stack and all its nodes from memory
 * \param       stack: pointer to stack
*/
void destroyStack(Stack *stack);

#endif