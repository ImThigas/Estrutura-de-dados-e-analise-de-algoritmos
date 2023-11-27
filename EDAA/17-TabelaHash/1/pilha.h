#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILHA 100

typedef struct TipoElemento {
    char *palavra;
    char *sinonimo;
} Elemento;

typedef struct TipoPilha {
    Elemento itens[TAM_PILHA];
    int topo;
} Pilha;

void CriarPilha(Pilha *p);
int PilhaVazia(Pilha *p);
int PilhaCheia(Pilha *p);
void Empilhar(Pilha *p, Elemento *e);
Elemento Desempilhar(Pilha *p);
void ImprimirPilha(Pilha *p);

#endif // PILHA_H
