#include <stdio.h>
#include <stdlib.h>

int x = 5; //Variavel de escopo global

int main()
{
    printf("x = %d\n",x); //Sera mostrado valor 5, jah que eh o valor atual de uma variavel com o nome "x"
    int x = 4;
    printf("x = %d\n", x);//Sera mostrado o valor 4, jah que eh o valor de uma variavel com o nome "x" no escopo mais proximo
    {
        int x = 3;
        printf("x = %d\n", x);//Sera mostrado o valor 3, jah que eh o valor de uma variavel com o nome "x" no escopo mais proximo
    }
    printf("x = %d\n", x);//Sera mostrado o valor 4, jah que eh o valor de uma variavel com o nome "x" no escopo mais proximo
    /*A variavel x com o valor 3 foi eliminada assim que seu escopo, delimitado peslas chaves "{}", foi finalizado
    Eh por isso que neste printf() o valor mostrado eh 4 e nao 3*/
    /*Observe que foi confuso identificar o valor das variaveis, portando evite cira-las com o mesmo nome
    Nao eh por ter o mesmo nome que o valor eh igual, como foi visto, para ser a mesma variavel tem de estar no mesmo escopo
    */
    system("pause");
    return 0;
}
