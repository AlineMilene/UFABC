#include <stdio.h>
#include <stdlib.h>
//#include "comparar_listas.h"

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

int comparar_listas(LinkedNode *inicio_lista1, LinkedNode *inicio_lista2) {
    LinkedNode *atual1 = inicio_lista1; 
    LinkedNode *atual2 = inicio_lista2; 
    LinkedNode *temp1 = inicio_lista1; 
    LinkedNode *temp2 = inicio_lista2;

    if(temp1 == NULL && temp2 == NULL){
        printf("são nulas iguais\n");
        return 1;
    }

    int qtd1 = 0, qtd2 = 0;

    while(temp1 != NULL){
        qtd1++;
        temp1 = temp1->next;
    }
    printf("qtde de elementos da lista1: %d\n", qtd1);

    while(temp2 != NULL){
        qtd2++;
        temp2 = temp2->next;
    }
    printf("qtde de elementos da lista2: %d\n", qtd2);

    int i = 0, iguais = 1;

    if(qtd1 != qtd2){
        printf("não são iguais, pois são de tamanhos diferentes\n");
        return 0;
    }else{
        while(i < qtd1){
            printf("entrei no while\n");
            if(atual1->data != atual2->data){
                iguais = 0;
                break;
            }
            atual1 = atual1->next; 
            atual2 = atual2->next;
            i++; 
        }
    }

    return iguais;

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

    LinkedNode *inicio_lista1 = NULL;
    LinkedNode *inicio_lista2 = NULL;
    
    int n;
    scanf("%d", &n);
    while(n != -1){
        inicio_lista1 = inserir_final_r(inicio_lista1, n);
        scanf("%d", &n);
    }

    imprimir(inicio_lista1);

    int o;
    scanf("%d", &o);
    while(o != -1){
        inicio_lista2 = inserir_final_r(inicio_lista2, o);
        scanf("%d", &o);
    }

    imprimir(inicio_lista2);

    int retorno = comparar_listas(inicio_lista1, inicio_lista2);

    printf("retorno dado: %d\n", retorno);
    return 0;
}
