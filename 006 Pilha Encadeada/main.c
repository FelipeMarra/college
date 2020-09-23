#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main()
{
    Stack S;
    S = createStack();

    printStack(S);

    int value = 10;
    push(S,value);
    printStack(S);

    value = 20;
    push(S,value);
    printStack(S);

    value = 30;
    push(S,value);
    printStack(S);

    pop(S);
    printStack(S);

    pop(S);
    printStack(S);

    pop(S);
    printStack(S);

    return 0;
}
