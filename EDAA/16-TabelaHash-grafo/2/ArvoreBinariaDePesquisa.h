#ifndef ARVORE_BINARIA_DE_PESQUISA_H
#define ARVORE_BINARIA_DE_PESQUISA_H

typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} ArvoreBinariaDePesquisa;

ArvoreBinariaDePesquisa* criarArvore();
void inserir(ArvoreBinariaDePesquisa* arvore, int chave);
void retirar(ArvoreBinariaDePesquisa* arvore, int chave);
void imprimirPreOrdem(No* no);
void imprimirPosOrdem(No* no);
void imprimirEmOrdem(No* no);
void imprimirArvore(ArvoreBinariaDePesquisa* arvore);
int buscar(ArvoreBinariaDePesquisa* arvore, int chave);
void destruirArvore(ArvoreBinariaDePesquisa* arvore);

#endif

