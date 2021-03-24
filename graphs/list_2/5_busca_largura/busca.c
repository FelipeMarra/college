#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include "queue.h"

//gcc -c busca.c queue.c && gcc busca.o queue.o -o prog && ./prog

typedef struct TGrafo{
  int dir;       		//0 não direcionado, 1 direcionado, -1 grafo nao criado
  int qv;    		    //quantidade de vértices
  int **matrizadj; //matriz de adjacência alocada dinamicamente
} Grafo;

Grafo* criaGrafo(int dir, int qv){
    Grafo* g = (Grafo*) malloc(sizeof(Grafo)); 
    g->dir = dir; 
    g->qv = qv; 
    //Aloca a matriz |V|x|V| 
    g->matrizadj = (int**) malloc(qv*sizeof(int*));
    for (int i = 0; i < qv; i++)
        g->matrizadj[i] = (int*) malloc(qv*sizeof(int));
    return g; 
}

void inicializaMatrizAdj(Grafo* g){
    for (int i = 0; i < g->qv; i++) 
        for (int j = 0; j < g->qv; j++)
            g->matrizadj[i][j] = 0;
}

void criaAresta(Grafo* g, int u, int v, int peso){
    if (u < 0 || u >= g->qv) return;
    if (v < 0 || v >= g->qv) return;
    if (g->dir)
        g->matrizadj[u][v] = peso; 
    else {
        g->matrizadj[u][v] = peso; 
        g->matrizadj[v][u] = peso; 
    } 
}

void imprimeMatrizAdj(Grafo* g){
    printf("Matriz de adjacência:\n"); 
    for (int i = 0; i < g->qv; i++) {
        for (int j = 0; j < g->qv; j++)
            printf(" %d ", g->matrizadj[i][j]);
        printf("\n");
    }
}

void liberaGrafo(Grafo *g){
    for (int i = 0; i < g->qv; i++) 
        free(g->matrizadj[i]);
    free(g->matrizadj); 
    free(g); 
}

int* adjacentes(Grafo* g, int v){
    //inicializa lista
    int* adjacentes = malloc(g->qv * sizeof(int));
    int index = 0;
    //varre a linha v procurando por pesos maiores que 0
    for (int i = 0; i < g->qv; i++){
        int peso_no_adj = g->matrizadj[v][i];
        if(peso_no_adj){
            printf("%d eh adjacente de %d \n",i,v);
            adjacentes[index] = i;
        }else{
            adjacentes[index] = -1;
        }
            index++;
    }
    return adjacentes;
}

typedef struct TBuca{
    int id;
    int cor;//0 branco, 1 cinza, 2 preto
    int d;//distância da origem
    int pred;//predecessor
} NoBusca;

void buscaLargura(Grafo* g, int s){
    //nós do grafo
    NoBusca* nos = (NoBusca*) malloc(g->qv * sizeof(NoBusca));
    
    //inicializa outros nós como branco e s como cinza
    for(int i = 0; i < g->qv; i++){
        nos[i].id = i;
        if(i != s){
            nos[i].cor = 0;
            nos[i].d = INT_MAX;
            nos[i].pred = -1;
        }else{
            nos[i].cor = 1;
            nos[i].d = 0;
            nos[i].pred = i;
        }
    }
    
    //TESTE INICIALIZAÇÂO
    for(int i = 0; i < g->qv; i++){
        NoBusca no = nos[i];
        printf("INICIALIZADO: id: %d, cor: %d, dis: %d, pred: %d \n",no.id,no.cor,no.d,no.pred);
    }
    
    //Inicia fila com s
    Queue Q;
    Q = createQueue();
    insertValue(Q,s);

    //Enquanto a fila não está vazia
    while (!vazio(Q)){
        NoBusca u = nos[removeValue(Q)];//Desenfileira
        int *adj = adjacentes(g,s);
        for(int i = 0; i < g->qv; i++){
            if(adj[i] != -1){
                NoBusca v = nos[adj[i]];
                v.cor = 1;
                v.d = u.d + 1;
                v.pred = u.id;
                insertValue(Q,v.id);
            }
        }
    printQueue(Q);
    u.cor = 2;
    printf("Vertice %d: cor = %d, d = %d e pred = %d\n", u.id, u.cor, u.d, u.pred);
    }
}

int main(){
    // int qv, dir; 
    // printf("Qual a quantidade de vertices do grafo:\n"); 
    // scanf("%d", &qv);
    // printf("O grafo é direcionado (1) ou não (0):\n");
    // scanf("%d", &dir);

    // if (qv <= 0){
    //     printf("Digite um valor válido para a quantidade de vertices\n");
    //     exit(1); 
    // }
    // if (dir != 0 && dir != 1){
    //     printf("Digite um valor válido para o tipo de grafo\n");
    //     exit(1); 
    // }

    Grafo* grafo = criaGrafo(0,6); 
    inicializaMatrizAdj(grafo); 
    //int u = 0, v, peso; 
    // while (u != -1){
    //     printf("Digite os vertices de origem, destino e o peso da aresta (origem -1 para sair):\n");         
    //     scanf("%d %d %d", &u, &v, &peso);
    //     criaAresta(grafo,u,v,peso);         
    // }

    criaAresta(grafo,0,1,1);         
    criaAresta(grafo,0,4,1);         
    criaAresta(grafo,1,5,1);         
    criaAresta(grafo,5,3,1);         
    
    imprimeMatrizAdj(grafo); 

    buscaLargura(grafo, 0);

    liberaGrafo(grafo);
    system("pause");
    return 0; 
}