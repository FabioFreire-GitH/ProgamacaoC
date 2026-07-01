/*Nivel Mestre: A Enigma Studios está finalizando o capítulo mais desafiador de 
Detective Quest, e escalaram você para um upgrade final: permitir que o jogador 
colecione pistas, relacione-as a suspeitos e tome uma decisão lógica sobre quem 
é o culpado.

Sua missão como desenvolvedor(a) técnico(a) é programar o sistema completo que:

    - Permite explorar uma mansão representada como uma árvore binária.
 
    - Armazena as pistas encontradas em uma árvore binária de busca. 
 
    - Associa cada pista a um suspeito usando uma tabela hash.
 
Ao final da exploração, o jogador deve indicar quem é o culpado, e o sistema 
avaliará, de maneira automática, se há pistas suficientes para sustentar a acusação.

# Requisitos funcionais

Seu programa em C deverá:
    - Criar uma árvore binária de cômodos, cada um com um nome exclusivo.
    - Ao visitar uma sala, identificar e exibir uma pista específica associada 
    à sala (se existir).
    - Armazenar cada pista coletada em uma árvore BST de forma ordenada.
    - Criar uma tabela hash com as pistas, como chaves, e seus respectivos 
    suspeitos como valores.
    - Permitir ao jogador explorar os cômodos de modo interativo, escolhendo 
    ir para a esquerda (e), direita (d) ou sair (s).
    - Ao final, listar as pistas coletadas e solicitar ao jogador a acusação 
    de um suspeito.
    - Verificar se, pelo menos, duas pistas apontam para o suspeito acusado e 
    exibir a mensagem correspondente ao desfecho.
 
Cada cômodo possui:
    - nome identificador do cômodo.
    - Uma pista estática associada a esse nome, definida por lógica no código.

# Requisitos não funcionais
    - Usabilidade: o jogo deve mostrar mensagens informativas sobre cada passo 
    da exploração e as ações finais do julgamento.
    - Legibilidade: o código deve ser bem indentado, com estruturas modulares e 
    nomes representativos.
    - Documentação: comentários explicativos devem existir nas seguintes funções:
        - criarSala() – cria dinamicamente um cômodo.
        - explorarSalas() – navega pela árvore e ativa o sistema de pistas.
        - inserirPista() / adicionarPista() – insere a pista coletada na árvore de pistas.
        - inserirNaHash() – insere associação pista/suspeito na tabela hash.
        - encontrarSuspeito() – consulta o suspeito correspondente a uma pista.
        - verificarSuspeitoFinal() – conduz à fase de julgamento final.

# Simplificações para o nível mestre
    - O mapa da mansão é fixo e é montado de forma manual no main().
    - Não há inserção ou remoção dinâmica de salas nem de suspeitos.
    - As pistas associadas a salas são definidas por regras codificadas (sem entrada 
    manual).
    - A exploração termina quando o jogador escolhe sair (s).

# Conceitos trabalhados
    - Árvore binária: representa a estrutura de navegação da mansão.
    - Árvore de busca binária (BST): armazena as pistas coletadas em ordem.
    - Tabela hash: associa pistas a suspeitos de forma eficiente.
    - Structs e ponteiros: utiliza alocação dinâmica e manipulação de dados compostos.
    - Recursividade: Exploração da árvore e contagem de pistas por suspeito.
    - Condicionais e loops: Controle da lógica de jogo e verificação de hipóteses.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
// TAMANHO DA HASH
///////////////////////////////////////////////////////////

#define TAMANHO_HASH 10

///////////////////////////////////////////////////////////
// ESTRUTURA DA HASH
///////////////////////////////////////////////////////////

struct HashNode {

    // Nome da pista
    char pista[100];

    // Nome do suspeito
    char suspeito[50];

    // Próximo nó (colisão)
    struct HashNode* proximo;
};

///////////////////////////////////////////////////////////
// TABELA HASH
///////////////////////////////////////////////////////////

struct HashNode* tabelaHash[TAMANHO_HASH];

///////////////////////////////////////////////////////////
// FUNÇÃO HASH
///////////////////////////////////////////////////////////

int funcaoHash(char* chave) {

    int soma = 0;

    for (int i = 0; chave[i] != '\0'; i++) {

        soma += chave[i];
    }

    return soma % TAMANHO_HASH;
}

///////////////////////////////////////////////////////////
// INSERE PISTA E SUSPEITO NA HASH
///////////////////////////////////////////////////////////

void inserirNaHash(char* pista, char* suspeito) {

    // Descobre posição
    int indice = funcaoHash(pista);

    // Cria novo nó
    struct HashNode* novo = (struct HashNode*)malloc(sizeof(struct HashNode));

    strcpy(novo->pista, pista);

    strcpy(novo->suspeito, suspeito);

    // Encadeamento
    novo->proximo = tabelaHash[indice];

    tabelaHash[indice] = novo;
}

///////////////////////////////////////////////////////////
// PROCURA SUSPEITO PELA PISTA
///////////////////////////////////////////////////////////

char* encontrarSuspeito(char* pista) {

    int indice = funcaoHash(pista);

    struct HashNode* atual = tabelaHash[indice];

    while (atual != NULL) {

        if (strcmp(atual->pista,
                   pista) == 0) {

            return atual->suspeito;
        }

        atual = atual->proximo;
    }

    return NULL;
}

///////////////////////////////////////////////////////////
// CONTA PISTAS DO SUSPEITO
///////////////////////////////////////////////////////////

int contarPistasSuspeito(struct PistaNode* raiz, char* suspeito) {

    if (raiz == NULL) {

        return 0;
    }

    int total = 0;

    // Descobre suspeito da pista
    char* encontrado = encontrarSuspeito(raiz->pista);

    // Se combina
    if (encontrado != NULL && strcmp(encontrado, suspeito) == 0) {

        total++;
    }

    // Soma esquerda + direita
    return total + contarPistasSuspeito(raiz->esquerda, suspeito)+ contarPistasSuspeito(
            raiz->direita, suspeito);
}

///////////////////////////////////////////////////////////
// JULGAMENTO FINAL
///////////////////////////////////////////////////////////

void verificarSuspeitoFinal(struct PistaNode* pistas) {

    char suspeito[50];

    printf("\n================================\n");

    printf("Suspeitos:\n");
    printf("- Mordomo\n");
    printf("- Jardineiro\n");
    printf("- Cozinheira\n");

    printf("\nQuem e o culpado? ");

    scanf(" %[^\n]", suspeito);

    // Conta pistas
    int quantidade = contarPistasSuspeito(pistas, suspeito);

    printf("\n");

    if (quantidade >= 2) {

        printf("%s foi considerado culpado!\n", suspeito);

        printf("Existem %d pistas contra ele.\n",quantidade);
    }

    else {

        printf("Pistas insuficientes!\n");

        printf("%s foi inocentado.\n", suspeito);
    }
}

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
    // ASSOCIA PISTAS A SUSPEITOS
    //////////////////////////////////////////////////////

    inserirNaHash("Faca suja de tinta","Cozinheira");

    inserirNaHash("Livro rasgado","Mordomo");

    inserirNaHash("Pegadas molhadas","Jardineiro");

    inserirNaHash("Controle remoto quebrado","Mordomo");

    inserirNaHash("Bilhete secreto","Mordomo");

    inserirNaHash("Chave dourada","Cozinheira");

    //////////////////////////////////////////////////////
    // INICIA EXPLORAÇÃO
    //////////////////////////////////////////////////////

    explorarSalasComPistas( raiz, &pistas);

    //////////////////////////////////////////////////////
    // JULGAMENTO FINAL
    //////////////////////////////////////////////////////

    verificarSuspeitoFinal(pistas);

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