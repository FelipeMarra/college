#include <stdio.h>
#include <stdlib.h>

int main()
{
    char path[50], path1[50],c;
    printf("Digite o nome do primeiro arquivo texto: ");
    gets(path);

    printf("Digite o nome do segundo arquivo texto: ");
    gets(path1);

    FILE *fp, *fp1, *fp2W,*fp2A,*fp2R ;

    fp = fopen(path, "r");
    fp1 = fopen(path1, "r");
    fp2W = fopen("novo.txt", "w");

    if(  fp == NULL || fp1 == NULL || fp2W == NULL){
        printf("deu ruim");
        exit(1);
    }
//Cria-se o novo arquivo com os dados de fp
    while ( (c = fgetc(fp)) != EOF)
      fputc(c, fp2W);

    fclose(fp);
    fclose(fp2W);
//Com o novo arquivo criado vamos dar um append dos dados de fp1
    fp2A = fopen("novo.txt", "a");

    if(fp2A == NULL){
        printf("deu ruim");
        exit(1);
    }

    while ( (c = fgetc(fp1)) != EOF)
      fputc(c, fp2A);
    
    fclose(fp1);
    fclose(fp2A);

    //Reabrindo novo como read
    fp2R = fopen("novo.txt", "r");

    //Print fp2
     while ( (c = fgetc(fp2R)) != EOF)
      printf("%c", c);
   
    fclose(fp2R);
   
    return 0;
}
