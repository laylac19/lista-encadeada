#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "listaEncadeada.h"

// Função auxiliar para criar um novo nó com o valor fornecido
struct No* criarNo(int elemento) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = elemento;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para inserir um elemento em ordem na lista
void inserir(struct No** lista, int elemento) {
    struct No* novoNo = criarNo(elemento);

    // Verifica se a lista está vazia
    if (*lista == NULL) {
        *lista = novoNo;
        printf("Elemento inserido como primeiro da lista.\n");
        return;
    }

    // Caso a lista não esteja vazia
    if (elemento < (*lista)->dado) {
        novoNo->proximo = *lista;
        *lista = novoNo;
    } else {
        struct No* atual = *lista;
        while (atual->proximo != NULL && atual->proximo->dado < elemento) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

// Função para remover um elemento da lista
void remover(struct No** lista, int elemento) {
    struct No* aux = *lista;
    struct No* anterior = NULL;

    // Procura o elemento a ser removido
    while (aux != NULL && aux->dado != elemento) {
        anterior = aux;
        aux = aux->proximo;
    }

    // Se o elemento não for encontrado
    if (aux == NULL) {
        printf("Elemento não encontrado na lista.\n");
        return;
    }

    // Remove o elemento da lista
    if (anterior == NULL) {
        *lista = aux->proximo;
    } else {
        anterior->proximo = aux->proximo;
    }

    free(aux);
    printf("Elemento removido com sucesso.\n");
}

// Função para imprimir a lista
void imprimirLista(struct No* lista) {
    // Verifica se a lista está vazia
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista: ");
    // Percorre a lista e imprime cada elemento
    while (lista != NULL) {
        printf("%d ", lista->dado);
        lista = lista->proximo;
    }
    printf("\n");
}

// Função para buscar um elemento na lista
void buscar(struct No* lista, int elemento) {
    // Percorre a lista procurando o elemento
    while (lista != NULL) {
        if (lista->dado == elemento) {
            printf("Elemento encontrado na lista.\n");
            return;
        }
        lista = lista->proximo;
    }

    printf("Elemento não encontrado na lista.\n");
}

// Função para liberar a memória ocupada pela lista
void liberarLista(struct No* lista) {
    struct No* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }
}

// Função para retornar o número de elementos na lista
int tamanhoLista(struct No* lista) {
    int tamanho = 0;
    // Percorre a lista e incrementa o tamanho para cada elemento
    while (lista != NULL) {
        tamanho++;
        lista = lista->proximo;
    }
    return tamanho;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct No* lista = NULL; // Inicializa a lista como vazia
    int opcaoSelecionada, elemento;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n"); // Opção para inserir um elemento na lista
        printf("2. Remover elemento\n"); // Opção para remover um elemento da lista
        printf("3. Imprimir lista\n"); // Opção para imprimir a lista
        printf("4. Buscar elemento\n"); // Opção para buscar um elemento na lista
        printf("5. Tamanho da lista\n"); // Opção para obter o tamanho da lista
        printf("6. Sair\n"); // Opção para sair do programa
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoSelecionada);

        switch (opcaoSelecionada) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &elemento);
                inserir(&lista, elemento); // Chama a função para inserir um elemento na lista
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &elemento);
                remover(&lista, elemento); // Chama a função para remover um elemento da lista
                break;
            case 3:
                imprimirLista(lista); // Chama a função para imprimir a lista
                break;
            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &elemento);
                buscar(lista, elemento); // Chama a função para buscar um elemento na lista
                break;
            case 5:
                printf("Tamanho da lista: %d\n", tamanhoLista(lista)); // Chama a função para obter o tamanho da lista
                break;
            case 6:
                liberarLista(lista);
                printf("Saindo do programa.\n");
                exit(0); // Sai do programa
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

