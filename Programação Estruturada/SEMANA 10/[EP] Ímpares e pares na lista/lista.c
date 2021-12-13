#include <stdio.h>
#include <stdlib.h>
// #include "lista.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

void impares_pares(LinkedNode *inicio, int *qtd_impares, int *qtd_pares) {
    int impar = 0, par = 0;

    LinkedNode *atual = inicio; 

    while(atual != NULL){
        if(atual->data % 2 == 0)
            par++;
        else if(atual->data % 2 != 0)
            impar++;
        atual = atual->next;
    }

    // Fazendo com que os ponteiros dos parametros apontem para os valores encontrados
    *qtd_impares = impar;
    *qtd_pares = par;

    printf("impar: %d\n", impar);    
    printf("par: %d\n", par);
    printf("qtd impar: %d\n", *qtd_impares);
    printf("qtd par: %d\n", *qtd_pares);
}

void imprimir(LinkedNode *inicio){
    LinkedNode *atual = inicio;
    while(atual != NULL){
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

LinkedNode *inserir_final_r(LinkedNode *inicio, int valor){
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    if(inicio == NULL){
        LinkedNode *novo = malloc(sizeof(LinkedNode));
        if(novo == NULL) return inicio;
        novo->data = valor;
        novo->next = NULL;

        return novo;
    }

    inicio->next = inserir_final_r(inicio->next, valor);
    return inicio;
}

void liberar_lista2(LinkedNode *inicio){
    LinkedNode *atual = inicio;
    LinkedNode *remover;
    while(atual != NULL){
        remover = atual;
        atual = atual->next;
        free(remover);
    }
}

int main(){

    LinkedNode *inicio = NULL;
    
    int n;
    scanf("%d", &n);
    while(n != -1){
        inicio = inserir_final_r(inicio, n);
        scanf("%d", &n);
    }

    imprimir(inicio);

    int *qtd_impares = malloc(sizeof(int));
    int *qtd_pares = malloc(sizeof(int));

    impares_pares(inicio, qtd_impares, qtd_pares);
    
    printf("qtd impar: %d\n", *qtd_impares);
    printf("qtd par: %d\n", *qtd_pares);

    liberar_lista2(inicio);

    return 0;
}
