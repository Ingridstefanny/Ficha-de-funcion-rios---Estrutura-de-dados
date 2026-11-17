#include <stdio.h>
#include <stdlib.h>

/**
 * No tem 2 atributos:
 *  elemento: tipo (um item da fila. hardcoded pra INT aqui)
 *  proximo: *No (o endereco do proximo no da fila)
**/
typedef struct no No;

/**
 * Fila tem 3 atributos:
 *  tamanho: int (o tamanho da fila)
 *  inicio: *No (o endereco do primeiro no da fila)
 *  fim: *No (o endereco do ultimo no da fila)
 *   !! fim nao e limpado ao desenfileirar o ultimo !!
 *   !!  item da fila, evitar acessar diretamente   !!
**/
typedef struct fila Fila;


/**
 * newFila: cria uma fila vazia, retornando o endereco dela
 * retornara NULL caso a alocacao da fila falhe
**/
Fila* newFila(void);

/**
 * isEmpty: retorna 1 se a fila estiver vazia, 0 se nao
**/
int isEmpty(Fila *fila);

/**
 * peek: retorna o item no inicio da fila
 * !! se a fila estiver vazia: !!
 * -imprimira uma mensagem no console e retornara 0/NULL
**/
int peek(Fila *fila);

/**
 * enfileirar: adiciona um no com o elemento no final da fila
 * retornara 1 se conseguir adicionar, 0 se nao (por erro de alocacao)
**/
int enfileirar(Fila *fila, int elemento);

/**
 * desenfileirar: remove e retorna o item no inicio da fila
 * !! se a fila estiver vazia: !!
 * -imprimira uma mensagem no console e retornara 0/NULL
**/
int desenfileirar(Fila *fila);

/**
 * liberar: libera a fila e os seus nos da memoria
**/
void liberar(Fila *fila);
