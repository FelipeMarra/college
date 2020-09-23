#include <stdio.h>
#include <stdlib.h>

int printDecrescente(int n){

    if(n < 1){
        printf("%d", n );
        return 0;
    }else{
        printf("%d,", n );
        return printDecrescente(n-1);
    }
     
}

int main(){

    int n;

    printf("Qual seu n? ");
    scanf("%d", &n);

    printf("Print de %d a 0: ", n);
    printDecrescente(n);

    return 0;
}