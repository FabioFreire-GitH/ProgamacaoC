/* Nivel Novato - Criar um tabuleiro de WAR com 5 territorios
onde cada territorio possui (nome, cor do exercito e quantidade de tropas)
Usaremos structs para representar os territorios 
e um array estatico para armazenar os territorios do tabuleiro.
Apos o cadastramento dos territorios, o programa deve exibir o tabuleiro completo com as informacoes de cada territorio.*/

/* Nivel Aventureiro :
Com funcoes de alocacao dinemica e ponteiros para manipular os territorios do tabuleiro.
A funcao de alocacao dinamica deve permitir criar um tabuleiro com um numero variavel de territorios, definido pelo usuario no inicio do programa.
O programa deve permitir ao usuario adicionar territorios ate atingir a capacidade maxima definida no inicio.
Usar a funcao free() para liberar a memoria alocada antes de encerrar o programa.
- Requisitos funcionais
Alocação dinâmica de territórios: utilizar calloc ou malloc para alocar memória para um vetor de struct Territorio com tamanho informado pelo usuário.
Simulação de ataques: criar uma função void atacar(Territorio* atacante, Territorio* defensor) que simula um ataque, utilizando números aleatórios como se fossem dados de batalha.
Atualização de dados: o território defensor deve mudar de dono (cor do exército) se o atacante vencer, e suas tropas devem ser atualizadas.
Exibição pós-ataque: o sistema deve exibir os dados atualizados dos territórios após cada ataque. 
- Requisitos não funcionais (Modularizacao; uso de ponteiros; gerenciamento de memoria; interface amigavel)
- Instruções detalhadas
Para que o programa funcione da maneira esperada, alguns elementos e etapas de implementação devem ser seguidos conforme descrito a seguir.
Bibliotecas necessárias: inclua stdio.h, stdlib.h, string.h e time.h.
Struct atualizada: utilize a struct Territorio com os campos char nome[30], char cor[10], int tropas.
Alocação de memória: peça ao usuário o número total de territórios e use calloc ou malloc para alocar esse vetor de forma dinâmica.
Função de ataque: implemente void atacar(Territorio* atacante, Territorio* defensor) que utilize rand() para simular um dado de ataque (1 a 6) para cada lado.
Atualização dos campos: transfira a cor e metade das tropas para o território defensor se o atacante vencer. Se perder, o atacante perde uma tropa.
Liberação de memória: crie uma função void liberarMemoria(Territorio* mapa) para liberar o espaço alocado.
*/

#include <stdio.h>
#include <string.h> // Para strspn()
#include <stdlib.h> 
#include <time.h> // Para gerar numeros aleatorios

// Constantes globais
#define MAX_TERRITORIOS 5
#define TAM_STRING 30

// Definição da struct Territorio
typedef struct {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
} Territorio;

// Funcao para limpar buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



