/*Estrutura de uma árvore binária na prática*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//Estrutura do nó em C

struct No {
    // Aramzena nome ou valor do nó (até 49 caracteres + '\0')
    char valor [50];

    // Ponteiro para filho à esquerda
    struct No *esquerda;

    // Ponteiro para filho à direita
    struct No *direita;

};

/*Por que usar ponteiros para nós em C?
    - Você nunca sabe, durante a execução, quantos nós terá 
    ou como estarão ligados.
        - Tudo depende dos dados e da lógica do programa.
        
    - Ponteiros permitem criar e ligar nós em tempo de execução.
        - Você cria nós conforme precisa, e os ponteiros guardam 
        os "endereços" desses nós na memória, formando as ligações 
        da árvore.
 */

// Calculo da alutura (funcao recursiva)
/* Função que calcula a altura de uma árvore binaria a partir
de um nó raiz.*/

int altura(struct No* raiz) {
    /*SE não existe nó:
    altura = 0
    SENÃO:
    descubra altura da esquerda
    descubra altura da direita
    pegue a maior
    some 1*/
    /*O segredo da recursão aqui:
    A função
    - Desce até o final
    - Depois volta calculando
    Ela primeiro vai até as folhas e só depois começa a retornar 
    os valores.*/
    if (raiz == NULL) //Se a arvore está vazia (ou nó folha), altura é 0
        return 0;
    
    int alt_esq = altura(raiz->esquerda);
    int alt_dir = altura(raiz->direita);
    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}


// Função que calcula a profundidade de um nó dentro da árvore.
//
// Parâmetros:
// raiz  -> nó atual que está sendo analisado
// alvo  -> nó que queremos encontrar
// nivel -> profundidade atual durante a busca
//
// Retorno:
// - Retorna a profundidade do nó alvo se ele for encontrado
// - Retorna -1 caso o nó não exista na árvore

int profundidade(struct No* raiz, struct No* alvo, int nivel) {

    // Caso base:
    // Se chegou em NULL, significa que o caminho terminou
    // e o nó alvo não foi encontrado aqui
    if (raiz == NULL) 
        return -1;

    // Se o nó atual é exatamente o nó que procuramos,
    // retornamos o nível atual (profundidade encontrada)
    if (raiz == alvo) 
        return nivel;

    // Procura o nó alvo na subárvore esquerda.
    // O "nivel + 1" indica que estamos descendo um nível na árvore.
    int esq = profundidade(raiz->esquerda, alvo, nivel + 1);

    // Se o retorno for diferente de -1,
    // significa que encontrou o nó na esquerda.
    // Então devolvemos imediatamente a profundidade encontrada.
    if (esq != -1) 
        return esq;

    // Se não encontrou na esquerda,
    // procura então na subárvore direita.
    return profundidade(raiz->direita, alvo, nivel + 1);
}
