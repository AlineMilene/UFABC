//#include "compactar.h"

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
        
        // Inserindo no vetor 2
        if(count > 0){
            inserir(aux, n, valor, count);
        }     
    }

    // copiando vetor aux para vetor original
    for(i = 0; i < n; i++){
        v[i] = aux[i];
    }
}