#include <stdlib.h>
#include <stdio.h>

#define N 5
int B [N][N];
int A [N][N];

int main()
{
    int i,j;

    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            printf("Dite o valor da posicao [%d][%d]: ", i,j);
            scanf("%d", &B[i][j]); 
        }
    }
    printf("\n");

    //print B
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            printf(" Valor da posicao [%d][%d]: %d", i,j, B[i][j]);
        }
    printf("\n");
    }
    printf("\n");

    //Gerando A = B^2
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            A[i][j] = B[i][j] * B[i][j]; 
        }
    }
    
    //print de A
    printf("A = B^2: \n");
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            printf(" Valor da posicao [%d][%d]: %d", i,j, A[i][j]);
        }
    printf("\n");
    }
    printf("\n");

    return 0;
}
