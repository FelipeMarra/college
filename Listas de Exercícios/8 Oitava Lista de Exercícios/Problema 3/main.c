#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam,i,j, count = 0;

    char vogais[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U',  '\0' };

    printf("Digite o tamanho da sua string: ");
    scanf("%d", &tam);
    char str[tam];

    printf("Digite sua string: ");
    setbuf(stdin, NULL);
    gets(str);

    for ( i = 0; i < tam; i++){
        for ( j = 0; j < tam; j++){
            if (str[i] == vogais[j]){
                count++;
            }
        }
    }
    
    printf("Numero de vogais = %d ", count);

    return 0;
}
