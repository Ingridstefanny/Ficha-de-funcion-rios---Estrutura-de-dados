#include <stdio.h>
#include <stdlib.h>

// lugares em que o tipo da fila ta hardcoded:
// l10, l19 x2, l40, l50 (arg), l60, l66

struct fila {
  int limite;
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
  fila->fim = 0;
  fila->vetor = vetor;
  
  return fila;
}


int isEmpty(Fila *fila) {
  return (fila->fim == 0);
}


int isFull(Fila *fila) {
  return (fila->fim >= fila->limite);
}


int peek(Fila *fila) {
  if (isEmpty(fila)) {
    printf("Fila vazia\n");
    return 0;
  }
  
  return fila->vetor[0];
}


int enfileirar(Fila *fila, int elemento) {
  if (isFull(fila)) { return 0; }
  
  fila->vetor[fila->fim] = elemento;
  fila->fim++;
  
  return 1;
}


int desenfileirar(Fila *fila) {
  if (isEmpty(fila)) {
    printf("Fila vazia\n");
    return 0;
  }
  
  int elemento = fila->vetor[0];
  int i;
  for (i = 0; i < fila->fim; i++) { fila->vetor[i] = fila->vetor[i+1]; }
  fila->fim--;
  
  return elemento;
}


void liberar(Fila *fila) {
  free(fila->vetor);
  free(fila);
}

/* ----------*/
