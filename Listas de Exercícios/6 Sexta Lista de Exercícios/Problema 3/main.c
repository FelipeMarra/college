#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho, i;
    //Criacao da str com espacos vazios
    printf("Digite quantos caracterres vc vai alocar na memoria: ");
    scanf("%d", &tamanho);
    //+1 no tamanho pelo \n do fgets() o compilador ja poe o \0
    tamanho += 1;
    char str[tamanho];
    printf("Digite os caracteres: ");
    setbuf(stdin, NULL);
    fgets(str, tamanho, stdin);
    //tirando  \n
    for( i = 0; i < tamanho; i++){
        if(str[i] == '\n'){
            str[i] = ' ';
        }
    }
    //loop print ao contrario
    printf("A string %s ao contrario eh : \n", str);
    for( i = tamanho; i >= 0; i--){
        printf("%c", str[i]);        
    }
    printf("\n");
    return 0;
}
