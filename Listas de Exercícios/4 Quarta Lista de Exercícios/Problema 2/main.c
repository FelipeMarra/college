#include <stdio.h>
#include <stdlib.h>
#define NUMERO 7
float idade[NUMERO];
float peso[NUMERO];

int main () {
    int i, pessoas = NUMERO, mais90 = 0;
    float somaIdades = 0;
    for (i = 1; i <= NUMERO; i++){

        printf( "Digite a idade do %d individuo: ", i); 
        scanf("%f", &idade[i-1]);
        somaIdades += idade[i-1];
    
        printf( "Digite o peso do %d individuo: ", i); 
        scanf("%f", &peso[i-1]);
        if (peso[i-1] > 90){
            mais90++;
        }
        printf( "\n");

    }    
    printf( "Pessoas com mais de 90 quilos: %d \n", mais90);
    printf( "Media das idades: %f \n", somaIdades/NUMERO);
return 0 ;
}