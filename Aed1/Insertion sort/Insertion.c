#include "Insertion.h"
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


void insertionSort(lista *lista) {
    int tam = lista->marcador;
    lista->marcador = 1;
    for(lista->marcador; lista->marcador<tam;){
        inserirOrdem (lista,lista->dados[lista->marcador]) ;
    }
}

void inserirOrdem(lista *lista, int n){
    int i ;
    if (lista->marcador==0){
        inserir(lista,n);
    } 
    if(lista->dados[lista->marcador-1]< n){
        inserir(lista,n);

    }else{
        for (i = 0; i < lista->marcador; i++){ 
            if (lista->dados[i] > n){
                inserirPosicao(lista,n,i);
                break;
            }   
        }
    }
}

int inserirPosicao(lista *lista,int valor,int posicao){
    if (posicao<0 || posicao > lista->marcador){
        return 0;
    
    }

    for(int i= lista->marcador; i>posicao ; i--){
        lista->dados[i] = lista->dados[i-1];

    }
    lista->dados[posicao]=valor;
    lista->marcador++;
    return 1;

}
