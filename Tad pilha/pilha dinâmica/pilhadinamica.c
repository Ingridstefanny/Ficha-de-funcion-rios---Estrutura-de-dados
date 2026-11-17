#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilhadinamica.h"


void criarPilha(Pilha *p){
    p->topo = NULL;
}

int vazia(Pilha *p){
    if(p->topo == NULL){
        return 1;
    }
    return 0;
}

int empilhar(Pilha *p, int valor){
    No *novo = malloc(sizeof(No));

    if(novo == NULL){
        return 0;
    }

    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;

    return 1;

}


int desempilhar(Pilha *p, int *valor){
    if(vazia(p)){
        return 0;
    }

    No *aux = p->topo;
    *valor = aux->valor;
    p-> topo = aux->prox;
    free(aux);

    return 1;
}

int consultarTopo(Pilha *p, int *valor){
    if(vazia(p) == 1){
        return 0;
    }

   *valor = p->topo->valor;
   return 1;
}