#include <stdio.h>
#include <stdlib.h>

#define N 2
int main()
{
    int i,j;
    float matM[N][N], matR[N][N], maior;

    printf("Preencha sua matriz \n");
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            printf(" Digite o valor da posicao [%d],[%d]: ", i,j);
            scanf("%f", &matM[i][j]);

            if(i == 0 && j == 0){
                maior = matM[0][0];
            }else if (matM[i][j] > maior){
                maior = matM[i][j];
            }
            
        }
        printf("\n");
    }
    
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            matR[i][j] = matM[i][j] * maior;
        }
    }

     printf("Mat R \n");
     for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            printf(" Valor em [%d],[%d]: %f", i,j, matR[i][j]);
        }
        printf("\n");
    }

    return 0;
}
