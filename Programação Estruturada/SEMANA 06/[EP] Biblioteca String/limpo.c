#include <stdlib.h>

int str_length (const char *str) {
    int i = 0;

    if(str == NULL) return -1;
    else{
        while(str[i] != '\0'){
            i++;
        }
        
        return i;
    }
}


char* str_duplicate (const char *str) {
    // Descobrindo o tamanho do ponteiro recebido
    int comp = str_length(str);

    if(comp == -1){ // ponteiro nulo foi passado
        char *duplicate_null = NULL;
        return duplicate_null;
    }else{ 
        // criando um novo ponteiro para duplicar, do tamanho do ponteiro que foi passado
        char *duplicate = malloc(comp);
        
        // Percorrendo esse vetor para efetuar a cópia
        int i;
        for (i = 0; i < comp; i++){
            duplicate[i] = str[i];
        }

        // Retornando o ponteiro duplicado
        return duplicate;
    }
}

int str_reverse (char *str) {
    int comp = str_length(str);

    if(comp == -1){ // nula
        return 0;
    }else if(str[0] == '\0'){ // vazia
        return 1;
    }else{ // preenchida
        
        // Declarando um ponteiro auxiliar de mesmo tamanho que o ponteiro de entrada
        char *aux = malloc(comp);

        // Copiando o conteúdo de forma invertida para o ponteiro auxiliar
        int i, j = 0;
        for(i = comp - 1; i >= 0; i--){
            aux[j] = str[i];
            j++;
        }

        // Copiando ponteiro auxiliar invertido para o ponteiro de entrada
        int l, m = 0;
        for(l = 0; l < comp; l++)
            str[l] = aux[l];
        
        free(aux);
        return 1;
    }
}

