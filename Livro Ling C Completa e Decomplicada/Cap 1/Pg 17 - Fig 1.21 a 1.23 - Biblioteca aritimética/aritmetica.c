/*
    A implementa��o da biblioteca:
    Aqui as fun��es s�o de fato implementadas, fazendo uso das vari�veis tamb�m j� decladaradas no cabe��lho
*/
#include "aritmetica.h" //chama o cabe��lho
int soma (int a, int b){  //cia uma fun��o que retornar� um inteiro, e tem duas vari�veis inteiras como par�metros
	return a+b; //retorna a soma de a e b
}

int subtracao (int a, int b){ //assim como as abaixo tamb�m cia uma fun��o que retornar� um inteiro, e tem duas vari�veis inteiras como par�metros
	return a-b; //retorna a diferen�a de a e b
}

int produto (int a, int b){
	return a*b; //retorna o produto de a e b
}

int divisao (int a, int b){
	return a/b; //retorna o quociente de a e b
}
