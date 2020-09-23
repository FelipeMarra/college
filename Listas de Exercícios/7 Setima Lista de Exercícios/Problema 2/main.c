#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(){
int i, j;
    int matriz[N][N];
    //zerando a matriz colocando 1 na principal
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                if( i == j){
                    matriz[i][j] = 1;
                }else{
                    matriz[i][j] = 0;
                }
            }
        }
    //print
    for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                printf(" Posicao [%d][%d] = ", i, j);   
                printf("%d", matriz[i][j]);
            }
            printf("\n");
        }
    
return 0;
}
