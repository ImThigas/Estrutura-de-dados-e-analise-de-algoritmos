#ifndef HASH_H
#define HASH_H

#include "fila.h"

#define TAM_HASH 3

typedef struct TipoEntrada {
    char *chave;
    Fila fila;
} Entrada;

typedef Entrada Hash[TAM_HASH];

void CriarHash(Hash h);
int FuncaoHash(char *chave);
void InserirHash(Hash h, char *chave, Elemento *e);
Fila PesquisarHash(Hash h, char *chave);
Elemento RemoverFila(Hash h, char *chave);
void LimparHash(Hash h);

#endif // HASH_H

