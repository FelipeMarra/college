#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int vet[N], i, menor;

    printf("Ponha inteiros ai ate acabar: \n");
    for(i=0; i < N; i++)
        scanf("%d", (vet + i));

    menor = *vet;
   // printf("menor: %d \n", menor);
        for (i=0; i < N-1; i++){
            if(  menor > *(vet + i) )
                menor = *(vet + i);
        }

    printf("menor: %d", menor);

    return 0;
}