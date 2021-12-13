#include "vetor.h"
#include <stdlib.h>

int *duplica_impares(int *v, int n_entrada, int *n_retorno) {
    // Descobrindo a quantidade de impares
    int i, qtde = 0;
    for(i = 0; i < n_entrada; i++)
        if(v[i] % 2 != 0) qtde++;

    // Declarando um novo vetor com o tamanho do vetor de entrada + as duplicações encontradas anteriormente
    int comp = qtde + n_entrada;
    int *v_duplicado = malloc(sizeof(int) * (comp));

    // Declarando n_retorno = novo comprimento
    *n_retorno = comp;

    // Preenchendo novo vetor
    int j, l = 0, tam = 0;
    for(j = 0; j < n_entrada; j++){
        if(v[j] % 2 != 0) {
            v_duplicado[l] = v[j];
            v_duplicado[l+1] = v[j];
            l+=2;    
        }else{
            v_duplicado[l] = v[j];
            l++;
        }
        
    }

    return v_duplicado;
}   

