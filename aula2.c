#include <stdio.h>

int main(){
    int idade;
    float altura;
    char opcao;
    char nome[20];

printf("Digite sua idade: ");    
scanf("%d", &idade);
printf("Sua idade é: %d\n", idade);

printf("Digite a sua altura: ");
scanf("%f", &altura);
printf("A altura é: %f\n", altura);

printf("Digite seu nome: ");
scanf("%s", nome);
printf("O nome é: %s\n", nome);

printf("Digite a opção: ");
scanf(" %c", &opcao);
printf("A opção é: %c\n", opcao);


return 0;
}

