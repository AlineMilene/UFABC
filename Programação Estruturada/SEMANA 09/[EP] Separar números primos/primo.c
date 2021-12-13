// #include "primos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eh_primo(int n){
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;

    int i;
    for(i = 3; i <= sqrt(n); i+=2)
        if(n % i == 0) return 0;
    return 1;
}

typedef struct ListaNumeros ListaNumeros;
struct ListaNumeros {
    int *numeros;
    int *primos;
    int n_numeros, n_primos;
};

void separar_numeros_primos(ListaNumeros *lista) {
    // Descobrindo a quantidade de número primos para criar um vetor de tamanho correto
    int i, count = 0;
    for(i = 0; i < lista->n_numeros; i++){
        if(eh_primo(lista->numeros[i])){
            count++;
        };
    }
    printf("contador: %d\n", count);

    // Inserindo na variavel de n_primos a quantidade de primos encontrada
    lista->n_primos = count;

    // Imprimindo n_primos para verificar
    printf("n_primos: %d\n", lista->n_primos);
    printf("\n");

    // Criando um vetor para armazenar os números primos
    int *vet = malloc(sizeof(int) * count);

    // Preenchendo o vetor criado com os primos e retirando da lista de numeros
    int j, k = 0;
    for(j = 0; j < lista->n_numeros; j++){ 
        if(eh_primo(lista->numeros[j])){
            vet[k] = lista->numeros[j];
            k++;
            for(int l = j; l < lista->n_numeros-k; l++){
                lista->numeros[l] = lista->numeros[l+1];
            }

            // imprimindo a nova lista para testar
            for(int l = 0; l < lista->n_numeros-k; l++){
                printf("%d ", lista->numeros[l]);
            }
            printf("\n");
        };
    }
    printf("\n");

    // Imprimindo o vetor de primos
    int l;
    for(l = 0; l < lista->n_primos; l++) 
        printf("%d ", vet[l]);
    printf("\n");
    printf("\n");

    // Fazendo com que o ponteiro de primos aponte para o vetor de primos criado
    lista->primos = vet;

    // Imprimindo o ponteiro de primos para testar
    for(int l = 0; l < lista->n_primos; l++){
        printf("%d ", lista->primos[l]);
    }
    printf("\n");   
}

int main(){
    // Se primo retorna 1
    // Se não primo retorna 0

    ListaNumeros *lista = malloc(sizeof(ListaNumeros));

    int n;
    scanf("%d", &n);

    int vetor[n];

    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    int j;
    for(j = 0; j < n; j++)
        printf("%d ", vetor[j]);
    printf("\n");
    printf("\n");

    lista->n_numeros = n;
    lista->numeros = vetor;
    lista->primos = NULL;
    lista->n_primos = 0;

    separar_numeros_primos(lista);

    return 0;
}