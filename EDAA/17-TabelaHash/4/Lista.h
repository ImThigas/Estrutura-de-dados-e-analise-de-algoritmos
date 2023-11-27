// Lista.h
#ifndef LISTA_H
#define LISTA_H

#include "Funcionario.h"

typedef struct TipoNoLista {
    Funcionario *funcionario;
    struct TipoNoLista *proximo;
} NoLista;

typedef struct TipoListaFuncionarios {
    NoLista *primeiro;
} ListaFuncionarios;

void InserirLista(ListaFuncionarios *lista, Funcionario *funcionario);
Funcionario* PesquisarLista(ListaFuncionarios *lista, char *chave);
void RemoverFuncionarioLista(ListaFuncionarios *lista, char *chave);
void LimparLista(ListaFuncionarios *lista);

#endif // LISTA_H
