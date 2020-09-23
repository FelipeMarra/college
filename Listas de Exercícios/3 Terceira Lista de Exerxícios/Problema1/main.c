#include <stdlib.h>
#include <stdio.h>
int power(int a,int b) {
        int result=1,count=0;
        for(;b>count; count++){
            result *= a;
        }

        return result;
    }
int main(){

    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d ^ %d = %d", a,b,power(a,b));

    return 0;
}
