#include "ArvoreBinariaDePesquisa.h"
#include <stdio.h>

int main() {
    ArvoreBinariaDePesquisa* arvore = criarArvore();

    int opcao, chave;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir chave\n");
        printf("2. Retirar chave\n");
        printf("3. Pesquisar chave\n");
        printf("4. Imprimir pré-ordem\n");
        printf("5. Imprimir pós-ordem\n");
        printf("6. Imprimir em ordem\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a chave para inserir: ");
                scanf("%d", &chave);
                inserir(arvore, chave);
                break;
            case 2:
                printf("Digite a chave para retirar: ");
                scanf("%d", &chave);
                retirar(arvore, chave);
                break;
            case 3:
                printf("Digite a chave para pesquisar: ");
                scanf("%d", &chave);
                if (buscar(arvore, chave)) {
                    printf("Chave %d encontrada na árvore.\n", chave);
                } else {
                    printf("Chave %d não encontrada na árvore.\n", chave);
                }
                break;
            case 4:
                printf("Percurso pré-ordem: ");
                imprimirPreOrdem(arvore->raiz);
                printf("\n");
                break;
            case 5:
                printf("Percurso pós-ordem: ");
                imprimirPosOrdem(arvore->raiz);
                printf("\n");
                break;
            case 6:
                printf("Percurso em ordem: ");
                imprimirEmOrdem(arvore->raiz);
                printf("\n");
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    // Destruir a árvore antes de sair
    destruirArvore(arvore->raiz);

    return 0;
}
