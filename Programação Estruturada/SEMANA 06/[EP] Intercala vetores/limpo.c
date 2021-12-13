#include <stdio.h>
#include <stdlib.h>

int* intercala(int *v1, int n1, int *v2, int n2){
    int a, i, j;
    int tam = n1+n2;
    int *v_intercalado = malloc(sizeof(int) * tam);
    
    i = 0;
    j = 0;
    for(i = 0; i < n1; i++){
        *(v_intercalado + i) = *(v1 + i);
    }
    for(i = n1; i < tam; i++){
        *(v_intercalado + i) = *(v2 + j);
        j++;
    }
    
    // Ordenando vetor intercalado
    int l, m, aux = 0;
    for(l = 0; l < tam; l++){
        for(m = l; m < tam; m++){
            if(*(v_intercalado + l) > *(v_intercalado + m)){
                aux = *(v_intercalado + l);
                *(v_intercalado + l) = *(v_intercalado + m);
                *(v_intercalado + m) = aux;
            }
        }
    }
    
    // Printando vetor intercalado
    int k;
    for(k = 0; k < tam; k++){
        printf("%d ", *(v_intercalado + k));
    }
    printf("\n");

    free(v_intercalado);
}

int main(){
    // Lendo n1 (tamanho do vetor1)
    int n1;
    scanf("%d", &n1);

    // Declarando vetor1
    int *vetor1 = malloc(sizeof(int) * n1);

    // Lendo elementos do vetor1
    int i;
    for(i = 0; i < n1; i++){
        scanf("%d", vetor1 + i);
    }

    // --------------------------------------

    // Lendo n2 (tamanho do vetor1)
    int n2;
    scanf("%d", &n2);

    // Declarando vetor2
    int *vetor2 = malloc(sizeof(int) * n2);

    // Lendo elementos do vetor2
    for(i = 0; i < n2; i++){
        scanf("%d", vetor2 + i);
    }

    intercala(vetor1, n1, vetor2, n2);
    free(vetor1);
    free(vetor2);
    return 0;
}