/*Requisitos funcionais
A seguir, são apresentadas as etapas para implementar o sistema de missões dos jogadores, desde a criação até a verificação de objetivos.
Criação do vetor de missões: declarar um vetor de strings contendo ao menos cinco descrições diferentes de missões estratégicas (ex: Conquistar 3 territórios seguidos, Eliminar todas as tropas da cor vermelha etc.).
Sorteio da missão: implementar a função void atribuirMissao(char* destino, char* missoes[], int totalMissoes) que sorteia uma missão e copia para a variável de missão do jogador usando strcpy.
Armazenamento e acesso: a missão de cada jogador deve ser armazenada dinamicamente utilizando malloc.
Verificação da missão: implementar a função int verificarMissao(char* missao, Territorio* mapa, int tamanho), que avalia se a missão do jogador foi cumprida (crie uma lógica simples inicial para verificação).
Exibição condicional: o sistema deve verificar, ao final de cada turno, se algum jogador cumpriu sua missão e declarar o vencedor.

Requisitos não funcionais
Para garantir organização e clareza na execução das missões, algumas práticas e estruturas devem ser seguidas durante a implementação. Vamos lá!
Modularização: o código deve estar dividido em funções específicas, como atribuirMissao, verificarMissao, exibirMissao, atacar, exibirMapa, liberarMemoria, e a main.
Uso de ponteiros: as missões dos jogadores devem ser manipuladas por meio de ponteiros.
Passagem por valor e referência: a missão deve ser passada por valor para exibição e por referência para atribuição e verificação.
Interface intuitiva: o sistema deve exibir a missão ao jogador apenas uma vez (no início) e verificar silenciosamente se ela foi cumprida ao longo da execução.

Instruções detalhadas
Os elementos a seguir ajudam a estruturar corretamente o funcionamento do jogo e o gerenciamento da memória. Veja!
Bibliotecas necessárias: inclua stdio.h, stdlib.h, string.h e time.h.
Estrutura dos territórios: utilize a struct Territorio com os campos char nome[30], char cor[10], int tropas.
Alocação de memória: use calloc ou malloc para alocar os vetores de territórios e armazenar a missão de cada jogador.
Função de ataque: implemente void atacar(Territorio* atacante, Territorio* defensor) usando rand() para simular uma rolagem de dados (valores entre 1 e 6).
Atualização de campos: transfira a cor e metade das tropas para o território defensor se o atacante vencer. Caso contrário, o atacante perde uma tropa.
Função de liberação: implemente void liberarMemoria(...) para liberar toda a memória alocada dinamicamente (territórios e missões).

Requisitos técnicos adicionais
Para finalizar a implementação com boas práticas, siga os cuidados técnicos adiante:
Use srand(time(NULL)) para gerar números aleatórios.
Valide os ataques para que o jogador só possa atacar territórios inimigos.
Utilize free() ao final para evitar vazamentos de memória.
Comente o código explicando o papel de cada função e lógica importante.
*/

#include <stdio.h>
#include <string.h> // Para strspn()
#include <stdlib.h> 
#include <time.h> // Para gerar numeros aleatorios

// Constantes globais
#define MAX_TERRITORIOS 5
#define TAM_STRING 100
#define MAX_MISSOES 5

// Definição da struct Territorio
typedef struct {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
} Territorio;

typedef struct {
    char descricao[TAM_STRING];
} Missao;


// Prototipos das funcoes
void limparBuffer();
void cadastrarTerritorios(Territorio *tabuleiro, int *numTerritorios);
void exibirMapa(Territorio *tabuleiro, int tamanho);
void atribuirMissao(Missao *missao);
void exibirMissao(Missao *missao);
int verificarMissao(Missao *missao, Territorio *tabuleiro, int tamanho);
void atacar(Territorio *tabuleiro, int numTerritorios, Missao *missao);
void liberarMemoria(Territorio *tabuleiro, Missao *missao);


// Funcao principal
int main() {

    srand(time(NULL));

    // Alocação dinâmica
    Territorio *tabuleiro =
        (Territorio *) calloc(MAX_TERRITORIOS, sizeof(Territorio));

    Missao *missao =
        (Missao *) malloc(sizeof(Missao));

    // Verificação de memória
    if (tabuleiro == NULL || missao == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int numTerritorios = 0;

    // Cadastro dos territórios
    cadastrarTerritorios(tabuleiro, &numTerritorios);

    // Exibição do mapa
    exibirMapa(tabuleiro, numTerritorios);

    // Sorteio da missão
    atribuirMissao(missao);

    // Exibir missão apenas uma vez
    exibirMissao(missao);

    // Fase do Jogo
    atacar(tabuleiro, numTerritorios, missao);

    // Liberar memória
    liberarMemoria(tabuleiro, missao);

    return 0;
}

// ==========================
// LIMPAR BUFFER
// ==========================
void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}    

