// #include "contafreq.h"
#include <stdio.h>

int contafreq(int num, int digito) {
   int resto;
   
   if (num == 0) return 0;
   else{
        resto = num % 10;
        num = num/10;
        if(resto == digito){
            return 1 + contafreq(num, digito);
        }
        contafreq(num, digito);
   }
}

int main(){
    int freq = contafreq(12343, 3);
    printf("frequência = %d\n", freq);

    return 0;
}