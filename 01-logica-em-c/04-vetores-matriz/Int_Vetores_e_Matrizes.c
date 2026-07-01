#include <stdio.h>
// Declaracao de um array de inteiros com 5 elementos

int numeros[5] = {10, 20, 30, 40, 50}; // o primeiro elemento tem indice 0
char letras[5] = {'A', 'B', 'C', 'D', 'E'};
char *nome[] = {"Ana", "Bruno", "Carlos", "Diana", "Eduardo"};

int main() {
    // Acessando e imprimindo os elementos do array

    printf("Acessando elementos do array:\n");
    printf("\n");

    for (int i = 0; i < 5; i++) {
        printf("O indice %d: %d\n", i, numeros[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("O indice %d: %c\n", i, letras[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("O indice %d: %s\n", i, nome[i]);
    }

    return 0;
}


