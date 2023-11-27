// Main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void CadastrarFuncionario(Hash h);
void PesquisarFuncionario(Hash h);
void ExcluirFuncionario(Hash h);
void MostrarTabela(Hash h);

int main() {
    Hash h;
    CriarHash(h);

    char opcao;
    do {
        printf("\n\nEscolha uma opcao:\n");
        printf("1. Cadastrar funcionario\n");
        printf("2. Pesquisar funcionario\n");
        printf("3. Excluir funcionario\n");
        printf("4. Mostrar tabela completa\n");
        printf("0. Sair\n");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("\nC A D A S T R O!\n\n\n");
                CadastrarFuncionario(h);
                break;
            case '2':
                system("clear || cls");
                printf("\nP E S Q U I S A!\n\n\n");
                PesquisarFuncionario(h);
                break;
            case '3':
                system("clear || cls");
                printf("\nE X C L U S A O!\n\n\n");
                ExcluirFuncionario(h);
                break;
            case '4':
                system("clear || cls");
                printf("\nM O S T R A R  T A B E L A!\n\n\n");
                MostrarTabela(h);
                break;
            case '0':
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != '0');

    LimparHash(h);

    printf("\n\n");
    system("pause");
    return 0;
}

void CadastrarFuncionario(Hash h) {
    char op;
    char nome[256];
    char dataAdmissao[11];
    float salario;
    Funcionario *funcionario;

    do {
        printf("\nInforme o nome do funcionario: ");
        scanf(" %255s", nome);

        printf("Informe a data de admissao (dd/mm/aaaa): ");
        scanf(" %10s", dataAdmissao);

        printf("Informe o salario: ");
        scanf("%f", &salario);

        funcionario = CriarFuncionario(nome, dataAdmissao, salario);
        InserirHash(h, nome, funcionario);

        printf("\nDeseja cadastrar outro funcionario (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}

void PesquisarFuncionario(Hash h) {
    char op, lixo, chave[256];
    Funcionario *funcionario;

    do {
        printf("\nInforme o nome do funcionario para pesquisa: ");
        scanf("%s", chave);
        scanf("%c", &lixo);

        funcionario = PesquisarHash(h, chave);

        if (funcionario != NULL) {
            printf("\nFuncionario encontrado!\n");
            printf("Nome: %s\nData de Admissao: %s\nSalario: %.2f\n", funcionario->nome, funcionario->dataAdmissao, funcionario->salario);
        } else {
            printf("\nFuncionario nao encontrado!");
        }

        printf("\nDeseja realizar uma nova pesquisa (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}

void ExcluirFuncionario(Hash h) {
    char op, lixo, chave[256];

    do {
        printf("\nInforme o nome do funcionario para exclusao: ");
        scanf("%s", chave);
        scanf("%c", &lixo);

        RemoverFuncionarioHash(h, chave);

        printf("\nFuncionario excluido com sucesso!");

        printf("\nDeseja excluir outro funcionario (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}

void MostrarTabela(Hash h) {
    printf("Conteudo da tabela:\n");
    for (int i = 0; i < TAM_HASH; i++) {
        if (h[i].chave != NULL) {
            printf("Entrada %d - Chave: %s\n", i, h[i].chave);
            printf("Funcionarios:\n");
            ImprimirLista(&(h[i].listaFuncionarios));
            printf("\n");
        }
    }
}
