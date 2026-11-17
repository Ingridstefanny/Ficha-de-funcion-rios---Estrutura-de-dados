#include <stdio.h>
#include <stdlib.h>

// lugares em que o tipo da fila ta hardcoded:
// l12, l21 x2, l44, l54 (arg), l65, l71

struct fila {
  int limite;
  int tamanho;
  int inicio;
  int fim;
  int *vetor;
};
typedef struct fila Fila;

/* ----------*/

Fila* newFila(unsigned int tamanho) {
  if (tamanho <= 0) { return NULL; }
  Fila *fila = malloc(sizeof(Fila));
  int *vetor = malloc(tamanho * sizeof(int));
  if (fila == NULL || vetor == NULL) { return NULL; }
  
  fila->limite = tamanho;
  fila->tamanho = 0;
  fila->inicio = 0;
  fila->fim = 0;
  fila->vetor = vetor;
  
  return fila;
}


int isEmpty(Fila *fila) {
  return (fila->tamanho == 0);
}


int isFull(Fila *fila) {
  return (fila->tamanho >= fila->limite);
}


int peek(Fila *fila) {
  if (isEmpty(fila)) {
    printf("Fila vazia\n");
    return 0;
  }
  
  return fila->vetor[fila->inicio];
}


int enfileirar(Fila *fila, int elemento) {
  if (isFull(fila)) { return 0; }
  
  fila->vetor[fila->fim] = elemento;
  fila->fim = (fila->fim++) % fila->limite;
  fila->tamanho++;
  
  return 1;
}


int desenfileirar(Fila *fila) {
  if (isEmpty(fila)) {
    printf("Fila vazia\n");
    return 0;
  }
  
  int elemento = fila->vetor[fila->inicio];
  fila->inicio = (fila->inicio++) % fila->limite;
  fila->tamanho--;
  
  return elemento;
}


void liberar(Fila *fila) {
  free(fila->vetor);
  free(fila);
}

/* ----------*/
