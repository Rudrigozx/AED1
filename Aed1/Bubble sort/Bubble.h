#ifndef BUBBLE_H
#define BUBBLE_H



typedef struct lista_Dados {
    int *dados;
    int marcador;  
    int capacidade;  
} lista;


void inicializar(lista *lista);
int inserir(lista *lista, int valor);
int procurar(lista *lista, int valor);
void exibir(lista *lista);
void trocar(lista *lista, int i, int j);
void bubbleSort(lista *lista);


#endif
