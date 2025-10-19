#include <stdio.h>
//Exemplo de matrizes
//Contem linhas e colunas
//Array multidimensional
//explemplo 3x3 (3 linhas e 3 colunas)

int matriz[3][3] = {
    {1, 2, 3}, //linha 0
    {4, 5, 6}, //linha 1
    {7, 8, 9}  //linha 2
};

int main() {
    //Acessando e imprimindo os elementos da matriz
    printf("Acessando elementos da matriz:\n");
    printf("\n");

    for (int i = 0; i < 3; i++) { //linhas
        for (int j = 0; j < 3; j++) { //colunas
            printf("Elemento na linha %d, coluna %d: %d\n", i, j, matriz[i][j]);
        }
    }

    return 0;
}




