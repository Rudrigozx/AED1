#include "Heap.h"
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

// Heap Sort in C
  
  #include <stdio.h>
  
  
  void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
  }
  
  void heapfy(lista *lista, int limite, int final) {
 
    int pai = final;
    int f_esquerdo = filhoEsquerda(pai);
    int f_direito = filhoDireita(pai);
  
    if (f_esquerdo < limite && lista->dados[f_esquerdo] > lista->dados[pai]){
      pai = f_esquerdo;
    }
    if ( f_direito < limite && lista->dados[f_direito] > lista->dados[pai]){
      pai = f_direito;
    }
    if (pai != final) {
      troca(&lista->dados[final], &lista->dados[pai]);
      heapfy(lista, limite, pai);
    }
  }
  
  
  void heap_sort(lista *lista, int tamanho) {

    for (int i = tamanho/ 2 - 1; i >= 0; i--){
      heapfy(lista, tamanho, i);
    }
    for (int i = tamanho - 1; i >= 0; i--) {
      troca(&lista->dados[0], &lista->dados[i]);
      heapfy(lista, i, 0);
    }
  }


int filhoEsquerda(int posicao){
    if (posicao>=0){
        return (2*posicao)+1;
    }else{
       return -1 ;
    }
}
int filhoDireita(int posicao){
        if (posicao>=0){
        return (2*posicao)+2;
    }else{
       return -1 ;
    }
}