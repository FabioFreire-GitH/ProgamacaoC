#include <stdio.h>
//criar void para cada movimento de peça
void movertorre(int casasrestantes, int direcao, int distancia) { // loop recursivo da torre
    if (casasrestantes <= 0) {
        printf("***Movimento da torre completo.***\n");
        return;
    }
    if (casasrestantes == distancia) {
        printf("\n");
        printf("Iniciando movimento de %d casa(s) para torre \n", distancia);
        printf("\n");
    }
    if (direcao == 1) { // cima
        printf("Movendo torre para cima\n");
    } else if (direcao == 2) { // baixo
        printf("Movendo torre para baixo\n");
    } else if (direcao == 3) { // esquerda
        printf("Movendo torre para esquerda\n");
    } else if (direcao == 4) { // direita
        printf("Movendo torre para direita\n");
    }
    movertorre(casasrestantes - 1, direcao, distancia);
}
void moverbispo(int distancia, int direcao) { // loop aninhado do bispo
    for (int i = 1; i <= distancia; i++) {
        if (direcao == 1) { // Diagonal Superior Esquerda
            printf("Movendo bispo %d casa(s) para Diagonal Superior Esquerda\n", i);
        } else if (direcao == 2) { // Diagonal Superior Direita
            printf("Movendo bispo %d casa(s) para Diagonal Superior Direita\n", i);
        } else if (direcao == 3) { // Diagonal Inferior Esquerda
            printf("Movendo bispo %d casa(s) para Diagonal Inferior Esquerda\n", i);
        } else if (direcao == 4) { // Diagonal Inferior Direita
            printf("Movendo bispo %d casa(s) para Diagonal Inferior Direita\n", i);
        }      
    }
    
    
}

void moverrainha(int distancia, int direcao) { 
    for (int i = 1; i <= distancia; i++) {
        if (direcao == 1) { // horizontal
            printf("Movendo rainha %d casa(s) para horizontal\n", i);
        } else if (direcao == 2) { // vertical
            printf("Movendo rainha %d casa(s) para vertical\n", i);
        } else if (direcao == 3) { // diagonal
            printf("Movendo rainha %d casa(s) para diagonal\n", i);
        }      
    }
}


int main() {
    int distancia, direcao;
    char peca;
    int movimentoCompleto = 1; // flag para controlar o loop do cavalo

    printf("Escolha a peca (T para Torre, B para Bispo, R para Rainha, C para Cavalo): ");
    scanf(" %c", &peca);
 
    switch (peca){
        case 'T': //torre
        case 't':
        printf ("Escolha a direção (1 para Cima, 2 para Baixo, 3 para Esquerda ou 4 para Direita): ");
        scanf ("%d", &direcao);
            if (direcao < 1 || direcao > 4) {
            printf("Direcao invalida. Escolha 1, 2, 3 ou 4.\n");
            }
            printf("Escolha a distancia (1 a 8): ");
            scanf("%d", &distancia);
            if (distancia < 1 || distancia > 8) {
            printf("Distancia invalida. Escolha um valor entre 1 e 8.\n");
            }
            movertorre(distancia, direcao, distancia);
          
        break;
        case 'B': //bispo
        case 'b':
        printf ("Escolha a direção (1 para Diagonal Superior Esquerda, 2 para Diagonal Superior Direita, 3 para Diagonal Inferior Esquerda ou 4 para Diagonal Inferior Direita): ");
        scanf ("%d", &direcao);
            if (direcao < 1 || direcao > 4) {
            printf("Direcao invalida. Escolha 1, 2, 3 ou 4.\n");
            }
            printf("Escolha a distancia (1 a 8): ");
            scanf("%d", &distancia);
            if (distancia < 1 || distancia > 8) {
            printf("Distancia invalida. Escolha um valor entre 1 e 8.\n");
            }
            moverbispo(distancia, direcao);
            
        break;
        case 'R': //rainha
        case 'r':
        printf ("Escolha a direção (1 para horizontal, 2 para vertical ou 3 para diagonal): ");
        scanf ("%d", &direcao);
            if (direcao < 1 || direcao > 3) {
            printf("Direcao invalida. Escolha 1, 2 ou 3.\n");
            }
            printf("Escolha a distancia (1 a 8): ");
            scanf("%d", &distancia);
            if (distancia < 1 || distancia > 8) {
            printf("Distancia invalida. Escolha um valor entre 1 e 8.\n");
            }
            moverrainha(distancia, direcao);
        break;
            case 'C': //cavalo com loop aninhado
            case 'c':
            printf ("Escolha a direção (1 para 'L' para Cima e Direita , 2 para 'L' para Cima e Esquerda, 3 para 'L' para Baixo e Direita, 4 para 'L' para Baixo e Esquerda): ");
            scanf ("%d", &direcao);
                if (direcao < 1 || direcao > 4) {
                printf("Direcao invalida. Escolha 1, 2, 3 ou 4.\n");
                }
                while (movimentoCompleto--) { // loop para realizar o movimento em 'L'
                    if (direcao == 1){
                        for (int i = 0; i < 2; i++) { // mover 2 casas para cima
                            printf("Movendo cavalo %d casa para cima\n", i + 1);
                        }
                        printf ("Movendo cavalo 1 casa para direita\n");
                    } else if (direcao == 2){
                            for (int i = 0; i < 2; i++) { // mover 2 casas para cima
                                printf("Movendo cavalo %d casa para cima\n", i + 1);
                            }
                            printf ("Movendo cavalo 1 casa para esquerda\n");
                        } else if (direcao == 3){
                                for (int i = 0; i < 2; i++) { // mover 2 casas para baixo
                                    printf("Movendo cavalo %d casa para baixo\n", i + 1);
                                }
                                printf ("Movendo cavalo 1 casa para direita\n");
                            } else if (direcao == 4){
                                    for (int i = 0; i < 2; i++) { // mover 2 casas para baixo
                                        printf("Movendo cavalo %d casa para baixo\n", i + 1);
                                    }
                                    printf ("Movendo cavalo 1 casa para esquerda\n");
                                }
                } 
                break;
                            
        default:
            printf("Peca invalida. Escolha T, B ou R.\n");
            break;  

    }

return 0;

}