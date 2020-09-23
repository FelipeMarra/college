#include <stdio.h>
#include <stdlib.h>
#define NUMERO 5
int valores[NUMERO];
int main()
{
    int i;
    for(i = 1; i <= NUMERO; i++){
        printf("Digite o %d valor \n", i);
        scanf("%d", &valores[i-1]);
    } 
    for(i = 5; i >= 0; i--)
    {
        printf("O valor na %d posicao eh %d \n", i, valores[i-1]);
    }
    
    return 0;
}

