#include "Floresta.h"
#include <stdio.h>
#include <stdlib.h>


Floresta* criarFloresta() {
    Floresta* novaFloresta = (Floresta*)malloc(sizeof(Floresta));
    for (int i = 0; i < 3; i++) {
        novaFloresta->categorias[i] = criarArvore();
    }
    return novaFloresta;
}

void inserirNaCategoria(Floresta* floresta, int categoria, int chave) {
    if (categoria >= 0 && categoria < 3) {
        inserir(floresta->categorias[categoria], chave);
        printf("Chave %d inserida na categoria %d.\n", chave, categoria);
    } else {
        printf("Categoria inválida.\n");
    }
}

void excluirNaCategoria(Floresta* floresta, int categoria, int chave) {
    if (categoria >= 0 && categoria < 3) {
        retirar(floresta->categorias[categoria], chave);
        printf("Chave %d removida da categoria %d.\n", chave, categoria);
    } else {
        printf("Categoria inválida.\n");
    }
}

void pesquisarNaCategoria(Floresta* floresta, int categoria, int chave) {
    if (categoria >= 0 && categoria < 3) {
        if (buscar(floresta->categorias[categoria], chave)) {
            printf("Chave %d encontrada na categoria %d.\n", chave, categoria);
        } else {
            printf("Chave %d não encontrada na categoria %d.\n", chave, categoria);
        }
    } else {
        printf("Categoria inválida.\n");
    }
}

void percorrerPreOrdem(Floresta* floresta) {
    printf("Percorrendo pré-ordem:\n");
    for (int i = 0; i < 3; i++) {
        printf("Categoria %d: ", i);
        imprimirPreOrdem(floresta->categorias[i]->raiz);
        printf("\n");
    }
}

void percorrerEmOrdem(Floresta* floresta) {
    printf("Percorrendo em-ordem:\n");
    for (int i = 0; i < 3; i++) {
        printf("Categoria %d: ", i);
        imprimirEmOrdem(floresta->categorias[i]->raiz);
        printf("\n");
    }
}

void percorrerPosOrdem(Floresta* floresta) {
    printf("Percorrendo pós-ordem:\n");
    for (int i = 0; i < 3; i++) {
        printf("Categoria %d: ", i);
        imprimirPosOrdem(floresta->categorias[i]->raiz);
        printf("\n");
    }
}

void inserirNovaCategoria(Floresta* floresta, int categoria) {
    if (categoria >= 0 && categoria < 3) {
        floresta->categorias[categoria] = criarArvore();
        printf("Nova categoria %d inserida na floresta.\n", categoria);
    } else {
        printf("Categoria inválida.\n");
    }
}

void destruirFloresta(Floresta* floresta) {
    for (int i = 0; i < 3; i++) {
        destruirArvore(floresta->categorias[i]);
    }
    free(floresta);
}

