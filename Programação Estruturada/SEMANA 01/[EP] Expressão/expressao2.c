#include <stdio.h>

int main(){
    int num_lido, i = 0, parcial = 0, resultado = 0, cont = 0;  
    char op_lido;

    // criando vetores para armazenar as listas
    int valores[100]; 
    char operadores[100];

    do{
        // lendo numero e operador
        scanf("%d %c", &num_lido, &op_lido);
        
        // salvando numero
        if(num_lido >= 0){
            valores[i] = num_lido;
            operadores[i] = op_lido;
            cont++;
            i++;
        }
    }while(op_lido != '=');

    for(i = 0; i <= cont; i++){
        if(operadores[i] == '*' || operadores[i] == '/'){
            if(operadores[i] == '*'){
                resultado = resultado + (valores[i] * valores[i+1]);
            }
            else if (resultado !=0){
                resultado = resultado / valores[i];
            }
            else{
                resultado = resultado + (valores[i] / valores[i+1]);
            }
        }
    }

    for(i = 0; i <= cont; i++){
        if(operadores[i] == '+' || operadores[i] == '-'){
            if(operadores[i] == '+'){
                if(resultado != 0){
                    if(operadores[i-1] == '\0' || (operadores[i-1] == '+' || operadores[i-1] == '-')){
                        resultado = valores[i] + resultado;
                    } 
                    else if(operadores[i+1] == '='){
                        resultado = valores[i+1] + resultado;
                    }
                }
            }
            else{
                if(resultado != 0){
                    if(operadores[i-1] == '\0' || operadores[i+1] == '='){
                        resultado = valores[i] - resultado;
                    }
                    else{
                        resultado = valores[i+1] - resultado;
                    }
                }
            }
        }
    }

    printf("%d\n", resultado);
}

// for(i = 0; i <= cont; i++){
    //     printf("vetor [%d]: %d\n", i, valores[i]);
    // }
    // for(i = 0; i <= cont; i++){
    //     printf("operador [%d]: %c\n", i, operadores[i]);
    // }

    // for(i = 0; i <= cont; i = i+2){
    //     if(operadores[i] == '*'){
    //         resultado = resultado + (valores[i] * valores[i+1]);
    //         printf("resultado do * %d\n", resultado);
    //     }
        
    //     else if(operadores[i] == '/'){
    //         resultado = resultado + (valores[i] / valores[i+1]);
    //     }

    //     else if(operadores[i] == '+' || operadores[i] == '-'){
    //         if(operadores[i] == '+'){
    //             if(operadores[i+1] == '='){
    //                     resultado = resultado + valores[i];
    //             }
    //             else if(operadores[i+1] == '+' || operadores[i+1] == '-'){
    //                 resultado = resultado + (valores[i] + valores[i+1]);
    //             }
    //             else{
    //                 if(operadores[i+1] == '*'){
    //                     resultado = resultado + (valores[i+1] * valores[i+2]);
    //                     resultado = resultado + valores[i];
    //                 }
    //                 if(operadores[i+1] == '/'){
    //                     resultado = resultado + (valores[i+1] / valores[i+2]);
    //                     resultado = resultado + valores[i];
    //                 }
    //             }
    //         printf("resultado do + %d\n", resultado);
    //         }
    //         else{
    //             if(operadores[i+1] == '='){
    //                     resultado = resultado - valores[i];
    //             }
    //             else if(operadores[i+1] == '+' || operadores[i+1] == '-'){
    //                 resultado = resultado + (valores[i] - valores[i+1]);
    //             }
    //             else{
    //                 if(operadores[i+1] == '*'){
    //                     resultado = resultado + (valores[i+1] * valores[i+2]);
    //                     resultado = valores[i] - resultado;
    //                 }
    //                 if(operadores[i+1] == '/'){
    //                     resultado = resultado + (valores[i+1] / valores[i+2]);
    //                     resultado = valores[i] - resultado;
    //                 }
    //             }
    //         printf("resultado do - %d\n", resultado);
    //         }
    //     }
    // }
    
// }   
