//Ponteiros para funções e estruturas

#include <stdio.h>

void saudacao() { 
    printf("Olá, mundo!\n");
}

int main(){
    void(*ptr)() = saudacao; // Ponteiro para função
    ptr(); // Chama a função através do ponteiro

    return 0;
    
}