#include <stdio.h>
#include <stdlib.h>

int main()
{
     /*char pesquisaCaracter;
     scanf("%c", &pesquisaCaracter);
     printf("%c", pesquisaCaracter);
    */
    int caracteres, i, pesquisaPosicao = -1;
    char pesquisaCaracter = 0;
    //Leitura do tamanho da string
    printf("Digite quantidade de caracteres da sua string: ");
    scanf("%d", &caracteres);
    //Declaracao da str
    caracteres += 2; //+1 do \0 e +1 \n
    char str[caracteres];
    //Limpeza do buffer e leitura das entradas da str
    setbuf(stdin, NULL);
    printf("Digite a sua string: ");
    fgets(str,caracteres,stdin);
    //Entrada do caractere a ser pesquisado
    printf("Digite o caracter q deseja encontrar: ");
    scanf("%c", &pesquisaCaracter);
    //Procura do caracter nas str
    for ( i = 0; i < caracteres; i++){
        if (str[i] == pesquisaCaracter){
             pesquisaPosicao = i+1;
        }
    }

    printf("O caractere pesquisado eh a %d letra: ", pesquisaPosicao);
     printf("\n");

    return 0;
}
