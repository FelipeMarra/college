#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i = 0;
    char list[4][30];
    for (; i < 5; i++){
        printf("nome: ");
        setbuf(stdin, NULL);
        fgets(list[i], 30, stdin);
    }

    for (i = 0; i < 5; i++){
        printf("posicao tal: %s", list[i]);
    }

    return 0;
}