int str_upper (char *str) {
    int comp = str_length(str);

    if(comp == -1){ // nula
        return -1;
    }else{
        int qtde_modificados = 0;       

        // Contando quantidade de letras que precisarão ser modificadas
        int i;
        for(i = 0; i < comp; i++){
            if(str[i] >= 97 && str[i] <= 122)
                qtde_modificados++;
        }

        // Criar um vetor com 26 posições sendo as letras maiusculas
        int maisc[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
        
        // Criar um vetor com 26 posições sendo as letras minusculas
        int minus[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
        
        // Realizando a operação de subir a caixa
        int j, k;
        for(j = 0; j < comp; j++){
            for(k = 0; k < 26; k++){
                if(str[j] == minus[k]){
                    str[j] = maisc[k];
                }
            }
        }
        
        return qtde_modificados;
    }
}

int str_lower (char *str) {
    int comp = str_length(str);

    if(comp == -1){ // nula
        return -1;
    }else{
        int qtde_modificados = 0;       

        // Contando quantidade de letras que precisarão ser modificadas
        int i;
        for(i = 0; i < comp; i++){
            if(str[i] >= 65 && str[i] <= 90)
                qtde_modificados++;
        }

        // Criar um vetor com 26 posições sendo as letras maiusculas
        int maisc[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
        
        // Criar um vetor com 26 posições sendo as letras minusculas
        int minus[26] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
        
        // Realizando a operação de subir a caixa
        int j, k;
        for(j = 0; j < comp; j++){
            for(k = 0; k < 26; k++){
                if(str[j] == maisc[k]){
                    str[j] = minus[k];
                }
            }
        }
        return qtde_modificados;
    }
}

int str_find_first (const char *str, const char c) {
    int comp = str_length(str);

    if(comp == -1){ // nula
        return -1;
    }else{
        int i;
        for(i = 0; i < comp; i++){
            if(str[i] == c){
                return i;
            }
        }
        return -1;
    }
}

int str_find_last (const char *str, const char c) {
    int comp = str_length(str);

    if(comp == -1){ // nula
        return -1;
    }else{
        int i, indice = -1;
        for(i = 0; i < comp; i++){
            if(str[i] == c){
                indice = i;
            }
        }
        if (indice != -1)
            return indice;
        else
            return -1;
    }
}

int str_compare (const char *stra, const char *strb) {
    // Descobrindo o tamanho da primeira string
    int comp_a = str_length(stra);
    
    // Descobrindo o tamanho da segunda string
    int comp_b = str_length(strb);

    // Percorrendo stra para comparar com strb
    int i, qtde_iguais = 0, comp;
    if(comp_a > comp_b){
        comp = comp_a;
    }else{
        comp = comp_b;
    }
    for(i = 0; i < comp; i++){
        if(stra[i] == strb[i]){
            qtde_iguais++;
        }
        else if(stra[i] < strb[i]){
            return -1;
        }
        else if (stra[i] > strb[i]){
            return 1;
        }
    }
    if(qtde_iguais == comp) return 0; 
}

int str_copy (char *dst, const char *src) {
     // Descobrindo o tamanho da string source
    int comp_src = str_length(src) + 1; // +1 para considerar o /0
    
    // Descobrindo o tamanho da string destioantion
    int comp_dst = str_length(dst) + 1; // +1 para considerar o /0
    
    if (src == NULL || dst == NULL){ // nulas
        return -1;
    }else if(comp_dst < comp_src){ // restrição de tamanho
        return 0;
    }else{
        int i;
        for(i = 0; i <= comp_src; i++){
            dst[i] = src[i];
        }
        return 1;
    }
}


char* str_concatenate (const char *stra, const char *strb) {
    // Descobrindo o tamanho da string source
    int comp_a = str_length(stra);
    
    // Descobrindo o tamanho da string destioantion
    int comp_b = str_length(strb);

    if(stra == NULL && strb == NULL){ // nulas
        char *ponteiro = NULL;
        return ponteiro;
    }else if(stra == NULL && strb != NULL){ // apenas stra nula
        char *ponteiro = malloc(comp_b);
        str_copy(ponteiro, strb);
        return ponteiro;
    }
    else if(stra != NULL && strb == NULL){ // apenas strb nula
        char *ponteiro = malloc(comp_a);
        str_copy(ponteiro, stra);
        return ponteiro;
    }else{
        // Tamanho do ponteiro novo é a soma dos dois ponteiros de entrada + \0
        int tam = comp_b + comp_a + 1;
        char *ponteiro = malloc(tam);
        
        // Inserindo o ponteiro stra no ponteiro de saida
        int i;
        for(i = 0; i < comp_a; i++){
            ponteiro[i] = stra[i];    
        }

        // Inserindo o ponteiro stra no ponteiro de saida a partir de stra
        int j, k = 0;
        for(j = comp_a; j < tam; j++){
            ponteiro[j] = strb[k];
            k++;
        }

        return ponteiro;
    }
}
char* str_concatenate (const char *stra, const char *strb) {
    // Descobrindo o tamanho da string source
    int comp_a = str_length(stra);
    
    // Descobrindo o tamanho da string destination
    int comp_b = str_length(strb);

    if(stra == NULL && strb == NULL){ // nulas
        char *ponteiro = NULL;
        return ponteiro;
    }else if(stra == NULL && strb != NULL){ // apenas stra nula
        char *ponteiro = malloc(comp_b);
        int i;
        for(i = 0; i <= comp_b; i++){
            ponteiro[i] = strb[i];
        }
        return ponteiro;
    }
    else if(stra != NULL && strb == NULL){ // apenas strb nula
        char *ponteiro = malloc(comp_a);
        int i;
        for(i = 0; i <= comp_a; i++){
            ponteiro[i] = stra[i];
        }
        return ponteiro;
    }else{
        // Tamanho do ponteiro novo é a soma dos dois ponteiros de entrada + \0
        int tam = comp_b + comp_a + 1;
        char *ponteiro = malloc(tam);
        
        // Inserindo o ponteiro stra no ponteiro de saida
        int i;
        for(i = 0; i < comp_a; i++){
            ponteiro[i] = stra[i];    
        }

        // Inserindo o ponteiro stra no ponteiro de saida a partir de stra
        int j, k = 0;
        for(j = comp_a; j <= tam; j++){
            ponteiro[j] = strb[k];
            k++;
        }

        return ponteiro;
    }
}

int str_count_words (const char *str) {
    int comp = str_length(str);

    if(str == NULL){ // nula
        return -1;
    }else if (comp == 0){
        return 0;
    }
    else{
        int i, qtde_palavras = 1, qtde_espacos = 0;
        for(i = 0; i < comp; i++){
            if(str[i] != ' ' && str[i+1] == ' '){
                int j, esp_restante = 0;
                for(j = i+1; j < comp; j++){
                    if(str[j] == ' '){
                        esp_restante++;
                    }
                }
                if(esp_restante == (comp - i - 1)){
                    // nada pois significa que o restante da string toda até o \0 é composta por espaços
                }else{
                    qtde_palavras++;
                }
            }                                 
            else if(str[i] == ' '){
                qtde_espacos++;
            }                                       
        }
        if(qtde_espacos == comp){
            qtde_palavras = 0;
        }
        return qtde_palavras;
    }
}