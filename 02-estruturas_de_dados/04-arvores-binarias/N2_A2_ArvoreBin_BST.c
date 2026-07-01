/*Árvores binárias de busca (BST)

- BST (Árvore Binaria de Busca) é uma estrutura hierarquica para
organizar dados, acelerando buscas, inserções e exclusões/

- Cada nó: valores menores à esquerda, maiores à direita.   

- Permite buscar, inserir e remover elementos de forma eficiente,
descartando metade da arvore a cad comparação.

- Ideal para aplicações que exigem dados ordenados e consultas 
rapidas. 

- Comece fazendo (em C):
    - Definição de Estrutura do nó
    - Criação dos nós
    - Inserção (Recursiva)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura do nó
/*Primeiro, é necessário definir a estrutura do nó. Lembrando: 
cada nó possui dois ponteiros para seus filhos e um campo para 
o valor armazenado. A diferença aqui é que usaremos strings.*/
struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
};

//Criando um nó
/*Sempre que quisermos adicionar um novo valor à árvore, precisaremos 
criar um nó com esse valor. Essa função aloca memória e inicializa os 
ponteiros como NULL, já que novos nós começam sem filhos.*/
struct No* criarNo(const char* valor) { 
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    if (novo == NULL) {
        printf("Erro de memoria!\n");
        exit(1);
    }
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

//Inserindo elementos na árvore
/*O passo agora é inserir os nós seguindo a regra da BST: valores 
menores vão à esquerda, maiores à direita:*/
struct No* inserir(struct No* raiz, const char* valor) {
    if (raiz == NULL)// Caso base: encontrou posição vazia 
        return criarNo(valor);
    // Valor menor -> esquerda
    if (strcmp(valor, raiz->valor) < 0)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    // Valor maior -> direita
    else if (strcmp(valor, raiz->valor) > 0)
            raiz->direita = inserir(raiz->direita, valor);
    
        return raiz;
}

//Percorrendo a árvore em ordem (in-order)
/*A principal vantagem da BST é poder ser percorrida em ordem crescente
com um algoritmo simples. Esse percurso visita primeiro a esquerda, 
epois o nó atual, e, por fim, a direita.*/
void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

//Buscando um valor na árvore (BST)
/*Procurar em uma BST é muito mais eficiente do que em uma lista, 
pelo simples fato de que porque podemos eliminar metade dos elementos 
a cada comparação. */
int buscar(struct No* raiz, const char* chave) {
    if (raiz == NULL) 
        return 0; //Caso base: Arvore vazia ou chegou ao fina sem encontrar a chave.
    
        if (strcmp(chave, raiz->valor) == 0)
            return 1;// Se o valor do nó atual é igual à chave, encontrou!
        else if (strcmp(chave, raiz->valor) < 0)
            return buscar(raiz->esquerda, chave);
        else// se a chave é maior que o valor do nó, busca na subarvore da direita 
            return buscar(raiz->direita, chave);
}

// Encontra o menor valor da árvore
struct No* encontrarMinimo(struct No* raiz) {

    while (raiz->esquerda != NULL) {

        raiz = raiz->esquerda;
    }

    return raiz;
}

//Remoção de um nó
struct No* remover(struct No* raiz, const char* valor) {
    if (raiz == NULL) 
        return NULL;

    if (strcmp(valor, raiz->valor) < 0) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (strcmp(valor, raiz->valor) > 0) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Caso 1: sem filhos (remoçao ná folha)
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }

        // Caso 2: um único filho
        else if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 3: dois filhos
        else {
            struct No* sucessor = encontrarMinimo(raiz->direita);
            // Copia valor do sucessor
            strcpy(raiz->valor, sucessor->valor);
            // Remove sucessor
            raiz->direita = remover(raiz->direita,sucessor->valor);
        }
    }
   
    return raiz;
}

// Libera memória da árvore
void liberar(struct No* raiz) {

    if (raiz != NULL) {

        liberar(raiz->esquerda);

        liberar(raiz->direita);

        free(raiz);
    }
}

int main() {
    struct No* raiz = NULL;
 
    raiz = inserir(raiz, "Pegadas de Lama");
    raiz = inserir(raiz, "Chave perdida");
    raiz = inserir(raiz, "Livro com página faltando");
    raiz = inserir(raiz, "Lençol manchado");
    raiz = inserir(raiz, "Gaveta perdida");
 
    printf("\nElementos em ordem: \n");
    emOrdem(raiz);
 
    printf("\nBusca por ‘Lençol manchado’: %s", buscar(raiz, "Lençol manchado") ? "Encontrado" : "Não encontrado");
    printf("\nBusca por ‘Óculos’: %s\n", buscar(raiz, "Óculos") ? "Encontrado" : "Não encontrado");
 
    return 0;
}