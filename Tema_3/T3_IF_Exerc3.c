#include <stdio.h>

int main() {
    int numero;

    printf("Insira um numero inteiro: ");
    scanf("%d", &numero);

// testar se o numero e par (% verifica o resto da divisao)
    if (numero % 2 == 0) { 
        printf("O número %d é par.\n", numero);
    } else {
        printf("O número %d é impar.\n", numero);
    }
    return 0;
}
