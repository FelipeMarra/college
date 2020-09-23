#include <stdlib.h>
#include <stdio.h>
int fac(int a){
    int factorial=1;

    for(; a>1; a--){
        factorial *= a;
    }

    return factorial;
}
int main(){
    int a;
    scanf("%d", &a);
    printf("O fatorial de %d eh %d", a,fac(a));
    return 0;
}
