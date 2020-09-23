#include <stdio.h>
#include <stdlib.h>
//Algoritmo que cálcula o fatorial
int fatorial(int n){

    int i,f = 1;
    for(i = 1; i <= n; i++)
        f = f * i;
    return f;

}
//Código do programa de fato
int main(){
    int x,y;
    printf("Digite um valor inteiro: ");
    scanf("%d", &x);
    if(x > 0){

        printf("X eh positivo\n");
        y = fatorial(x);
        printf("Fatorial de X eh %d\n",y);

    }else{
        if(x < 0)
            printf("X eh negativo\n");
        else
            printf("X eh Zero\n");

    }

    printf("Fim do programa!\n");
    system("pause");
    return 0;

}
