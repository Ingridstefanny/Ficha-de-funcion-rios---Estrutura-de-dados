#ifndef PILHA_H
#define PILHA_H


typedef struct No{
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void criarPilha(Pilha *p);

int vazia(Pilha *p);

int empilhar(Pilha *p, int valor);

int desempilhar(Pilha *p, int *valor);

int consultarTopo(Pilha *p, int *valor);

#endif