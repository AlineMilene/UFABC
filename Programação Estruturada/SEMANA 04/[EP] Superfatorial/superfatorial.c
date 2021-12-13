// #include "superfatorial.h"

#include <stdio.h>

int fatorial(int n) {
    if (n == 0) return 1;
    else return n * fatorial(n-1);
}

long superfatorial(int n) {
    int soma;
    
    if (n == 0) return 1;
    else return superfatorial(n-1) * fatorial(n);
}    

int main (){
    
    int b;
    scanf("%d", &b);

    int resultado = superfatorial(b);
    printf("resultado = %d\n", resultado);
    return 0;
}