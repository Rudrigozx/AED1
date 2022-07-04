#ifndef MERGE_H
#define MERGE_H



typedef struct lista_Dados {
    int *dados;
    int marcador;  
    int capacidade;  
} lista;


void inicializar(lista *lista);
int inserir(lista *lista, int valor);
int procurar(lista *lista, int valor);
void exibir(lista *lista);
void merge_sort(lista *lista, int inicio, int fim);
void merge(lista *lista, int inicio, int meio, int fim);


#endif
