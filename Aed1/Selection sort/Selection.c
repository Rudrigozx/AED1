#include "Selection.h"
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

void seletionSort(lista *lista){
    int menorPosicao;
    int tam = lista->marcador;
    lista->marcador = 0;
    for(lista->marcador; lista->marcador<tam;lista->marcador++){
        menorPosicao = procurarPosicaoMenorAPartirDe(lista, lista->marcador,tam);
        trocar(lista,menorPosicao,lista->marcador);
    }
}

int procurarPosicaoMenorAPartirDe(lista *lista, int i, int tam){
    int menor=9999999;
    int posicaoMenor;

    for (i ; i < tam; i++){

        if(lista->dados[i] < menor){
            menor = lista->dados[i];
            posicaoMenor=i;
        }
    }
    return posicaoMenor;
}
