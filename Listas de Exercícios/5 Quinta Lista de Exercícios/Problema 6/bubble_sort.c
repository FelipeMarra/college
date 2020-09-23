#include <stdio.h>
#include <stdlib.h>
#define NUMERO 4
float valores[NUMERO];
int main()
{
    int i, x; 
    float atual, antecessor;
    for(i = 1; i <= NUMERO; i++){
        printf("Digite o %d valor \n", i);
        scanf("%f", &valores[i-1]);
    } 
    
    for( x = 0; x < NUMERO; x++){
        for(i = 0; i < NUMERO; i++){
            if(valores[i]>valores[i+1]){
                printf("ENTROU\n");
                int back = valores[i];
                valores[i] = valores[i+1];
                valores[i+1] = back;
            }
        }
    }
    
    
    for( i = 0; i <= NUMERO; i++){
        printf("O valor na posicao %d e %f \n", i, valores[i]);
    }
    return 0;
}