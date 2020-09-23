#include <stdio.h>
#include <stdlib.h>
#define N 5

int contaValores(int *vet, int *pares, int *impares, int *negativos){

    int i, atual;

    for ( i = 0; i < N; i++){
        atual = *(vet + i);

        if(atual % 2 == 0)
            *pares += 1;
        else
            *impares += 1;

        if (atual < 0)
            *negativos += 1;

    }

}

int main()
{
    int vet[N], i, pares = 0, impares = 0, negativos = 0;    
    
    printf("Vai digitando valor ate acabar: \n");
    for ( i = 0; i < N; i++)
        scanf("%d", (vet + i));

    contaValores(vet, &pares, &impares, &negativos);

    printf("Pares: %d; Impares: %d; Negativos: %d", pares, impares, negativos);
    
    return 0;
}