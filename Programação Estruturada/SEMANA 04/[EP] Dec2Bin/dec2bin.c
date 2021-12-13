// #include "dec2bin.h"

#include <stdio.h>

int dec2bin(int n_decimal) {
    if(n_decimal == 0) return 0;
    else return dec2bin(n_decimal/2)*10 + n_decimal%2;
}

int main(){

    printf("resultado = %d\n", dec2bin(14));
    return 0;
}