#include <stdio.h>
int main (){
    float nota1, nota2, nota3;
    float media;

    printf("*** Programa de Cáculo de Media ***\n");

    printf("Digite sua primeira nota:\n");
    scanf("%f", &nota1);

    printf("Digite sua segunda nota:\n");
    scanf("%f", &nota2);
    
    printf("Digite sua terceira nota:\n");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3)/3;

    printf ("A media é: %.2f\n", media);
    
    return 0;
}