#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,tamanho;

    printf("Digite o tamanho das matrix: ");
    scanf("%d", &tamanho);

    int matA[tamanho][tamanho];
    int matB[tamanho][tamanho];
    int SomaAB[tamanho][tamanho];
    printf("Digite os valores da matrix A: \n");
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            printf("Valor da posicao [%d][%d]: ", i,j);
            scanf("%d", &matA[i][j]);
        }
    printf("\n");
    }
    printf("\n");

    printf("A matrix A esta assim: \n");
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            printf(" Valor da posicao [%d][%d]: %d", i,j, matA[i][j]);
        }
    printf("\n");
    }

    printf("Digite os valores da matrix B: \n");
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            printf("Valor da posicao [%d][%d]", i,j);
            scanf("%d", &matB[i][j]);
        }
    printf("\n");    
    }
    printf("\n"); 

    printf("A matrix B esta assim: \n");
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            printf(" Valor da posicao [%d][%d]: %d", i,j, matB[i][j]);
        }
    printf("\n");
    }
    printf("\n"); 

    //Soma das matrix
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            SomaAB[i][j] = matA[i][j] + matB[i][j];
        }
    }
    
    //Print soma das matrizes
    printf("A matrix Soma de A + B esta assim: \n");
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            printf(" Valor da posicao [%d][%d]: %d", i,j, SomaAB[i][j]);
        }
    printf("\n");
    }
    printf("\n"); 
    
    return 0;
}
