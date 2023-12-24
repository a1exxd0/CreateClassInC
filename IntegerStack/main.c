#include "StackClass.h"
#include <stdio.h>


int main(){
    Stack *myStack = createEmptyStack();

    myStack->push(myStack, 5);
    printf("pushed 5 to stack. size is %d\n", myStack->size);
    printf("peeking top after pushing 5? we get %d\n", myStack->peek(myStack));

    myStack->push(myStack, 3);
    printf("peeking top after pushing 3? we get %d\n", myStack->peek(myStack));

    printf("now pop once: we popped %d\n", myStack->pop(myStack));
    printf("now pop twice: we popped %d\n", myStack->pop(myStack));
    printf("now pop thrice: we popped %d\n", myStack->pop(myStack));
    printf("stack size is %d\n", myStack->size);
    destroyStack(myStack);
}