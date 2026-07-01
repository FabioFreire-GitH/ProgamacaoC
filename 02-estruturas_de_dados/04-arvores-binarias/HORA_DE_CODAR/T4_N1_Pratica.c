/*Etapas do desenvolvimento
-Definição da estrutura da árvore binária, com os campos necessários para armazenar os dados e os ponteiros para os nós esquerdo e direito.
-Implementação da inserção de elementos utilizando alocação dinâmica.
-Exploração dos percursos (caminhamentos) da árvore:
    -Pré-ordem
    -Em ordem
    -Pós-ordem
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct No {
    char valor[50];
    struct No* esquerda;
    struct No* direita;
};

//Cria  e inicializa uma FUNÇÃO nó tipo STRUCT de árvore binária,
//armazenando o valor recebido.
struct No* criarNo(char* valor) {
    // Aloca dinamicamente memoria oara um novo nó e guarda o endereço em 'novo'
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    if (novo==NULL){
        printf("Erro ao alocar memória!\n");
        exit(1); // Encerra o programa em caso de erro de memoria
    }
    // Copia o valor passado como parametro (string) para o campo 'valor' do nó
    strcpy(novo->valor, valor);
    // Inicializa os ponteiros dos filhos como NULL (sem filhos ainda)
    novo->esquerda = NULL;
    novo->direita = NULL;
    // Retorna o endereço do novo nó criado
    return novo;
}

//Inserir valor
struct No* inserir(struct No* raiz, char* valor) {

    // Caso a posição esteja vazia,
    // cria um novo nó e retorna ele.
    if (raiz == NULL) {
        return criarNo(valor);
    }

    // strcmp compara strings:
    //
    // < 0  -> primeira string é menor
    // > 0  -> primeira string é maior
    // == 0 -> iguais

    // Se o valor for "menor",
    // insere na subárvore esquerda
    if (strcmp(valor, raiz->valor) < 0) {

        raiz->esquerda = inserir(raiz->esquerda, valor);

    } else {

        // Caso contrário, insere na direita
        raiz->direita = inserir(raiz->direita, valor);
    }

    // Retorna a raiz atual da árvore
    return raiz;
}

//Funçao que libera toda a memoria alocada para uma arvore
//binaria de forma recursiva.
void liberar(struct No* raiz) {
    // Se o nó existe
    if (raiz != NULL) {
        // Libera primeiro a subárvore esquerda
        liberar(raiz->esquerda);
        // Depois, libera a subárvore direita 
        liberar(raiz->direita);
        // Por ultimo, libera o próprio nó atual.
        free(raiz);
    }
}

void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("%s | ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(struct No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%s | ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(struct No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s | ", raiz->valor);
    }
}

int main() {
    //Cria o nó raiz da arvore, representado o "Hall de Entrada"
    struct No* raiz = criarNo("Hall de Entrada");
    raiz = inserir(raiz, "Sala de Estar");
    raiz = inserir(raiz, "Biblioteca");
    raiz = inserir(raiz, "Quarto");
    raiz = inserir(raiz, "Cozinha");
    raiz = inserir(raiz, "Banheiro");
    
    //Exibe os elementos da arvore em Pré-Ordem (raiz, esq., dir.)
    printf("Pré-ordem: ");
    preOrdem(raiz);
    printf("\n");
 
    //Exibe os elementos da arvore Em Ordem (esq., raiz, dir.)
    printf("Em ordem: ");
    emOrdem(raiz);
    printf("\n");
 
    //Exibe os elementos da arvore em Pós-Ordem (esq., dir., raiz)
    printf("Pós-ordem: ");
    posOrdem(raiz);
    printf("\n");
 
    //Libera toda memoria alocada para a árvore
    liberar(raiz);
    //Indica que o programa terminou com sucesso
    return 0;
}

