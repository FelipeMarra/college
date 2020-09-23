#include <stdio.h>
#include <stdlib.h>

int ImparImparVezes(int *vet, int tamanho){
    int count = 0, i, j;
    //Loop para achar o num impar que a aparece um num impar de vezes
    for (i = 0; i < tamanho; i++){
        //Verifica se eh impar
        if(vet[i] % 2 != 0){
            //E entao ver quntas vezes aparece
            for (j = 0; j < tamanho; j++){
                if(vet[i] == vet[j]){
                    count++;    
                }
            }
            //E dai verificar se essa quantidade de vezes eh imapar
            if(count % 2 != 0){
                //Em caso afirmativo, este eh o numero buscado
                return vet[i];
                //Caso n seja, zerar o count e repetir o processo
            }else{
                count = 0;
            }
        }
        //Se chegar no ultimo processo da ultima repeticao do loop, com o count zerado, o numero buscado n exite
        if ( i == tamanho-1 && count == 0){
            return -1;
        }
    }
}

int main()
{
    int i,tamanho, retorno;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    //Declaracao do vet
    int vet[tamanho];
    printf("Digite os valores inteiros: ");
    for (i = 0; i < tamanho; i++){
        printf("Posicao [%d]: ", i);
        scanf("%d", &vet[i]);
    }
    
    retorno = ImparImparVezes(vet, tamanho);
    if (retorno != -1){
        printf("O numero impar que aparece um numero impar de vezes eh: %d ", retorno);
    }else{
        printf("N existe um numero impar que aparece um numero impar de vezes");
    }
    
    return 0;
}
