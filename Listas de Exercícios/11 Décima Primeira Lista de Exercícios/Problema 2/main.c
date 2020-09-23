#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float distancia2pts( float x1,  float x2,  float y1,  float y2){
    
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

}

int main()
{
    int i;
    struct ponto
    {
        float x, y;
    };
    struct ponto p[2];
   
    for (i = 0; i < 2; i++)    {
    printf("Digite as do %d ponto: \n", i);
    printf("x: ");
    scanf("%f", &p[i].x);
    printf("y: ");
    scanf("%f", &p[i].y);
    }

    printf("A distancia entre os dois pontos eh: %f", distancia2pts(p[0].x, p[1].x, p[0].y, p[1].y ));
   
    return 0;
}
