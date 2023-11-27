// Funcionario.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Funcionario.h"

Funcionario* CriarFuncionario(const char* nome, const char* dataAdmissao, float salario) {
    Funcionario* novoFuncionario = (Funcionario*)malloc(sizeof(Funcionario));
    if (novoFuncionario != NULL) {
        strcpy(novoFuncionario->nome, nome);
        strcpy(novoFuncionario->dataAdmissao, dataAdmissao);
        novoFuncionario->salario = salario;
    }
    return novoFuncionario;
}

void LiberarFuncionario(Funcionario* funcionario) {
    free(funcionario);
}
void ImprimirLista(Funcionario* listaFuncionarios) {
    Funcionario* atual = listaFuncionarios;

    while (atual != NULL) {
        printf("Nome: %s, Data de Admissao: %s, Salario: %.2f\n", atual->nome, atual->dataAdmissao, atual->salario);
        atual = atual->prox;  // Supondo que há um campo "prox" que aponta para o próximo funcionário na lista
    }
}
