// #include "conta_linhas_texto.h"

#include <stdio.h>
#include <stdlib.h>

int tam_frase(char frase[]){
    int i = 0;
    while (frase[i] != '\0')
        i++;
    return i;
}

void conta_linhas(char texto[], int largura_linha, int* qtd_linhas) {
    // Descobrindo o tamanho da frase
    int tam = tam_frase(texto);

    // Descobrindo a quantidade de palavras
    int i, qtde_palavras = 1;
    for(i = 0; i < tam; i++)
        if(texto[i] == ' ' && texto[i+1] != '\0')
            qtde_palavras++;

    // Contando caracteres de cada palavra e guardando no vetor aux
    int j, cont= 0, k = 0, aux[qtde_palavras-1];
    for(j = 0; j < tam; j++){
        while(texto[j] != ' ' && texto[j] != '\0' && texto[j] != '\n'){
            cont++;
            j++;
        }
        if(cont != 0){
            aux[k] = cont;
            k++;
        }
        cont=0;
    }

    // Inserindo em um vetor de tamanho da largura dada para contar as linhas
    int m, n, vet[largura_linha], linhas = 0;
    for(m = 0; m < qtde_palavras; m++){
        if((aux[m] + aux[m+1] + aux[m+2] + aux[m+3] + aux[m+4] + aux[m+5] + aux[m+6] + 6) <= largura_linha){
            linhas++;
            m+=6;
        }
        else if((aux[m] + aux[m+1] + aux[m+2] + aux[m+3] + aux[m+4] + aux[m+5] + 5) <= largura_linha){
            linhas++;
            m+=5;
        }
        else if((aux[m] + aux[m+1] + aux[m+2] + aux[m+3] + aux[m+4] + 4) <= largura_linha){
            linhas++;
            m+=4;
        }
        else if((aux[m] + aux[m+1] + aux[m+2] + aux[m+3] + 3) <= largura_linha){
            linhas++;
            m+=3;
        }
        else if((aux[m] + aux[m+1] + aux[m+2] + 2) <= largura_linha){
            linhas++;
            m+=2;
        }
        else if((aux[m] + aux[m+1] + 1) <= largura_linha){
            linhas++;
            m++;
        }
        else if(aux[m] <= largura_linha){
            linhas++;
        }
    }
    *qtd_linhas = linhas;
    printf("qtde linhas: %d\n", *qtd_linhas);    
}

int main(){

    char frase[100];
    fgets(frase, 100, stdin);

    int *qtd_linhas = malloc(sizeof(int));

    conta_linhas(frase, 10, qtd_linhas);
}





// o que mais passou:
// Contando caracteres de cada palavra e guardando no vetor aux
    // int j, cont= 0, k = 0, aux[qtde_palavras];
    // for(j = 0; j < tam; j++){
    //     if(texto[j] >= 'a' && texto[j] <= 'z' || texto[j] >= 'A' && texto[j] <= 'Z'){
    //         cont++;
    //     }
    //     else{
    //         if(cont != 0){
    //             aux[k] = cont;
    //             k++;
    //         }
    //         cont=0;
    //     }
    // }