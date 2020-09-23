#include <stdio.h>
#include <stdlib.h>
#include "operatios.h"

#define StackSize 10

struct stack
{
    int currentSize;
    int stackArray[StackSize];
};

Stack initializeStack(){
    Stack S = malloc(sizeof(struct stack));

    S->currentSize = 2;
    for (int i = 0; i < StackSize; i++)
    {
        S->stackArray[i] = i;        
    }

    return S;
}

void showFullStack(Stack S){
    printf("\n Your Stack \n");
    for (int i = S->currentSize; i >= 0; i--)
    {
        printf("Memory: %d, Array Position: %d Value: %d \n",
                &(S->stackArray[i]), i, S->stackArray[i]);
    }
    printf(" End of Stack\n");
}

int getTop(Stack S){
    if(S->currentSize > 0){
        return S->stackArray[S->currentSize];
    }else
    {
        return -1;
    }
}

int push(Stack S, int value){
    if(S->currentSize == StackSize-1){
        return -1;
    }else
    {
        S->stackArray[S->currentSize+1] = value;
        S->currentSize++; 
        return S->currentSize-1;
    }
}

int pop(Stack S, int value){
    if(S->currentSize == -1){
        return -1;
    }else
    {
        S->currentSize--;
        return S->currentSize+1;
    }
}