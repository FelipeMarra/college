#include <stdio.h>
#include <stdlib.h>

int main(){

    char c; int n; float f;

    scanf("%c%d%f", &c,&n,&f);

    printf("Separado por espacos: %c %d %f \n", c,n,f); 
    
    printf("Separado por tab horizontal: \t%c \t%d \t%f \n", c,n,f);
    
    printf("Separado por linha: \n%c \n%d \n%f", c,n,f);


    return 0;
}
