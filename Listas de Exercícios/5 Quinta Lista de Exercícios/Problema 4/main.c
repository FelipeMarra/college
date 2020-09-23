#include <stdio.h>
#include <stdlib.h>
#define NUMERO 10
float valores[NUMERO];
int main()
{
    int i; 
    float maior = 0, menor = 0;
    for(i = 1; i <= NUMERO; i++){
        printf("Digite o %d valor \n", i);
        scanf("%f", &valores[i-1]);
    } 
    maior = valores[0]; menor = valores[0];
    for(i = 1; i <= NUMERO-1; i++)
    {
        if( valores[i] > maior){
            maior = valores[i];
        }else if( valores[i] < menor){
            menor = valores[i];
        }
    }
    printf("O maior valor valor eh %f e o menor valor eh %f", maior, menor);
    return 0;
}