#include "ArvoreBinariaDePesquisa.h"
#include "Floresta.h"
#include <stdio.h>

int main() {
    Floresta* floresta = criarFloresta();

    int opcao, categoria, chave;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir chave\n");
        printf("2. Retirar chave\n");
        printf("3. Pesquisar chave\n");
        printf("4. Imprimir pré-ordem\n");
        printf("5. Imprimir em-ordem\n");
        printf("6. Imprimir pós-ordem\n");
        printf("7. Inserir nova categoria\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a categoria (1, 2 ou 3): ");
                scanf("%d", &categoria);
                printf("Digite a chave para inserir: ");
                scanf("%d", &chave);
                inserirNaCategoria(floresta, categoria, chave);
                break;
            case 2:
                printf("Digite a categoria (1, 2 ou 3): ");
                scanf("%d", &categoria);
                printf("Digite a chave para retirar: ");
                scanf("%d", &chave);
                excluirNaCategoria(floresta, categoria, chave);
                break;
            case 3:
                printf("Digite a categoria (1, 2 ou 3): ");
                scanf("%d", &categoria);
                printf("Digite a chave para pesquisar: ");
                scanf("%d", &chave);
                pesquisarNaCategoria(floresta, categoria, chave);
                break;
            case 4:
                percorrerPreOrdem(floresta);
                break;
            case 5:
                percorrerEmOrdem(floresta);
                break;
            case 6:
                percorrerPosOrdem(floresta);
                break;
            case 7:
                printf("Digite o número da nova categoria: ");
                scanf("%d", &categoria);
                inserirNovaCategoria(floresta, categoria);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    destruirFloresta(floresta);

    return 0;
}

