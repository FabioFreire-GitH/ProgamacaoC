//testar temperatura se esta calor
#include <stdio.h>

int main (){

    float temperatura;

    printf("Insira a temperatura em graus Celsius: ");
    scanf("%f", &temperatura);

    if (temperatura > 30.0){
        printf("Está calor\n\n");
    }
        return 0;
}