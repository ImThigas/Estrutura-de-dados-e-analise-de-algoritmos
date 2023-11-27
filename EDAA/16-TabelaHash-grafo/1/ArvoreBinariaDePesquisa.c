#include "ArvoreBinariaDePesquisa.h"
#include <stdio.h>
#include <stdlib.h>

No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

ArvoreBinariaDePesquisa* criarArvore() {
    ArvoreBinariaDePesquisa* novaArvore = (ArvoreBinariaDePesquisa*)malloc(sizeof(ArvoreBinariaDePesquisa));
    novaArvore->raiz = NULL;
    return novaArvore;
}

void inserirNo(No* no, int chave) {
    if (chave < no->chave) {
        if (no->esquerda == NULL) {
            no->esquerda = criarNo(chave);
        } else {
            inserirNo(no->esquerda, chave);
        }
    } else if (chave > no->chave) {
        if (no->direita == NULL) {
            no->direita = criarNo(chave);
        } else {
            inserirNo(no->direita, chave);
        }
    }
}

void inserir(ArvoreBinariaDePesquisa* arvore, int chave) {
    if (arvore->raiz == NULL) {
        arvore->raiz = criarNo(chave);
    } else {
        inserirNo(arvore->raiz, chave);
    }
}

No* encontrarNo(No* no, int chave) {
    if (no == NULL || no->chave == chave) {
        return no;
    }

    if (chave < no->chave) {
        return encontrarNo(no->esquerda, chave);
    } else {
        return encontrarNo(no->direita, chave);
    }
}

No* encontrarMenorNo(No* no) {
    while (no->esquerda != NULL) {
        no = no->esquerda;
    }
    return no;
}

No* retirarNo(No* no, int chave) {
    if (no == NULL) {
        return no;
    }

    if (chave < no->chave) {
        no->esquerda = retirarNo(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = retirarNo(no->direita, chave);
    } else {
        if (no->esquerda == NULL) {
            No* temp = no->direita;
            free(no);
            return temp;
        } else if (no->direita == NULL) {
            No* temp = no->esquerda;
            free(no);
            return temp;
        }

        No* temp = encontrarMenorNo(no->direita);
        no->chave = temp->chave;
        no->direita = retirarNo(no->direita, temp->chave);
    }

    return no;
}

void retirar(ArvoreBinariaDePesquisa* arvore, int chave) {
    arvore->raiz = retirarNo(arvore->raiz, chave);
}

void imprimirPreOrdem(No* no) {
    if (no != NULL) {
        printf("%d ", no->chave);
        imprimirPreOrdem(no->esquerda);
        imprimirPreOrdem(no->direita);
    }
}

void imprimirPosOrdem(No* no) {
    if (no != NULL) {
        imprimirPosOrdem(no->esquerda);
        imprimirPosOrdem(no->direita);
        printf("%d ", no->chave);
    }
}

void imprimirEmOrdem(No* no) {
    if (no != NULL) {
        imprimirEmOrdem(no->esquerda);
        printf("%d ", no->chave);
        imprimirEmOrdem(no->direita);
    }
}

void imprimirArvore(ArvoreBinariaDePesquisa* arvore) {
    printf("Árvore Binária de Pesquisa (em ordem): ");
    imprimirEmOrdem(arvore->raiz);
    printf("\n");
}

int buscar(ArvoreBinariaDePesquisa* arvore, int chave) {
    return encontrarNo(arvore->raiz, chave) != NULL;
}

void destruirArvore(ArvoreBinariaDePesquisa* arvore) {
    if (arvore->raiz != NULL) {
        destruirArvoreRecursivo(arvore->raiz);
        free(arvore);
    }
}

void destruirArvoreRecursivo(No* no) {
    if (no != NULL) {
        destruirArvoreRecursivo(no->esquerda);
        destruirArvoreRecursivo(no->direita);
        free(no);
    }
}
