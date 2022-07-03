#include "Quick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>


void inicializar(lista *lista) {
    int capacidade=1;
    lista->dados = (int *) malloc(sizeof(int) * capacidade);
    lista->marcador = 0;
    lista->capacidade = capacidade;
}

int inserir(lista *lista, int valor){
    
    if(lista->marcador >= lista->capacidade) {
        int *dados_antigos;
        dados_antigos = lista->dados;

        lista->capacidade = 2 * lista->capacidade;
        lista->dados = (int *) malloc(sizeof(int) * lista->capacidade);
        
        memmove(lista->dados, dados_antigos, sizeof(int)* lista->capacidade / 2);

        free(dados_antigos);
        
    } 
    
    lista->dados[lista->marcador] = valor;
    lista->marcador ++;
    return 1;
    
}

void exibir(lista *lista){
   int i;
   system("clear");
   printf("LISTA: ");
   for(i=0; i<lista->marcador; i++) {
        printf("[%d]", lista->dados[i]);
    }
    printf("\n");
}



int procurar(lista *lista, int valor) {
    int i;
    int posicao = -1;    
    for(i=0; i<lista->marcador; i++) {
        if(lista->dados[i] == valor) {

            posicao = i;
            break;
        } 
    }

    return posicao;
}


void trocar(lista *lista, int i, int j){
    int aux;
    aux = lista->dados[i];
    lista->dados[i] = lista->dados[j];
    lista->dados[j]= aux; 

}


void quick_sort(lista *lista, int inicio, int fim){

    int pivo = lista->dados[(fim + inicio)/2];
    int i=inicio;
    int j = fim;
    for (;i <= j;){
        for (; lista->dados[i] < pivo; i++){
        }
        for (;lista->dados[j] > pivo; j--){
        }
        if(i<=j){
            trocar(lista,i,j);
            i++;
            j--;
        }
    }
    if (inicio<j){
        quick_sort(lista,inicio,j);
    }
    if (i<fim){
        quick_sort(lista,i,fim);
    }    
}

