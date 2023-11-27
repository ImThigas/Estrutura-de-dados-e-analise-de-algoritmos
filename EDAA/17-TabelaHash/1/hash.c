#include "hash.h"

void CriarHash(Hash h) {
    for (int i = 0; i < TAM_HASH; i++) {
        h[i].chave = NULL;
        CriarPilha(&(h[i].pilha));
    }
}

int FuncaoHash(char *chave) {
    int i, soma = 0;
    for (i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return (soma % TAM_HASH);
}

void InserirHash(Hash h, char *chave, Elemento *e) {
    int i = FuncaoHash(chave);

    if (h[i].chave != NULL) {
        free(h[i].chave);
    }

    h[i].chave = (char *)malloc(sizeof(char) * (strlen(chave) + 1));
    strcpy(h[i].chave, chave);

    Empilhar(&(h[i].pilha), e);
}

Pilha PesquisarHash(Hash h, char *chave) {
    Pilha pilhaResultado;
    CriarPilha(&pilhaResultado);

    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL && strcmp(h[i].chave, chave) == 0) {
            // Modificamos para copiar a pilha atual para a pilha resultado
            Pilha pilhaTemporaria;
            CriarPilha(&pilhaTemporaria);

            while (!PilhaVazia(&(h[i].pilha))) {
                Elemento elementoAtual = Desempilhar(&(h[i].pilha));
                Empilhar(&pilhaResultado, &elementoAtual);
                Empilhar(&pilhaTemporaria, &elementoAtual);
            }

            // Restauramos a pilha original
            while (!PilhaVazia(&pilhaTemporaria)) {
                Elemento elementoTemporario = Desempilhar(&pilhaTemporaria);
                Empilhar(&(h[i].pilha), &elementoTemporario);
            }

            break;
        }
    }

    return pilhaResultado;
}

Elemento ExcluirHash(Hash h, char *chave) {
    Elemento e = {NULL, NULL};

    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL && strcmp(h[i].chave, chave) == 0) {
            e = Desempilhar(&(h[i].pilha));
            // Se a pilha ficar vazia, liberamos a chave
            if (PilhaVazia(&(h[i].pilha))) {
                free(h[i].chave);
                h[i].chave = NULL;
            }
            break;
        }
    }

    return e;
}

void LimparHash(Hash h) {
    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL) {
            free(h[i].chave);
            while (!PilhaVazia(&(h[i].pilha))) {
                Desempilhar(&(h[i].pilha));
            }
        }
    }
}

