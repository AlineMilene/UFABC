// #include "frase.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tam_frase(char frase[]){
    int i = 0;
    while (frase[i] != '\0')
        i++;
    return i;
}

int comp_palavra(char frase[], int indice){
    int i = 0;
    while (frase[i] != ' ')
        i++;
    return i;
}

void estatisticas_frase(char frase[], int *min, int *max, int *soma, double *media, double *desvio) {    
    // Descobrindo o tamanho da frase
    int tam = tam_frase(frase);
    printf("tamanho = %d\n", tam);
    
    // Descobrindo a quantidade de palavras
    int i, qtde_palavras = 1;
    for(i = 0; i < tam; i++)
        if(frase[i] == ' ' && frase[i+1] != '\0')
            qtde_palavras++;
    printf("qtde palavras: %d\n", qtde_palavras);
    printf("\n");

    // Contando caracteres de cada palavra e guardando no vetor aux
    int m, cont= 0, l = 0, aux[qtde_palavras-1];
    for(m = 0; m < tam; m++){
        if(frase[m] >= 'a' && frase[m] <= 'z' || frase[m] >= 'A' && frase[m] <= 'Z'){
            cont++;
        }
        else{
            if(cont != 0){
                aux[l] = cont;
                l++;
            }
            printf("palavra: %d\n", cont);
            cont=0;
        }
    }
    printf("\n");

    // Imprimindo vetor aux
    int j;
    for(j = 0 ; j < qtde_palavras; j++)
        printf("aux[%d]: %d\n",j, aux[j]);
    printf("\n");

    // Cenário minimo
    *min = aux[0];
    *max = aux[0];
    *media = 0;
    *soma = 0;
    *desvio = 0;

    // Percorrendo vetor aux para realizar estatisticas de min e max
    int n;
    for(n = 0; n < qtde_palavras; n++){
        if(aux[n] < *min) *min = aux[n]; 
        if(aux[n] > *max) *max = aux[n];
        *soma += aux[n];
    }

    // Realizando estatisticas de soma e media
    *media = *soma / ((double) qtde_palavras);
    
    // Realizando a estatisca do desvio
    int y;
    double temp_soma = 0.00;
    for(y = 0; y < qtde_palavras; y++){
        temp_soma += (aux[y] - *media) *(aux[y] - *media);
    }
    temp_soma = temp_soma / qtde_palavras;

   *desvio = sqrt(temp_soma);
}

int main(){

    char vetor_frase[100];
    fgets(vetor_frase, 100, stdin);

    int *min, *max, *soma;
    double *media, *desvio;

    min = malloc(sizeof(int));
    max = malloc(sizeof(int));
    soma = malloc(sizeof(int));
    media = malloc(sizeof(double));
    desvio = malloc(sizeof(double));

    estatisticas_frase(vetor_frase, min, max, soma, media, desvio);

    printf("min: %d max: %d soma: %d media: %.2lf desvio: %.2lf\n", *min, *max, *soma, *media, *desvio);

    free(min);
    free(max);
    free(soma);
    free(media);
    free(desvio);
}

