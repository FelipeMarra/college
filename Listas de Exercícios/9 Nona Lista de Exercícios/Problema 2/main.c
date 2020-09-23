#include <stdio.h>
#include <stdlib.h>

int  ehPalindromo(char *str, char *invert, int tam, int  counter){

    if(counter == tam){
         printf("eh palindromo");
         return 0;
    }else if (str[counter] != invert[counter] ){
         printf("NAO eh palindromo");
         return 0;
    }else{
        return ehPalindromo(str, invert, tam, counter+1);
    }
}

int main(){

    int tam, counter = 0, i = 0, j;
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
    
    for ( j = tam-1; j >= 0; j--){
            invert[i] = str[j];
            i++;
    }
    printf("invert: %s \n", invert);
        

    ehPalindromo(str, invert, tam, counter);
        
    
    return 0;
}