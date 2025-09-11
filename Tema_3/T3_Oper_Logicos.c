#include <stdio.h>

int main() {
    int a = 5, b = -10, c = 1;
    
    // Operador AND lógico (&&)
    if (a > 0 && b > 0) {
        printf("Os dois números são positivos.\n");
    } else {
        printf("Pelo menos um dos números é negativo.\n");
    }
    
    // Operador OR lógico (||)
    if (a > 0 || b > 0) {
        printf("Pelo menos um dos números é positivo.\n");
    } else {
        printf("Os dois números são negativos.\n");
    }

    // Operador NOT lógico (!)
    if (!(a > 0)) {
        printf("A variavel a é negativa.\n");
    } else {
        printf("A variavel a é positivo.\n");
    }
    
    // Testando precedência de operadores
    if (a > 0 && b < 0 || c == 0) {
        printf("A condição é verdadeira.\n");
    } else {
        printf("A condição é falsa.\n");
    }
    return 0;
}