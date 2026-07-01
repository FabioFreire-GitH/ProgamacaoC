#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numerojogador, numerocomputador, resultado;
    char tipocomparacao;

    // Gerar numero aleatório entre 1 e 100
    srand(time(0));
    numerocomputador = rand() % 100 + 1;

    //inicio do jogo
    printf("bem-vindo ao jogo Maior, Menor ou Igual!\n");
    printf("Você deve escolher um número entre 1 e 100 e o tipo de comparação\n");
    printf("M. Maior\n");
    printf("N. Menor\n");
    printf("I. Igual\n");

    printf("Escolha a comparação: ");
    scanf(" %c", &tipocomparacao);
    printf("Escolha um número entre 1 e 100: ");
    scanf("%d", &numerojogador);

    //Exibir o número do computador
    printf("Número do computador: %d\n", numerocomputador);

    switch (tipocomparacao)
    {
    case 'M':
    case 'm':
        printf("Você escolheu Maior\n");
        resultado = (numerojogador > numerocomputador) ? 1 : 0;
        break;
    case 'N':
    case 'n':
        printf("Você escolheu Menor\n");
        resultado = (numerojogador < numerocomputador) ? 1 : 0;
        break;
    case 'I':
    case 'i':
        printf("Você escolheu Igual\n");
        resultado = (numerojogador == numerocomputador) ? 1 : 0;
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }

    if (resultado == 1){
        printf("Parabéns! Você ganhou!\n");
    } else {
        printf("Que pena! Você perdeu!\n");
    }

    return 0;

}