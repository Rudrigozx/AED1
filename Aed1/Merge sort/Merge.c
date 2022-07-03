#include "Merge.h"
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

void merge_sort(lista * lista, int inicio, int fim) {
     
    if(fim - inicio == 1) {
        
    } else {
        int meio = (inicio + fim) / 2;
        merge_sort(lista, inicio, meio);
        merge_sort(lista, meio, fim);
        merge(lista, inicio, meio, fim);
    }
}

void merge(lista * lista, int inicio, int meio, int fim){
  
    int *temp; 
    int i,j,k;
    int tamanho = fim-inicio;
    temp = (int *) malloc (sizeof(int) * (tamanho));

    for(i=inicio, j = meio, k=0; i<meio && j < fim; k++ ) {
        if( lista->dados[j]  <  lista->dados[i] ){
            temp[k]= lista->dados[j];
            j++;
        }else{
            temp[k]= lista->dados[i];
            i++;
        }
    }
    if (i<meio){
        for (; i < meio; i++,k++){
          temp[k]= lista->dados[i];  
        }    
    }else  if (j<fim){
        for (; j< fim; j++,k++){
          temp[k]= lista->dados[j];  
        } 
    }

    for(i=inicio, k=0; k < tamanho; k++, i++) {
        lista->dados[i] = temp[k];
       
    }
    free(temp);  
}

