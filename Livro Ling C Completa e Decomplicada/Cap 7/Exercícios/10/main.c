#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i,tamanhoStr;
    printf("Digite quantos caracateres tera sua str: ");
    scanf("%d", &tamanhoStr);
    char str[tamanhoStr];
     for(i = 0; i < tamanhoStr; i++){
        str[i] = 0;
    }
    printf("Digite sua str de %d caracteres: ", tamanhoStr);
    setbuf(stdin, NULL);
    gets(str);
    printf("Sua string normal: %s \n", str);
    for(i = 0; i < tamanhoStr; i++){
        if(str[i] != 0){
            str[i] -= 32;
        }
    }
    printf("Sua string UperCase: %s \n", str);

    return 0;
}
