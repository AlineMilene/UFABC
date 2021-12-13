#include <stdio.h>
#include <stdlib.h>

int obter_comprimento(char *frase, int i){
    while (frase[i] != '\0' && frase[i] != '\n') // considerar 
        i++;
    return i;
}

char *avanca_palavra(char *frase, char *trecho) {
    // Descobrindo comprimento da frase
    int comp_frase = obter_comprimento(frase, 0);

    // Descobrindo comprimento do trecho
    int comp_trecho = obter_comprimento(trecho, 0);

    if(comp_trecho > comp_frase){
        return NULL;
    }else{
    // Descobrindo o indice que a frase precisa iniciar (após o trecho)
    int i, j = 0, x = 0, qtde = 0, aux_i = 0;
    for (i = 0; i < comp_frase; i++) // Faz verificação de todas as letras da FRASE
	{
		if (trecho[0]==frase[i]) // Compara a primeira letra de PALAVRA com as letras da frase
		{
			aux_i = i;
			x = 0; // Variavel de controle de sequencia
			for(j = 0; j < comp_trecho; j++)// Faz verificação da sequencia da sequencia PALAVRA com a sequencia da FRASE
			{
				if(trecho[j]==frase[aux_i]) // Faz contagem da sequencia, para fazer comparação com tamanho
				{
					x++;					
				}
				aux_i++;
			}
			if (x >= comp_trecho){// Verifica se sequencia da PALAVRA foi encontrada na FRASE
                qtde++;
                break;
            }
		}	
	}
    int indice = 0;
    if(qtde != 0){
        indice = aux_i - comp_trecho;
    }else{
        return NULL;
    }

    // Declarando um ponteiro de char do tamanho restante
    int comp_restante;
    if(indice == 0){
        comp_restante = comp_frase;
    }else{
        comp_restante = comp_frase - comp_trecho;
    }
    char *restante = malloc(comp_restante);

    // Preenchendo o vetor com a frase restante
    int k, l = indice;
    for(k = 0; k < comp_restante; k++){
        restante[k] = frase[l];
        l++;
    }

    return restante;
    }
}

int main(){
    char frase[1000];
    fgets(frase, 1000, stdin);

    char trecho[100];
    fgets(trecho, 100, stdin);

    avanca_palavra(frase, trecho);

    return 0;
}