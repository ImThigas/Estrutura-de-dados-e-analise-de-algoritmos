#ifndef FLORESTA_H
#define FLORESTA_H

#include "ArvoreBinariaDePesquisa.h"

typedef struct {
    ArvoreBinariaDePesquisa* categorias[3];
} Floresta;

Floresta* criarFloresta();
void inserirNaCategoria(Floresta* floresta, int categoria, int chave);
void excluirNaCategoria(Floresta* floresta, int categoria, int chave);
void pesquisarNaCategoria(Floresta* floresta, int categoria, int chave);
void percorrerPreOrdem(Floresta* floresta);
void percorrerEmOrdem(Floresta* floresta);
void percorrerPosOrdem(Floresta* floresta);
void inserirNovaCategoria(Floresta* floresta, int categoria);
void destruirFloresta(Floresta* floresta);

#endif

