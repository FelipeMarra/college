#include <stdlib.h>  
#include <stdio.h>  
#include "insertion.h"

int insertion(int N, float *Array){
    int i,j;
    float aux;
    for ( i = 1; i < N; i++)
    {
        j = i;
        aux = Array[i]; //Selecting the first unsorted element
        while (Array[j-1] > aux && j >= 0) 
        {
            Array[j] = Array[j-1];  // This loop shifts the elements right till it finds  
            j--;                    //the correct position to the unsorted element we  
            Array[j] = aux;         //selected before
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