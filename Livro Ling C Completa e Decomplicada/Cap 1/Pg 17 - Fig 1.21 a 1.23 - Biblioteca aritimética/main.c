//inclui as bibliotecas nativas
#include <stdio.h>
#include <stdlib.h>

//inclui nossa biblioteca, chamando o arquivo aritimetica.h contido na pasta headers gerada pelo codeblocks
#include "aritmetica.h"

int main(void) { //inicia o m�todo principal

		int x,y,z; //declara 3 vari�veis (x, y e z) do tipo inteiro
		char ch;   //declara uma vari�vel ch do tipo char
		printf("Digite uma opera��o matem�tica (+,-,*,/): "); // utiliza a fun��o nativa printf() para escrever na tela
		ch = getchar();//utiliza a fun��o getchar para receber um valor por input do usu�rio do tipo char, e atribui a vari�vel ch
		printf("Digite 2 n�meros: "); //novamente faz uso de printf()
		scanf("%d %d",&x,&y);//pega o input de dois valores a serem digitados pelo usu�rio, o primeiro ser� armazenado em x e o segundo em y
		switch(ch){ /*a estrutura switch realiza compara��es em rela��o ao par�metro passado ente par�nteses
		            cada case � como se fosse um if*/

		case '+': z = soma(x,y); break; /*caso o valor de ch seja +, atribua a z o valor retornado pela fun��o soma (que criamos na nossa biblioteca),
                                        em que esta recebe os par�metros x e y vindos do input do usu�rio em scanf() na linha 16*/
		case '*': z = produto(x,y); break; //faz o mesmo que a fun��o acima por�m caso ch seja *, e atribui a z o retorno da fun��o produto
		case '-': z = subtracao(x,y); break;//j� deu pra entender a l�gica neh?
		case '/': z = divisao(x,y); break;
		default: z = soma(x,y); //o default � executado quando nenhuma das verifica��es acima foi verdadeira

		}

		printf("Resultado = %d\n ", z);//escreve na tela "Resultado = " e em seguida o valor da vari�vel z

		system("pause"); //faz uma pausa antes de terminar o programa
		return 0; /*Como a fun��o main � do tipo inteiro, ela deve retornar um valor inteiro
                    O valor 0 indica que est� tudo OK*/


}
