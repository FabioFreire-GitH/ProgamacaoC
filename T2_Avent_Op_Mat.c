#include <stdio.h>
 
int main() {
    /*
    Soma (+)
    Subtração (-)
    Multiplicação (*)
    Divisão (/)    
    */

    int numero1, numero2;
    int soma, subtracao, multiplicacao, divisao;

    printf ("Entre com o numero 1: \n");
    scanf ("%d", &numero1);
    printf ("Entre com o numero 2: \n");
    scanf ("%d", &numero2);

    soma = numero1 + numero2;
    //operação soma

    subtracao = numero1 - numero2;
    //operação subtração

    multiplicacao = numero1 * numero2;
    //operação multiplicação

    divisao = numero1 / numero2;
    //operação divisão

    printf ("A Soma é: %d\n", soma);
    printf ("A Subtração é: %d\n", subtracao);
    printf ("A Mutiplicação é: %d\n", multiplicacao);
    printf ("A Divisão é: %d\n", divisao);
    
}
