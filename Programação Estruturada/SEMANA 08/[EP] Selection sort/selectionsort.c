#include <stdio.h>
#include <stdlib.h>

int *vetor_aleatorio(int n){
    int *v = malloc(sizeof(int) * n);

    int i;
    for(i = 0; i < n; i++)
        scanf("%d", v + i); 

    return v;
}

void imprimir(int *v, int n){
    int i;
    for(i = 0; i < n; i++)
        if(i == n-1) printf("%d", v[i]);
        else printf("%d ", v[i]);
    printf("\n");
}

int compara(int a, int b){
    // Agora, para colocar em ordem decrescente os 3 de uma vez, somente inverter o sinal abaixo
    return (a > b);
}


int selection_sort(int *v, int n){
    int eh_diferente = 0;
    int i;
    for(i = 0; i < n-1; i++){
        // Encontrando o menor elemento no restante do vetor
        int indice_menor = i;
        int k;
        for(k = i+1; k < n; k++)
            if(compara(v[indice_menor], v[k]))
                indice_menor = k;

        // Trocando o menor com o elemento atual
        if (indice_menor != i){
            eh_diferente++;
            int temp = v[indice_menor];
            v[indice_menor] = v[i];
            v[i] = temp;
        }
        imprimir(v, n);
    }
    return eh_diferente;
}

int main(){
    // Lendo tamanho do vetor1
    int tamanho;
    scanf("%d", &tamanho);

    // Declarando vetor1
    int *vetor = NULL;
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    int diferente = selection_sort(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("%d\n", diferente); 
    free(vetor);



    return 0;
}