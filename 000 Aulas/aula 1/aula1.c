#include <stdio.h>
#include <stdlib.h>
#include "aula1.h"

struct complexo{
	float real;
	float imag;
};

Complexo criar(float a, float b){
	Complexo z;
	
	z = malloc(sizeof(struct complexo));
	z->real = a;
	z->imag = b;
	printf("Numero complexo criado!\n");
	printf("Parte real: %f\n",z->real);
	printf("Parte imaginaria: %f\n\n",z->imag);
	
	return z;
}

Complexo soma(Complexo u, Complexo v){
	Complexo z;
	
	z = criar(u->real + v->real, u->imag + v->imag);
	printf("z = %f + %fi\n",z->real,z->imag);
	return z;
}