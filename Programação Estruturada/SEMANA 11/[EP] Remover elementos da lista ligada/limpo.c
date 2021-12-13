#include <stdlib.h>
#include "dna.h"

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

    return qtde;
}

int qtde_G(LinkedNode *inicio){
    int qtde = 0;
    
    LinkedNode *atual = inicio;

    while(atual != NULL){
        if(atual->data == 'G') qtde++;
        atual = atual->next;
    }

    return qtde;
}

void libera_lista(LinkedNode *inicio){
    if(inicio == NULL) return;
    libera_lista(inicio->next);
    free(inicio);
}

LinkedNode *remover_especifico(LinkedNode *inicio, char valor){
    if (inicio == NULL) return NULL;
    
    int tam = tamanho_lista(inicio);

    // Remoção do primeiro nó
    if (inicio->data == valor) {
        if(tam == 1){
            libera_lista(inicio);
            inicio = NULL;
            return inicio;
        }else{
            LinkedNode *temp = inicio->next;
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
        libera_lista(inicio);
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