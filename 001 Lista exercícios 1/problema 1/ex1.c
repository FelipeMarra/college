#include <stdio.h>
#include <stdlib.h>

    typedef struct{
        float real;
        float imag;
    }Complexo;
    
    Complexo soma(Complexo* u, Complexo* v){
        Complexo z;

        z.real = (*u).real + v -> real;
        z.imag = u -> imag + v -> imag;

        return z;
    }

int main()
{
    Complexo u,v,z;    

    u.real = 2;
    u.imag = 3;

    v.real = 4;
    v.imag = 5;

    z = soma(&u, &v);

    printf("z = %f + %fi \n", z.real, z.imag);

    return 0;
}
