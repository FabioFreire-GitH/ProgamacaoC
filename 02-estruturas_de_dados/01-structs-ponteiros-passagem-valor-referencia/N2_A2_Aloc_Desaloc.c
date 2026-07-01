#include <stdio.h>
#include <stdlib.h>

int main() {

    // Ponteiro para inteiro
    int *a;

    // Variável inteira comum
    int b;

    // ===============================
    // ALOCAÇÃO DINÂMICA DE MEMÓRIA
    // ===============================

    // malloc reserva espaço na memória
    // para armazenar 1 inteiro

    a = (int*) malloc(sizeof(int));

    // Verifica se a memória foi alocada corretamente
    if(a == NULL) {

        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // ===============================
    // ATRIBUINDO VALORES
    // ===============================

    // Guardando valor na memória apontada por "a"
    *a = 50;

    // Variável comum
    b = 20;

    // ===============================
    // EXIBIÇÃO
    // ===============================

    printf("Valor armazenado em *a: %d\n", *a);

    printf("Valor armazenado em b: %d\n", b);

    // Mostra o endereço de memória
    printf("Endereco de a: %p\n", a);

    // ===============================
    // DESALOCAÇÃO DE MEMÓRIA
    // ===============================

    // free libera a memória reservada
    free(a);

    // Boa prática:
    // deixar o ponteiro apontando para NULL
    a = NULL;

    printf("Memoria liberada com sucesso.\n");

    return 0;
}