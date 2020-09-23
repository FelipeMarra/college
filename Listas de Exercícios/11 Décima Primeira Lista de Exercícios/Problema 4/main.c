#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    int i, cod = 1, qtd, flagSemEstoque = 0;

    struct produto
    {
        int cod, qtd;
        char nome[25];
        float preco;
    };
    
     struct produto p[N];

    for ( i = 0; i < N; i++){
        printf("Digite o %d codigo: ", i);
        scanf("%d", &p[i].cod);

        printf("Digite o %d nome: ", i);
        setbuf(stdin, NULL);
        gets(p[i].nome);

        printf("Digite o %d preco: ", i);
        scanf("%f", &p[i].preco);

        printf("Digite a %d quantidade: ", i);
        scanf("%d", &p[i].qtd);
        printf("\n");
    }

    do{
       
        printf("Digite seu codigo: ");
        scanf("%d", &cod);
        if( cod == 0)
            break;

        for ( i = 0; i < N; i++){
            if(p[i].cod == cod){
                printf("Qual a quantidade desejada: ");
                scanf("%d", &qtd);
                
                if(p[i].qtd >= qtd){
                    p[i].qtd -= qtd;
                    printf("Estoque atualizado! Foram removidas %d unidades, restam %d \n", qtd, p[i].qtd);
                }else{
                     printf("Produto sem estoque \n");
                     flagSemEstoque = 1;
                }

            }else if (i == N-1 && flagSemEstoque == 1){
                printf("Produto ineistente \n");
            }
         flagSemEstoque == 0;
        }
        printf("\n");    
    }while( cod != 0);
    
    printf("Fim");

    return 0;
}
