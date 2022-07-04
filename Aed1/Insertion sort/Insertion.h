#ifndef INSERTION_H
#define INSERTION_H



typedef struct lista_Dados {
    int *dados;
    int marcador;  
    int capacidade;  
} lista;


void inicializar(lista *lista);
int inserir(lista *lista, int valor);
int procurar(lista *lista, int valor);
void exibir(lista *lista);
void inserirOrdem(lista *lista, int n);
void insertionSort(lista *lista);
int inserirPosicao(lista *lista,int valor,int posicao);


#endif
