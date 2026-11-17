#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

void criarPilha(Pilha *p){
    p->topo = -1;
}

int vazia(Pilha *p){
    if(p->topo == -1){
        return 1;
    }
    return 0;
}

int cheia(Pilha *p){
    if(p->topo == MAX-1){
        return 1;
    }
    return 0;
}

int empilhar(Pilha *p, int valor){
    if(cheia(p) == 1){
        return 0;
    }

    p->topo++;
    p->dados[p->topo] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valor){
    if(vazia(p) == 1){
        return 0;
    }

    *valor = p->dados[p->topo];
    p->topo--;
    return 1;
}

int consultarTopo(Pilha *p, int *valor){
    if(vazia(p) == 1){
        return 0;
    }

    *valor = p->dados[p->topo];
    return 1;
}