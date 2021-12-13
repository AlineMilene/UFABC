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
                    if(qtde_espacos == i){
                        inicio_retirada_palavra = j + 1;
                        break;
                    }
                }
            }
            if(inicio_retirada_palavra == -1) return;
            
            inicio_proxima_palavra = j;      
            int deslocamento = comp - inicio_proxima_palavra;

            // Retirada da palavra / Deslocamento da próxima
            for(j = inicio_proxima_palavra; j < comp; j++){
                frase[j] = 0;
            }
        }
        else if(i == 1){ // Pediu a primeira palavra
            int j;
            inicio_retirada_palavra = 0;
            
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
                }
            }
            if(inicio_proxima_palavra == -1){
                inicio_proxima_palavra = comp-1;
            }
            
            int deslocamento = inicio_proxima_palavra - inicio_retirada_palavra;

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
                    if(qtde_espacos == i){
                        inicio_retirada_palavra = j + 1;
                        break;
                    }
                }
            }
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
                }
            }
            if(inicio_proxima_palavra == -1) inicio_proxima_palavra = comp-1;
            
            int deslocamento = inicio_proxima_palavra - inicio_retirada_palavra;

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
