/*
    A implementação da biblioteca:
    Aqui as funções são de fato implementadas, fazendo uso das variáveis também já decladaradas no cabeçãlho
*/
#include "aritmetica.h" //chama o cabeçãlho
int soma (int a, int b){  //cia uma função que retornará um inteiro, e tem duas variáveis inteiras como parâmetros
	return a+b; //retorna a soma de a e b
}

int subtracao (int a, int b){ //assim como as abaixo também cia uma função que retornará um inteiro, e tem duas variáveis inteiras como parâmetros
	return a-b; //retorna a diferença de a e b
}

int produto (int a, int b){
	return a*b; //retorna o produto de a e b
}

int divisao (int a, int b){
	return a/b; //retorna o quociente de a e b
}
