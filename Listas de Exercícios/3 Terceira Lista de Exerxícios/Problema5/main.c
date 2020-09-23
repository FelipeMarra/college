#include <stdlib.h>
#include <stdio.h>

int main(){

    float n,H=0;
    int count;

    scanf("%f", &n);
    for(; n>0; n--){
        H += 1/n;
    }
    printf("O numero H eh: %f", H);
    return 0;
}