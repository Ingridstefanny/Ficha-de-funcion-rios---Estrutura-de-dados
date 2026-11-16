#ifndef PILHA_H
#define PILHA_H

#define MAX 10

typedef struct {
    int dados[MAX];
    int topo;
}Pilha;

void criarPilha(Pilha *p);
int vazia(Pilha *p);
int cheia(Pilha *p);
int empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p, int *valor);
int consultarTopo(Pilha *p, int *valor);

#endif