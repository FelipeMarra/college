#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#define ArraySize 10

struct queue{
    int firstItemPosition;//the first item position in the array
    int lastItemPosition;//the last item position in the array
    int itens;  //the number of items
    int queueArray[ArraySize]; //the array it self
};

Queue initializeQueue(){
    Queue Q;
    Q = malloc(sizeof(struct queue));

    Q->firstItemPosition = 6;
    Q->lastItemPosition = 0;
    Q->itens = 5;

    Q->queueArray[6] = 2;
    Q->queueArray[7] = 3;
    Q->queueArray[8] = 4;
    Q->queueArray[9] = 5;
    Q->queueArray[0] = 1;

    return Q;
}

void printQueue(Queue Q){ 
    int printPosition = Q->firstItemPosition;

    printf("\nThis is your array: \n");    

    for (int i = 0; i < Q->itens; i--)
    {
        printf("[%d]: %d \n", printPosition,Q->queueArray[printPosition]);
        
        if(printPosition == 9)
            printPosition = 0;
        else 
            printPosition++;    
    }
    printf("End of array \n");
}

int insetInQueue(Queue Q, int value){
    if(Q->itens == 10){
        return -1;
    }
    int nextItemPosition = Q->lastItemPosition+1;
    if(nextItemPosition > 9){
        Q->queueArray[0] = value;
        Q->lastItemPosition = 0;
    }
    else{
        Q->queueArray[nextItemPosition] = value;
        Q->lastItemPosition = nextItemPosition;
    }
    Q->itens++;
    return Q->lastItemPosition;
}

int removeFromQueue(Queue Q){
    if(Q->firstItemPosition == 9){
        Q->firstItemPosition = 0;
    }else
    {
        Q->firstItemPosition++;
    }
    Q->itens--;
}
















