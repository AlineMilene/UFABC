#include <stdio.h>

int main(){
    int num_lido, j, k, l, i, resultado = 0;  
    char op_lido;

    // criando vetores para armazenar as listas
    int valores[6]; 
    char operadores[6];

    i = 0;
    do{
        // lendo numero e operador
        scanf(" %d %c ", &num_lido, &op_lido);
        
        // salvando numero
        if(num_lido >= 0){
            valores[i] = num_lido;
            operadores[i] = op_lido;
            i++;
        }
    }while(op_lido != '=');
    
    i++;
    
    l = 0;
    for(j = 0; j < i; j++){
        if(operadores[j] == '*'){
            valores[j] = valores[j] * valores[j+1];
            for(k = j + 1; k < i-l; k++){
                valores[k] = valores[k+1];
                operadores[k-1] = operadores[k];
            }
            l++;
        }

        if(operadores[j] == '/'){
            valores[j] = valores[j] / valores[j+1];
            for(k = j + 1; k < i-l; k++){
                valores[k] = valores[k+1];
                operadores[k-1] = operadores[k];
            }
            l++;
        }
    }

    for(j = 0; j < i-l; j++){
        if(operadores[j] == '+'){
            valores[j] = valores[j] + valores[j+1];
            for(k = j + 1; k < i - l; k++){
                valores[k] = valores[k+1];
                operadores[k-1] = operadores[k];
            }
            l++;
        }

        if(operadores[j] == '-'){
            valores[j] = valores[j] - valores[j+1];
            for(k = j + 1; k < i - l; k++){
                valores[k] = valores[k+1];
                operadores[k-1] = operadores[k];
            }
            l++;
        }
    }
    for(i = 0; i < 6; i++){
        printf("op: %c\n", operadores[i]);
    }
    for(i = 0; i < 6; i++){
        printf("num: %d\n", valores[i]);
    }

    int a = 0;
    while(operadores[a] != '='){
        if(operadores[a] == '*'){
            resultado += valores[a] * valores[a+1];
        }
        else if(operadores[a] == '/'){
            resultado += valores[a] / valores[a+1];
        }else{
            resultado += valores[0] + valores[1];
        } 
        a++;
    }
    
    printf("%d\n", resultado);
    return 0; 
}