#include <stdlib.h>
#include <stdio.h>

#define N 10

int main()
{
    int i,j;
    float atual;

    float bubble[N];

    for ( i = 0; i < N; i++){
        printf("Digite o valor da posicao [%d]: ", i+1);
        scanf("%f", &bubble[i]);
    }
    printf("\n");

    for ( i = 0; i < N; i++){
        printf("Valor da posicao [%d]: %f \n", i+1, bubble[i]);
    }
    printf("\n");
    //bubble sort
    for (j = 0; j < 10; j++){

        for ( i = N; i > 0; i--){
        
            if ( bubble[i] < bubble[i-1] ){
                //backupp do atual
                atual = bubble[i];
                //troca de valores
                bubble[i] = bubble[i-1];
                bubble[i-1] = atual;
            }
        }
    }
    
    for ( i = 0; i < N; i++){
        printf("Valor da posicao [%d]: %f \n", i+1, bubble[i]);
    }
    
    return 0;
}
