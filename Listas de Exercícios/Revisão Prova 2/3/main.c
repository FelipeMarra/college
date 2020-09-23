#include <stdio.h>
#include <stdlib.h>

int encontraMenor( int *vet, int tamanho, int menor){
    
    if(tamanho == 0){
            return menor;
    }else if (vet[tamanho] < menor){
        menor = vet[tamanho];
    }

    return encontraMenor(vet, tamanho-1, menor);
}

int main()
{
    int i,tamanho, menor;

    printf("digite o tamanho do vet: ");
    scanf("%d", &tamanho);
    int vet[tamanho];
    printf("\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("Valor posicao [%d]: ", i);
        scanf("%d", &vet[i]);
    }
    printf("\n");
    menor = vet[0];
    printf("O menor valor do ver eh %d ",  encontraMenor(vet, tamanho, menor));

    return 0;
}
