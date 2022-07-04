#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Insertion.h"


int main(int argc, char* argv[]) {
    int quantidade,n;
    lista lista;
    
    inicializar(&lista);
    
    FILE *f = fopen("/home/rodrigo/Área de Trabalho/listas de test/1.000.000.txt", "r");
    if (f==NULL){
        system("clear");
        printf("Erro!!!\n");
        exit(1);
    }
    fscanf(f,"%d",&quantidade);
    for (int i = 0; i < quantidade; i++){
        fscanf(f,"%d",&n);
        inserir(&lista,n);
    }
    fclose(f);
    insertionSort(&lista); 
    
}