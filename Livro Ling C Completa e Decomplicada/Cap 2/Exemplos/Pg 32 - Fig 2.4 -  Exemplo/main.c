#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 125;  // valor em decimal, equivale a: 1*10^2 + 1*10^1 + 5*10^0 => 100+20+5 => 125
    int b = 0435; // valor em octal, equivale a: 4*8^2 + 3*8^1 + 5*8^0 => 256+24+5 => 285
    int c = 0x1FA;// valor em hexadecimal, quivale a: 1*16^2 + 15*16^1 + 10*16^0 => 256+240+10 => 506

    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);
    printf("Valor de c: %d\n", c);
    system("pause");
    return 0;
}
