// Escreva um programa que leia um número inteiro (int) e imprima a quantidade de dígitos ímpares.

// Por exemplo, no número 786254968 há 3 dígitos ímpares (7, 5, 9). Portanto, para o número 786254968, o programa deverá imprimir o valor 3.

#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);

    int qtde_impares = 0;
    int resto = 0;
    while(numero > 0){

        if (numero % 10 != 0){
            resto = numero % 10;
            if(resto % 2 != 0){
                qtde_impares++;
            } 
        }
        numero = numero / 10;
    }
    printf("%d\n", qtde_impares);
}