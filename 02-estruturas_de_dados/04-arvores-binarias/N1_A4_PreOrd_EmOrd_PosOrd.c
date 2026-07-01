//Pré-ordem, em ordem e pós-ordem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    // Aramzena nome ou valor do nó (até 49 caracteres + '\0')
    char valor [50];

    // Ponteiro para filho à esquerda
    struct No *esquerda;

    // Ponteiro para filho à direita
    struct No *direita;

};

void preOrdem(struct No* raiz) { // NÓ - ESQUERDA - DIREITA
    if (raiz != NULL) {
        printf("%s ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}
 
void emOrdem(struct No* raiz) { //ESQUERDO - NÓ - DIREITA
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}
 
void posOrdem(struct No* raiz) { // ESQUERDA - DIREITA - NÓ
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->valor);
    }
}

/*EXEMPLOS PRATICOS:
    - Pré-Ordem: Copiar ou serializar a árvore para armazenamento.
    - Em ordem: Imprimir elementos ordenados de uma BST.
    - Pós-Ordem: remover todos os nós (liberar memoria), calcular valor
    de expressões. 

*/