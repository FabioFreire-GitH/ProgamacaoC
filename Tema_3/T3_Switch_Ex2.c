#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //jogo da adivinhação
    int opcao;
    int numeroSecreto, palpite;

    printf("Menu Principal\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao (1-3): ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            srand(time(0)); // Inicializa o gerador de numeros aleatorios
            numeroSecreto = rand () % 10; // Gera um numero aleatorio entre 0 e 9
            printf ("Digite um numero (0-9): ");
            scanf ("%d", &palpite);
            if (palpite == numeroSecreto) {
                printf ("Parabens! Voce acertou o numero secreto!\n");
            } else {
                printf ("Que pena! Voce errou. O numero secreto era %d.\n\n", numeroSecreto);
            }
            break;
        case 2:
            printf("Explicacao das regras do jogo:\n");
            break;
        case 3:
            printf("Saindo do jogo. Ate mais!\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}