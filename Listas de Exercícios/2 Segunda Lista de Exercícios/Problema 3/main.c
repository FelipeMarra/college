#include <stdio.h>
#include <stdlib.h>

int main(){

    float x,y,z;
    printf("Digite tres valores: ");
    scanf("%f %f %f", &x, &y, &z);
    if(x>y && x>z){
        printf("%f eh o maior valor.", x);
    }else if( y>x && y>z){
        printf("%f eh o maior valor.", y);
    }else {
        printf("%f eh o maior valor.", z);
    }
    return 0;
}