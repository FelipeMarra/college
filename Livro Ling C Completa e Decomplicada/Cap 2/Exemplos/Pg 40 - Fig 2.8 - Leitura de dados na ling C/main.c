#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,z;
    float y;

    printf("Leitura de um valor inteiro: ");
    //Leitura de um valor inteiro
    scanf("%d,",&x);     /*mostrando valores:*/printf("Voce digitou: %d\n",x);

    printf("Leitura de um valor real: ");
    //Leitura de um valor real
    scanf("%f",&y);      /*mostrando valores:*/printf("Voce digitou: %f\n",y);

    printf("Leitura de um valor inteiro e outro real: ");
    //Leitura de um valor inteiro e outro real
    scanf("%d%f",&x,&y); /*mostrando valores:*/printf("Voce digitou: %d e %f\n",x,y);

    printf("Leitura de dois valores inteiros: ");
    //Leitura de dois valores inteiros
    scanf("%d%d",&x,&z); /*mostrando valores:*/printf("Voce digitou: %d e %d\n",x,z);

    printf("Leitura de dois valores inteiros com espaco: ");
    //Leitura de dois valores inteiros com espaco
    scanf("%d %d",&x,&z); /*mostrando valores:*/printf("Voce digitou: %d e %d\n",x,z);
    //o scanf ignora os espacos portando este exemplo eh equivalente ao de cima

    system("pause");
    return 0;
}
