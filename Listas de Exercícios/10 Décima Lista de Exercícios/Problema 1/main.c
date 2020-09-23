#include <stdio.h>
#include <stdlib.h>

int printExc( int n, int count, int i){

    if( n < count ){
        return 0;
    }else
    {
        for ( i = 0; i < count; i++)
            printf("!");
        printf("\n");
        
        printExc(n, count+1, i);
    }
    
}


int main(){
    int n, count = 1, i;

    printf("Digite o numero n: ");
    scanf("%d", &n);
    printExc(n, count, i);

    return 0;
}
