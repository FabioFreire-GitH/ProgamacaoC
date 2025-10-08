#include <stdio.h>

int main() {
    int opcao;
    float nota1, nota2, media;

    printf("Menu de Gerenciamento de Estudantes\n");
    printf("1. Calcular Média de Notas\n");
    printf("2. Determinar Status");
    printf("3. Sair\n");
    printf("Escolha uma opção (1-3): ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Calcular Média de Notas\n");
            printf("Digite a primeira nota: ");
            scanf("%f", &nota1);
            printf("Digite a segunda nota: ");
            scanf("%f", &nota2);
            //Testar a condiçao se a nota é >=0 e <=10
            if ((nota1 >= 0 && nota1 <= 10) && (nota2 >= 0 && nota2 <= 10)) {
                media = (nota1 + nota2) / 2;
                printf("Média: %.2f\n", media);
            } else {
                printf("Notas inválidas! As notas devem estar entre 0 e 10.\n");
            }
            break;
        case 2:
            printf("Determinar Status\n");
            break;
        case 3:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;

    return 0;

    }