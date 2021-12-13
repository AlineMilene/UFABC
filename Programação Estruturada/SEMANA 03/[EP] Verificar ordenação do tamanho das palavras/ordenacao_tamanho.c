// #include "ordenacao_tamanho.h"
#include <stdio.h>

int obter_comprimento(char frase[]){
    int i = 0;
    while (frase[i] != '\0')
        i++;
    return i;
}

int verificar_ordenacao_tamanho(char texto[]) {
    // Descobrir o comprimento do texto
    int comp = obter_comprimento(texto);
    printf("comprimento: %d\n", comp);
    printf("\n");

    // Quantidade de palavras no texto
    int i, qtde_palavras = 1;
    for(i = 0; i < comp; i++)
        if(texto[i] == ' ' && texto[i+1] != '\0')
            qtde_palavras++;
    printf("qtde palavras: %d\n", qtde_palavras);
    printf("\n");

    // Contando caracteres de cada palavra e guardando no vetor aux
    int cont= 0, k = 0, aux[qtde_palavras-1];
    for(i = 0; i < comp; i++){
        if(texto[i] >= 'a' && texto[i] <= 'z' || texto[i] >= 'A' && texto[i] <= 'Z'){
            cont++;
        }
        else{
            aux[k] = cont;
            k++;
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

    // Verificando ordenamento do vetor aux:
    int l, eh_crescente = 0, eh_decrescente = 0, eh_igual =0;
    for(l = 0; l < qtde_palavras-1; l++){
        if(aux[l+1] > aux[l])
            eh_crescente++;
        else if(aux[l+1] < aux[l])
            eh_decrescente++;
        else   
            eh_igual++;
    }
    printf("crescente: %d\n", eh_crescente);
    printf("decrescente: %d\n", eh_decrescente);
    printf("igual: %d\n", eh_igual);

    // Condicionais para o return
    if(eh_crescente + eh_igual == (qtde_palavras - 1) && eh_crescente > 0)
        printf("CRESCENTE\n");
    else if(eh_decrescente + eh_igual == (qtde_palavras - 1) && eh_decrescente > 0)
        printf("DECRESCENTE\n");
    else
        printf("NAO ORDENADA\n");

}

int main() {
    char texto[101];
    fgets(texto, 101, stdin);
    
    int ret = verificar_ordenacao_tamanho(texto);
    printf("verificar_ordenacao_tamanho = %d\n", ret);
    return 0;
}