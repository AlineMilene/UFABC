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

    for(linha = 0; linha < n; linha++){
        for(coluna = 0; coluna < n; coluna++){          
            if(linha == coluna){
                diagonal = m[linha][coluna];
            }
            else{
                soma_linha += m[linha][coluna];
            }
        }
        if(diagonal > soma_linha){
                eh_estrita++;
        }
        soma_linha = 0; 
    }
    if(eh_estrita == n){
        return 1;
    }
    else{
        return 0;
    }
}

