//#include "maior_palindromo.h"

#include <stdio.h>

void converte_numero_para_vetor_de_digitos(int n, int v[]) {
    int i = 0, resto, digito = 0, qtde_digitos = 0;

    // Descobrindo o tamanho do numero
    int tam_numero = 0, resto_numero, numero_aux;
    numero_aux = n;
    while(numero_aux > 0){
        resto = numero_aux % 10;
        tam_numero++; 
        numero_aux = numero_aux / 10;
    }
    printf("tamanho do numero é: %d\n", tam_numero);
    
   // Quebrando o valor digitado em um vetor de digitos
    while(n > 0){
        resto = n % 10;
        v[i] = resto;
        i++; 
        n = n / 10;
    }
    v[i] = -1;

    // Imprimindo o vetor normal
    printf("Vetor normal antes\n");
    int k;
    for(k = 0; k < i+1; k++){
        printf("vetor [%d]: %d\n", k, v[k]);
    }

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

    // Imprimindo o vetor normal
    printf("\n");
    printf("Vetor normal depois\n");
    for(k = 0; k < i+1; k++){
        printf("vetor [%d]: %d\n", k, v[k]);
    }
    printf("\n");
    printf("-------------------------------------------");
    printf("\n");
}


int eh_palindromo(int v[]) {
    int tam = 0, i = 0;

    // Descobrindo tamanho do vetor (apenas numeros válidos)
    while(v[i] != -1){
        i++;
        tam++;
    }
    printf("i: %d\n", i);
    printf("tamanho: %d\n", tam);
    
    // Imprimindo o vetor normal
    printf("\n");
    printf("Vetor normal DENTRO DA SEGUNDA FUNCAO \n");
    int k;
    for(k = 0; k < tam+1; k++){
        printf("vetor [%d]: %d\n", k, v[k]);
    }


    // Descobrindo se é um palíndromo
    int j = tam-1;
    k = 0;
    while(k < j) {
        if(v[k] != v[j]){
            printf("NAOOOOOO é um palindromo\n");
            return 0;
            break;
        }
        k++;
        j--;
    }
    if(k >= j){
        printf("é um palindromo\n");
        return 1; 
    }

}

int maior_palindromo(int m, int fatores[2]) {
    printf("\n");
    printf("-------------------------------------------");
    printf("\n");
    
    int a, b, prod_tam, prod, retorno = 0;

    a = m;
    b = m;
    prod = a * b;
    prod_tam = prod;
    
    while(retorno == 0){
        printf("valor de a: %d\n", a);
        printf("valor de b: %d\n", b);
        printf("valor do produto: %d\n", prod);

        // Descobrindo o tamanho do produto entre A e B
        int tam = 0, resto;
        while(prod_tam > 0){
            resto = prod_tam % 10;
            tam++; 
            prod_tam = prod_tam / 10;
        }
        printf("valor de prod depois: %d\n", prod);
        printf("valor do tamanho: %d\n", tam);

        // Declarando vetor de tamanho i+1 para comportar o -1, sendo i o tamanho do produto entre A e B
        int v[tam+1];
        
        // Imprimindo o vetor
        printf("\n");
        int k;
        for(k = 0; k < tam+1; k++){
            printf("vetor [%d]: %d\n", k, v[k]);
        }

        // Convertendo o produto de A e B para um vetor de digitos
        printf("\nchamei a função de converter\n\n");
        converte_numero_para_vetor_de_digitos(prod, v);
        
        // Verificando se essa combinação é um palíndromo
        printf("\nchamei a função de palindromo\n\n");
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
    int v[5];
    converte_numero_para_vetor_de_digitos(6006, v);

    eh_palindromo(v);

    int v2[2];
    maior_palindromo(25, v2);
}