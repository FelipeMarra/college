#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia, mes, ano;
    //Leitura de 3 valores inteiros com barra entre eles
    printf("Digite os valores: ");//printf apenas para a inteface
    scanf("%d/%d/%d",&dia,&mes, &ano);//as barras seriam ignoradas pelo scanf(), portanto poderiam ser usado para receber dadods formatados
    //como eh dito no livro, porem as barras estao interferindo no valor...
    printf("Data: %d/%d/%d \n", dia, mes, ano);//para mostrar a data formatada deve-se colocar manualmente as barras no printf()
    system("pause");
    return 0;
}
