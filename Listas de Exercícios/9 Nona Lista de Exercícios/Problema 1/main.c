#include <stdio.h>
#include <stdlib.h>

int somaVetor(int *vet, int tam, int soma){

    if(tam < 0){
        return soma;
    }
    soma  += vet[tam];
   return somaVetor(vet, tam-1, soma);

}

int main(){

    int tam,i, soma = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    int vet[tam];
    printf("Digite as entradas do vetor: ");
    for ( i = 0; i < tam; i++){
     printf("Valor na posicao [%d]: ", i);        
     scanf("%d", &vet[i]);   
    }
     printf("Soma dos valores = %d", somaVetor(vet, tam, soma));

    return 0;
}