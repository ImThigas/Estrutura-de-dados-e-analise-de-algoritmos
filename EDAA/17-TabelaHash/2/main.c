#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void CadastrarDicionario(Hash h);
void PesquisarDicionario(Hash h);
void ExcluirPalavra(Hash h);
void MostrarFila(Hash h);

int main() {
    Hash h;
    CriarHash(h);

    char opcao;
    do {
        printf("\n\nEscolha uma opcao:\n");
        printf("1. Cadastrar palavra no dicionario\n");
        printf("2. Pesquisar palavra no dicionario\n");
        printf("3. Excluir palavra do dicionario\n");
        printf("4. Mostrar fila completa\n");
        printf("0. Sair\n");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("\nC A D A S T R O!\n\n\n");
                CadastrarDicionario(h);
                break;
            case '2':
                system("clear || cls");
                printf("\nP E S Q U I S A!\n\n\n");
                PesquisarDicionario(h);
                break;
            case '3':
                system("clear || cls");
                printf("\nE X C L U S A O!\n\n\n");
                ExcluirPalavra(h);
                break;
            case '4':
                system("clear || cls");
                printf("\nM O S T R A R  F I L A!\n\n\n");
                MostrarFila(h);
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

void CadastrarDicionario(Hash h) {
    char op;
    char lixo, termo[256];
    int i = 0, tam;
    Elemento e;

    do {
        printf("\n\nInforme uma palavra: ");
        scanf("%s", termo);
        tam = strlen(termo) + 1;
        e.palavra = (char *)malloc(sizeof(char) * tam);
        strcpy(e.palavra, termo);

        printf("\nInforme o sinonimo da palavra: ");
        scanf("%s", termo);
        tam = strlen(termo) + 1;
        e.sinonimo = (char *)malloc(sizeof(char) * tam);
        strcpy(e.sinonimo, termo);

        InserirHash(h, e.palavra, &e);

        scanf("%c", &lixo); // Limpar o buffer
        printf("\nDeseja inserir uma nova palavra (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}

void PesquisarDicionario(Hash h) {
    char op, lixo, palavra[256];
    Fila filaResultado;

    do {
        printf("\n\nInforme uma palavra: ");
        scanf("%s", palavra);
        scanf("%c", &lixo);

        filaResultado = PesquisarHash(h, palavra);

        if (!FilaVazia(&filaResultado)) {
            printf("\nPalavra encontrada! Conteudo da fila:\n");
            ImprimirFila(&filaResultado);
        } else {
            printf("\nPalavra nao encontrada!");
        }

        printf("\nDeseja realizar uma nova pesquisa (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}

void ExcluirPalavra(Hash h) {
    char op, lixo, palavra[256];
    Elemento e;

    do {
        printf("\n\nInforme uma palavra para excluir: ");
        scanf("%s", palavra);
        scanf("%c", &lixo);

        e = RemoverFila(h, palavra);

        if (e.palavra != NULL) {
            printf("\nPalavra excluida com sucesso! Conteudo removido da fila:\n");
            printf("Palavra: %s, Sinonimo: %s\n", e.palavra, e.sinonimo);
        } else {
            printf("\nPalavra nao encontrada!");
        }

        printf("\nDeseja excluir outra palavra (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}

void MostrarFila(Hash h) {
    printf("Conteudo da fila:\n");
    for (int i = 0; i < TAM_HASH; i++) {
        ImprimirFila(&(h[i].fila));
    }
}

