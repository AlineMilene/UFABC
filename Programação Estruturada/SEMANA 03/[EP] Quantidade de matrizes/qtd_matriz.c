#include <stdio.h>


// Entrada do programa:
// [Número de linhas da matriz 1] [Número de colunas da matriz 1]
// Valores da matriz 1, linha por linha
// [Número de linhas da matriz 2] [Número de colunas da matriz 2]
// Valores da matriz 2, linha por linha

// Saída:
// Quantidade de vezes que matriz 2 aparece dentro da matriz 1

int verificar_sequencia(int l1, int c1, int matriz1[l1][c1],  int l2, int c2, int matriz2[l2][c2]) {
    int contador = 0, frequencia = 0;
    
    // Printando a matriz1 para verificar se deu bom
    printf("\n");
    printf("----------- MATRIZ 1 DENTRO DA FUNCAO ------------\n");
    int t, u;
    for(t = 0; t < l1; t++){
        for(u = 0; u < c1; u++){
            printf("%d ", matriz1[t][u]);
        }
        printf("\n");
    }

    // Printando a matriz2 para verificar se deu bom
    printf("\n");
    printf("----------- MATRIZ 2 DENTRO DA FUNCAO ------------\n");
    for(t = 0; t < l2; t++){
        for(u = 0; u < c2; u++){
            printf("%d ", matriz2[t][u]);
        }
        printf("\n");
    }

    // Descobrindo a quantidade de itens da matriz2
    int qtde_matriz2 = l2*c2;
    printf("qtde m2 = %d\n", qtde_matriz2);
    printf("\n");

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
    printf("contador= %d\n", contador);
    printf("frequencia= %d\n", frequencia);
    
    return contador;
}
int main(){
    int linhas1, colunas1, linhas2, colunas2;

    // Lendo a quantidade das linhas e colunas da matriz1
    printf("Quantidadade de Linhas e Colunas M1\n");
    scanf("%d %d", &linhas1, &colunas1);
    int m1[linhas1][colunas1];
    
    // Lendo a matriz1
    printf("Ler a matriz 1\n");
    int i, j;
    for(i = 0; i < linhas1; i++){
        for(j = 0; j < colunas1; j++){
            scanf("%d", &m1[i][j]);
        }
    }

    // Lendo a quantidade das linhas e colunas da matriz2
    printf("Quantidadade de Linhas e Colunas M2\n");
    scanf("%d %d", &linhas2, &colunas2);
    int m2[linhas2][colunas2];

    // Lendo a matriz2
    printf("Ler a matriz 2\n");
    int x, y;
    for(x = 0; x < linhas2; x++){
        for(y = 0; y < colunas2; y++){
            scanf("%d", &m2[x][y]);
        }
    }

    // Printando a matriz1 para verificar se deu bom
    printf("\n");
    printf("----------- MATRIZ 1 ------------\n");
    int t, u;
    for(t = 0; t < linhas1; t++){
        for(u = 0; u < colunas1; u++){
            printf("%d ", m1[t][u]);
        }
        printf("\n");
    }

    // Printando a matriz2 para verificar se deu bom
    printf("\n");
    printf("----------- MATRIZ 2 ------------\n");
    for(t = 0; t < linhas2; t++){
        for(u = 0; u < colunas2; u++){
            printf("%d ", m2[t][u]);
        }
        printf("\n");
    }

    // Chamando função para verificar a sequencia e retornar a qtde
    int qtde_matrizes;
    qtde_matrizes = verificar_sequencia(linhas1, colunas1, m1, linhas2, colunas2, m2);

    printf("\n");
    printf("\n");

    printf("Qtde retornada da funcao de matrizes: %d\n", qtde_matrizes);
    return 0;
}