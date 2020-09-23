#include <stdlib.h>
#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    
    if(x == 2 || x == 3 || x == 5 || x == 7){

        printf("%d eh primo", x);

    }else if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0|| x % 7 == 0|| x == 1){
        printf("%d nao eh primo", x);
    }else{
        printf("%d eh primo", x);
    }
    


    return 0;
}
