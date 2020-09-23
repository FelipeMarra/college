#include <stdlib.h>
#include <stdio.h>

int somatorio(int n){

    if (n==0){
        return 0;
    } else
    {
        return n + somatorio(n-1);
    }
    

}

int main()
{
    int n;
    printf("Digite o inteiro n para o calculo do somatorio de 1 a n:");
    scanf("%d", &n);
    printf("Somatorio de 1 a n = %d", somatorio(n));

    return 0;
}
