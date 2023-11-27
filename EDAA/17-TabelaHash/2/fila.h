#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_FILA 100

typedef struct TipoElemento {
    char *palavra;
    char *sinonimo;
} Elemento;

typedef struct TipoFila {
    Elemento itens[TAM_FILA];
    int frente, tras;
} Fila;

void CriarFila(Fila *f);
int FilaVazia(Fila *f);
int FilaCheia(Fila *f);
void Enfileirar(Fila *f, Elemento *e);
Elemento Desenfileirar(Fila *f);
void ImprimirFila(Fila *f);

#endif // FILA_H
