// #include "diagonal_dominante.h"
#include <stdio.h>

void tirar_modulo(int n, int m[][n]){
    int linha, coluna, diagonal;
    for(linha = 0; linha < n; linha++){
        for(coluna = 0; coluna < n; coluna++){
            if(m[linha][coluna] < 0)
                m[linha][coluna] = m[linha][coluna] * -1;
        }
    }
}

int diagonal_dominante(int n, int m[][n]) {
    int linha, coluna, diagonal;
    int soma_linha = 0, eh_estrita = 0;

    // chamando funcao modulo
    tirar_modulo(n, m);

    // imprindo modulo
    for(linha = 0; linha < n; linha++){
        for(coluna = 0; coluna < n; coluna++)
            printf("%d ", m[linha][coluna]);
        printf("\n");
    }
    
    printf("\n");


    for(linha = 0; linha < n; linha++){
        for(coluna = 0; coluna < n; coluna++){          
            if(linha == coluna){
                diagonal = m[linha][coluna];
                printf("dp: %d\n", m[linha][coluna]);
            }
            else{
                soma_linha += m[linha][coluna];
            }
        }
        printf("soma linha %d: %d\n", linha, soma_linha);
        
        if(diagonal > soma_linha){
            eh_estrita++;
        }
        soma_linha = 0;
    }
    printf("\n");
    printf("qtde estritas: %d\n", eh_estrita);
    if(eh_estrita == n){
        printf("deu bom\n");
    }
    else{
        printf("deu ruim\n");
    }
}

int main(){
    // int n = 3;
    // int matriz[n][n];

    // matriz[0][0] = 7;
    // matriz[0][1] = 2;
    // matriz[0][2] = 0;

    // matriz[1][0] = 3;
    // matriz[1][1] = 5;
    // matriz[1][2] = -1;
    
    // matriz[2][0] = 0;
    // matriz[2][1] = 5;
    // matriz[2][2] = -6;

    int n = 4;
    int matriz[n][n];

    matriz[0][0] = 4;
    matriz[0][1] = 2;
    matriz[0][2] = -3;
    matriz[0][3] = -3;

    matriz[1][0] = 3;
    matriz[1][1] = 9;
    matriz[1][2] = 2;
    matriz[1][3] = 1;
    
    matriz[2][0] = 1;
    matriz[2][1] = 1;
    matriz[2][2] = 6;
    matriz[2][3] = 1;

    matriz[3][0] = 2;
    matriz[3][1] = 0;
    matriz[3][2] = 2;
    matriz[3][3] = 8;

    int linha, coluna;
    for(linha = 0; linha < n; linha++){
        for(coluna = 0; coluna < n; coluna++)
            printf("%d ", matriz[linha][coluna]);
        printf("\n");
    }
    
    printf("\n");

    // chamando a funcao
    diagonal_dominante(n, matriz);

}