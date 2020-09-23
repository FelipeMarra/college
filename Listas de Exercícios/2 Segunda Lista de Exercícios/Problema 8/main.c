#include <stdio.h>
#include <stdlib.h>

int main(){

    int idade;
    printf("Dgite a quantos anos voce vive: ");
    scanf("%d", &idade);
    if (idade>=10 && idade<=14){
        printf("Eh kid");
    }else if (idade>=15 && idade<=17) {
        printf("Eh menino Juvenil");
    }else if (idade>=18 && idade<=50) {
        printf("Ta quase idoso");
    }else if (idade>=51) {
        printf("Death is coming to u");
    }
     
    return 0;
    }
