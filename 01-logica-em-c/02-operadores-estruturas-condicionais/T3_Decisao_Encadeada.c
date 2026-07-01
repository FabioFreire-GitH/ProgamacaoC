#include <stdio.h>

int main (){

    int idade;
    
        printf("Digite sua idade: ");
        scanf("%d", &idade);

        // Crianca < 12
        // Adolescente 12-18
        // Adulto 19-60
        // Idoso > 60

        if (idade < 12){
            printf("Criança\n\n");
        } else if (idade >= 12 && idade <= 18){
            printf("Adolescente\n\n");
        } else if (idade >= 19 && idade <= 60){
            printf("Adulto\n\n");
        } else {
            printf("Idoso\n\n");
        }
        return 0;

        }