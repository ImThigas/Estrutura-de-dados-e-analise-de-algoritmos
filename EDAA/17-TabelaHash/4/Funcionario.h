// Funcionario.h
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct Funcionario {
    char nome[256];
    char dataAdmissao[11];
    float salario;
    struct Funcionario* prox;
} Funcionario;

Funcionario* CriarFuncionario(const char* nome, const char* dataAdmissao, float salario);
void LiberarFuncionario(Funcionario* funcionario);
void ImprimirLista(Funcionario* listaFuncionarios);

#endif // FUNCIONARIO_H
