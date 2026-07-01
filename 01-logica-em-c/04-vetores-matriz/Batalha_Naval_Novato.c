#include <stdio.h>

int main () {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int coluna[10] = {1,2,3,4,5,6,7,8,9,10};
    int tabuleiro[10][10];
    // Inicializa o tabuleiro com '0' representando água
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // Exibe o tabuleiro inicial
    printf("Tabuleiro Inicial:\n");
    printf("  ");
    for (int j = 0; j < 10; j++) { // Cabeçalho das colunas
        printf(" %d", coluna[j]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) { // Linhas do tabuleiro
        printf("%c ", linha[i]);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // incluir navios na vertical no tabuleiro com valor '3' e com tres casas
    tabuleiro[0][4] = 3; // Navio na posição A4 
    tabuleiro[1][4] = 3; // Navio na posição B4
    tabuleiro[2][4] = 3; // Navio na posição C4

   // incluir navios na horizontal no tabuleiro com valor '3' e com tres casas
    tabuleiro[9][4] = 3; // Navio na posição J5
    tabuleiro[9][5] = 3; // Navio na posição J6
    tabuleiro[9][6] = 3; // Navio na posição J7 

    // Exibe o tabuleiro atualizado com navios
    printf("Tabuleiro com Navios:\n");
    printf("  ");
    for (int j = 0; j < 10; j++) { // Cabeçalho das colunas
        printf(" %d", coluna[j]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) { // Linhas do tabuleiro
        printf("%c ", linha[i]);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");   
    }
    // Incluir no tabuleiro dois navios na diagonal com valor '3' em duas diagonais diferentes
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3; // Navios na diagonal principal
    }

    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3; // Navios na diagonal secundária
    }

    printf("\nTabuleiro com Navios na Diagonal:\n");
    printf("  ");
    for (int j = 0; j < 10; j++) { // Cabeçalho das colunas
        printf(" %d", coluna[j]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) { // Linhas do tabuleiro
        printf("%c ", linha[i]);
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");   
    }   



    return 0;

}
