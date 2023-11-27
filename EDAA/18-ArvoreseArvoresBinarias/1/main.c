// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void CadastrarDicionario(Hash h);
void PesquisarDicionario(Hash h);
void ExcluirPalavra(Hash h);
void MostrarArvore(Hash h);

int main() {
    Hash h;
    CriarHash(h);

    char opcao;
    do {
        printf("\n\nEscolha uma opcao:\n");
        printf("1. Cadastrar palavra no dicionario\n");
        printf("2. Pesquisar palavra no dicionario\n");
        printf("3. Excluir palavra do dicionario\n");
        printf("4. Mostrar arvore completa\n");
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
                printf("\nM O S T R A R  A R V O R E!\n\n\n");
                MostrarArvore(h);
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
    char termo[256];
    Elemento e;

    do {
        printf("\n\nInforme uma palavra: ");
        scanf(" %255s", termo); // Limitando o tamanho da leitura para 255 caracteres
        e.palavra = strdup(termo);

        printf("\nInforme o sinonimo da palavra: ");
        scanf(" %255s", termo); // Limitando o tamanho da leitura para 255 caracteres
        e.sinonimo = strdup(termo);

        InserirHash(h, e.palavra, &e);

        printf("\nDeseja inserir uma nova palavra (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}


void PesquisarDicionario(Hash h) {
    char op, lixo, palavra[256];
    Arvore arvoreResultado;

    do {
        printf("\n\nInforme uma palavra: ");
        scanf("%s", palavra);
        scanf("%c", &lixo);

        arvoreResultado = PesquisarHash(h, palavra);

        if (!ArvoreVazia(&arvoreResultado)) {
            printf("\nPalavra encontrada! Conteudo da arvore:\n");
            ImprimirArvore(arvoreResultado.raiz);
        } else {
            printf("\nPalavra nao encontrada!");
        }

        printf("\nDeseja realizar uma nova pesquisa (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}

void ExcluirPalavra(Hash h) {
    char op, lixo, palavra[256];
    Arvore arvoreRemovida; // Correção aqui

    do {
        printf("\n\nInforme uma palavra para excluir: ");
        scanf("%s", palavra);
        scanf("%c", &lixo);

        arvoreRemovida = RemoverArvore(h, palavra); // Correção aqui

        if (!ArvoreVazia(&arvoreRemovida)) {
            printf("\nPalavra excluida com sucesso! Conteudo removido da arvore:\n");
            // Imprimir os elementos removidos, se necessário
        } else {
            printf("\nPalavra nao encontrada!");
        }

        printf("\nDeseja excluir outra palavra (s/n)? ");
        scanf(" %c", &op);

    } while (op == 's');
}

void MostrarArvore(Hash h) {
    printf("Conteudo da arvore:\n");
    for (int i = 0; i < TAM_HASH; i++) {
        ImprimirArvore(h[i].arvore.raiz);
    }
}
