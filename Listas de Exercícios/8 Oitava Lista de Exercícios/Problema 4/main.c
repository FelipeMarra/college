#include <stdio.h>
#include <stdlib.h>

int somaIntervalo( int i, int j){
    
    int count, diferenca, soma = 0;

    diferenca = j-i;
    
    for ( count = 1; count < diferenca; count++){
        soma += i + count;
    }

    return soma;
}

int main()
{
    int i,j;

    printf("Digite o premeiro numero do intervalo aberto: ");
    scanf("%d", &i);
    printf("Digite o segundo numero do intervalo aberto: ");
    scanf("%d", &j);

    printf("A soma dos numeros no intervalo aberto de %d a %d = %d", i, j, somaIntervalo(i,j));

    return 0;
}
