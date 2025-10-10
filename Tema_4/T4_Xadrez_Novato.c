#include <stdio.h>

//programa para simular o movimento da torre, bispo e rainha num jogo de xadrez
//utilizando for, while ou do..while
//Escolha a direção das pecas: cima, baixo, esquerda, direita e diagonal
//utilizando tabuleiro 8x8

int main() {
    int direcao1, direcao2 , distancia;
    char peca;
    printf("Escolha a peca (T para torre, B para bispo, R para rainha): ");
    scanf(" %c", &peca);
    printf("Escolha a direcao (1 para horizontal, 2 para vertical, 3 para diagonal): ");
    scanf("%d", &direcao1);
    if (direcao1 < 1 || direcao1 > 3) {
        printf("Direcao invalida. Escolha 1, 2 ou 3.\n");
       }
    printf("Escolha a direcao (1 para cima, 2 para baixo, 3 para esquerda, 4 para direita): ");
    scanf("%d", &direcao2);
    if (direcao2 < 1 || direcao2 > 4) {
        printf("Direcao invalida. Escolha 1, 2, 3 ou 4.\n");
    }
    printf("Escolha a distancia (1 a 8): ");
    scanf("%d", &distancia);
    if (distancia < 1 || distancia > 8) {
        printf("Distancia invalida. Escolha um valor entre 1 e 8.\n");
    }
    switch (peca) {
        case 'T': //torre
        case 't':
            if (direcao1 == 3) { //diagonal
                printf("A torre não pode se mover na direcao diagonal.\n");
                break;
            }
            for (int i = 1; i <= distancia; i++) {
               if (direcao1 == 1) { // horizontal
                   if (direcao2 == 3) {
                       printf("Movendo torre %d casa(s) para a esquerda\n", i);
                   } else if (direcao2 == 4) {
                       printf("Movendo torre %d casa(s) para a direita\n", i);
                   }
               } else if (direcao1 == 2) { // vertical
                   if (direcao2 == 1) {
                       printf("Movendo torre %d casa(s) para cima\n", i);
                   } else if (direcao2 == 2) {
                       printf("Movendo torre %d casa(s) para baixo\n", i);
                   }
               }
           }
           break;





        }


return 0;

}