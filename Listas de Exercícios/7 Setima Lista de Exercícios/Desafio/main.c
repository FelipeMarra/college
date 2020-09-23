#include <stdio.h>
#include <stdlib.h>
int main()
{
    int linhas, colunas, i, j, atual, antecessor, count;
    
    //Isnsercao dos dados de linha e coluna
    printf("Digite a quantidade de linhas: \n");
    scanf("%d", &linhas);
    
    printf("Digite a quantidade de colunas: \n");
    scanf("%d", &colunas);
    printf("\n");

    //Declaracao da mtriz
    int matriz[linhas][colunas]; 
    
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

    //Loop para ordenar de acodo com a quantidade de index
    for ( count = 0; count <= linhas*colunas; count++)
    {
         //loop na matriz de baixo para cima
        //sem a ultima posicao de cada para comparar com o sucessor depois
        for(i = linhas-1; i >= 0; i--){
            printf("\n Pimero laco");
            for (j = colunas-1; j >= 0; j--){
            printf("\nSegundo laco");
                //backup dos valores atual e seu sucessor
                atual = matriz[i][j];//1
            printf("\n atual %d", atual);
                antecessor = matriz [i][j-1];//2
            printf("\n antecessor %d", antecessor);
                //Se o atual eh menor que o antecessor troque-os de lugar
                if(atual < antecessor){
                    matriz[i][j] = antecessor;
                    matriz[i][j-1] = atual;
                }
            }
        }   
    }    

    //Print da mtriz ordenada
    printf("\n");
    printf("Sua matriz agora esta ordenada:  \n");
        for ( i = 0; i < linhas; i++){
            for ( j = 0; j < colunas; j++){
                printf(" Posicao [%d][%d] = %d", i,j,matriz[i][j]);
            }    
            printf("\n");    
    }

    return 0;
}