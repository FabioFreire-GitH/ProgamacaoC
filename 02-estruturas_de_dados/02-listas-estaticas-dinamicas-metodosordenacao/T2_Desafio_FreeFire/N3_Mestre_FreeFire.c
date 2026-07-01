/*Sua tarefa é implementar diferentes algoritmos de ordenação,
analisar seu desempenho, aplicar uma busca binária otimizada e 
permitir ao jogador decidir qual estratégia usar com base nas 
condições de jogo. Esta fase integra e consolida os conhecimentos 
de ordenação, busca eficiente e modularização.

Você deve criar um sistema de priorização e montagem de componentes 
da torre de fuga, em que o jogador pode escolher diferentes critérios 
de ordenação (por nome, tipo ou prioridade) e, após ordenar, realizar 
busca binária por um item-chave que destrava a ativação da torre. 
Além disso, o sistema deve mostrar o número de comparações para que o 
jogador entenda os impactos da escolha do algoritmo.

# Requisitos funcionais #

Confira as principais funcionalidades do sistema a serem implementados:

1. Criação de structs:
-Componente: com os campos char nome[30], char tipo[20], int prioridade.

2. Entrada dos dados:
-Cadastro de até 20 componentes necessários para a montagem da torre.
-Os dados devem incluir o nome do componente (ex: “chip central”), 
seu tipo (ex: “controle”, “suporte”, “propulsão”) e a prioridade 
(de 1 a 10).

3. Opções de ordenação:
-Bubble sort: ordenar por nome (string).
-Insertion sort: ordenar por tipo (string).
-Selection sort: ordenar por prioridade (int).

4. Busca binária:
-Aplicável apenas após a ordenação por nome.
-Deve localizar o componente-chave para iniciar a montagem.

5. Medição de desempenho:
-Contar número de comparações realizadas em cada ordenação.
-Mostrar o tempo de execução de cada algoritmo (usar clock()).

6. Montagem final:
-Exibir todos os componentes ordenados conforme a estratégia escolhida.
-Confirmar visualmente a presença do componente-chave.

# Requisitos não funcionais #

Considere também os seguintes critérios relevantes durante o 
desenvolvimento:

1. Interface amigável: um menu interativo deve ter essa característica.
 
2. Desempenho educacional: o programa deve fornecer feedback numérico 
sobre comparações e tempo.
 
3. Clareza no código: todas as funções e blocos principais devem estar 
comentados.
 
4. Modularização adequada: cada algoritmo deve estar em uma função separada, facilitando comparação e manutenção.

Instruções detalhadas

A seguir, veja os elementos básicos que devem compor a estrutura do 
programa:

1. Bibliotecas necessárias: stdio.h, stdlib.h, string.h, time.h.
2. Funções obrigatórias:
-selectionSortPrioridade(Componente[], int)
-insertionSortTipo(Componente[], int)
-bubbleSortNome(Componente[], int)
-buscaBinariaPorNome(Componente[], int, char[])
-mostrarComponentes(Componente[], int)
-medirTempo(void (*algoritmo)(Componente[], int), Componente vetor[], int tamanho)
3. Entrada e saída: 
-Use fgets para capturar strings com segurança.
-Exibir o vetor de componentes formatado com nome, tipo e prioridade após cada operação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 20
#define MAX_STR_NOME 30
#define MAX_STR_TIPO 20

// ================= ESTRUTURA =================
typedef struct {
    char nome[MAX_STR_NOME];
    char tipo[MAX_STR_TIPO];
    int quantidade;
    int prioridade;
} Componente;

// ================= VARIÁVEL GLOBAL =================
int comparacoes = 0;

// ================= PROTÓTIPOS =================
void adicionarComponente(Componente torre[], int *contador);
void removerComponente(Componente torre[], int *contador);
void mostrarComponentes(Componente torre[], int contador);

void bubbleSortNome(Componente vetor[], int tamanho);
void insertionSortTipo(Componente vetor[], int tamanho);
void selectionSortPrioridade(Componente vetor[], int tamanho);

int buscaBinariaPorNome(Componente vetor[], int tamanho, char nomeBusca[]);

void medirTempo(void (*algoritmo)(Componente[], int), Componente vetor[], int tamanho);

// ================= MAIN =================
int main() {

    Componente torre[MAX_ITEMS];
    int contador = 0;
    int opcao;

    char nomeBusca[MAX_STR_NOME];

    do {

        printf("\n=============================\n");
        printf("TORRE DE FUGA\n");
        printf("=============================\n");

        printf("1. Adicionar componente\n");
        printf("2. Remover componente\n");
        printf("3. Mostrar componentes\n");
        printf("4. Bubble Sort por nome\n");
        printf("5. Insertion Sort por tipo\n");
        printf("6. Selection Sort prioridade\n");
        printf("7. Busca Binaria por nome (precisa estar ordenado)\n");
        printf("0. Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {

            case 1:
                adicionarComponente(torre, &contador);
                break;

            case 2:
                removerComponente(torre, &contador);
                break;

            case 3:
                mostrarComponentes(torre, contador);
                break;

            case 4:

                comparacoes = 0;

                medirTempo(bubbleSortNome,torre,contador);

                mostrarComponentes(torre, contador);

                printf("\nComparacoes: %d\n",comparacoes);

                break;

            case 5:

                comparacoes = 0;

                medirTempo(insertionSortTipo,torre,contador);

                mostrarComponentes(torre, contador);

                printf("\nComparacoes: %d\n",comparacoes);

                break;

            case 6:

                comparacoes = 0;

                medirTempo(selectionSortPrioridade,torre,contador);

                mostrarComponentes(torre, contador);

                printf("\nComparacoes: %d\n",comparacoes);

                break;

            case 7:

                printf("Digite o nome do componente: ");

                fgets(nomeBusca,MAX_STR_NOME,stdin);

                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                int resultado = buscaBinariaPorNome(torre,contador,nomeBusca);

                if(resultado != -1) {

                    printf("\nComponente-chave encontrado!\n");
                }
                else {

                    printf("\nComponente nao encontrado.\n");
                }

                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

// ================= ADICIONAR =================
void adicionarComponente(Componente torre[],int *contador) {

    if(*contador >= MAX_ITEMS) {

        printf("Limite atingido!\n");
        return;
    }

    Componente novo;

    printf("\nNome: ");
    fgets(novo.nome, MAX_STR_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Tipo: ");
    fgets(novo.tipo, MAX_STR_TIPO, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    printf("Prioridade: ");
    scanf("%d", &novo.prioridade);

    getchar();

    torre[*contador] = novo;

    (*contador)++;

    printf("Componente adicionado!\n");
}

// ================= REMOVER =================
void removerComponente(Componente torre[],int *contador) {

    char nome[MAX_STR_NOME];

    printf("Nome do componente: ");

    fgets(nome, MAX_STR_NOME, stdin);

    nome[strcspn(nome, "\n")] = '\0';

    int pos = -1;

    for(int i = 0; i < *contador; i++) {

        if(strcmp(torre[i].nome, nome) == 0) {

            pos = i;
            break;
        }
    }

    if(pos == -1) {

        printf("Nao encontrado!\n");
        return;
    }

    for(int i = pos; i < *contador - 1; i++) {

        torre[i] = torre[i + 1];
    }

    (*contador)--;

    printf("Removido com sucesso!\n");
}

// ================= MOSTRAR =================
void mostrarComponentes(Componente torre[],int contador) {

    printf("\n===== COMPONENTES =====\n");

    for(int i = 0; i < contador; i++) {

        printf("%d. %s | Tipo: %s | Quantidade: %d | Prioridade: %d\n", i + 1,
            torre[i].nome,
            torre[i].tipo,
            torre[i].quantidade,
            torre[i].prioridade
        );
    }
}

// ================= BUBBLE =================
void bubbleSortNome(Componente vetor[],int tamanho) {

    for(int i = 0; i < tamanho - 1; i++) {

        for(int j = 0; j < tamanho - 1 - i; j++) {

            comparacoes++;

            if(strcmp(vetor[j].nome,vetor[j + 1].nome) > 0) {

                Componente temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// ================= INSERTION =================
void insertionSortTipo(Componente vetor[],int tamanho) {

    for(int i = 1; i < tamanho; i++) {

        Componente chave = vetor[i];

        int j = i - 1;

        while(j >= 0 && strcmp(vetor[j].tipo, chave.tipo) > 0) {

            comparacoes++;

            vetor[j + 1] = vetor[j];

            j--;
        }

        vetor[j + 1] = chave;
    }
}

// ================= SELECTION =================
void selectionSortPrioridade(Componente vetor[],int tamanho) {

    for(int i = 0; i < tamanho - 1; i++) {

        int maior = i;

        for(int j = i + 1; j < tamanho; j++) {

            comparacoes++;

            if(vetor[j].prioridade > vetor[maior].prioridade) {

                maior = j;

            }
        }

        Componente temp = vetor[i];

        vetor[i] = vetor[maior];

        vetor[maior] = temp;
    }
}

// ================= BUSCA BINÁRIA =================
int buscaBinariaPorNome(Componente vetor[],int tamanho,char nomeBusca[]) {

    int inicio = 0;
    int fim = tamanho - 1;

    while(inicio <= fim) {

        int meio = (inicio + fim) / 2;

        int resultado =
            strcmp(vetor[meio].nome, nomeBusca);

        if(resultado == 0) {

            return meio;
        }

        if(resultado < 0) {

            inicio = meio + 1;
        }
        else {

            fim = meio - 1;
        }
    }

    return -1;
}

// ================= TEMPO =================
void medirTempo(void (*algoritmo)(Componente[], int),Componente vetor[],int tamanho) {

    clock_t inicio = clock();

    algoritmo(vetor, tamanho);

    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao: %.6f segundos\n", tempo);
}