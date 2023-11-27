// hash.h
#ifndef HASH_H
#define HASH_H

#include "arvore.h"

#define TAM_HASH 3

typedef struct TipoEntrada {
    char *chave;
    Arvore arvore;
} Entrada;

typedef Entrada Hash[TAM_HASH];

void CriarHash(Hash h);
int FuncaoHash(char *chave);
void InserirHash(Hash h, char *chave, Elemento *e);
Arvore PesquisarHash(Hash h, char *chave);
Arvore RemoverArvore(Hash h, char *chave);
void LimparHash(Hash h);

#endif // HASH_H
