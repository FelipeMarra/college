#include <stdio.h>
#include <stdlib.h>

int main(){

    float x;
    printf("Digite um valor: ");
    scanf("%f", &x);
    if(x > 0){
        printf("O valor eh positivo ");
    }else if(x < 0){
        printf("O valor eh negativo");
    }else {
        printf("O valor eh igual a 0 ");
    }

    return 0;
}