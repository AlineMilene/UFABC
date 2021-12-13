// Escreva um programa que fique lendo uma sequência de números inteiros com uma 
// quantidade indeterminada de números. O programa deve ler números até que seja lido
// um número negativo. Quando a leitura for finalizada, o programa deve imprimir o 
// percentual de números lidos que são múltiplos de 10 (o número negativo deve ser 
// desconsiderado para realizar o cálculo do percentual). O percentual deve ser impresso 
// utilizando duas casas decimais após a vírgula.

// Por exemplo, para a sequência 10 100 8 55 10 -99, o programa deve imprimir o 
// valor 0.60 (são 3 múltiplos de 10 de um total de 5 números na sequência).

// Importante: não é permitido o uso de vetor e stdlib.h para resolver este exercício.

#include <stdio.h>

int main (){
    int numero, qtde_multiplos_dez = 0, total_numeros = 0;
    double percentual = 0.00;
    
    do{
        scanf("%d", &numero);
        if(numero > 0)
            total_numeros++;

        if(numero % 10 == 0)
            qtde_multiplos_dez++;

    }while (numero > 0);

    percentual = (double) qtde_multiplos_dez / total_numeros;

    printf("%.2lf\n", percentual);
}