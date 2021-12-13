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
    return (a == b);
}

int busca_binaria(int *v, int n, int x) {
    int esq = 0, dir = n-1, count = 0, meio;
        while (esq <= dir) {
            meio = (esq + dir) / 2;
            if (compara(v[meio], x, &count)){
                printf("%d\n", meio);
                return count;
            }
            else if (v[meio] < x)
                esq = meio + 1;
            else
                dir = meio - 1;    
            count++;
        }
    if(meio == (dir+esq)/2){
        meio = -1;
        printf("indice: %d\n", meio);
        return count;
    }else{
        return -1;
    } 
}

int main(){
    // Lendo um numero X para ser buscado
    int x;
    printf("lendo x: ");
    scanf("%d", &x);

    // Lendo n para representar o tamanho do vetor
    int n;
    printf("lendo n: ");
    scanf("%d", &n);

    // Declarando e lendo o vetor
    int *vetor = NULL;
    vetor = vetor_aleatorio(n);
    imprimir(vetor, n);

    // Fazendo a busca binaria
    int count = busca_binaria(vetor, n, x);
    
    // Imprimindo o indice que o elemento x está dentro do vetor ou -1 quando não estiver 
    printf("comparações: %d\n", count); 
    free(vetor);

    return 0;
}

int busca_binaria(int *v, int n, int x) {
    int esq = 0, dir = n-1, count = 0;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (compara(v[meio], x, &count)){
            printf("%d\n", meio);
            return count;
        }
        else if (v[meio] < x)
            esq = meio + 1;
        else
            dir = meio - 1;    
        count++;
    }
    return -1;
}