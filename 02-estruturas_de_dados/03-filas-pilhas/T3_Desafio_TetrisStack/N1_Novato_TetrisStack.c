/* Desafio Novato: Jogo Tetris Stack
- Simule uma fila de peças futuras.
- As peças tem tipos: "I","O","T"e"L".
    - Essas "Letras" representam as formas das peças.

- Cada peça terá:
    - Seu tipo (como nome);
    - Numero ID (exclusivo).

- O programa permitirá que o jogador:
    - Visualize a fila;
    - Jogue uma peça (remoção da frente);
    - Adicione uma nova peça ao final da fila.

- Inicializar uma fila com um numer fixo de peás.
    - EX.: 5.

- Permitir que o jogador:
    - Jogue uma peça (dequeue) se tiver pecas na fila;
    - Inserir nova peça (enqueue) se houver espaço;

- Exibir o estado atual da fila após cada ação.

## Simplificações para o nível básico ##

Veja a seguir as principais considerações:

- O foco é somente na estrutura de fila.
 
- A pilha de peças reservadas não será implementada neste desafio.
 
 -O menu é simples, com três opções fixas: 
    - jogar peça;
    - inserir nova peça;
    - sair. 
 
As peças são geradas de forma automática, e não inseridas manualmente pelo jogador.

Fila de peças
[T 0] [O 1] [L 2] [I 3] [I 4]

Código | Ação
1	   | Jogar peça (dequeue)
2	   | Inserir nova peça (enqueue)
0	   | Sair
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILA 5

// ======================================
// STRUCT DA PEÇA
// ======================================
typedef struct {

    int id;
    char tipo[2];

} Peca;

// ======================================
// STRUCT DA FILA
// ======================================
typedef struct {

    Peca fila[MAX_FILA];

    int inicio;
    int fim;
    int quantidade;

} Fila;

// ======================================
// PROTÓTIPOS
// ======================================
void inicializarFila(Fila *f);

int filaVazia(Fila *f);

int filaCheia(Fila *f);

void enqueue(Fila *f, Peca novaPeca);

void dequeue(Fila *f);

void mostrarFila(Fila *f);

Peca gerarPeca(int id);

// ======================================
// MAIN
// ======================================
int main() {

    srand(time(NULL));

    Fila fila;

    inicializarFila(&fila);

    int proximoID = 0;

    // ======================================
    // FILA INICIAL COM 5 PEÇAS
    // ======================================
    for(int i = 0; i < MAX_FILA; i++) {

        enqueue(&fila,gerarPeca(proximoID));

        proximoID++;
    }

    int opcao;

    do {

        printf("\n=====================================\n");
        printf("TETRIS STACK - FILA DE PECAS\n");
        printf("=====================================\n");

        mostrarFila(&fila);

        printf("\nCodigo | Acao\n");
        printf("1      | Jogar peca (dequeue)\n");
        printf("2      | Inserir nova peca (enqueue)\n");
        printf("0      | Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            // ======================================
            // REMOVER PEÇA
            // ======================================
            case 1:

                dequeue(&fila);

                break;

            // ======================================
            // INSERIR PEÇA
            // ======================================
            case 2:

                enqueue(&fila,gerarPeca(proximoID));

                proximoID++;

                break;

            case 0:

                printf("\nEncerrando o jogo...\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

// ======================================
// INICIALIZAR FILA
// ======================================
void inicializarFila(Fila *f) {

    f->inicio = 0;

    f->fim = -1;

    f->quantidade = 0;
}

// ======================================
// VERIFICAR FILA VAZIA
// ======================================
int filaVazia(Fila *f) {

    return (f->quantidade == 0);
}

// ======================================
// VERIFICAR FILA CHEIA
// ======================================
int filaCheia(Fila *f) {

    return (f->quantidade == MAX_FILA);
}

// ======================================
// GERAR PEÇA AUTOMÁTICA
// ======================================
Peca gerarPeca(int id) {

    Peca nova;

    char tipos[4][2] = {"I","O","T","L"};

    int sorteio = rand() % 4;

    strcpy(nova.tipo, tipos[sorteio]);

    nova.id = id;

    return nova;
}

// ======================================
// ENQUEUE -> INSERIR NO FINAL
// ======================================
void enqueue(Fila *f, Peca novaPeca) {

    if(filaCheia(f)) {

        printf("\nFila cheia!\n");

        return;
    }

    // FILA CIRCULAR
    f->fim = (f->fim + 1) % MAX_FILA;

    f->fila[f->fim] = novaPeca;

    f->quantidade++;

    printf("\nNova peca [%s %d] adicionada!\n", novaPeca.tipo,novaPeca.id);
}

// ======================================
// DEQUEUE -> REMOVER DA FRENTE
// ======================================
void dequeue(Fila *f) {

    if(filaVazia(f)) {

        printf("\nFila vazia!\n");

        return;
    }

    Peca removida = f->fila[f->inicio];

    printf(
        "\nPeca [%s %d] jogada!\n",
        removida.tipo,
        removida.id
    );

    // FILA CIRCULAR
    f->inicio =
        (f->inicio + 1) % MAX_FILA;

    f->quantidade--;
}

// ======================================
// MOSTRAR FILA
// ======================================
void mostrarFila(Fila *f) {

    printf("\nFila de pecas\n");

    if(filaVazia(f)) {

        printf("[ FILA VAZIA ]\n");

        return;
    }

    int indice = f->inicio;

    for(int i = 0;i < f->quantidade;i++) {

        printf("[%s %d] ",f->fila[indice].tipo,f->fila[indice].id);

        // FILA CIRCULAR
        indice = (indice + 1) % MAX_FILA;
    }

    printf("\n");
}