#include <stdio.h>

int main() {
    int opcao;
    float nota1, nota2, media;

    printf("Menu de Gerenciamento de Estudantes\n");
    printf("1. Calcular Média de Notas\n");
    printf("2. Determinar Status\n");
    printf("3. Sair\n");
    printf("Escolha uma opção (1-3): ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a primeira nota: ");
            scanf("%f", &nota1);
            printf("Digite a segunda nota: ");
            scanf("%f", &nota2);

            if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10) {
                printf("Notas inválidas! As notas devem estar entre 0 e 10.\n");
            }
            media = (nota1 + nota2) / 2;
            printf("A média das notas é: %.2f\n", media);
            break;
        case 2:
            printf("Digite a média do estudante: ");
            scanf("%f", &media);
            if (media >= 7.0) {
                printf("Status: Aprovado\n");
            } else if (media >= 5.0) {
                printf("Status: Recuperação\n");
            } else {
                printf("Status: Reprovado\n");
            }
            break;
        case 3:
            printf("Saindo do programa. Até mais!\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    return 0;
}