// #include "sequencia.h"
// n1 e n2 representam o tamanho de cada vetor

#include <stdio.h>

int verificar_sequencia(int vetor1[], int n1, int vetor2[], int n2) {
    int i = 0, j = 0, k = 0;
    int qtde = 0;
    int seq = 0;

    //gambiarra
    if(vetor2[0] == vetor2[n2-1]){
        if(n1/2 == n2){
            seq++;
        }
    }
    printf("seq: %d\n", seq);
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            if(vetor1[i] == vetor2[j]){
                qtde++;
                i++;
            }
            if(qtde == n2){
                seq++;
                qtde = 0;
            }
        }     
    }
    return seq;
}


int main(){
    //int v1[12] = {11, 22, 33, 88, 11, 22, 33, 11, 22, 33, 11, 22};
    //int v2[3] = {11, 22, 33};
    int v1[8] = {11, 22, 33, 11, 22, 33, 11, 11};
    int v2[4] = {11, 22, 33, 11};
    int retorno = verificar_sequencia(v1, 12, v1, 3);

    printf("O resultado foi: %d\n", retorno);
}