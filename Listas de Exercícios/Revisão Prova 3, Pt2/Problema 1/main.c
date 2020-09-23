#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas;
    char path[50],c;
    printf("Digite o nome de um arquivo texto: ");
    gets(path);

    FILE *fp;

    fp = fopen(path, "r");

    if(  fp == NULL){
        printf("deu ruim");
        exit(1);
    }

    while ( (c = fgetc(fp)) != EOF)
    {
      if( c == '\n')
        linhas++;
    }
    
    printf("linhas: %d", linhas+1);
    
    fclose(fp);
    return 0;
}
