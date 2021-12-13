#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetor_aleatorio(int n){
    int *v = malloc(sizeof(int) * n);

    int i;
    for(i = 0; i < n; i++)
        scanf("%d",v + i);

    return v;
}

void imprimir(int *v, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int qtde_digitos(int numero){
    printf("numero: %d\n", numero);
    int resto = 0, count = 0;
    while(numero > 0){
        if (numero % 10 != -1){
            resto = numero % 10;
            count++;
        }
        numero = numero / 10;
    }
    printf("qtd_digitos: %d\n", count);
    return count;
}

int soma_digitos(int numero){
    printf("numero: %d\n", numero);
    int resto = 0, soma = 0;
    while(numero > 0){
        if (numero % 10 != 0){
            resto = numero % 10;
            soma+= resto;
        }
        numero = numero / 10;
    }

    return soma;
}

void bubble_es(int *v, int n){
    int i, trocou = 1;
    for(i = 0; i < n-1 && trocou; i++){
        trocou = 0;
        int k;
        for(k = 0; k < n-1-i; k++){
            if(soma_digitos(v[k]) > soma_digitos(v[k+1])){
                int temp = v[k];
                v[k] = v[k+1];
                v[k+1] = temp;
                trocou = 1;
            }
            else if(soma_digitos(v[k]) == soma_digitos(v[k+1])){
                if(qtde_digitos(v[k]) > qtde_digitos(v[k+1])){
                    int temp = v[k];
                    v[k] = v[k+1];
                    v[k+1] = temp;
                    trocou = 1; 
                }
            }      
        }
    }
}

int main(){
    // Lendo tamanho do vetor1
    int tamanho;
    // scanf("%d", &tamanho);

    // Declarando vetor1
    int *vetor = NULL;
    // vetor = vetor_aleatorio(tamanho);

    // Imprimindo vetor antes de ordenar
    // imprimir(vetor, tamanho);

    // Ordenando em ordem crescente via bubble 
    // insertion_sort(vetor, tamanho);
    
    // Imprimindo vetor depois de ordenar
    // imprimir(vetor, tamanho);
    
    // Liberando memória
    free(vetor);

    int num;
    scanf("%d", &num);
    qtde_digitos(num);

    return 0;
}