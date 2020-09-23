#include <stdio.h>
#include <stdlib.h>

void func1(){
    int x; //variavel local existente apenas na funcao func1()
}

void func2(){
    int x; //variavel local existente apenas na funcao func2()
}

int main()
{
    int x;//variavel local existente apenas na funcao main()
    printf("Digite um valor para x: ");
    scanf("%d", &x);
    if(x==5){
        int y=1;//variavel local existente apenas neste if, dentro da funcao main()
        printf("O valor de y eh: %d\n",y);
    }
    system("pause");
    return 0;
}
