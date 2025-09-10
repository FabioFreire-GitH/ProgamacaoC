#include <stdio.h>

int main (){
    float temperatura, umidade;
    unsigned int estoque, estoque_minimo = 100;

    printf("Insira a temperatura: \n");
    scanf("%f", &temperatura);
    printf("Insira a umidade: \n");
    scanf("%f", &umidade);
    printf("Insira o estoque: \n");
    scanf("%u", &estoque);

    if (temperatura > 30.0){
        printf("Temperatura está alta \n");
    }else{
        printf("Temperatura dentro dos parâmetros \n");
    }

    if (umidade > 50.0){
        printf("Umidade elevada. \n");
    }else{
        printf("Umidade dentro dos parâmetros. \n");
    }
    if (estoque < estoque_minimo){
        printf("Estoque baixo. \n");
    }else{
        printf("Estoque normal. \n");
    }
    return 0;
}
