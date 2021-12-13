#include <stdio.h>
#include <stdlib.h>

double **criar_matriz(int n_linhas, int n_colunas) {
    // alocando as linhas (vetor de ponteiro)
    double **m = malloc(sizeof(double *) * n_linhas);

    // alocando as colunas (completar a matriz)
    int i;
    for(i = 0; i < n_linhas; i++)
        m[i] = malloc(sizeof(double) * n_colunas);

    // preenchendo a matriz
    int i_linha, i_coluna;
    for(i_linha = 0; i_linha < n_linhas; i_linha++){
        for(i_coluna = 0; i_coluna < n_colunas; i_coluna++){
            m[i_linha][i_coluna] = (((i_linha + i_coluna) % 2 == 0) ? 0 : 1);
        }
        i_coluna++;
    }

    return m; 
}

void liberar_matriz(double **matriz, int n_linhas) {
    int i;
    for(i = 0; i < n_linhas; i++)
        free(matriz[i]);
    free(matriz);
}

void imprimir(double **matriz, int n_linhas, int n_colunas) {
    
    int l, c;
    for (l = 0; l < n_linhas; l++) {
        for (c = 0; c < n_colunas; c++)
            printf("%.0lf ", matriz[l][c]);
        printf("\n");
    }
    
}

int main() {
    
    int n_linhas, n_colunas;
    scanf("%d %d", &n_linhas, &n_colunas);
    
    double **m = criar_matriz(n_linhas, n_colunas);
    
    imprimir(m, n_linhas, n_colunas);
    
    liberar_matriz(m, n_linhas);
    
    return 0;
}