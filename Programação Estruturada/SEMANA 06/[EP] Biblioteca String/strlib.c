//inclua as implementações das funções descritas em strlib.h
#include <stdio.h>
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
    printf("comprimento = %d\n", comp);

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

        // Printando o vetor duplicado
        int j;
        for (j = 0; j < comp; j++){
            printf("%c",duplicate[j]);
        }

        // Retornando o ponteiro duplicado
        return duplicate;
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

int str_reverse (char *str) {
    int comp = str_length(str);
    printf("comprimento = %d\n", comp);

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

        // Printando ponteiro auxiliar:
        printf("ponteiro auxiliar\n");
        int k;
        for(k = 0; k < comp; k++){
            printf("%c", aux[k]);
        }
        printf("\n");

        // Copiando ponteiro auxiliar invertido para o ponteiro de entrada
        int l, m = 0;
        for(l = 0; l < comp; l++)
            str[l] = aux[l];
        
        // Printando ponteiro de entrada:
        printf("ponteiro de entrada\n");
        for(j = 0; j < comp; j++){
            printf("%c", str[j]);
        }
        printf("\n");

        free(aux);
        return 1;
    }
    
}

int str_upper (char *str) {
    int comp = str_length(str);
    printf("comprimento = %d\n", comp);

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

        // Printando a string
        int l;
        for(l = 0; l < comp; l++){
            printf("%c", str[l]);
        }

        return qtde_modificados;
    }
}

int str_lower (char *str) {
    int comp = str_length(str);
    printf("comprimento = %d\n", comp);

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

        // Printando a string
        int l;
        for(l = 0; l < comp; l++){
            printf("%c", str[l]);
        }

        return qtde_modificados;
    }
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


/**
 * @brief string contatenate (contatena strings)
 * @details contatena stra e strb em uma nova string, alocada pela fun-
 * ção. o ponteiro desta nova string é retornado pela função.
 * 
 * @param stra primeira string
 * @param strb segunda string
 * 
 * @return a concatenação das strings stra e strb. caso as duas sejam 
 * não nulas, retorna a concatenação. caso uma das strings seja nula, 
 * uma nova string deve ser alocada e uma cópia da string não nula é
 * retornada. caso stra e strb sejam nulas, um ponteiro nulo é retorna-
 * do pela função.
 */
char* str_concatenate (const char *stra, const char *strb) {
    // Descobrindo o tamanho da string source
    int comp_a = str_length(stra);
    printf("compa = %d\n", comp_a);
    
    // Descobrindo o tamanho da string destioantion
    int comp_b = str_length(strb);
    printf("compb = %d\n", comp_b);

    if(stra == NULL && strb == NULL){ // nulas
        char *ponteiro = NULL;
        printf("retornou ponteiro nulo\n");
        return ponteiro;
    }else if(stra == NULL && strb != NULL){ // apenas stra nula
        char *ponteiro = malloc(comp_b);
        printf("retornou ponteiro b\n");
        
        int i;
        for(i = 0; i <= comp_b; i++){
            ponteiro[i] = strb[i];
        }

        // Printando a saida
        int l;
        for(l = 0; l <= comp_b; l++){
            printf("%c", ponteiro[l]);
        }
        printf("\n");
        return ponteiro;
    }
    else if(stra != NULL && strb == NULL){ // apenas strb nula
        char *ponteiro = malloc(comp_a);
        printf("retornou ponteiro a\n");
        int i;
        for(i = 0; i <= comp_a; i++){
            ponteiro[i] = stra[i];
        }

        // Printando a saida
        int l;
        for(l = 0; l <= comp_a; l++){
            printf("%c", ponteiro[l]);
        }
        printf("\n");

        return ponteiro;
    }else{
        // Tamanho do ponteiro novo é a soma dos dois ponteiros de entrada + \0
        int tam = comp_b + comp_a + 1;
        printf("comp tam = %d\n", tam);
        char *ponteiro = malloc(tam);
        
        // Inserindo o ponteiro stra no ponteiro de saida
        int i;
        for(i = 0; i < comp_a; i++){
            ponteiro[i] = stra[i];    
        }

        // Inserindo o ponteiro stra no ponteiro de saida a partir de stra
        int j, k = 0;
        for(j = comp_a; j < tam-1; j++){
            ponteiro[j] = strb[k];
            k++;
        }

        
        // Printando a saida
        int l;
        for(l = 0; l < tam; l++){
            printf("%c", ponteiro[l]);
        }
        printf("\n");
        return ponteiro;
    }
}

