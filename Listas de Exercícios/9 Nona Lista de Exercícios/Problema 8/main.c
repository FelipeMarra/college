#include <stdio.h>
#include <stdlib.h>

int nAn(int n){
    int i, nAn = 1;
    for ( i = 0; i < n; i++){
        nAn *= n;
    }
    return nAn;
}

int  hiperfatorial(int n, int produto){

    if(n == 1){
        printf("%d", produto);
        return 0;
    }else{
        produto *=   nAn(n);
        return hiperfatorial(n-1, produto);
    }
     
}

int main(){

    int n, produto = 1;

    printf("Qual seu n? ");
    scanf("%d", &n);

    printf("Calculo do seu hiperfatorial  ate %d: ", n);
    hiperfatorial(n, produto);

    return 0;
}