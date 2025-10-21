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
    return 0;

    

}
