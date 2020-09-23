#include <stdio.h>
#include <stdlib.h>

int contaVogais(char *path){
    char c;
    int count = 0;
    FILE *fp;

    fp = fopen(path, "r");

    while ( (c = fgetc(fp) ) != EOF)
    {
        if ( c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' || c == 'u')
            count++;
    }
    
    return count;
} 

int main()
{
    int nVogais;
    char path[50];
    printf("Digite um camin: ");
    gets(path);

    nVogais = contaVogais(path);

    printf("%d", nVogais);

    return 0;

}
