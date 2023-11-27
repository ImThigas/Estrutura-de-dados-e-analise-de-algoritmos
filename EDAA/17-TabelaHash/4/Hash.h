// Hash.h
#ifndef HASH_H
#define HASH_H

#include "Lista.h"

#define TAM_HASH 10

typedef struct TipoEntrada {
    char *chave; // Chave será o nome do funcionário
    ListaFuncionarios listaFuncionarios;
} Entrada;

typedef Entrada Hash[TAM_HASH];

void CriarHash(Hash h);
void InserirHash(Hash h, char *chave, Funcionario *funcionario);
Funcionario* PesquisarHash(Hash h, char *chave);
void RemoverFuncionarioHash(Hash h, char *chave);
void LimparHash(Hash h);

#endif // HASH_H
