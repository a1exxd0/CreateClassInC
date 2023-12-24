#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "StackClass.h"

static StackNode* createStackNode(int val){
    fflush(stdout);
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    fflush(stdout);
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
    }
    node->data = val;
    return node;
}

static void destroyStackNode(StackNode *node){
    free(node);
}

static void destroyLowerStackNodes(StackNode *node){
    if(node->next != NULL){
        destroyLowerStackNodes(node->next);
        destroyStackNode(node);
    } else{
        destroyStackNode(node);
    }
}

void push(Stack *stack, int val){
    StackNode *node = createStackNode(val);
    stack->size = (stack->size) + 1;
    StackNode *topNode = stack->top;
    node->next = topNode;
    stack->top = node;
}

int pop(Stack *stack){
    if (stack->size == 0){
        printf("ERROR: EMPTY STACK\n");
        return 0;
    } else{
        StackNode *nextTop = stack->top->next;
        int returnedValue = stack->top->data;
        destroyStackNode(stack->top);
        stack->size = (stack->size) - 1;
        stack->top = nextTop;
        return (returnedValue);   
    }
}

int peek(Stack *stack){
    if (stack->size == 0){
        printf("ERROR: EMPTY STACK\n");
        return 0;
    } else{
        return (stack->top->data);   
    }
}

Stack* createEmptyStack(){
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->push = &push;
    stack->pop = &pop;
    stack->peek = &peek;
    return stack;
}

void destroyStack(Stack *stack){
    if (stack->size == 0){
        free(stack);
    } else{
        destroyLowerStackNodes(stack->top);
        free(stack);
    }
}
