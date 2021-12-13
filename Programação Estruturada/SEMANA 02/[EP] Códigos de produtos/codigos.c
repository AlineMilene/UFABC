// Uma empresa registra o código de cada produto vendido ao longo do dia em uma lista. 
// O gerente gostaria que, ao adicionar um código na lista, essa lista se mantenha ordenada
// (em ordem crescente). Dessa forma, ao final do dia, é mais fácil verificar quais produtos 
// foram vendidos.

// Faça um programa que fique lendo códigos de produtos (números inteiros):

// • Cada número deverá ser inserido em um vetor de códigos de produtos mantendo a
// ordenação (ordem crescente). Assuma que haverá no máximo 100 códigos de produtos. 
// No início, o vetor não possui nenhum código de produto armazenado.
// • Após cada inserção, imprima o vetor completo. O programa encerra quando o usuário
//  digitar o número -1 (não imprima o vetor após o usuário digitar -1, apenas encerre o 
//  programa).

#include <stdio.h>

int main (){
    int codigo_produto[100];
    int numero, i = 0, aux, qtde = 0;

    do{
        // Entrada do número
        printf("Digite: ");
        scanf("%d", &numero);
        qtde++;

        // Salvando o número
        if(numero != -1){
            codigo_produto[i] = numero;
            i++;
        }

        // Ordenando o vetor        
        for(i = qtde-1; i >= 0 && numero != -1; i--){
            if(numero < codigo_produto[i]){
                codigo_produto[i+1] = codigo_produto[i]; 
                codigo_produto[i] = numero;
            }
        }
        
        // Imprimindo o vetor
        for(i = 0; i < qtde && numero != -1; i++){
            printf("%d ", codigo_produto[i]);
        }
        printf("\n");
    }while(numero != -1);
}