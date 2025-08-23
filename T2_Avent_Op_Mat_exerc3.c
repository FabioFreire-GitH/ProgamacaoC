#include <stdio.h>

int main(){
    /*
    Incremento (++)
    Pré-Incremento ++a
    Pós-Incremento a++
    Decremento (--)
    Pré-Decremento --a
    Pós-Decremento a--
    */

    int numero1 = 1, resultado;

    printf("Antes Incremento: %d\n", numero1);
    numero1++; 
    // numero1 = numero1 + 1;
    // numero1 += 1;
    printf("Após Incremento: %d\n", numero1);

    numero1--; 
    // numero1 = numero1 - 1;
    // numero1 -= 1;
    printf("Após Decremento: %d\n", numero1);

    resultado = numero1++;
    printf("Após Pós-Incremento - Numero 1: %d - Resultado: %d\n", numero1, resultado);
    //Pos incremeto: 
    //resultado = numero1
    //numero1++

    resultado = ++numero1;
    printf("Após Pré-Incremento - Numero 1: %d - Resultado: %d\n", numero1, resultado);
    //Pre incremeto: 
    //numero1++
    //resultado = numero1
    
    resultado = numero1--;
    printf("Após Pós-Decremento - Numero 1: %d - Resultado: %d\n", numero1, resultado);

    resultado = --numero1;
    printf("Após Pré-Decremento - Numero 1: %d - Resultado: %d\n", numero1, resultado);

}
