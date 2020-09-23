#include <stdlib.h>
#include <stdio.h>

//Crescente
int printToN(int n, int count){

    if (n == count){
        printf("%d \n", n);
    }else{
        printf("%d \n", count);
        count++;
        printToN(n ,count);
    }

}
/*
Decrescente:
int printToN(int n){
    if (n == 0){
        printf("%d \n", 0);
    } else{
        printf("%d \n", n);
        n--;
        printToN(n);
    }
}
*/
int main()
{
    int n, count = 0;
    printf("Digite um inteiro n para o print dos inteiros de 0 a n: ");
    scanf("%d", &n);
    printf("Naturais de 0 a %d: \n", n);
    printToN(n, count);

    return 0;
}
