#include <stdio.h>
#include <stdlib.h>
/*
pegar a posicao na string, converter pra ascii
se estiver entre 97 e 122, diminuir 42 jogar de volta pra string
se nao, na fazer nada
*/
int main()
{
    int tamanho, i;
    //Criacao da str com espacos vazios
    printf("Digite quantos caracterres vc vai alocar na memoria: ");
    scanf("%d", &tamanho);
    //+1 no tamanho pelo \n do fgets() o compilador ja poe o \0
    tamanho += 1;
    char str[tamanho];
    printf("Digite os caracteres: ");
    setbuf(stdin, NULL);
    fgets(str, tamanho, stdin);
    //trasformando em maiuscuo
    for( i = 0; i < tamanho; i++){
        if(str[i] <= 90 && str[i] >= 65){
            printf("str[%d] = %d \n", i, str[i]);
            str[i] = str[i] +32;
        }
    }
    printf("String Lowcase %s", str);
    return 0;
}
