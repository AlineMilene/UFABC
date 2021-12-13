//#include "maior_palindromo.h"

#include <stdio.h>

void converte_numero_para_vetor_de_digitos(int n, int v[]) {
    int i = 0, resto, digito = 0, qtde_digitos = 0;

    // Descobrindo o tamanho do numero
    int tam_numero = 0, resto_numero, numero_aux;
    numero_aux = n;
    while(numero_aux > 0){
        if (numero_aux % 10 != 0){
            resto = numero_aux % 10;
            tam_numero++; 
        }
        numero_aux = numero_aux / 10;
    }
    
   // Quebrando o valor digitado em um vetor de digitos
    while(n > 0){
        if (n % 10 != 0 || i <= tam_numero){
            resto = n % 10;
            v[i] = resto;
            i++; 
        }
        n = n / 10;
    }
    v[i] = -1;

    // Invertendo os digitos e adicionando a um vetor invertido
    int m = i-1;
    int vetInvert[i], j;
    for(j = 0; j < i; j++){ 
        vetInvert[j] = v[m];
        m--; 
    }

    vetInvert[j] = -1;

    // Copiando a sequencia correta para o vetor normal
    int o;
    for(o = 0; o < i; o++){
        v[o] = vetInvert[o];
    }
}


int eh_palindromo(int v[]) {
    int tam = 0, i = 0;

    // Descobrindo tamanho do vetor (apenas numeros válidos)
    while(v[i] != -1){
        i++;
        tam++;
    }


    // Descobrindo se é um palíndromo
    int j = tam-1, k = 0;
    while(k < j) {
        if(v[k] != v[j]){
            return 0;
            break;
        }
        k++;
        j--;
    }
    if(k >= j){
        return 1; 
    }

}

int maior_palindromo(int m, int fatores[2]) {  
    int a, b, prod_tam, prod, retorno = 0;

    a = m;
    b = m;
    prod = a * b;
    prod_tam = prod;
    
    while(retorno == 0){
        // Descobrindo o tamanho do produto entre A e B
        int tam = 0, resto;
        while(prod_tam > 0){
            if (prod_tam % 10 != 0){
                resto = prod_tam % 10;
            }
            tam++; 
            prod_tam = prod_tam / 10;
        }

        // Declarando vetor de tamanho i+1 para comportar o -1, sendo i o tamanho do produto entre A e B
        int v[tam+1];

        // Convertendo o produto de A e B para um vetor de digitos
        converte_numero_para_vetor_de_digitos(prod, v);
        
        // Verificando se essa combinação é um palíndromo
        retorno = eh_palindromo(v);
        printf("retorno: %d\n", retorno);
        
        if(retorno == 0){
            m--;
            b = m;
            prod = a * b;
            prod_tam = prod;
        }   
    }

    // Encontrado o maior palindromo, salvando os valores de a e b no vetor de fatores
    fatores[0] = a;
    fatores[1] = b;
    printf("fator [0]: %d\n", fatores[0]);
    printf("fator [1]: %d\n", fatores[1]);
    printf("palindromo = %d\n", prod);
    return prod;
}

int main(){
    int v[4];
    converte_numero_para_vetor_de_digitos(246, v);

    eh_palindromo(v);

    int v2[2];
    maior_palindromo(25, v2);
}