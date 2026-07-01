/*Você está criando o protótipo de um sistema para armazenar e consultar 
os jogadores de um campeonato on-line. Os jogadores são organizados em um 
ranking baseado em pontuação (ordem decrescente). 

O objetivo é desenvolver um sistema que gerencie pontuações de jogadores 
em um ranking, permitindo: 

Inserção e remoção de jogadores. 
 
Visualização do ranking.
 
Busca por jogador (nome). 
 
Comparação entre vetores e listas encadeadas. 
 
Teste prático entre busca sequencial e binária (iterativa e recursiva).
 
O sistema deve aceitar:

Cadastro e remoção de jogadores.
 
Visualização do ranking.
 
Busca por nome (com diferentes algoritmos).
 
Análise comparativa do desempenho das estruturas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ================= ESTRUTURA =================
typedef struct {
    char nome[50];
    int pontos;
} Jogador;

// ================= LISTA ENCADEADA =================
typedef struct No {
    Jogador jogador;
    struct No* proximo;
} No;

// ================= FUNÇÕES VETOR =================

// Inserir jogador no vetor
void inserirJogador(Jogador ranking[], int *total, char nome[], int pontos) {

    strcpy(ranking[*total].nome, nome);
    ranking[*total].pontos = pontos;

    (*total)++;

    // Ordenar em ordem decrescente
    for(int i = 0; i < *total - 1; i++) {

        for(int j = 0; j < *total - 1 - i; j++) {

            if(ranking[j].pontos < ranking[j + 1].pontos) {

                Jogador temp = ranking[j];
                ranking[j] = ranking[j + 1];
                ranking[j + 1] = temp;
            }
        }
    }
}

// Remover jogador
void removerJogador(Jogador ranking[], int *total, char nome[]) {

    int encontrado = -1;

    for(int i = 0; i < *total; i++) {

        if(strcmp(ranking[i].nome, nome) == 0) {
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1) {
        printf("Jogador nao encontrado!\n");
        return;
    }

    for(int i = encontrado; i < *total - 1; i++) {
        ranking[i] = ranking[i + 1];
    }

    (*total)--;

    printf("Jogador removido com sucesso!\n");
}

// Visualizar ranking
void mostrarRanking(Jogador ranking[], int total) {

    printf("\n===== RANKING =====\n");

    for(int i = 0; i < total; i++) {

        printf("%dº %s - %d pontos\n",
               i + 1,
               ranking[i].nome,
               ranking[i].pontos);
    }
}

// ================= BUSCA SEQUENCIAL =================
int buscaSequencial(Jogador ranking[], int total, char nome[]) {

    for(int i = 0; i < total; i++) {

        if(strcmp(ranking[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}

// ================= BUSCA BINÁRIA ITERATIVA =================
// IMPORTANTE:
// A busca binária funciona corretamente
// somente se o vetor estiver ordenado por nome.
int buscaBinariaIterativa(Jogador ranking[], int total, char nome[]) {

    int inicio = 0;
    int fim = total - 1;

    while(inicio <= fim) {

        int meio = (inicio + fim) / 2;

        int comparacao = strcmp(ranking[meio].nome, nome);

        if(comparacao == 0) {
            return meio;
        }

        if(comparacao < 0) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    return -1;
}

// ================= BUSCA BINÁRIA RECURSIVA =================
int buscaBinariaRecursiva(Jogador ranking[],
                          int inicio,
                          int fim,
                          char nome[]) {

    if(inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    int comparacao = strcmp(ranking[meio].nome, nome);

    if(comparacao == 0) {
        return meio;
    }

    if(comparacao < 0) {
        return buscaBinariaRecursiva(
            ranking,
            meio + 1,
            fim,
            nome
        );
    }

    return buscaBinariaRecursiva(
        ranking,
        inicio,
        meio - 1,
        nome
    );
}

// ================= LISTA ENCADEADA =================

// Inserir no início
void inserirLista(No **inicio, char nome[], int pontos) {

    No *novo = (No*) malloc(sizeof(No));

    strcpy(novo->jogador.nome, nome);
    novo->jogador.pontos = pontos;

    novo->proximo = *inicio;
    *inicio = novo;
}

// Mostrar lista
void mostrarLista(No *inicio) {

    printf("\n===== LISTA ENCADEADA =====\n");

    while(inicio != NULL) {

        printf("%s - %d pontos\n",
               inicio->jogador.nome,
               inicio->jogador.pontos);

        inicio = inicio->proximo;
    }
}

// ================= MAIN =================
int main() {

    Jogador ranking[MAX];
    int total = 0;

    // Inserções
    inserirJogador(ranking, &total, "Carlos", 1200);
    inserirJogador(ranking, &total, "Ana", 1800);
    inserirJogador(ranking, &total, "Bruno", 1500);
    inserirJogador(ranking, &total, "Fernanda", 2000);

    mostrarRanking(ranking, total);

    // Busca sequencial
    int pos = buscaSequencial(ranking, total, "Bruno");

    if(pos != -1) {
        printf("\nBusca Sequencial: Bruno encontrado!\n");
    }

    // Remoção
    removerJogador(ranking, &total, "Carlos");

    mostrarRanking(ranking, total);

    // ================= LISTA ENCADEADA =================
    No *lista = NULL;

    inserirLista(&lista, "Lucas", 900);
    inserirLista(&lista, "Marina", 1300);
    inserirLista(&lista, "Joao", 700);

    mostrarLista(lista);

    return 0;
}