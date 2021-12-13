// Leia uma sequência de n inteiros e mostre quantos são potências de 2.

// Observação: não utilize math.h.

// Entrada (o primeiro número lido é o comprimento do vetor, que no caso é 5):
// 5
// 2
// 8
// 9
// 10
// 16

// Saída:
// 3


#include <stdio.h>

int main(){
    // Ler n para a sequência
    int vetor;
    scanf("%d", &vetor);

    // Sequência de n números
    int i;
    int qtde_potencias = 0;
    for(i = 1; i <= vetor; i++){
        int numero;
        scanf("%d", &numero);
        int quociente = 0;

        if (numero > 0){
            while(numero %2 == 0){
                numero = numero/2;
            }
            if (numero == 1)
                qtde_potencias++;
        }
        
    }
    printf("%d\n", qtde_potencias);
}
