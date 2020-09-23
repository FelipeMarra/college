#include <stdio.h>
#include <stdlib.h>

int main(){
    float salario, prestacao;
    printf("Digite o valor do salario: ");
    scanf("%f", &salario);
    printf("Digite o valor da prestacao: ");
    scanf("%f", &prestacao); 
    prestacao > salario * 0.2 ? printf("Emprestimo nao consedido") : printf("Emprestimo consedido");
    return 0;
    }