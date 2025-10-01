#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int escolhaJogador, escolhaComputador;
    srand(time(0));

    printf("**** JOGO JOKENPO ****\n");
    printf("Escolha uma opção:\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("Escolha: ");
    scanf("%d", &escolhaJogador);

    escolhaComputador = rand() %3 +1; // Gera um número aleatório entre 1 e 3

    switch (escolhaJogador){
        case 1:
            printf("Jogador escolheu Pedra\n");
        break;
        case 2:
            printf("Jogador escolheu Papel\n");
        break;
        case 3:
            printf("Jogador escolheu Tesoura\n");
        break;
        default:
            printf("Escolha invalida!\n");
        break;
    }
    switch (escolhaComputador){
        case 1:
            printf("Computador escolheu Pedra\n");
        break;
        case 2:
            printf("Computador escolheu Papel\n");
        break;
        case 3:
            printf("Computador escolheu Tesoura\n");
        break;
    }
        if (escolhaJogador == escolhaComputador){
            printf("Empate!\n");
        } else if ((escolhaJogador == 1 && escolhaComputador == 3) ||
                   (escolhaJogador == 2 && escolhaComputador == 1) ||
                   (escolhaJogador == 3 && escolhaComputador == 2)){
            printf("Jogador vence!\n");
        } else {
            printf("Você Perdeu!\n");
    }

    return 0;

    }





