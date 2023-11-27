#ifndef ARVORE_H
#define ARVORE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct TipoElemento {
    char *palavra;
    char *sinonimo;
} Elemento;

typedef struct TipoNo {
    Elemento *elemento;
    struct TipoNo *esquerda;
    struct TipoNo *direita;
} No;

typedef struct TipoArvore {
    No *raiz;
} Arvore;

void CriarArvore(Arvore *arvore);
int ArvoreVazia(Arvore *arvore);
No* InserirNo(No *raiz, Elemento *e);
Arvore PesquisarArvore(Arvore *arvore, char *palavra);
Elemento RemoverNo(No **raiz, char *palavra);
void LimparArvore(No *raiz);
void ImprimirArvore(No *raiz);
void ImprimirNo(No *raiz);


#endif // ARVORE_H
