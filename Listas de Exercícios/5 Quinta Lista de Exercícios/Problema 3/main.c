#include <stdio.h>
#include <stdlib.h>
#define NUMERO 10
float valores[NUMERO];
int main()
{
    int i; 
    int pos1, pos2;
    for(i = 1; i <= NUMERO; i++){
        printf("Digite o %d valor \n", i);
        scanf("%f", &valores[i-1]);
    } 

    
    for(i = 1; i <= 2; i++){
       printf("Digite a %d posicao que deseja ler no array: ", i);
       if(i==1){
           scanf("%d", &pos1);
       }else
       {
            scanf("%d", &pos2);
       }
    }
    
    printf("A soma dos valores %f e %f eh %f", valores[pos1], valores[pos2], valores[pos1] + valores[pos2] );
    return 0;
}

