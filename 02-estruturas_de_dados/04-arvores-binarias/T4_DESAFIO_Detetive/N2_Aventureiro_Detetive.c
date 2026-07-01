/*Nivel Aventureiro: A Enigma Studios, especialista no desenvolvimento de jogos educativos de lógica e 
programação, está expandindo o título Detective Quest com um novo recurso: coleta de 
pistas.

Você, como desenvolvedor(a) técnico(a), será responsável por implementar o sistema 
de pistas coletadas durante a exploração da mansão. Para isso, ampliará o sistema 
anterior de árvore binária adicionando:

- Pistas associadas a cada cômodo da mansão.
 
- Uma árvore BST para armazenar e organizar as pistas conforme forem encontradas.
 
O objetivo do programa é permitir que o detetive explore a mansão, colete pistas 
espalhadas pelos cômodos e visualize ao final todos os indícios organizados de acordo 
com o alfabeto.

# Requisitos funcionais

Seu programa em C deverá:
    - Criar uma árvore binária que represente o mapa da mansão, com pistas já associadas 
    aos cômodos.
    - Criar uma árvore BST na qual serão armazenadas as pistas coletadas.
    - Permitir a exploração da mansão a partir do "Hall de Entrada", escolhendo o próximo 
    caminho entre esquerda (e), direita (d) ou sair (s).
    - Adicionar automaticamente à árvore de pistas cada pista encontrada durante a jornada.
    - Exibir todas as pistas coletadas em ordem alfabética ao final da exploração.

Cada cômodo possui:
    - nome: string com o nome da sala (ex: “Sala de Estar”, “Cozinha”).
    - pista: string opcional com o conteúdo da pista encontrada naquele cômodo.

#Requisitos não funcionais
    - Usabilidade: o programa deve apresentar mensagens claras sobre localização 
    atual, pistas e opções disponíveis.
    - Legibilidade: o código-fonte deve ser organizado, indentado e com nomes de 
    variáveis compreensíveis.
    - Documentação: comentário de cada parte importante do código, incluindo:
        - criarSala() – cria dinamicamente um cômodo com ou sem pista.
        - inserirPista() – insere uma nova pista na árvore de pistas.
        - explorarSalasComPistas() – controla a navegação entre salas e coleta de pistas.
        - exibirPistas() – imprime a árvore de pistas em ordem alfabética.

#Simplificações para o nível aventureiro
    - O mapa da mansão é fixo e pré-definido no main().Ou seja, não há inserção ou 
    remoção dinâmica de salas.
    - Não há detecção automática do fim da jornada: o usuário deve optar por sair (s) 
    a qualquer momento.
    - As árvores não precisam ser balanceadas ou otimizadas.

Conceitos trabalhados
    - Árvore binária: é a estrutura hierárquica para modelar os cômodos da mansão.
    - Árvore binária de busca (BST): armazena as pistas de forma ordenada.
    - Structs: usa tipos personalizados (Sala, PistaNode) para modelar os dados.
    - Alocação dinâmica: usa malloc() para criação de elementos das árvores.
    - Recursividade: exploração das árvores e exibição ordenada das pistas.
    - Modularização: separação clara de responsabilidades por função.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////
// ESTRUTURA DA SALA (ÁRVORE DA MANSÃO)
///////////////////////////////////////////////////////////

struct Sala {

    // Nome do cômodo
    char nome[50];

    // Pista encontrada no cômodo
    char pista[100];

    // Filhos da árvore binária
    struct Sala* esquerda;
    struct Sala* direita;
};

///////////////////////////////////////////////////////////
// ESTRUTURA DA BST DE PISTAS
///////////////////////////////////////////////////////////

struct PistaNode {

    // Texto da pista
    char pista[100];

    // Filhos da BST
    struct PistaNode* esquerda;
    struct PistaNode* direita;
};

///////////////////////////////////////////////////////////
// CRIA UMA SALA
///////////////////////////////////////////////////////////

struct Sala* criarSala(char* nome, char* pista) {

    // Aloca memória
    struct Sala* nova = (struct Sala*) malloc(sizeof(struct Sala));

    if (nova == NULL) {

        printf("Erro de memoria!\n");

        exit(1);
    }

    // Copia nome
    strcpy(nova->nome, nome);

    // Copia pista
    strcpy(nova->pista, pista);

    // Inicializa filhos
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova;
}

///////////////////////////////////////////////////////////
// CRIA NÓ DA BST DE PISTAS
///////////////////////////////////////////////////////////

struct PistaNode* criarPista(char* pista) {

    struct PistaNode* novo = (struct PistaNode*) malloc(sizeof(struct PistaNode));

    if (novo == NULL) {

        printf("Erro de memoria!\n");

        exit(1);
    }

    strcpy(novo->pista, pista);

    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

///////////////////////////////////////////////////////////
// INSERÇÃO NA BST DE PISTAS
///////////////////////////////////////////////////////////

struct PistaNode* inserirPista(struct PistaNode* raiz, char* pista) {

    // Caso base:
    // encontrou posição vazia
    if (raiz == NULL) {

        return criarPista(pista);
    }

    // Menor -> esquerda
    if (strcmp(pista, raiz->pista) < 0) {

        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    }

    // Maior -> direita
    else if (strcmp(pista, raiz->pista) > 0) {

        raiz->direita = inserirPista(raiz->direita, pista);
    }

    return raiz;
}

///////////////////////////////////////////////////////////
// EXIBE PISTAS EM ORDEM ALFABÉTICA
///////////////////////////////////////////////////////////

void exibirPistas(struct PistaNode* raiz) {

    if (raiz != NULL) {

        // esquerda
        exibirPistas(raiz->esquerda);

        // raiz
        printf("- %s\n", raiz->pista);

        // direita
        exibirPistas(raiz->direita);
    }
}

///////////////////////////////////////////////////////////
// EXPLORAÇÃO DA MANSÃO
///////////////////////////////////////////////////////////

void explorarSalasComPistas(struct Sala* raiz, struct PistaNode** arvorePistas) {

    // Representa posição atual
    struct Sala* atual = raiz;

    char opcao;

    while (atual != NULL) {

        printf("\n================================\n");

        printf("Voce esta em: %s\n", atual->nome);

        ///////////////////////////////////////////
        // COLETA DE PISTA
        ///////////////////////////////////////////

        // Se existe pista na sala
        if (strlen(atual->pista) > 0) {

            printf("Pista encontrada: %s\n", atual->pista);

            // Insere na BST
            *arvorePistas = inserirPista(*arvorePistas, atual->pista);
        }

        printf("================================\n");

        ///////////////////////////////////////////
        // MENU
        ///////////////////////////////////////////

        printf("\nEscolha:\n");

        if (atual->esquerda != NULL) {

            printf("(e) Ir para: %s\n", atual->esquerda->nome);
        }

        if (atual->direita != NULL) {

            printf("(d) Ir para: %s\n", atual->direita->nome);
        }

        printf("(s) Sair\n");

        printf("\nOpcao: ");

        scanf(" %c", &opcao);

        ///////////////////////////////////////////
        // SAIR
        ///////////////////////////////////////////

        if (opcao == 's' ||
            opcao == 'S') {

            break;
        }

        ///////////////////////////////////////////
        // ESQUERDA
        ///////////////////////////////////////////

        else if (opcao == 'e' || opcao == 'E') {

            if (atual->esquerda != NULL) {

                atual = atual->esquerda;

            } else {

                printf("Nao existe sala a esquerda!\n");
            }
        }

        ///////////////////////////////////////////
        // DIREITA
        ///////////////////////////////////////////

        else if (opcao == 'd' || opcao == 'D') {

            if (atual->direita != NULL) {

                atual = atual->direita;

            } else {

                printf("Nao existe sala a direita!\n");
            }
        }

        else {

            printf("Opcao invalida!\n");
        }
    }
}

///////////////////////////////////////////////////////////
// LIBERA ÁRVORE DA MANSÃO
///////////////////////////////////////////////////////////

void liberarSalas(struct Sala* raiz) {

    if (raiz != NULL) {

        liberarSalas(raiz->esquerda);

        liberarSalas(raiz->direita);

        free(raiz);
    }
}

///////////////////////////////////////////////////////////
// LIBERA BST DE PISTAS
///////////////////////////////////////////////////////////

void liberarPistas(struct PistaNode* raiz) {

    if (raiz != NULL) {

        liberarPistas(raiz->esquerda);

        liberarPistas(raiz->direita);

        free(raiz);
    }
}

///////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////

int main() {

    //////////////////////////////////////////////////////
    // BST DAS PISTAS
    //////////////////////////////////////////////////////

    struct PistaNode* pistas = NULL;

    //////////////////////////////////////////////////////
    // CRIAÇÃO DA MANSÃO
    //////////////////////////////////////////////////////

    struct Sala* raiz = criarSala("Hall de Entrada", "");

    raiz->esquerda = criarSala("Cozinha", "Faca suja de tinta");

    raiz->direita = criarSala( "Biblioteca", "Livro rasgado");

    raiz->esquerda->esquerda = criarSala("Lavanderia", "Pegadas molhadas");

    raiz->esquerda->direita = criarSala("Sala de Estar", "Controle remoto quebrado");

    raiz->direita->esquerda = criarSala( "Escritorio", "Bilhete secreto");

    raiz->direita->direita = criarSala( "Quarto", "Chave dourada");

    //////////////////////////////////////////////////////
    // INICIA EXPLORAÇÃO
    //////////////////////////////////////////////////////

    explorarSalasComPistas( raiz, &pistas);

    //////////////////////////////////////////////////////
    // EXIBE PISTAS COLETADAS
    //////////////////////////////////////////////////////

    printf("\n================================\n");

    printf("PISTAS COLETADAS:\n\n");

    exibirPistas(pistas);

    printf("================================\n");

    //////////////////////////////////////////////////////
    // LIBERA MEMÓRIA
    //////////////////////////////////////////////////////

    liberarSalas(raiz);

    liberarPistas(pistas);

    return 0;
}