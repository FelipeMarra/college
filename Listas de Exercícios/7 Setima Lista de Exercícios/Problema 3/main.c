#include <stdio.h>
#include <stdlib.h>
#define N 4
int main()
{
    int i,j,count10;
    int matriz[N][N];
    printf("Insira os 16 valores da matriz 4x4: \n");
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf(" Valor [%d][%d]: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    //Print da matriz + contagem dos valores +10
    printf("Sua matriz esta assim: \n");
      for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                printf(" Posicao [%d][%d] = ", i, j);   
                printf("%d", matriz[i][j]);

                if(matriz[i][j] > 10)
                    count10++;
            }
            printf("\n");
        }
    printf("\n");
    printf("Ela possui %d valores maiores do que 10", count10);
    
    return 0;
}
