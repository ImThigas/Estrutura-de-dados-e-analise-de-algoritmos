// Hash.c
#include "Hash.h"
#include <stdlib.h>
#include <string.h>

void CriarHash(Hash h) {
    for (int i = 0; i < TAM_HASH; i++) {
        h[i].chave = NULL;
        h[i].listaFuncionarios.primeiro = NULL;
    }
}

int FuncaoHash(char *chave) {
    int i, soma = 0;
    for (i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return (soma % TAM_HASH);
}

void InserirHash(Hash h, char *chave, Funcionario *funcionario) {
    int i = FuncaoHash(chave);

    if (h[i].chave != NULL) {
        free(h[i].chave);
    }

    h[i].chave = strdup(chave);
    InserirLista(&(h[i].listaFuncionarios), funcionario);
}

Funcionario* PesquisarHash(Hash h, char *chave) {
    int i = FuncaoHash(chave);

    if (h[i].chave != NULL && strcmp(h[i].chave, chave) == 0) {
        return PesquisarLista(&(h[i].listaFuncionarios), chave);
    }

    return NULL;
}

void RemoverFuncionarioHash(Hash h, char *chave) {
    int i = FuncaoHash(chave);

    if (h[i].chave != NULL && strcmp(h[i].chave, chave) == 0) {
        RemoverFuncionarioLista(&(h[i].listaFuncionarios), chave);

        // Se a lista ficar vazia, liberamos a chave
        if (h[i].listaFuncionarios.primeiro == NULL) {
            free(h[i].chave);
            h[i].chave = NULL;
        }
    }
}

void LimparHash(Hash h) {
    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL) {
            free(h[i].chave);
            LimparLista(&(h[i].listaFuncionarios));
        }
    }
}
