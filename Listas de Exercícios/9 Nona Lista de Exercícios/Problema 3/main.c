#include <stdio.h>
#include <stdlib.h>

int  strInvert(char *str,  char *invert, int tam, int count){

    if( tam <  0 ){
        printf("invert: %s \n", invert);
        return 0;
    }
    else{
        invert[count] = str[tam];
    }
    return strInvert(str, invert, tam-1, count+1);
}

int main(){

    int tam, j, count = 0;
    printf("Digite o tamanho da string: ");
    scanf("%d", &tam);
    char str[tam+1], invert[tam+1];

    for ( j = 0; j < tam; j++){
        invert[j] = ' ';
        str[j] = ' ';    
    }

    printf("Digite a string: ");
    setbuf(stdin, NULL);
    gets(str);
    printf("str: %s \n", str);
    
   strInvert(str, invert, tam-1, count);
    
    return 0;
}