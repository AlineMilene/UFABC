#include <stdio.h>

int main(){
    int num1, num2, num3, i = 0, cont = 0, resultado = 0;  
    char op1, op2, op3;


    do{
        // lendo numero e operador
        if(cont == 0){
            scanf("%d", &num1);
        }
        else if(cont == 1){
            scanf("%c", &op1);

        }

    if(op1 == '*'){
            resultado = num1 * num2;
        if(op2 = '*'){
            resultado += resultado * num3;
        }
        else if(op2 = '/'){
            resultado += resultado / num3;
        }
        else if(op2 = '+'){
            resultado += resultado + num3;
        }
        else if (op2 == '-'){
            resultado = resultado - num3;
        }
    }
    else if(op1 == '/'){
        resultado = num1 / num2;
        if(op2 = '*'){
            resultado = resultado * num3;
        }
        else if(op2 = '/'){
            resultado = resultado / num3;
        }
        else if(op2 = '+'){
            resultado = resultado + num3;
        }
        else if (op2 == '-'){
            resultado = resultado - num3;
        }
    }
    else if(op1 == '+'){
        if(op2 = '*'){
            resultado = num1 + (num2 * num3);
        }
        else if(op2 = '/'){
            resultado = num1 + (num2 / num3);
        }
        else if(op2 = '+'){
            resultado = num1 + num2 + num3;
        }
        else if (op2 == '-'){
            resultado = num1 + num2 - num3;
        }
    }
    else if(op1 == '-'){
        if(op2 = '*'){
            resultado = num1 - (num2 * num3);
        }
        else if(op2 = '/'){
            resultado = num1 - (num2 / num3);
        }
        else if(op2 = '+'){
            resultado = num1 - num2 + num3;
        }
        else if (op2 == '-'){
            resultado = num1 - num2 - num3;
        }
    }
    }while(op3 != '=');
    
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("op1: %c\n", op1);
    printf("op2: %c\n", op2);
    printf("op3: %c\n", op3);

    // Fazendo as contas
    

    printf("resultado = %d\n", resultado);

}
