#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas, i, j, maior=-1;
    //Isnsercao dos dados de linha e coluna
    printf("Digite a quantidade de linhas: \n");
    scanf("%d", &linhas);
    printf("Digite a quantidade de colunas: \n");
    scanf("%d", &colunas);
    //Declaracao da mtriz
    int matriz[linhas][colunas];
    printf("\n"); 
    //Insercao dos valores dos index
    printf("Digite os valores da sua matriz \n");
    for ( i = 0; i < linhas; i++){
        for ( j = 0; j < colunas; j++){
            printf(" Posicao [%d][%d] = ", i,j);
            scanf("%d", &matriz[i][j]);
        }        
    }
    //Print da matriz
    printf("\n"); 
     printf("Sua matriz esta assim:  \n");
        for ( i = 0; i < linhas; i++){
            for ( j = 0; j < colunas; j++){
                printf(" Posicao [%d][%d] = %d", i,j,matriz[i][j]);
            }    
            printf("\n");    
    }

    //achando maior valor
    for ( i = 0; i < linhas; i++){
        for ( j = 0; j < colunas; j++){
            if (matriz[i][j] > maior){
                maior = matriz[i][j];            }
        }        
    }

    printf("\n");  
    printf("O maior valor eh %d", maior);
    return 0;
}
