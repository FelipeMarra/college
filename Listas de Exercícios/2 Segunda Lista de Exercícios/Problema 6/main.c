#include <stdio.h>
#include <stdlib.h>

int main(){

    float nota1, nota2, nota3, nota4, media;
    printf("Digite suas 4 notas: ");
    scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
    media = (nota1+nota2+nota3+nota4)/4;
    if(media > 7){
        printf("Aprovado(a)");
    }else if (media < 6.5) {
        printf("Reprovado(a)");
    }else
    {
        printf("De recuperacao");
    }
    
    

    return 0;
}