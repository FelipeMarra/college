#include <stdio.h>
#include <stdlib.h>

int main()
{

    float** matrx;
    //5 pointers to 5 other pointers that will be the lines
    matrx = (float**) malloc(5*sizeof(float*));
    for (int i = 0; i < 5; i++){
        //allocating memory for the lines, five spaces for floats for each pointer that was created after
        *(matrx + i) = (float*) malloc(5*sizeof(float));
        //giving values to it
        for (int j = 0; j < 5; j++){
            *(*(matrx + i) + j) = i + j;
        }
    }

    for (int i = 0; i < 5; i++){
        printf("%p: %p\n", matrx+i, *(matrx+i));
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%f  ", *(*(matrx+i)+j) );
        }
        printf("\n");
    }

    return 0;
}
