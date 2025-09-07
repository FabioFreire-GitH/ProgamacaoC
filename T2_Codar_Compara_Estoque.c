#include <stdio.h>

int main() {
    char produtoA[30] = "Produto A";
    char produtoB[30] = "Produto B";
    
    unsigned int estoqueA = 1000;
    unsigned int estoqueB = 2000;

    float valorA = 10.50;
    float valorB = 20.40;

    unsigned int estoqueminimoA = 500;
    unsigned int estoqueminimoB = 2500;

    double valortotalA;
    double valortotalB;

    int resultadoA, resultadoB;

    // Exibir  as informações dos produtos
    printf("Produto %s tem estoque %u e o valor unitario é R$ %.2f\n", produtoA, estoqueA, valorA);
    printf("Produto %s tem estoque %u e o valor unitario é R$ %.2f\n\n", produtoB, estoqueB, valorB);
    
    //Comparações com a valor minimo de estoque
    resultadoA = (estoqueA > estoqueminimoA);
    resultadoB = (estoqueB > estoqueminimoB);

    printf("O produto %s tem estoque minimo %d\n", produtoA, resultadoA);
    printf("O produto %s tem estoque minimo %d\n\n", produtoB, resultadoB);

    //Comparações entre valores totais dos produtos
    printf  ("O Valor total de A (R$ %.2f) é maior que o Valor total de B (R$ %.2f)? %d\n",
            estoqueA * valorA, estoqueB * valorB, (estoqueA * valorA) > (estoqueB * valorB));




    /* Solicita ao usuário que insira os valores de estoque
    printf("Digite o estoque atual: ");
    scanf("%d", &estoque_atual);
    printf("Digite o estoque minimo: ");
    scanf("%d", &estoque_minimo);
    printf("Digite o estoque maximo: ");
    scanf("%d", &estoque_maximo);

    // Calcula o estoque médio
    estoque_medio = (estoque_minimo + estoque_maximo) / 2;

    // Compara o estoque atual com o estoque médio e exibe a mensagem apropriada
    if (estoque_atual >= estoque_medio) {
        printf("Estoque suficiente\n");
    } else {
        printf("Estoque insuficiente\n");
    }
*/
    return 0;
}
