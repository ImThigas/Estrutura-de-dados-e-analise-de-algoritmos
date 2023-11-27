#include "hash.h"

void CriarHash(Hash h) {
    for (int i = 0; i < TAM_HASH; i++) {
        h[i].chave = NULL;
        CriarFila(&(h[i].fila));
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

    Enfileirar(&(h[i].fila), e);
}

// Alterações em PesquisarHash
Fila PesquisarHash(Hash h, char *chave) {
    Fila filaResultado;
    CriarFila(&filaResultado);

    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL && strcmp(h[i].chave, chave) == 0) {
            // Copiar a fila atual para a fila resultado
            for (int j = h[i].fila.frente; j <= h[i].fila.tras; j++) {
                Elemento elementoAtual = h[i].fila.itens[j];
                Elemento copiaElemento = {strdup(elementoAtual.palavra), strdup(elementoAtual.sinonimo)};
                Enfileirar(&filaResultado, &copiaElemento);
            }
            break;
        }
    }

    return filaResultado;
}

// Alterações em RemoverFila
Elemento RemoverFila(Hash h, char *chave) {
    Elemento elementoRemovido = {NULL, NULL};

    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL && strcmp(h[i].chave, chave) == 0) {
            if (!FilaVazia(&(h[i].fila))) {
                Elemento elementoAtual = Desenfileirar(&(h[i].fila));
                elementoRemovido.palavra = strdup(elementoAtual.palavra);
                elementoRemovido.sinonimo = strdup(elementoAtual.sinonimo);

                // Se a fila ficar vazia, liberamos a chave
                if (FilaVazia(&(h[i].fila))) {
                    free(h[i].chave);
                    h[i].chave = NULL;
                }
            }
            break;
        }
    }

    return elementoRemovido;
}

void LimparHash(Hash h) {
    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL) {
            free(h[i].chave);
            while (!FilaVazia(&(h[i].fila))) {
                Desenfileirar(&(h[i].fila));
            }
        }
    }
}

