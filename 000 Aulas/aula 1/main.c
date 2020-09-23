#include "aula1.h"

int main(){
	Complexo u,v,z;
	float a = 3;
	float b = 4;
	float c = 5;
	float d = 6;
	
	u = criar(a,b);
	v = criar(c,d);
	z = soma(u,v);
	
	return 0;
}