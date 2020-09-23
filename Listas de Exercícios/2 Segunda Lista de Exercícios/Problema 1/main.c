#include <stdio.h>
#include <stdlib.h>

int main(){

    int x;
    printf("Digite um valor inteiro: ");
    scanf("%d", &x);
    x%2 > 0 ? printf("Numero impar") : printf("Numero par"); 

    return 0;
}