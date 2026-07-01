#include <stdio.h>

int main() {

    // Idade esteja entre 18 e 65 anos
    // Renda menor que 3000.00
    // Numero de dependentes maior que 2

    int idade, num_dependentes;
    float renda;

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite sua renda mensal: ");
    scanf("%f", &renda);
    printf("Digite o numero de dependentes: ");
    scanf("%d", &num_dependentes);

    if (idade >= 18 && idade <= 65){
        if (renda < 3000.00){
            if (num_dependentes > 2){
                printf("Você atende aos requisitos!\n");
            } else {
                printf("Numero de dependentes menor que o permitido!\n");
            }
        } else {
            printf("Renda maior que o permitido!\n");
        }
    } else {
        printf("Idade fora do permitido!\n");
    }
    return 0;
}
