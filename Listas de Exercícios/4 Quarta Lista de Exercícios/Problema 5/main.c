#include <stdio.h>
#include <stdlib.h>

//Novamente usando array somente para treinar
//Sem array eh mais facil
int main () {
    int N, i, soma = 0;
    printf("Digite o  numero N: ");
    scanf("%d", &N);
    int numerosIntervalo[N];
    for( i = 0; i <= N; i++)
    {
        numerosIntervalo[i] = 0;
    }

    for(i = 0; i <= N; i++){
        if (i % 2 != 0){
            numerosIntervalo[i] = i;
            printf("numero %d sendo adicionado ao index %d \n", i,i);
        }
    }
    for( i = 0; i <= N; i++)
    {
        soma += numerosIntervalo[i];
    }
    
    printf("A soma do numeros impares  o intervalo [1,%d] eh: %d", N, soma);

return 0 ;
}