// ==========================
// CADASTRAR TERRITÓRIOS
// ==========================
void cadastrarTerritorios(Territorio *tabuleiro, int *numTerritorios) {
    printf("=====================\n");
    printf("CADASTRO DE TERRITORIOS\n");
    printf("=====================\n");
    printf("Digite o número total de territórios (máximo %d): ", MAX_TERRITORIOS);
    scanf("%d", numTerritorios);
    limparBuffer();

    // Validação do número de territórios
    if (*numTerritorios < 1 || *numTerritorios > MAX_TERRITORIOS) {
        printf("Número inválido de territórios. Encerrando o programa.\n");
        exit(1);
    }

    // Cadastro dos territórios
    for (int i = 0; i < *numTerritorios; i++) {
        
        printf("\n");
        printf("TERRITORIO %d\n", i + 1);
        printf("=====================\n");
        printf(" - Digite o nome do territorio: ");
        fgets(tabuleiro[i].nome, TAM_STRING, stdin);
        tabuleiro[i].nome[strcspn(tabuleiro[i].nome, "\n")] = '\0'; // Remover o caractere de nova linha

        printf(" - Digite a cor do exercito: ");
        fgets(tabuleiro[i].cor, TAM_STRING, stdin);
        tabuleiro[i].cor[strcspn(tabuleiro[i].cor, "\n")] = '\0'; // Remover o caractere de nova linha

        printf(" - Digite a quantidade de tropas: ");
        scanf("%d", &tabuleiro[i].tropas);
        
        limparBuffer(); // Limpar o buffer de entrada
        printf("\n");
          
    }
}

// ==========================
// EXIBIR MAPA
// ==========================
void exibirMapa(Territorio *tabuleiro, int tamanho) {
    printf("=====================\n");
    printf("MAPA DO JOGO\n");
    printf("=====================\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d. %s | Cor do exercito: %s | Tropas: %d\n", i + 1, tabuleiro[i].nome, tabuleiro[i].cor, tabuleiro[i].tropas);
    }
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar o usuário pressionar Enter
}

// ==========================
// ATRIBUIR MISSÃO
// ==========================
void atribuirMissao(Missao *missao) {
    // Exemplo de missões pré-definidas
    char *missoesPreDefinidas[MAX_MISSOES] = {
        "Conquistar 3 territorios seguidos",
        "Eliminar todas as tropas da cor vermelha",
        "Controlar 5 territorios diferentes",
        "Conquistar o territorio mais forte",
        "Manter um territorio 3 tropas"
    };
        int indiceSorteado = rand() % MAX_MISSOES;
        strcpy(missao->descricao, missoesPreDefinidas[indiceSorteado]);
}

// ==========================
// EXIBIR MISSÃO
// ==========================
void exibirMissao(Missao *missao) {
    printf("Sua missão é: %s\n", missao->descricao);
    printf("\nPressione Enter para continuar...");
    getchar(); // Esperar o usuário pressionar Enter
}

// ==========================
// VERIFICAR MISSÃO
// ==========================
int verificarMissao(Missao *missao, Territorio *tabuleiro, int tamanho) {
    
    // MISSÃO 1
    if (strcmp(missao->descricao, "Controlar 5 territorios diferentes") == 0) {

        if (tamanho >= 5) {
            return 1;
        }
    }

    // MISSÃO 2
    if (strcmp(missao->descricao, "Eliminar todas as tropas da cor vermelha") == 0) {

        int vermelhoExiste = 0;

        for (int i = 0; i < tamanho; i++) {

            if (strcmp(tabuleiro[i].cor,
                "Vermelho") == 0) {

                vermelhoExiste = 1;
            }
        }

        if (!vermelhoExiste) {
            return 1;
        }
    }

    // MISSÃO 3
    if (strcmp(missao->descricao,
        "Manter um territorio com 3 tropas") == 0) {

        for (int i = 0; i < tamanho; i++) {

            if (tabuleiro[i].tropas >= 3) {
                return 1;
            }
        }
    }

    return 0;
}

