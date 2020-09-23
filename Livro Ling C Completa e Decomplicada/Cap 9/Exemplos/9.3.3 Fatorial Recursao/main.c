#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int fatorial(int n){
    
    if (n == 0){
        return 1;
    } else {
        return n * fatorial(n-1);
    }

}

int main()
{
    int n;
    printf("Digite o inteiro para o calculo de seu fatorail:");
    scanf("%d", &n);
    printf("Fatorial = %d", fatorial(n));

    return 0;
}
