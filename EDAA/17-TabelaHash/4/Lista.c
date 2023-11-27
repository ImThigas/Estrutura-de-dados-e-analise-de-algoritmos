// Lista.c
#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NoLista* CriarNo(Funcionario *funcionario) {
    NoLista *novoNo = (NoLista *)malloc(sizeof(NoLista));
    if (novoNo != NULL) {
        novoNo->funcionario = funcionario;
        novoNo->proximo = NULL;
    }
    return novoNo;
}

void InserirLista(ListaFuncionarios *lista, Funcionario *funcionario) {
    NoLista *novoNo = CriarNo(funcionario);

    if (novoNo != NULL) {
        if (lista->primeiro == NULL || strcmp(funcionario->nome, lista->primeiro->funcionario->nome) < 0) {
            novoNo->proximo = lista->primeiro;
            lista->primeiro = novoNo;
        } else {
            NoLista *atual = lista->primeiro;
            while (atual->proximo != NULL && strcmp(funcionario->nome, atual->proximo->funcionario->nome) > 0) {
                atual = atual->proximo;
            }
            novoNo->proximo = atual->proximo;
            atual->proximo = novoNo;
        }
    }
}

Funcionario* PesquisarLista(ListaFuncionarios *lista, char *chave) {
    NoLista *atual = lista->primeiro;

    while (atual != NULL) {
        if (strcmp(chave, atual->funcionario->nome) == 0) {
            return atual->funcionario;
        }
        atual = atual->proximo;
    }

    return NULL;
}

void RemoverFuncionarioLista(ListaFuncionarios *lista, char *chave) {
    NoLista *atual = lista->primeiro;
    NoLista *anterior = NULL;

    while (atual != NULL && strcmp(chave, atual->funcionario->nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            lista->primeiro = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }

        LiberarFuncionario(atual->funcionario);
        free(atual);
    }
}

void LimparLista(ListaFuncionarios *lista) {
    NoLista *atual = lista->primeiro;
    NoLista *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        LiberarFuncionario(atual->funcionario);
        free(atual);
        atual = proximo;
    }

    lista->primeiro = NULL;
}
