#ifndef HASH_H
#define HASH_H

#include "pilha.h"

#define TAM_HASH 3

typedef struct TipoEntrada {
    char *chave;
    Pilha pilha;
} Entrada;

typedef Entrada Hash[TAM_HASH];

void CriarHash(Hash h);
int FuncaoHash(char *chave);
void InserirHash(Hash h, char *chave, Elemento *e);
Pilha PesquisarHash(Hash h, char *chave);
Elemento ExcluirHash(Hash h, char *chave);
void LimparHash(Hash h);

#endif // HASH_H

