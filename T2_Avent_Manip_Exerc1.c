#include <stdio.h>
 
int main() {
    int a = 10;
    float b = 3.5;
    float resultado = a + b; //'a' é convertido implicitamente  para float
    int x = 10;
    int y = 3;
    float quociente = (float) x / y; //'a'é explicitamente convertido  pdo para float

    printf("Resultado: %.2f\n", resultado);
    printf("Quociente: %.2f\n", quociente);

    return 0;

}