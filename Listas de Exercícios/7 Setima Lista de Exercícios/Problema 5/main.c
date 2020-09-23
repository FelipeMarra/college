#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    int i, j, k, soma = 0;
    //Declaracao da matriz
    int matriz[N][N];
    //Leitura da matriz
    printf("Insira os %d valores da matriz %dx%d: \n", N*N, N, N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf(" Valor [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }   
        printf("\n");
    }

    //print
    printf("Sua matriz esta assim: \n");
    for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                printf(" Posicao [%d][%d] = ", i, j);   
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }

    //Soma da diagonal principal
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if( i == j ){
                for( k=j+1; k < N; k++){
                    printf("add %d a soma \n", matriz[i][k]);
                    soma += matriz[i][k];
                }
            } 
        }   
    }
    printf("Soma = %d", soma);
    return 0;
}