// ==========================
// ATAQUE/MENU
// ==========================
void atacar(Territorio *tabuleiro, int numTerritorios, Missao *missao) {
    int opcao;
    int atacanteIndex, defensorIndex;
    
      
    do {

         printf("\n=====================\n");
        printf("MENU WAR\n");
        printf("=====================\n");

        printf("1. Atacar\n");
        printf("2. Verificar missao\n");
        printf("3. Exibir mapa\n");
        printf("0. Sair\n");

        printf("=====================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        limparBuffer();
        
        // Encerrar jogo
        if (opcao == 0) {
            printf("Encerrando jogo...\n");
            break;
        }
        
        // ==========================
        // VERIFICAR MISSÃO
        // ==========================
        if (opcao == 2) {

            exibirMissao(missao);

            if (verificarMissao(missao,
                                tabuleiro,
                                numTerritorios)) {

                printf("\nMISSAO CUMPRIDA!\n");
                printf("VOCE VENCEU O JOGO!\n");

            } else {

                printf("\nMissao ainda nao concluida.\n");
            }

            printf("\nPressione Enter para continuar...");
            getchar();

            continue;
        }

         // ==========================
        // EXIBIR MAPA
        // ==========================
        if (opcao == 3) {

            exibirMapa(tabuleiro,
                       numTerritorios);

            continue;
        }

        // ==========================
        // OPÇÃO INVÁLIDA
        // ==========================
        if (opcao != 1) {

            printf("Opcao invalida.\n");

            printf("\nPressione Enter para continuar...");
            getchar();

            continue;
        }

         // ==========================
        // MOSTRAR TABULEIRO
        // ==========================
        printf("\n=====================\n");
        printf("TABULEIRO DE WAR\n");
        printf("=====================\n");
        //mostrar territorios para o jogador escolher
        for (int i = 0; i < numTerritorios; i++) {
            printf("%d. %s | Cor do exercito: %s | Quantidade de tropas: %d\n", i + 1, tabuleiro[i].nome, tabuleiro[i].cor, tabuleiro[i].tropas);
        }

        // ==========================
        // ESCOLHER ATACANTE
        // ==========================
      
        printf("\nEscolha um territorio atacante: ");
        scanf("%d", &atacanteIndex);
        limparBuffer(); // Limpar o buffer de entrada

        

        // Validação
        if (atacanteIndex < 1 ||
            atacanteIndex > numTerritorios) {

            printf("Território inválido.\n");
            printf("\nPressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter;
            continue;
        }

        // Verificar tropas
        if (tabuleiro[atacanteIndex - 1].tropas <= 1) {

            printf("Tropas insuficientes para atacar.\n");
            printf("\nPressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter;
            continue;
            
        }
       
        // ==========================
        // ESCOLHER DEFENSOR
        // ==========================
        printf("Escolha um territorio defensor: ");
        scanf("%d", &defensorIndex);
        limparBuffer(); // Limpar o buffer de entrada

            //validacao
            if (defensorIndex < 1 || defensorIndex > numTerritorios || defensorIndex == atacanteIndex) {
                printf("Defensor inválido.\n");
                printf("\nPressione Enter para continuar...");
                getchar(); // Esperar o usuário pressionar Enter;
                continue;
            }
            
            // Não permitir atacar aliado
            if (strcmp(tabuleiro[atacanteIndex - 1].cor, tabuleiro[defensorIndex - 1].cor) == 0) {
                printf("Você não pode atacar um território aliado.\n");
            printf("\nPressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter;
            continue;
            }

            // Simulação de dados
            int dadoAtacante = rand() % 6 + 1;
            int dadoDefensor = rand() % 6 + 1;

            printf("\nDado atacante: %d\n", dadoAtacante);
            printf("Dado defensor: %d\n", dadoDefensor);
    
            // Determinar o vencedor do ataque
            if (dadoAtacante > dadoDefensor) {
                printf("O atacante venceu!\n");
                // Transferir a cor
                strncpy(tabuleiro[defensorIndex - 1].cor, tabuleiro[atacanteIndex - 1].cor, TAM_STRING);
                // Transferir metade das tropas
                int tropasTransferidas = tabuleiro[atacanteIndex - 1].tropas / 2;
                tabuleiro[defensorIndex - 1].tropas = tropasTransferidas;
                tabuleiro[atacanteIndex - 1].tropas -= tropasTransferidas;
            // Vitória do defensor
            } else {
            printf("O defensor venceu!\n");
                // O atacante perde uma tropa
                tabuleiro[atacanteIndex - 1].tropas--;
            }
    
            // Exibir mapa atualizado após o ataque
            printf("\nMapa atualizado:\n");
            for (int i = 0; i < numTerritorios; i++) {
                printf("%d. %s | Cor do exercito: %s | Quantidade de tropas: %d\n", i + 1, tabuleiro[i].nome, tabuleiro[i].cor, tabuleiro[i].tropas);
                }
            
            // ==========================
        // VERIFICAR MISSÃO AUTOMÁTICO
        // ==========================
        if (verificarMissao(missao, tabuleiro, numTerritorios)) {
            printf("\nMISSAO CUMPRIDA!\n");
            printf("VOCE VENCEU O JOGO!\n");
            break;
        }


        }
           
        while (1);


        
}
    
// ==========================
// LIBERAR MEMÓRIA
// ==========================
void liberarMemoria(Territorio *tabuleiro, Missao *missao) {

    free(tabuleiro);

    free(missao);
}
