#include <stdlib.h>
#include <stdio.h>

int main(){

    int x, count=0, soma=0;
    float media;

    do {
        
        scanf("%d", &x);    
        if(x<0){
            media = soma/count;
            printf("Vc digitou %d numeros positivos. A media entre eles eh: %f", count, media);
        }else{
            printf("O numero que vc digitou foi: %d", x);
            soma += x;
            count++;
        }

    }while(x>0);

    return 0;
}
