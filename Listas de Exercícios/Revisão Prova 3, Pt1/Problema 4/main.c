#include <stdio.h>
#include <stdlib.h>
#define N 5

void printVet(int *vet){
    int i;
    for(i=0; i < N; i++)
        printf("indice [%d]: %d \n",i, *(vet + i));
}


int main()
{
    int vet[N], i;

    printf("Ponha inteiros ai ate acabar: \n");
    for(i=0; i < N; i++)
        scanf("%d", (vet + i));

    printVet(vet);
  
    return 0;
}
