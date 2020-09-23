#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "bubble.h"

int bubbleSort(int N, float *Array){
    int i,j;
    float temp = 0;
    for (i = 0; i < N-1; i++)
    {
        for (j = 0; j < N-1; j++)
        {
            if (Array[j] > Array[j+1])
            {
                temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
            }
        }
    }
    return 0;
}

int bubbleSortStop(int N, float *Array){
    bool Changed = true;
    int lastChange = N-1;
    int tempLastChange = N-1;
    int j,temp;
    while (Changed)
    {
        Changed = false;
        j=0;
        while (j < lastChange)
        {
            if (Array[j] > Array[j+1])
            {
                temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
                Changed = true;
                tempLastChange = j;
            }
            j++;
        }
        lastChange = tempLastChange;
    }
    return 0;
}

void printArray(int N, float *Array){
    printf("Yuor Array:\n");
    for (int i = 0; i < N; i++){
        printf("Memory: %p postion [%d]: %f \n", 
        (Array+i),i,Array[i]);
    }
    printf("End of list \n");
}