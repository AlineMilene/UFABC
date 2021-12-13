// #include "funcao.h"

#include <stdio.h>
#include <stdlib.h>

int somatoria_aux(int n, int j){
    int k = 1, soma1 = 0;
    for(k = 1; k <= n; k++){
        soma1 += (j+k)*(j+k);
    }
    return soma1;
}

void valor_funcao(int m, int n, int *resultado) {
    int j = 1, k = 1;
    int soma1 = 0;
    for(k = 1; k <= n; k++){
        soma1 += (j+k)*(j+k);
    }
    printf("valor soma1: %d\n", soma1);

    for(j = 1; j <= m; j++){
        *resultado += (((j+1) * (j+1)) + 10 * somatoria_aux(n, j));
    }
    printf("valor resultado: %d\n", *resultado);
}

int main(){

    int *resultado = malloc(sizeof(int));

    valor_funcao(5, 8, resultado);

    return 0;
}
