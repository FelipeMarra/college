#include <stdio.h>
#include <stdlib.h>
#define NUMEROS 10
float numeros[NUMEROS];
int main () {
    int i, noIntervalo = 0;
    
    for (i = 1; i <= 10; i++){

        printf("Digite o %d numero: ", i);
        scanf("%f", &numeros[i-1]);
        if (numeros[i-1] > 40 && numeros[i-1]< 60 ){
            noIntervalo++;
        }
        printf("\n");
    }
    printf("Numeros no intervalo: %d", noIntervalo);
return 0 ;
}