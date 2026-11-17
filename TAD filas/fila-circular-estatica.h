#include <stdio.h>
#include <stdlib.h>

/**
 * Fila tem 5 atributos:
 *  limite: int (maximo que a fila pode suportar)
 *  tamanho: int (quantidade de itens na fila)
 *  inicio: int (o indice do primeiro item na fila)
 *  fim: int (o menor indice livre na fila)
 *   -se inicio e fim forem iguais, quer dizer
 *    que a fila esta cheia ou vazia.
 *  vetor: tipo[] (a fila em si. hardcoded pra INT aqui)
**/
typedef struct fila Fila;


/**
 * newFila: cria uma fila vazia, retornando o endereco dela
 * nao criara a fila (retorno NULL) se:
 * -argumento 'tamanho' nao for positivo
 * -alocacao de alguma parte da fila falhar
**/
Fila* newFila(unsigned int tamanho);

/**
 * isEmpty: retorna 1 se a fila estiver vazia, 0 se nao
**/ 
int isEmpty(Fila *fila);

/**
 * isFull: retorna 1 se a fila estiver cheia, 0 se nao
**/ 
int isFull(Fila *fila);

/**
 * peek: retorna o item no inicio da fila
 * !! se a fila estiver vazia: !!
 * -imprimira uma mensagem no console e retornara 0/NULL
**/
int peek(Fila *fila);

/**
 * enfileirar: adiciona o elemento no final da fila
 * retornara 1 se conseguir adicionar, 0 se nao
**/
int enfileirar(Fila *fila, int elemento);

/**
 * desenfileirar: remove e retorna o item no inicio da fila
 * !! se a fila estiver vazia: !!
 " -imprimira uma mensagem no console e retornara 0/NULL
**/
int desenfileirar(Fila *fila);

/**
 * liberar: libera o espaco de memoria da fila
**/
void liberar(Fila *fila);
