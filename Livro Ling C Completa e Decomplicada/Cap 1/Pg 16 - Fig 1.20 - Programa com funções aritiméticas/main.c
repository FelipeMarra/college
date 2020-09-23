//inclui as bibliotecas nativas
#include <stdio.h>
#include <stdlib.h>

int soma (int a, int b)//cia uma função que retornará um inteiro, e tem duas variáveis inteiras como parâmetros
{
	return a+b; //retorna a soma de a e b
}

int subtracao (int a, int b) //assim como as abaixo também cia uma função que retornará um inteiro, e tem duas variáveis inteiras como parâmetros
{
	return a-b; //retorna a diferença de a e b
}

int produto (int a, int b)
{
	return a*b; //retorna o produto de a e b
}

int divisao (int a, int b){
	return a/b; //retorna o quociente de a e b
}

int main(void) { //inicia o método principal

		int x,y,z; //declara 3 variáveis (x, y e z) do tipo inteiro
		char ch;   //declara uma variável ch do tipo char
		printf("Digite uma operação matemática (+,-,*,/): "); // utiliza a função nativa printf() para escrever na tela
		ch = getchar();//utiliza a função getchar para receber um valor por input do usuário do tipo char, e atribui a variável ch
		printf("Digite 2 números: "); //novamente faz uso de printf()
		scanf("%d %d",&x,&y);//pega o input de dois valores a serem digitados pelo usuário, o primeiro será armazenado em x e o segundo em y
		switch(ch){ /*a estrutura switch realiza comparações em relação ao parâmetro passado ente parênteses
		            cada case é como se fosse um if*/

		case '+': z = soma(x,y); break; /*caso o valor de ch seja +, atribua a z o valor retornado pela função soma (que criamos na nossa biblioteca),
                                        em que esta recebe os parâmetros x e y vindos do input do usuário em scanf() na linha 16*/
		case '*': z = produto(x,y); break; //faz o mesmo que a função acima porém caso ch seja *, e atribui a z o retorno da função produto
		case '-': z = subtracao(x,y); break;//já deu pra entender a lógica neh?
		case '/': z = divisao(x,y); break;
		default: z = soma(x,y); //o default é executado quando nenhuma das verificações acima foi verdadeira

		}

		printf("Resultado = %d\n ", z);//escreve na tela "Resultado = " e em seguida o valor da variável z

		system("pause"); //faz uma pausa antes de terminar o programa
		return 0; /*Como a função main é do tipo inteiro, ela deve retornar um valor inteiro
                    O valor 0 indica que está tudo OK*/


}
