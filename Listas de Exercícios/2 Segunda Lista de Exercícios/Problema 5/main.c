#include <stdio.h>
#include <stdlib.h>

int main(){

    int idade;
    printf("Digite sua idade");
    scanf("%d", &idade);
    if (idade < 18 || idade > 67) {
        printf("Voce nao esta apto a doar sangue :(");
    }else{
        printf("Doa tudo amiga! :)");
    } 
    return 0;
}