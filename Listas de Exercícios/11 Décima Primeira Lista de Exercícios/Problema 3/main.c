#include <stdio.h>
#include <stdlib.h>
#define N 5

int main()
{
    int i, maiorTempo = 0;
    struct hora
    {
        int hr, min, seg, tdEmSeg;
    };

    struct hora h[N];

    for ( i = 0; i < N; i++){
        printf("Digite a %d hora: ", i);
        scanf("%d", &h[i].hr);

        printf("Digite o %d minuto: ", i);
        scanf("%d", &h[i].min);

        printf("Digite o %d segundo: ", i);
        scanf("%d", &h[i].seg);

        h[i].tdEmSeg = h[i].hr * 3600 + h[i].min * 60 + h[i].seg;
    }
    
    for ( i = 0; i < N; i++)
        if (h[i].tdEmSeg > maiorTempo)
            maiorTempo = h[i].tdEmSeg;
    
    for ( i = 0; i < N; i++){
        if (h[i].tdEmSeg == maiorTempo){
            printf("O maior tempo eh %d:%d:%d", h[i].hr, h[i].min, h[i].seg); 
            break;
        }
    }        

    return 0;
}
