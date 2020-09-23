#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Digite o caractere: ");
    c = getchar(); //Pega o caractere por meio da funcao getchar()
    /*Note que a funcao getchar() retorna um valor do tipo int, e ele esta sendo atribuido a uma variavel do tipo char
      Isto mostra como a lingugem c realiza a conversao de valores no moento da leitura*/
    printf("Caractere: %c\n", c);//Mostra na tela o caractere digitado
    printf("Codigo ASCII: %d\n", c);//Mostra o codigo da tabela ASCII correspondente a tal caractere
    system("pause");
    return 0;
}
