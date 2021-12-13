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

void std(int v[], double *media, int qtde, double *desvio){
    int i;
    double temp_soma = 0.0;
    for(i = 0; i < qtde; i++){
        temp_soma += (v[i] - *media) *(v[i] - *media);
    }
    temp_soma = temp_soma / qtde;

    *desvio = sqrt(temp_soma);
}

void estatisticas_frase(char frase[], int *min, int *max, int *soma, double *media, double *desvio) {    
    // Descobrindo o tamanho da frase
    int tam = tam_frase(frase);

    // Descobrindo a quantidade de palavras
    int i, qtde_palavras = 1;
    for(i = 0; i < tam; i++)
        if(frase[i] == ' ' && frase[i+1] != '\0')
            qtde_palavras++;

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
            cont=0;
        }
    }

    // Cenário minimo
    *min = aux[0];
    *max = aux[0];

    // Percorrendo vetor aux para realizar estatisticas de min e max
    int n;
    for(n = 0; n < qtde_palavras; n++){
        if(aux[n] < *min) *min = aux[n]; 
        if(aux[n] > *max) *max = aux[n];
        *soma += aux[n];
    }

    // Realizando estatisticas de soma e media
    *media = *soma / ((double) qtde_palavras);
    
    // Chamando funcao para estatistica do desvio
    std(aux, media, qtde_palavras, desvio);

    free(min);
    free(max);
    free(soma);
    free(media);
    free(desvio);
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

