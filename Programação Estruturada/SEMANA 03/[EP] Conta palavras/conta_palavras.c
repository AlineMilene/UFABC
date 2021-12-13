#include <stdio.h>

int obter_comprimento(char frase[]){
    int i = 0;
    while (frase[i] != '\0')
        i++;
    return i;
}

int main(){

    char frase[100];
    fgets(frase, 100, stdin);

    int comp;
    comp = obter_comprimento(frase);
    
    int i, qtde_palavras = 1;
    for(i = 0; i < comp; i++)
        if(frase[i] == ' ' && frase[i+1] != '\0')
            qtde_palavras++;
    printf("%d\n", qtde_palavras);
}