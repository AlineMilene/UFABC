// #include "remover_palavra.h"

#include <stdio.h>

int obter_comprimento(char frase[]){
    int i = 0;
    while (frase[i] != '\0')
        i++;
    return i;
}

int quantidade_palavras(char frase[]){
    int comp = obter_comprimento(frase);

    int j, qtde_palavras = 1;
    for(j = 0; j < comp; j++)
        if(frase[j] == ' ' && frase[j+1] != '\0')
            qtde_palavras++;
    return qtde_palavras;
}

void remover_palavra(int i, char frase[]) {
    int inicio_retirada_palavra = -1, inicio_proxima_palavra = -1; 

    // Descobrindo comprimento da frase  
    int comp = obter_comprimento(frase);

    // Descobrindo quantidade de palavras
    int qtde_palavra = quantidade_palavras(frase);
    
    printf("comprimento: %d\n", comp);
    printf("qtde palavras: %d\n", qtde_palavra);

    if(qtde_palavra > 0){
        if(i > qtde_palavra){ // Pediu um indice maior que a qtde de palavras que tem
            return;
        }
        else if(i == qtde_palavra){ // Pediu a ultima palavra
            int j;
            int qtde_espacos = 1;
            // Descobrindo inicio da palavra a ser retirada
            for(j = 0; j < comp; j++){
                if(frase[j] == ' '){
                    qtde_espacos++;
                    printf("qtde espacos: %d\n", qtde_espacos);
                    if(qtde_espacos == i){
                        inicio_retirada_palavra = j + 1;
                        break;
                    }
                }
            }
            printf("\n");
            printf("Inicio da palavra a retirar: %d\n", inicio_retirada_palavra);
            if(inicio_retirada_palavra == -1) return;
            
            inicio_proxima_palavra = j;      
            printf("Inicio da próxima palavra: %d\n", inicio_proxima_palavra);
            printf("\n");
            
            int deslocamento = comp - inicio_proxima_palavra;
            printf("deslocamento: %d\n", deslocamento);

            // Retirada da palavra / Deslocamento da próxima
            for(j = inicio_proxima_palavra; j < comp; j++){
                frase[j] = 0;
            }
        }
        else if(i == 1){ // Pediu a primeira palavra
            int j;
            inicio_retirada_palavra = 0;

            printf("\n");
            printf("Inicio da palavra a retirar: %d\n", inicio_retirada_palavra);
            
            // Descobrindo inicio da palavra próxima palavra
            int existe_simbolo = 0;
            for(j = inicio_retirada_palavra; j < comp; j++){
                if(frase[j] == ' '){
                    if(frase[j-1] >= 'a' && frase[j-1] <= 'z' || frase[j-1] >= 'A' && frase[j-1] <= 'Z'){
                       inicio_proxima_palavra = j + 1;
                        break; 
                    }else{
                        inicio_proxima_palavra = j - 1;
                        existe_simbolo = 1;
                        break;
                    }
                    printf("encontrou o espaço no indice: %d", j);
                    
                }
            }
            printf("Inicio da próxima palavra: %d\n", inicio_proxima_palavra);
            if(inicio_proxima_palavra == -1){
                inicio_proxima_palavra = comp-1;
            }
            printf("\n");
            
            int deslocamento = inicio_proxima_palavra - inicio_retirada_palavra;
            printf("deslocamento: %d\n", deslocamento);

            // Retirada da palavra / Deslocamento da próxima
            if(existe_simbolo == 0){
                for(j = inicio_retirada_palavra; j < comp - deslocamento + 1; j++){
                    frase[j] = frase[j + deslocamento];
                }
            }
            else{
                deslocamento++;
                for(j = inicio_retirada_palavra-1; j < comp - deslocamento + 1; j++){
                    frase[j] = frase[j + deslocamento];
                }
            }
        }
        else{
            int j;
            int qtde_espacos = 1;
            // Descobrindo inicio da palavra a ser retirada
            for(j = 0; j < comp; j++){
                if(frase[j] == ' '){
                    qtde_espacos++;
                    printf("qtde espacos: %d\n", qtde_espacos);
                    if(qtde_espacos == i){
                        inicio_retirada_palavra = j + 1;
                        break;
                    }
                }
            }
            printf("\n");
            printf("Inicio da palavra a retirar: %d\n", inicio_retirada_palavra);
            if(inicio_retirada_palavra == -1) return;
            
            // Descobrindo inicio da palavra próxima palavra
            int existe_simbolo = 0;
            for(j = inicio_retirada_palavra; j < comp; j++){
                if(frase[j] == ' '){
                    if(frase[j-1] >= 'a' && frase[j-1] <= 'z' || frase[j-1] >= 'A' && frase[j-1] <= 'Z'){
                       inicio_proxima_palavra = j + 1;
                        break; 
                    }else{
                        inicio_proxima_palavra = j - 1;
                        existe_simbolo = 1;
                        break;
                    }
                    printf("encontrou o espaço no indice: %d", j);
                    
                }
            }
            printf("Inicio da próxima palavra: %d\n", inicio_proxima_palavra);
            if(inicio_proxima_palavra == -1){
                inicio_proxima_palavra = comp-1;
            }
            printf("\n");
            
            int deslocamento = inicio_proxima_palavra - inicio_retirada_palavra;
            printf("deslocamento: %d\n", deslocamento);

            // Retirada da palavra / Deslocamento da próxima
            if(existe_simbolo == 0){
                for(j = inicio_retirada_palavra; j < comp - deslocamento + 1; j++){
                    frase[j] = frase[j + deslocamento];
                }
            }
            else{
                deslocamento++;
                for(j = inicio_retirada_palavra-1; j < comp - deslocamento + 1; j++){
                    frase[j] = frase[j + deslocamento];
                }
            }
        }
    }
    

}

int main (){
    char frase[100];
    fgets(frase, 100, stdin);

    printf("----------------------------\n");
    remover_palavra(8, frase);
    printf("----------------------------\n");
    puts(frase);
    return 0;
}