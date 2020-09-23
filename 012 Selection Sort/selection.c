#include <stdlib.h>  
#include <stdio.h>  
#include "selection.h"

int selection(int N, float *Array){
    int i,min,j,temp;
    for (i = 0; i < N-1; i++)
    {
        min = i;
        for (j = i+1; j < N; j++)
        {
            if (Array[j]<Array[min])
            {
                min = j;
            }
        }
        if (Array[min] != Array[i])
        {
            temp = Array[i];
            Array[i] = Array[min];
            Array[min] = temp;
        }
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