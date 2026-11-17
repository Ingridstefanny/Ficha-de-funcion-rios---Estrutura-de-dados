#include <stdio.h>
#include <stdlib.h>

// lugares em que o tipo da fila ta hardcoded:
// l8, l40, l50 (arg), l66, l73

struct no {
  int elemento;
  struct no *proximo;
};
typedef struct no No;


struct fila {
  int tamanho;
  No *inicio;
  No *fim;
};
typedef struct fila Fila;

/* ----------*/

Fila* newFila(void) {
  Fila *fila = malloc(sizeof(Fila));
  if (fila == NULL) { return NULL; }
  
  fila->tamanho = 0;
  fila->inicio = NULL;
  fila->fim = NULL;
  
  return fila;
}


int isEmpty(Fila *fila) {
  return (fila->tamanho == 0);
}


int peek(Fila *fila) {
  if (isEmpty(fila)) {
    printf("Fila vazia\n");
    return 0;
  }
  
  return fila->inicio->elemento;
}


int enfileirar(Fila *fila, int elemento) {
  No *no = malloc(sizeof(No));
  if (no == NULL) { return 0; }
  
  no->elemento = elemento;
  no->proximo = NULL;
  
  if (isEmpty(fila)) { fila->inicio = &no; }
  else /* fila nao vazia */ { fila->fim->proximo = &no; }
  fila->fim = &no;
  fila->tamanho++;
  
  return 1;
}


int desenfileirar(Fila *fila) {
  if (isEmpty(fila)) {
    printf("Fila vazia\n");
    return 0;
  }
  
  No *no = fila->inicio;
  int elemento = no->elemento;
  fila->inicio = no->proximo;
  free(no);
  fila->tamanho--;
  
  return elemento;
}


void liberar(Fila *fila) {
  No *no = fila->inicio;
  while(no != NULL) {
    No *todelete = no;
    no = no->proximo;
    free(todelete);
  }
  
  free(fila);
}

/* ----------*/