// Funcao principal
int main() {

    Territorio *tabuleiro; // Ponteiro para o array de territorios
    //abaixo: alocacao dinamica para o array de territorios
    tabuleiro = (Territorio *)calloc(MAX_TERRITORIOS, sizeof(Territorio));
    
    // Verificar se a alocação de memória foi bem-sucedida
    if (tabuleiro == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1; // Encerrar o programa com código de erro
    }

    int numTerritorios = 0; // Contador de territorios cadastrados
       
    printf("=====================\n");
    printf("CADASTRO DE TERRITORIOS\n");
    printf("=====================\n");
    printf("Digite o número total de territórios (máximo %d): ", MAX_TERRITORIOS);
    scanf("%d", &numTerritorios);
    limparBuffer(); // Limpar o buffer de entrada
    if (numTerritorios < 1 || numTerritorios > MAX_TERRITORIOS) {
        printf("Número inválido de territórios. Encerrando o programa.\n");
        free(tabuleiro); // Liberar a memória alocada
        return 1; // Encerrar o programa com código de erro
    }
    // Laço para cadastrar os territorios
    for (int i = 0; i < numTerritorios; i++) {
        
        printf ("TERRITORIO %d\n", i + 1);
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

    // Exibir o tabuleiro completo como lista de opcoes para fase de ataque e defesa
    int atacanteIndex, defensorIndex;
      
    do {
        printf("=====================\n");
        printf("TABULEIRO DE WAR\n");
        printf("=====================\n");
        for (int i = 0; i < numTerritorios; i++) {
            printf("%d. Territorio: %s | Cor do exercito: %s | Quantidade de tropas: %d\n", i + 1, tabuleiro[i].nome, tabuleiro[i].cor, tabuleiro[i].tropas);
        }
        printf("0. Sair\n");
        printf("=====================\n");
        printf("Escolha um territorio atacante (ou 0 para sair): ");
        scanf("%d", &atacanteIndex);
        limparBuffer(); // Limpar o buffer de entrada
        if (atacanteIndex < 0 || atacanteIndex > numTerritorios || tabuleiro[atacanteIndex - 1].tropas < 1) { // Verificar se o territorio atacante tem tropas suficientes para atacar
            printf("Opção inválida. Por favor, escolha um território válido. Ou trops insuficientes.\n");
            printf("\nPressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter
            printf("\n");
        } else if (atacanteIndex == 0) {
            printf("Saindo do jogo. Até mais!\n");
            printf("\n");
            break; // Sair do loop principal        
        } else {
                printf("Escolha um territorio defensor: ");
                scanf("%d", &defensorIndex);
                limparBuffer(); // Limpar o buffer de entrada
                if (defensorIndex < 1 || defensorIndex > numTerritorios || defensorIndex == atacanteIndex) {
                    printf("Opção inválida. Por favor, escolha um território válido e diferente do atacante.\n");
                    printf("\nPressione Enter para continuar...");
                    getchar(); // Esperar o usuário pressionar Enter
                    printf("\n");
                } else {
                   // Simular o ataque entre os territórios selecionados
                   printf("\n");
                   printf("Simulando ataque entre %s (atacante) e %s (defensor)...\n", tabuleiro[atacanteIndex - 1].nome, tabuleiro[defensorIndex - 1].nome);
                   printf("\n");
                       // Gerar números aleatórios para o ataque (1 a 6)
                        srand(time(NULL)); // Inicializar a semente para números aleatórios
                        int dadoAtacante = rand() % 6 + 1;
                        int dadoDefensor = rand() % 6 + 1;
    
                        printf("Dado do atacante: %d\n", dadoAtacante);
                        printf("Dado do defensor: %d\n", dadoDefensor);
                        printf("\n");
    
                        // Determinar o vencedor do ataque
                        if (dadoAtacante > dadoDefensor) {
                            printf("O atacante venceu! O território defensor muda de dono e metade das tropas são transferidas.\n");
                            // Transferir a cor e metade das tropas para o território defensor
                            strncpy(tabuleiro[defensorIndex - 1].cor, tabuleiro[atacanteIndex - 1].cor, TAM_STRING);
                            int tropasTransferidas = tabuleiro[atacanteIndex - 1].tropas / 2;
                            tabuleiro[defensorIndex - 1].tropas = tropasTransferidas;
                            tabuleiro[atacanteIndex - 1].tropas -= tropasTransferidas;
                        } else {
                            printf("O defensor venceu! O atacante perde uma tropa.\n");
                            // O atacante perde uma tropa
                            if (tabuleiro[atacanteIndex - 1].tropas > 0) {
                                tabuleiro[atacanteIndex - 1].tropas -= 1;
                            }

                        }
    
                        // Exibir os dados atualizados dos territórios após o ataque
                        printf("\nDados atualizados dos territórios:\n");
                        for (int i = 0; i < numTerritorios; i++) {
                            printf("%d. Territorio: %s | Cor do exercito: %s | Quantidade de tropas: %d\n", i + 1, tabuleiro[i].nome, tabuleiro[i].cor, tabuleiro[i].tropas);
                        }                   
                    
                }
        }
    
    } while (atacanteIndex != 0); // Continuar até o usuário escolher sair
    free(tabuleiro); // Liberar a memória alocada antes de encerrar o programa
    return 0; // Encerrar o programa com código de sucesso

}


