#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, older = 0, youngest = 10000;
    float heaviest = 0.0, lighter = 10000.0;
    char STRheaviest[30], STRolder[30], STRyoungest[30], STRlighter[30];


    struct gato
    {
        char nome[30];
        char raca[30];
        int idade;
        float peso;
    };

    struct gato g[5];

    for ( i = 0; i < 5; i++)
    {
        printf("\n");
        printf("Qual o nome do gatin? ");
        setbuf(stdin, NULL);
        gets(g[i].nome);

        printf("Qual a raca do bixano? ");
        setbuf(stdin, NULL);
        gets(g[i].raca);

        printf("Qual a idade do individuo? ");
        setbuf(stdin, NULL);
        scanf("%d", &g[i].idade);

        printf("Qual o peso dda praga? ");
        setbuf(stdin, NULL);
        scanf("%f", &g[i].peso);

    }

    for ( i = 0; i < 5; i++)
    {
        if (g[i].idade < youngest){
            youngest = g[i].idade;
        }
        if (g[i].idade > older){
            older = g[i].idade;
        }
        if (g[i].peso > heaviest){
            heaviest = g[i].peso;
        }
        if (g[i].peso < lighter){
            lighter = g[i].peso;
        }
    }

    for ( i = 0; i < 5; i++)
    {
        if (g[i].idade == youngest){
            strncpy( STRyoungest, g[i].nome, 30);
        }

        if (g[i].idade == older){
            strncpy( STRolder, g[i].nome, 30);
        }


        if (g[i].peso == heaviest)
            strncpy( STRheaviest, g[i].nome, 30);

        if (g[i].peso == lighter)
            strncpy( STRlighter, g[i].nome, 30);
    }

    printf("\n");
    printf("O gatin mais novo eh o %s e o mais velho eh %s\n", STRyoungest, STRolder);
    printf("O gatin mais pesado eh o %s, e o mais leve %s \n", STRheaviest, STRlighter);

    return 0;
}