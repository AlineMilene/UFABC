#include <stdio.h>
#include <stdlib.h>
//#include "inserir.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

int size_list(LinkedNode* inicio){
    LinkedNode *temp = inicio; 
    int qtd = 0;

    while(temp != NULL){
        qtd++;
        temp = temp->next;
    }

    return qtd;
}

LinkedNode* qual_posicao(LinkedNode* inicio, int posicao){
    int tam = size_list(inicio);

    if(posicao >= 0 && posicao < tam){
        LinkedNode* atual = inicio;

        int i;
        for(i = 0; i < posicao; i++)
            atual = atual->next;

        return atual;
    }
    return NULL;
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

LinkedNode* inserir_posicao(int posicao, int valor, LinkedNode *inicio) {
    LinkedNode *atual = inicio;  
    LinkedNode *temp = inicio; 
    LinkedNode *anterior = NULL; 

    if(posicao == 0){
        LinkedNode *novo = malloc(sizeof(LinkedNode));
        
        if(novo == NULL) return inicio;
        novo->data = valor;
        novo->next = NULL;

        return novo;  
    }else if(posicao == size_list(inicio)){
        inserir_final_r(inicio, valor);
    }else{
        LinkedNode* atual = qual_posicao(inicio, posicao);
        
        if(atual != NULL){
            LinkedNode* anterior = qual_posicao(inicio, posicao-1);

            LinkedNode *novo = malloc(sizeof(LinkedNode));
            if(novo == NULL) return inicio;
            novo->data = valor;
            anterior->next = novo;
            novo->next = atual;
        }
    }
    return inicio;
}

void imprimir(LinkedNode *inicio){
    LinkedNode *atual = inicio;
    while(atual != NULL){
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

int main(){

    LinkedNode *inicio = NULL;
    
    int n;
    scanf("%d", &n);
    while(n != -1){
        inicio = inserir_final_r(inicio, n);
        scanf("%d", &n);
    }
    printf("lista original: \n");
    imprimir(inicio);

    inserir_posicao(3, 40, inicio);
    printf("lista modificada: \n");
    imprimir(inicio);
    
    // printf("valor da posição dada: %d\n", qual_posicao(inicio, 2)->data);
    return 0;
}
