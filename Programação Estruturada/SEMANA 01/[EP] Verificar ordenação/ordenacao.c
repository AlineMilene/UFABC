// Escreva um programa que fique lendo uma sequência de números inteiros com uma 
// quantidade indeterminada de números. O programa deve ler números até que seja lido 
// um número negativo. Quando a leitura for finalizada, o programa deve imprimir se a 
// sequência de números lidos está ordenada em ordem crescente, descrescente ou 
// não ordenada (considere que o valor negativo não faz parte da sequência para verificar 
// a ordenação). A sequência de números pode conter números repetidos, mas haverá pelo 
// menos dois números diferentes na sequência.

// Por exemplo:

// para a sequência 10 20 30 40 50 -99, o programa deve imprimir "CRESCENTE"
// para a sequência 50 40 30 20 10 -99, o programa deve imprimir "DECRESCENTE".
// para a sequência 30 20 50 10 20 -99, o programa deve imprimir "NAO ORDENADA".
// Importante: não é permitido o uso de vetor e stdlib.h para resolver este exercício.

#include <stdio.h>

int main(){
    int num_lido, num_anterior = 0, eh_crescente = 0, eh_decrescente = 0, total_lidos = 0;

    do{
        scanf("%d", &num_lido);
        
        if(num_lido > 0){
            total_lidos++;

            if(num_lido > num_anterior)
                eh_crescente++;
            else if(num_lido < num_anterior)
                eh_decrescente--;
            
            num_anterior = num_lido;
        }
    }while(num_lido > 0);

    if(eh_crescente > 0 && eh_decrescente == 0)
        printf("CRESCENTE\n");
    else if(eh_decrescente < 0 && eh_crescente == 1)
        printf("DECRESCENTE\n");
    else
        printf("NAO ORDENADA\n");
}