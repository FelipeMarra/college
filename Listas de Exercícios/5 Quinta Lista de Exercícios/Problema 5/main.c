#include <stdio.h>
#include <stdlib.h>
#define NUMERO 10
float valores[NUMERO];
int main()
{
    int i, qtdNegativos = 0; 
    float somaPositivos = 0;
    for(i = 1; i <= NUMERO; i++){
        printf("Digite o %d valor \n", i);
        scanf("%f", &valores[i-1]);
    } 
    
    for(i = 0; i <= NUMERO-1; i++)
    {
        if( valores[i] < 0){
            qtdNegativos++;
        }else{
            somaPositivos += valores[i];
        }
    }
    printf("A qtd de negativos eh %d e soma de positivos eh %f", qtdNegativos, somaPositivos);
    return 0;
}