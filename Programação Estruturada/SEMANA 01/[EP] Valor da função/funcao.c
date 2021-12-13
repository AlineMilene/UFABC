// Escreva um programa que leia os valores inteiros de n e m, e então imprima 
// o valor da função definida a seguir:


#include <stdio.h>

int funcao_dada(int n, int m){
    int i = 1, k = 1;
    int soma1 = 0, resultado = 0;
    for(k = 1; k <= m; k++){
        soma1 += (k+1)*(k+1);

    }
    for(i = 1; i <= n; i++){
        resultado += (m + 5 * soma1);
    }
    return resultado;
}

int main(){
    int n=0, m=0;
    scanf("%d %d", &n,&m);
    
    printf("%d\n", funcao_dada(n,m));
}

