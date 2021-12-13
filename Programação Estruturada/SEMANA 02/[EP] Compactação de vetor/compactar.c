#include <stdio.h>

void inserir(int v[], int n, int numero, int repeticao){
    int i;
    for(i = 0; i < n; i++){
        if(v[i] == -1){
            v[i] = numero;
            v[i+1] = repeticao;
            break; 
        } 
    }
}

void compactar_vetor(int v[], int n) {
    int i, j = 0, k, l, m, valor, atual, teste, qtde, count;
    int aux[n];

    printf("n: %d\n", n);
    // inserindo -1 em todo vetor auxiliar
    for(m = 0; m < n; m++){
        aux[m] = -1;
    }

    for(i = 0; i < n; i++){
        count = 0;
        
        if(v[i] != -1){
            valor = v[i];   
        }
        else{
            valor = -99;
        }
        // realizando a contagem
        while(v[j] == valor){   
            count++;
            j++;
        }
        printf("valor: %d\n", valor);
        printf("count: %d\n", count);
        
        // Inserindo no vetor 2
        if(count > 0){
            inserir(aux, n, valor, count);
        }     
        
        printf("----------------------\n");
    }

    // copiando vetor aux para vetor original
    for(i = 0; i < n; i++){
        v[i] = aux[i];
    }

    // Imprimindo o vetor (não incluir no moodle)
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    for(i = 0; i < n; i++){
        printf("%d ", aux[i]);
    }
    printf("\n");
}

int main(){
    //int v1[10] = {10, 10, 10, 10, 10, 50, 50, 90, -1, -1};
    int vetor[12] = {11, 11, 11, 22, 22, 55, 11, 11, -1, -1, -1, -1};
    //compactar_vetor(v1, 10);
    compactar_vetor(vetor, 12);
}