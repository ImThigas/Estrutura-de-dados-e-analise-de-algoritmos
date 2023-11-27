#include "pilha.h"

void CriarPilha(Pilha *p) {
    p->topo = -1;
}

int PilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int PilhaCheia(Pilha *p) {
    return p->topo == TAM_PILHA - 1;
}

void Empilhar(Pilha *p, Elemento *e) {
    if (!PilhaCheia(p)) {
        p->topo++;
        p->itens[p->topo] = *e;
    }
}

Elemento Desempilhar(Pilha *p) {
    Elemento e;
    if (!PilhaVazia(p)) {
        e = p->itens[p->topo];
        p->topo--;
        return e;
    }
    // Retornar um elemento inválido para indicar que a pilha está vazia
    Elemento elementoInvalido = {NULL, NULL};
    return elementoInvalido;
}

void ImprimirPilha(Pilha *p) {
    for (int i = p->topo; i >= 0; i--) {
        printf("Palavra: %s ,Sinonimo: %s \n", p->itens[i].palavra, p->itens[i].sinonimo);
    }
}

