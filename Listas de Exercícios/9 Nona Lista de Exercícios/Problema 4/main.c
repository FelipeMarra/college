#include <stdio.h>
#include <stdlib.h>

float sequencia(int n, float soma){

    if(n < 1){
        printf("%f", soma);
        return 0;
    }else{
        soma += 1.0/ n;
        return sequencia(n-1, soma);
    }
     
}

int main(){

    int n;
    float soma = 0;

    printf("Qual seu n? ");
    scanf("%d", &n);

    printf("Calculo da sua sequencia ate %d: ", n);
    sequencia(n, soma);

    return 0;
}