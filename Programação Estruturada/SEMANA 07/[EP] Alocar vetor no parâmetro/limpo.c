// #include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

int intercala_vetores(int *v_a, int n_a, int *v_b, int n_b, int **v) {
    int a, i, j;
    int tam = n_a+n_b;
    *v = malloc(sizeof(int) * tam);
    
    i = 0;
    j = 0;
    for(i = 0; i < n_a; i++){
        (*v)[i] = *(v_a + i);
    }
    for(i = n_a; i < tam; i++){
        (*v)[i] = *(v_b + j);
        j++;
    }
    
    // Ordenando vetor intercalado
    int l, m, aux = 0;
    for(l = 0; l < tam; l++){
        for(m = l; m < tam; m++){
            if((*v)[l] > (*v)[m]){
                aux = (*v)[l];
                (*v)[l] = (*v)[m];
                (*v)[m] = aux;
            }
        }
    }

    return tam;
}

int main(){
    int *v_a = malloc(sizeof(int) * 3);
    v_a[0] = 10;
    v_a[1] = 30;
    v_a[2] = 50;
    int *v_b = malloc(sizeof(int) * 2);
    v_b[0] = 20;
    v_b[1] = 40;
    int *v_r;
    int n_r = intercala_vetores(v_a, 3, v_b, 2, &v_r);
    int i;
    for (i = 0; i < n_r; i++)
        printf("%d ", v_r[i]);
    free(v_a);
    free(v_b);
    free(v_r);
}