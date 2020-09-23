#include <stdio.h>
#include <stdlib.h>

void trocaValor ( int *a, int *b){

    int backup;

    backup = *a;
    *a = *b;
    *b = backup;

}


int main()
{
    int a, b;
    printf("valor de a: ");
    scanf("%d", &a);

    printf("valor de b: ");
    scanf("%d", &b);

    trocaValor(&a,&b);

    printf("Valor apos chamar a funcao\n");
    printf("valor de a: %d\n", a);
    printf("valor de b: %d", b);

    return 0;
}
