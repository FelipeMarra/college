#include <stdlib.h>
#include <stdio.h>
struct cadastro{
    char nome[50];
    int idade;
    char rua[50];
    int numero;
};

int main()
{
    int i;
    struct cadastro c[4];
    for (i = 0; i < 4; i++)
    {
        gets(c[i].nome);
        scanf("%d", &c[i].idade);
        gets(rua[i].nome);
        scanf("%d", &c[i].numero);
    }
    
    return 0;
}
