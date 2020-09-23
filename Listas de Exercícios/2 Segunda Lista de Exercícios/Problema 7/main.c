#include <stdio.h>
#include <stdlib.h>

int main(){

    int num1, num2, num3;
    printf("Digite os 3 numeros: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    if(num1> num2 && num1> num3){
        printf("Este algoritimo eh burro mas o %d eh o maior", num1);            
    }else if (num2> num1 && num2> num3) {
        printf("Este algoritimo eh burro mas o %d eh o maior", num2);
    }else
    {
        printf("Este algoritimo eh burro mas o %d eh o maior", num3);
    }
    
    return 0;
}