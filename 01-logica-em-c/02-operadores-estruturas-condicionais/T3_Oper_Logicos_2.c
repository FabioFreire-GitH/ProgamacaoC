#include <stdio.h>

int main() {

    int idade;
    float altura;

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);

    if (idade >= 18 && idade <= 35 && altura > 1.70) {
        printf("Voce atende aos requisitos.\n");
    } else {
        printf("Voce não atende aos requisitos.\n\n");
    }

return 0;

}