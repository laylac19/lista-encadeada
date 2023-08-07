#ifndef LISTA_H
#define LISTA_H

struct No {
    int dado;
    struct No* proximo;
};

// Prot�tipos das fun��es
struct No* criarNo(int elemento); // Cria um novo n� com o valor fornecido
void inserir(struct No** lista, int elemento); // Insere um elemento de forma ordenada na lista
void remover(struct No** lista, int elemento); // Remove um elemento da lista
void imprimirLista(struct No* lista); // Imprime todos os elementos da lista
void buscar(struct No* lista, int elemento); // Busca um elemento na lista
void liberarLista(struct No* lista); // Libera a mem�ria ocupada pela lista
int tamanhoLista(struct No* lista); // Retorna o n�mero de elementos na lista

#endif

