#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int vet[N], i;    
    
    printf("Vai digitando valor ate acabar: \n");
    for ( i = 0; i < N; i++)
        scanf("%d", (vet + i));

    for ( i = 0; i < N; i++)
        printf("Valor em %d: %d \n", i, *(vet + i) * 2);
    
    return 0;
}
