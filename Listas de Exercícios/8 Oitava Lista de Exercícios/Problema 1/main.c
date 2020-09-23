#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    int i,j, count = 0;
    int vetX[N], vetY[N], vetUniao[N*2];

    //Anulando os vetores
    
    for ( i = 0; i < N*2; i++){

        if( i < N ){
            vetX[i] = 0;
            vetY[i] = 0;
        }
        
        vetUniao[i] = 0;

    }

    printf("Digite as entradas do vetor X: \n");
    for( i = 0; i < N; i++){
        printf("Valor posicao [%d]: ", i);
        scanf("%d", &vetX[i]);
    }

    printf("Digite as entradas do vetor Y: \n");
    for( i = 0; i < N; i++){
        printf("Valor posicao [%d]: ", i);
        scanf("%d", &vetY[i]);
    }

    //Uniao de X e Y
    for ( i = 0; i < N; i++){
            vetUniao[i] = vetX[i];
    }
         
    for ( i = 0; i < N; i++){
         for ( j = 0; j < N; j++){
            if(vetY[i] != vetUniao[j]){
                count++;
            }
        }
        if (count == 10){
            vetUniao[i+N] = vetY[i];
        }
        count = 0;
    }

    printf("Vet Uniao: \n");
    for( i = 0; i < N*2; i++){
        printf("Valor posicao [%d] = %d \n", i, vetUniao[i]);
    }   
    
    return 0;
}
