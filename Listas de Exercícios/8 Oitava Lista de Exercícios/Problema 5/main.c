#include <stdio.h>
#include <stdlib.h>

#define N 2

int main()
{
    int i,j,mat[N][N], somaLinhas = 0, vetSomaLinhas[N], multiPelaSomaLinha[N][N];

    for ( i = 0; i < N; i++)
    {
        vetSomaLinhas[i] = 0;
    }
    

    printf("Preencha sua matriz \n");
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            printf(" Digite o valor da posicao [%d],[%d]: ", i,j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }

    //soma das linhas
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            somaLinhas += mat[i][j];
        }
        vetSomaLinhas[i] = somaLinhas;
        somaLinhas = 0;
    }

    for ( i = 0; i < N; i++)
    {
        printf(" vet soma linhas [%d] = %d", i, vetSomaLinhas[i]);
    }

    //multiplicacao pela soma da linha correspondente
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            multiPelaSomaLinha[i][j] = mat[i][j] * vetSomaLinhas[i];
        }
    }
    printf("\n");
    printf("Sua matriz multiPelaSomaLinha\n");
    for ( i = 0; i < N; i++){
        for ( j = 0; j < N; j++){
            printf(" Valor da posicao [%d],[%d]: %d", i,j, multiPelaSomaLinha[i][j]);
            
        }
        printf("\n");
    }

    
    return 0;
}
