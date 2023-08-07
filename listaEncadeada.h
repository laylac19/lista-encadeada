#ifndef LISTA_H
#define LISTA_H

struct No {
    int dado;
    struct No* proximo;
};

// Protótipos das funções
struct No* criarNo(int elemento); // Cria um novo nó com o valor fornecido
void inserir(struct No** lista, int elemento); // Insere um elemento de forma ordenada na lista
void remover(struct No** lista, int elemento); // Remove um elemento da lista
void imprimirLista(struct No* lista); // Imprime todos os elementos da lista
void buscar(struct No* lista, int elemento); // Busca um elemento na lista
void liberarLista(struct No* lista); // Libera a memória ocupada pela lista
int tamanhoLista(struct No* lista); // Retorna o número de elementos na lista

#endif

