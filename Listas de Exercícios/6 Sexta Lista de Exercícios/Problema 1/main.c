#include <stdio.h>
#include <stdlib.h>
#define N 6
int main()
{
    char str[N];
    setbuf(stdin, NULL);
    printf("Digite sua string: ");
    fgets(str, N, stdin);
    printf("\n");
    printf("5 primeiros caracteres: %s \n", str);
    return 0;
}
