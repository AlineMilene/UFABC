#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "dna.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char data;
   LinkedNode *next;
};

void imprimir(LinkedNode *inicio){
    LinkedNode *atual = inicio;
    while(atual != NULL){
        printf("[%c] ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int tamanho_lista(LinkedNode *inicio){
    int qtde = 0;
    
    LinkedNode *atual = inicio;

    while(atual != NULL){
        atual = atual->next;
        qtde++;
    }

    return qtde;
}

int qtde_C(LinkedNode *inicio){
    int qtde = 0;
    
    LinkedNode *atual = inicio;

    while(atual != NULL){
        if(atual->data == 'C') qtde++;
        atual = atual->next;
    }
    printf("C: %d\n", qtde);
    return qtde;
}

int qtde_G(LinkedNode *inicio){
    int qtde = 0;
    
    LinkedNode *atual = inicio;

    while(atual != NULL){
        if(atual->data == 'G') qtde++;
        atual = atual->next;
    }
    printf("G: %d\n", qtde);
    return qtde;
}

void liberar_lista(LinkedNode *inicio){
    if(inicio == NULL) return;
    liberar_lista(inicio->next);
    free(inicio);
}

LinkedNode *remover_especifico(LinkedNode *inicio, char valor){
    if (inicio == NULL) return NULL;
    
    int tam = tamanho_lista(inicio);

    // Remoção do primeiro nó
    if (inicio->data == valor) {
        if(tam == 1){
            liberar_lista(inicio);
            inicio = NULL;
            return inicio;
        }else{
            LinkedNode *temp = inicio->next;
            //free(inicio);
            inicio->data = temp->data;
            inicio->next = temp->next;
            return inicio;
        }
    }
    // Remoção do qualquer outro nó
    inicio->next = remover_especifico(inicio->next, valor);
    return inicio;
}

LinkedNode *remover_bases(LinkedNode *inicio) {
    if (inicio == NULL) return NULL;

    int tam = tamanho_lista(inicio);
    int qtdeC = qtde_C(inicio);
    int qtdeG = qtde_G(inicio);

    if(qtdeC + qtdeG == tam && tam != 1){
        liberar_lista(inicio);
        inicio = NULL;
        return inicio;
    }else{
        int i;
        for(i = 0; i < qtdeC; i++){
            remover_especifico(inicio, 'C');
        }
        
        int j;
        for(j = 0; j < qtdeG; j++){
            remover_especifico(inicio, 'G');
        }
        
        return inicio;
    }
}

LinkedNode *inserir_final(LinkedNode *inicio, char valor){
    LinkedNode *novo = malloc(sizeof(LinkedNode));
    if(novo == NULL) return inicio;

    novo->data = valor;
    novo->next = NULL;

    if(inicio == NULL) return novo;
    
    LinkedNode *anterior = NULL;
    LinkedNode *atual = inicio;

    while(atual != NULL){
        anterior = atual;
        atual = atual->next;
    }

    anterior->next = novo;
    return inicio;
}

int main(){
    // Criando uma lista ligada
    LinkedNode *inicio = NULL;

    // Leitura das strings
    int n;
    scanf("%d ", &n);

    int i;
    for(i = 0; i < n; i++){
        char texto;
        scanf("%c ", &texto);

        // Armazenando na lista ligada
        inicio = inserir_final(inicio, texto);
    }

    imprimir(inicio);

    remover_bases(inicio);

    imprimir(inicio);
    return 0;
}