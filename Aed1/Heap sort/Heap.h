#ifndef HEAP_H
#define HEAP_H



typedef struct lista_Dados {
    int *dados;
    int marcador;  
    int capacidade;  
} lista;


void inicializar(lista *lista);
int inserir(lista *lista, int valor);
int procurar(lista *lista, int valor);
void exibir(lista *lista);
void troca(int *a, int *b);
int filhoEsquerda(int posicao);
int filhoDireita(int posicao);
void heap_sort(lista *lista, int tamanho);
void heapfy(lista *lista, int n, int final);

#endif
