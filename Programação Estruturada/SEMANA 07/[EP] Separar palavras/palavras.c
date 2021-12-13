// #include "palavras.h"
#include <stdio.h>
#include <stdlib.h>

int comprimento_frase(const char *str) {
    int i = 0;

    if(str == NULL) return -1;
    else{
        while(str[i] != '\0'){
            i++;
        }  
        return i;
    }
}

int comprimento_palavra(const char *str) {
    int i = 0;

    if(str == NULL) return -1;
    else{
        while(str[i] != ' ' || str[i] == '\0'){
            i++;
        }  
        return i;
    }
}

int conta_palavras(const char *str) {
    int comp = comprimento_frase(str);

    if(str == NULL){ // nula
        return -1;
    }else if (comp == 0){
        return 0;
    }
    else{
        int i, qtde_palavras = 1, qtde_espacos = 0;
        for(i = 0; i < comp; i++){
            if(str[i] != ' ' && str[i+1] == ' '){
                int j, esp_restante = 0;
                for(j = i+1; j < comp; j++){
                    if(str[j] == ' '){
                        esp_restante++;
                    }
                }
                if(esp_restante == (comp - i - 1)){
                    // nada pois significa que o restante da string toda até o \0 é composta por espaços
                }else{
                    qtde_palavras++;
                }
            }                                 
            else if(str[i] == ' '){
                qtde_espacos++;
            }                                       
        }
        if(qtde_espacos == comp){
            qtde_palavras = 0;
        }
        return qtde_palavras;
    }
}

char **separar_palavras(char *frase, int *n_palavras) {
    // Descobrindo o tamanho da frase
    int comp = comprimento_frase(frase);
    printf("comprimento = %d\n", comp);
    
    // Descobrindo a quantidade de palavras
    int qtd_palavras = conta_palavras(frase);
    printf("qtde palavras = %d\n", qtd_palavras);
    
    // Retornando via parametro n_palavra a qtde de palavras
    *n_palavras = qtd_palavras;

    // alocando as linhas (vetor de ponteiro)
    char **m = malloc(sizeof(char) * qtd_palavras);

    // criando vetor auxiliar para guardar os tamanhos de cada palavra
    int v_aux[qtd_palavras];

    // descobrindo o tamanho de cada palavra para alocar as colunas
    int i, j = 0, p_tam;
    for(i = 0; i < comp; i++){
        p_tam = 0;
        while(frase[i] != ' ' && frase[i] != '\0'){
            p_tam++;
            i++;
        }
        v_aux[j] = p_tam;
        printf("vetor auxiliar[%d] = %d\n", j, v_aux[j]);
        j++;
    }

    // printando o vetor
    printf("--------------------\n");
    int z;
    for(z = 0; z < qtd_palavras; z++)
        printf("%d ", v_aux[z]);
    printf("\n");
    printf("--------------------\n");

    // alocando as colunas (completar a matriz)
    int k;
    for(k = 0; k < qtd_palavras; k++)
        m[k] = malloc(sizeof(char *) * v_aux[k]);

    // preenchendo a matriz com as palavras
    int i_linha, i_coluna, n = 0, p = 0;
    for(i_linha = 0; i_linha < qtd_palavras; i_linha++){
        int coluna = v_aux[n];
        for(i_coluna = 0; i_coluna < coluna; i_coluna++){
            if(frase[p] != ' ' && frase[p] != '\n'){
                m[i_linha][i_coluna] = frase[p];
                p++;
            }else if(frase[p] == ' '){
                m[i_linha][i_coluna] = frase[p+1];
                p = p + 2;
            }
        }
        n++;
    }
    // imprimindo a matriz completa
    int o = 0;
    for(i_linha = 0; i_linha < qtd_palavras; i_linha++){
        int coluna = v_aux[o];
        for(i_coluna = 0; i_coluna < coluna; i_coluna++){
            printf("%c ", m[i_linha][i_coluna]);
        }
        o++;
        printf("\n");
    }

    return m;
}



int main(){
    char *frase = "Este exercicio envolve o uso de ponteiro para ponteiro na linguagem C";
    int *num;

    separar_palavras(frase, num);
    return 0;
}