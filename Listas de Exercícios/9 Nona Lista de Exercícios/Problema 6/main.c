#include <stdio.h>
#include <stdlib.h>

float printCrescente(int n, int count){

    if(count == n){
        printf("%d", n );
        return 0;
    }else{
        printf("%d,", count );
        return printCrescente(n, count+1);
    }
     
}

int main(){

    int n, count;

    printf("Qual seu n? ");
    scanf("%d", &n);

    printf("Print de 0 a %d : ", n);
    printCrescente(n, count);

    return 0;
}