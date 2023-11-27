// hash.c
#include "hash.h"

void CriarHash(Hash h) {
    for (int i = 0; i < TAM_HASH; i++) {
        h[i].chave = NULL;
        CriarArvore(&(h[i].arvore));
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

    h[i].chave = strdup(chave);

    Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
    novoElemento->palavra = strdup(e->palavra);
    novoElemento->sinonimo = strdup(e->sinonimo);

    h[i].arvore.raiz = InserirNo(h[i].arvore.raiz, novoElemento);
}


Arvore PesquisarHash(Hash h, char *chave) {
    Arvore arvoreResultado;
    CriarArvore(&arvoreResultado);

    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL && strcmp(h[i].chave, chave) == 0) {
            // Copiar a árvore atual para a árvore resultado
            // (implemente a lógica apropriada para copiar árvores)
            arvoreResultado = h[i].arvore;
            break;
        }
    }

    return arvoreResultado;
}

Arvore RemoverArvore(Hash h, char *chave) {
    Arvore arvoreRemovida;
    CriarArvore(&arvoreRemovida);

    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL && strcmp(h[i].chave, chave) == 0) {
            // Remover árvore da hash e atribuir à arvoreRemovida
            arvoreRemovida = h[i].arvore;

            // Se a árvore ficar vazia, liberamos a chave
            if (ArvoreVazia(&h[i].arvore)) {
                free(h[i].chave);
                h[i].chave = NULL;
            }
            break;
        }
    }

    return arvoreRemovida;
}

void LimparHash(Hash h) {
    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL) {
            free(h[i].chave);
            LimparArvore(h[i].arvore.raiz);
        }
    }
}
