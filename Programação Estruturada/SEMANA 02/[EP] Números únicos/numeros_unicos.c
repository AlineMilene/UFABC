//#include "numeros_unicos.h"

#include <stdio.h>

int qtd_numeros_unicos(int v[], int n) {
    int i,j, unique = 0;

    //Ordenando o vetor
    for(i = 0; i < n; i++){
        for(j = i ; j < n; j++){
            if(v[i] > v[j]){
                int aux;
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

        }
    }
    
    // Imprimindo o vetor (não incluir no moodle)
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    for(i = 0; i < n; i++){
        if(v[i] != v[i+1] && (i+1) <= n){
            unique++;
        }
    }
    return unique;
}

int main(){
    int vetor1[10] = {11, 11, 11, 22, 22, 11, 33, 44, 44, 44};
    int vetor2[25] = {11, 22, 33, 44, 55, 11, 22, 33, 44, 55, 11, 22, 33, 44, 55, 11, 22, 33, 44, 55, 11, 22, 33, 44, 55};
    //int resultado = qtd_numeros_unicos(vetor1, 10); 
    int resultado = qtd_numeros_unicos(vetor2, 25); 

    printf("qtde unicos: %d\n", resultado);
}