#include <stdio.h>
#include <stdlib.h>

int triangLat( int n, int count, int i, int flag){

    if( count == 0 ){
        return 0;
    }else if(count < n && flag == 0){
        for ( i = 0; i < count; i++)
            printf("*");
        printf("\n");
        
        triangLat(n, count+1, i, flag);
    }else if(n >= count){
        flag = 1;
        for ( i = 0; i < count; i++)
            printf("*");
        printf("\n");
        
        triangLat(n, count-1, i, flag);
    }
    
}


int main(){
    int n, count = 1, i, flag = 0;

    printf("Digite o numero n: ");
    scanf("%d", &n);
   triangLat(n, count, i, flag);

    return 0;
}