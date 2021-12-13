#include <stdio.h>
#include <stdlib.h>

int **criar_matriz(int n_linhas, int n_colunas) {
    // alocando as linhas (vetor de ponteiro)
    int **m = malloc(sizeof(int *) * n_linhas);

    // alocando as colunas (completar a matriz)
    int i;
    for(i = 0; i < n_linhas; i++)
        m[i] = malloc(sizeof(int) * n_colunas);

    // preenchendo a matriz
    int i_linha, i_coluna;
    for(i_linha = 0; i_linha < n_linhas; i_linha++){
        for(i_coluna = 0; i_coluna < n_colunas; i_coluna++){
            scanf("%d", &m[i_linha][i_coluna]);
        }
    }

    return m;
}

void liberar_matriz(int **matriz, int n_linhas) {
    int i;
    for(i = 0; i < n_linhas; i++)
        free(matriz[i]);
    free(matriz);
}

void multiplicar_matrizes(int **matriz_A, int n_linhas_A, int n_colunas_A, int **matriz_B, int n_linhas_B, int n_colunas_B) {
    // Condição de existência
    if(n_colunas_A == n_linhas_B){
        // Criando a matriz resultante que tem o mesmo numero de linhas 
        // que a primeira matriz e o mesmo numero de colunas da segunda matriz

        // alocando as linhas (vetor de ponteiro)
        int **res = malloc(sizeof(int *) * n_linhas_A);

        // alocando as colunas (completar a matriz)
        int i;
        for(i = 0; i < n_linhas_A; i++)
            res[i] = malloc(sizeof(int) * n_colunas_B);

        // preenchendo a matriz resultante
        int k1, k2, l, temp;
        for(k1 = 0; k1 < n_linhas_A; k1++){
            for(k2 = 0; k2 < n_colunas_B; k2++){
                temp = 0;
                for(l = 0; l < n_colunas_A; l++){
                    temp = temp + matriz_A[k1][l] * matriz_B[l][k2];
                }
                res[k1][k2] = temp;
            }
        }

        // Imprimindo a matriz resultante
        int j,k;
        for(j = 0; j < n_linhas_A; j++){
            for(k = 0; k < n_colunas_B; k++){
                if(k != (n_colunas_B-1)){
                    printf("%d ", res[j][k]);
                }
                else{
                    printf("%d \n", res[j][k]);
                }
            }
        }
        
        // Liberando memória da matriz resultante
        liberar_matriz(res, n_linhas_A);
    
    }
}

int main() {
    // Lendo dimensões da matriz A
    int n_linhas_A, n_colunas_A;
    scanf("%d %d", &n_linhas_A, &n_colunas_A);
    
    // Criando a matriz A e preenchendo
    int **matriz_A = criar_matriz(n_linhas_A, n_colunas_A);

    //

    // Lendo dimensões da matriz B
    int n_linhas_B, n_colunas_B;
    scanf("%d %d", &n_linhas_B, &n_colunas_B);
    
    // Criando a matriz B e preenchendo
    int **matriz_B = criar_matriz(n_linhas_B, n_colunas_B);

    multiplicar_matrizes(matriz_A, n_linhas_A, n_colunas_A, matriz_B, n_linhas_B, n_colunas_B);
    
    // Liberando memória da matriz A e matriz B
    liberar_matriz(matriz_A, n_linhas_A);
    liberar_matriz(matriz_B, n_linhas_B);
    
    return 0;
}