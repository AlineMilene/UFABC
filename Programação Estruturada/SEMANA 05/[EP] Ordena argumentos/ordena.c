#include <stdio.h>
#include <stdlib.h>

void ordena(int *a, int *b, int *c) {
    int aux = 0;

    if(*a > *b) {
        aux = *a;
        *a = *b;
        *b = aux;
    }
    if(*a > *c){
        aux = *a;
        *a = *c;
        *c = aux;
    }
    if(*b > *c){
        aux = *b;
        *b = *c;
        *c = aux;
    }
}

int main(){

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));

    *a = 3;
    *b = 2;
    *c = 1;

    printf("ANTES -------------\n");
    printf("a: %d   b: %d   c: %d\n", *a, *b, *c);
    ordena(a, b, c);
    printf("DEPOIS -------------\n");
    printf("a: %d   b: %d   c: %d\n", *a, *b, *c);
    return 0;
}
