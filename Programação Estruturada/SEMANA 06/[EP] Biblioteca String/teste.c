#include <stdio.h>
#include <string.h>

int main(){
    // Testando a função de tamanho

    char *resultado = malloc(15);
    char result;

    char *stra = "joao";
    char *strb = "aline";

    strcat(stra, strb);
    printf("resultado = %s\n", strcat(stra, strb));

    return 0;
}

