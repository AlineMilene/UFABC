//#include "multiplicacao.h"

#include <stdio.h>

int multiplicacao_russa(int a, int b) {
    if (a == 0) return 0;
    
    else if((a%2) == 1){
        a -= 1;
        return multiplicacao_russa(a/2, b*2) + b;
    }
    else{
        return multiplicacao_russa(a/2, b*2);
    }
    return 0;
}

int main(){
    
    // testes
    int resultado = multiplicacao_russa(150,4);
    printf("resultado = %d\n", resultado);
    return 0;
}