int str_find_first (const char *str, const char c) {
    int comp = str_length(str);
    printf("comprimento = %d\n", comp);

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
    printf("comprimento = %d\n", comp);

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

int str_count_words (const char *str) {
    int comp = str_length(str);
    printf("comprimento = %d\n", comp);

    if(str == NULL){ // nula
        return -1;
    }else if (comp == 0){
        return 0;
    }
    else{
        int i, qtde_palavras = 1, qtde_espacos = 0;
        for(i = 0; i < comp; i++){
            if(str[i] != ' ' && str[i+1] == ' '){
                printf("valor de i: %d\n", i);
                printf("comprimento: %d\n", comp);
                int j, esp_restante = 0;
                for(j = i+1; j < comp; j++){
                    if(str[j] == ' '){
                        esp_restante++;
                    }
                }
                printf("\n");
                printf("quantidade de espaco restante: %d\n", esp_restante);
                if(esp_restante == (comp - i - 1)){
                    printf("entrou aqui no if\n");
                    // nada pois significa que o restante da string toda até o \0 é composta por espaços
                }else{
                    qtde_palavras++;
                }
            }                                 
            else if(str[i] == ' '){
                qtde_espacos++;
            }                                       
        }
        printf("qtde espacos = %d\n", qtde_espacos);
        if(qtde_espacos == comp){
            printf("entrou aqui\n");
            qtde_palavras = 0;
        }
        return qtde_palavras;
    }
}


int main(){
    // Testando a função de tamanho
    // char frase[100];
    // fgets(frase, 100, stdin);

    // Teste para a função length
    // int resultado = str_length(frase);
    // printf("resultado = %d\n", resultado);

    // Teste para a função duplicate
    // char *nulo = NULL;
    // int resultado1 = str_duplicate(nulo);
    // int resultado2 = str_duplicate(frase);
    // printf("resultado1 = %d\n", resultado1);
    // printf("resultado2 = %d\n", resultado2);

    // Teste para a função compare
    // char *stra = "abc";
    // char *strb = "cba";
    // int resultado = str_compare(stra, strb);
    // printf("resultado = %d\n", resultado);
    //return 0;

    // Teste para a função de reverse
    // char *stra = "abcde";
    // str_reverse(stra);

    // Teste para a função upper
    // char *stra = "AliNe";
    // int resultado = str_upper(stra);
    // printf("resultado = %d\n", resultado);

    // Teste para a funcao str_find_first
    // char *stra = "aline";
    // char c = 'i';
    // int resultado = str_find_first(stra, c);
    // printf("resultado = %d\n", resultado);

    // Teste para a funcao str_find_first
    // char *stra = "banana";
    // char c = 'a';
    // int resultado = str_find_last(stra, c);
    // printf("resultado = %d\n", resultado);

    // Teste para count_words
    char texto[500] = "  frase de teste  ";    
    printf("%d\n", str_count_words(texto));

    // char *stra = NULL;
    // int resultado = str_count_words(frase);
    // int resultado1 = str_count_words(stra);
    // printf("resultado = %d\n", resultado);
    // printf("resultado1 = %d\n", resultado1);

    // Teste para concatenate
    // char *stra = "joao";
    // char *strb = "ALINE";
    // int resultado = str_concatenate(stra, strb);
    // int resultado1 = str_count_words(stra);
    // printf("resultado = %d\n", resultado);
    // printf("resultado1 = %d\n", resultado1);
}