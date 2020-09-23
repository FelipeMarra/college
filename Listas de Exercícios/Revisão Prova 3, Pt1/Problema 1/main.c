#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float vet[10];

    for ( i = 0; i < 10; i++){

        printf(" Posicao %d em decimal: %d \n", i, (vet + 1) );
        printf(" Posicao %d em decimal: %p \n", i, (vet + 1) );
        printf("\n");
    }

    return 0;
}
