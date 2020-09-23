#include <stdio.h>
#include <stdlib.h>

float fatorial(int n){
    int i;
    float fat = 1.0;

    for ( i = 2; i <= n; i++)
        fat *= i;
    printf("fat de %d = %f \n", n, fat);

    return fat;
}

int nep( int n, int count, float soma){

    if(count > n){
        printf("O neperiano ate %d eh = %f", n, soma);
        return 0;
    }else
    {
        soma += 1.0/fatorial(count);
        printf("soma = %f\n", soma);
        nep(n, count+1, soma);
    }
    
}


int main(){
    int n, count = 0;
    float soma = 0.0;

    printf("Digite o numero n: ");
    scanf("%d", &n);
    nep(n, count, soma);

    return 0;
}
