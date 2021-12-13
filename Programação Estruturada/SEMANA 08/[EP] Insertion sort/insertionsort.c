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

int compara(int a, int b, int *count){
    *count= *count + 1;
    // Agora, para colocar em ordem decrescente os 3 de uma vez, somente inverter o sinal abaixo
    return (a > b);
}

int insertion_sort(int *v, int n){
    int count = 0;
    int i;
    for(i = 1; i < n; i++){
        int item_atual = v[i]; // Guarda elemento atual
        
        int indice_para_insercao = i; // Encontra índice para inseção e 
        int k;                        // desloca elementos para a direita
        
        // Para mudar para decrescente, é necessário apenas mudar o treco após o && para: item_atual > v[k]
        for(k = i-1; k >=0 && compara(v[k], item_atual, &count); k--){
            v[k+1] = v[k];   
            indice_para_insercao--;
        }
        v[indice_para_insercao] = item_atual;   // Insere elemento atual
        imprimir(v, n);
    }
    return count;
}

int main(){
    // Lendo tamanho do vetor1
    int tamanho;
    scanf("%d", &tamanho);

    // Declarando vetor1
    int *vetor = NULL;
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    int count = insertion_sort(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("%d\n", count); 
    free(vetor);



    return 0;
}