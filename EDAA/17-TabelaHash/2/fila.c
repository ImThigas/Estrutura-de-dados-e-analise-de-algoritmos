#include "fila.h"

void CriarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

int FilaVazia(Fila *f) {
    return f->tras < f->frente;
}

int FilaCheia(Fila *f) {
    return f->tras == TAM_FILA - 1;
}

void Enfileirar(Fila *f, Elemento *e) {
    if (!FilaCheia(f)) {
        f->tras++;
        f->itens[f->tras] = *e;
    }
}

Elemento Desenfileirar(Fila *f) {
    Elemento e;
    if (!FilaVazia(f)) {
        e = f->itens[f->frente];
        f->frente++;
        return e;
    }
    // Retornar um elemento inválido para indicar que a fila está vazia
    Elemento elementoInvalido = {NULL, NULL};
    return elementoInvalido;
}

void ImprimirFila(Fila *f) {
    for (int i = f->frente; i <= f->tras; i++) {
        printf("Palavra: %s, Sinonimo: %s\n", f->itens[i].palavra, f->itens[i].sinonimo);
    }
}

