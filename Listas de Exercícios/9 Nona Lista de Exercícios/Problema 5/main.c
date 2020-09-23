#include <stdio.h>
#include <stdlib.h>

int  somatorio(int n, float soma){

    if(n < 1){
        printf("%f", soma);
        return 0;
    }else{
        soma +=  n;
        return somatorio(n-1, soma);
    }
     
}

int main(){

    int n;
    float soma = 0;

    printf("Qual seu n? ");
    scanf("%d", &n);

    printf("Calculo do seu somatorio ate %d: ", n);
    somatorio(n, soma);

    return 0;
}