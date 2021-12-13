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

    // Quantidade de palavras no texto
    int i, qtde_palavras = 1;
    for(i = 0; i < comp; i++)
        if(texto[i] == ' ' && texto[i+1] != '\0')
            qtde_palavras++;

    // Contando caracteres de cada palavra e guardando no vetor aux
    int cont= 0, k = 0, aux[qtde_palavras-1];
    for(i = 0; i < comp; i++){
        if(texto[i] >= 'a' && texto[i] <= 'z' || texto[i] >= 'A' && texto[i] <= 'Z'){
            cont++;
        }
        else{
            aux[k] = cont;
            k++;
            cont=0;
        }
    }

    // Verificando ordenamento do vetor aux:
    int l, eh_crescente = 0, eh_decrescente = 0, eh_igual = 0;
    for(l = 0; l < qtde_palavras-1; l++){
        if(aux[l+1] > aux[l])
            eh_crescente++;
        else if(aux[l+1] < aux[l])
            eh_decrescente++;
        else   
            eh_igual++;
    }

    // Condicionais para o return
    if(eh_crescente + eh_igual == (qtde_palavras - 1))
        return 1;
    else if(eh_decrescente + eh_igual == (qtde_palavras - 1))
        return 2;
    else
        return 3;
}

int main() {
    char texto[101];
    fgets(texto, 101, stdin);
    
    int ret = verificar_ordenacao_tamanho(texto);
    printf("verificar_ordenacao_tamanho = %d\n", ret);
    return 0;
}