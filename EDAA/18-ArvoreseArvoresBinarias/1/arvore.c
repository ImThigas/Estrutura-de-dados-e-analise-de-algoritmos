#include "arvore.h"
#include <stdio.h>

No* PesquisarNo(No *raiz, char *palavra);
No* EncontrarMenor(No *raiz);

void CriarArvore(Arvore *arvore) {
    arvore->raiz = NULL;
}

int ArvoreVazia(Arvore *arvore) {
    return arvore->raiz == NULL;
}

No* InserirNo(No *raiz, Elemento *e) {
    if (raiz == NULL) {
        No *novoNo = (No *)malloc(sizeof(No));
        novoNo->elemento = (Elemento *)malloc(sizeof(Elemento));

        // Alocar e atribuir a palavra
        novoNo->elemento->palavra = (char *)malloc(strlen(e->palavra) + 1);
        strcpy(novoNo->elemento->palavra, e->palavra);

        // Alocar e atribuir o sinônimo
        novoNo->elemento->sinonimo = (char *)malloc(strlen(e->sinonimo) + 1);
        strcpy(novoNo->elemento->sinonimo, e->sinonimo);

        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    if (strcmp(e->palavra, raiz->elemento->palavra) < 0) {
        raiz->esquerda = InserirNo(raiz->esquerda, e);
    } else if (strcmp(e->palavra, raiz->elemento->palavra) > 0) {
        raiz->direita = InserirNo(raiz->direita, e);
    }

    return raiz;
}


Arvore PesquisarArvore(Arvore *arvore, char *palavra) {
    Arvore resultado;
    CriarArvore(&resultado);

    if (arvore->raiz != NULL) {
        resultado.raiz = PesquisarNo(arvore->raiz, palavra);
    }

    return resultado;
}

No* PesquisarNo(No *raiz, char *palavra) {
    if (raiz == NULL || strcmp(palavra, raiz->elemento->palavra) == 0) {
        return raiz;
    }

    if (strcmp(palavra, raiz->elemento->palavra) < 0) {
        return PesquisarNo(raiz->esquerda, palavra);
    } else {
        return PesquisarNo(raiz->direita, palavra);
    }
}

Elemento RemoverNo(No **raiz, char *palavra) {
    Elemento elementoRemovido = {NULL, NULL};

    if (*raiz == NULL) {
        return elementoRemovido;
    }

    if (strcmp(palavra, (*raiz)->elemento->palavra) < 0) {
        elementoRemovido = RemoverNo(&((*raiz)->esquerda), palavra);
    } else if (strcmp(palavra, (*raiz)->elemento->palavra) > 0) {
        elementoRemovido = RemoverNo(&((*raiz)->direita), palavra);
    } else {
        elementoRemovido = *(*raiz)->elemento; // Correção aqui

        if ((*raiz)->esquerda == NULL) {
            No *temp = (*raiz)->direita;
            free((*raiz)->elemento->palavra);
            free((*raiz)->elemento->sinonimo);
            free((*raiz)->elemento);
            free(*raiz);
            *raiz = temp;
        } else if ((*raiz)->direita == NULL) {
            No *temp = (*raiz)->esquerda;
            free((*raiz)->elemento->palavra);
            free((*raiz)->elemento->sinonimo);
            free((*raiz)->elemento);
            free(*raiz);
            *raiz = temp;
        } else {
            No *temp = EncontrarMenor((*raiz)->direita);
            (*raiz)->elemento = temp->elemento;
            elementoRemovido = RemoverNo(&((*raiz)->direita), temp->elemento->palavra);
        }
    }

    return elementoRemovido;
}

No* EncontrarMenor(No *raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

void LimparArvore(No *raiz) {
    if (raiz != NULL) {
        LimparArvore(raiz->esquerda);
        LimparArvore(raiz->direita);
        free(raiz->elemento->palavra);
        free(raiz->elemento->sinonimo);
        free(raiz->elemento);
        free(raiz);
    }
}

void ImprimirArvore(No *raiz) {
    if (raiz != NULL) {
        ImprimirArvore(raiz->esquerda);
        printf("Palavra: %s, Sinonimo: %s\n", raiz->elemento->palavra, raiz->elemento->sinonimo);
        ImprimirArvore(raiz->direita);
    }
}
void ImprimirNo(No *raiz) {
    if (raiz != NULL) {
        ImprimirNo(raiz->esquerda);

        // Verificar se os elementos na árvore são nulos antes de imprimir
        if (raiz->elemento != NULL) {
            printf("Palavra: %s, Sinonimo: %s\n", raiz->elemento->palavra, raiz->elemento->sinonimo);
        }

        ImprimirNo(raiz->direita);
    }
}

