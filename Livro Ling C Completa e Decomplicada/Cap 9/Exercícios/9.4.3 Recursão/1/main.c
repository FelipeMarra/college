#include <stdlib.h>
#include <stdio.h>

int cube(int n){
    return n * n * n;
}

int cubesSum(int n){
    if ( n == 0){
      return 0;
    } else{
      return cube(n) + cubesSum(cube(n-1));
    }
    
}

int main()
{
    int n;
    printf("Digite o inteiro ate o qual os cubos serao somados:");
    scanf("%d", &n);
    printf("Soma = %d", cubesSum(n));
    
    return 0;
}
