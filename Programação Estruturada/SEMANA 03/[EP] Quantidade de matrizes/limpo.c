#include <stdio.h>

int verificar_sequencia(int l1, int c1, int matriz1[l1][c1],  int l2, int c2, int matriz2[l2][c2]) {
    int contador = 0, frequencia = 0;
    
    // Descobrindo a quantidade de itens da matriz2
    int qtde_matriz2 = l2*c2;

    for(int lin1 = 0; lin1 < l1;  lin1++){ // Percorrendo a linha da matriz1
        for(int col1 = 0; col1 < c1; col1++){ // Percorrendo a coluna da matriz1      
            contador = 0;
            if(matriz1[lin1][col1]==matriz2[0][0]){ 
                for(int lin2=0; lin2 < l2; lin2++){ // Percorrendo a linha da matriz2
                    for(int col2 =0; col2 < c2; col2++){ // Percorrendo a coluna da matriz2
                        if(matriz1[lin1+lin2][col1+col2] == matriz2[lin2][col2]){
                            contador++;
                            if(contador == qtde_matriz2){
                                contador = 0;
                                frequencia++;
                            } 
                        }
                    }
                }
            }        
        } 
    }
    
    return frequencia;
}
int main(){
    int linhas1, colunas1, linhas2, colunas2;

    // Lendo a quantidade das linhas e colunas da matriz1
    scanf("%d %d", &linhas1, &colunas1);
    int m1[linhas1][colunas1];
    
    // Lendo a matriz1
    int i, j;
    for(i = 0; i < linhas1; i++){
        for(j = 0; j < colunas1; j++){
            scanf("%d", &m1[i][j]);
        }
    }

    // Lendo a quantidade das linhas e colunas da matriz2
    scanf("%d %d", &linhas2, &colunas2);
    int m2[linhas2][colunas2];

    // Lendo a matriz2
    int x, y;
    for(x = 0; x < linhas2; x++){
        for(y = 0; y < colunas2; y++){
            scanf("%d", &m2[x][y]);
        }
    }

    // Chamando função para verificar a sequencia e retornar a qtde
    int qtde_matrizes;
    qtde_matrizes = verificar_sequencia(linhas1, colunas1, m1, linhas2, colunas2, m2);

    printf("%d\n", qtde_matrizes);
    return 0;
}