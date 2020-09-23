#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho, i=0, l;
    //Criacao da str com espacos vazios
    printf("Digite quantos caracterres vc vai alocar na memoria: ");
    scanf("%d", &tamanho);
    //+1 no tamanho pelo \n do fgets() o compilador ja poe o \0
    tamanho += 1;
    char str[tamanho];
    printf("Digite os caracteres: ");
    setbuf(stdin, NULL);
    fgets(str, tamanho, stdin);
    //Leitrura do numero de indices com caracteres
    while(1){
        if( str[i] == ' ' || str[i] == '\n' || str[i] == '\0'){
            break;
        }else{
            i++;
        }
    }
    //saida 
    printf("Voce colocou %d caracteres na string", i);

    return 0;
}
