/* Desafio Aventureiro: Jogo Tetris Stack
- Simule uma pilha de peças RESERVAS
- As peças tem tipos: "I","O","T"e"L".
    - Essas "Letras" representam as formas das peças.

- Cada peça terá:
    - Seu tipo (como nome);
    - Numero ID (exclusivo).

- Inicializar uma fila com um numer fixo de peás.
    - EX.: 5.

- Permitir que o jogador:
    - Jogue uma peça (dequeue) se tiver pecas na fila;
    - Reservar uma peça (push);
    - Usar uma peça reservada (pop).

- Exibir o estado atual da fila após cada ação.

# Simplificações para o nível intermediário #

- O foco aqui está no uso combinado da fila e da pilha. 

Algumas limitações são:
 
- O jogador não pode escolher o tipo da peça, pois elas são sempre geradas de forma aleatória.
 
- Impossibilidade de trocar diretamente a peça da fila com a da pilha.
 
- A fila sempre mantém o tamanho, e a pilha tem um tamanho máximo fixo.
 
- O menu é simples, com quatro opções fixas: jogar, reservar, usar peça da reserva e sair.

Estado atual:

Fila de peças	[T 0] [O 1] [L 2] [I 3] [I 4]
Pilha de reserva 	(Topo -> Base): [T 7] [O 6]
Tabela: Visualização atual da fila de peças e da pilha de reserva.

Opções de Ação:

Código	 Ação
1	Jogar peça
2	Reservar peça
3	Usar peça reservada
0	Sair
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILA 5
#define MAX_PILHA 3

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
// STRUCT DA PILHA
// ======================================
typedef struct {

    Peca pilha[MAX_PILHA];

    int topo;

} Pilha;

// ======================================
// PROTÓTIPOS FILA
// ======================================
void inicializarFila(Fila *f);

int filaVazia(Fila *f);

int filaCheia(Fila *f);

void enqueue(Fila *f, Peca novaPeca);

Peca dequeue(Fila *f);

void mostrarFila(Fila *f);

// ======================================
// PROTÓTIPOS PILHA
// ======================================
void inicializarPilha(Pilha *p);

int pilhaVazia(Pilha *p);

int pilhaCheia(Pilha *p);

void push(Pilha *p, Peca novaPeca);

Peca pop(Pilha *p);

void mostrarPilha(Pilha *p);

// ======================================
// OUTROS
// ======================================
Peca gerarPeca(int id);

// ======================================
// MAIN
// ======================================
int main() {

    srand(time(NULL));

    Fila fila;
    Pilha reserva;

    inicializarFila(&fila);
    inicializarPilha(&reserva);

    int proximoID = 0;

    // ======================================
    // FILA INICIAL
    // ======================================
    for(int i = 0; i < MAX_FILA; i++) {

        enqueue(
            &fila,
            gerarPeca(proximoID)
        );

        proximoID++;
    }

    int opcao;

    do {

        printf("\n=====================================\n");
        printf("TETRIS STACK - FILA E RESERVA\n");
        printf("=====================================\n");

        mostrarFila(&fila);

        mostrarPilha(&reserva);

        printf("\nCodigo | Acao\n");
        printf("1      | Jogar peca (dequeue)\n");
        printf("2      | Reservar peca (push)\n");
        printf("3      | Usar peca reserva (pop)\n");
        printf("0      | Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            // ======================================
            // JOGAR PEÇA
            // ======================================
            case 1: {

                if(filaVazia(&fila)) {

                    printf("\nFila vazia!\n");

                    break;
                }

                Peca removida = dequeue(&fila);

                printf("\nPeca [%s %d] jogada!\n",removida.tipo, removida.id);

                // Mantém fila sempre cheia
                enqueue(&fila, gerarPeca(proximoID));

                proximoID++;

                break;
            }

            // ======================================
            // RESERVAR PEÇA
            // ======================================
            case 2: {

                if(pilhaCheia(&reserva)) {

                    printf("\nReserva cheia!\n");

                    break;
                }

                Peca reservada = dequeue(&fila);

                push(&reserva, reservada);

                printf("\nPeca [%s %d] reservada!\n",reservada.tipo,reservada.id);

                // Mantém fila cheia
                enqueue(&fila, gerarPeca(proximoID));

                proximoID++;

                break;
            }

            // ======================================
            // USAR RESERVA
            // ======================================
            case 3: {

                if(pilhaVazia(&reserva)) {

                    printf(
                        "\nNenhuma peca reservada!\n"
                    );

                    break;
                }

                Peca usada = pop(&reserva);

                printf("\nPeca reserva [%s %d] utilizada!\n",usada.tipo,usada.id);

                break;
            }

            case 0:

                printf(
                    "\nEncerrando jogo...\n"
                );

                break;

            default:

                printf(
                    "\nOpcao invalida!\n"
                );
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
// FILA VAZIA
// ======================================
int filaVazia(Fila *f) {

    return (f->quantidade == 0);
}

// ======================================
// FILA CHEIA
// ======================================
int filaCheia(Fila *f) {

    return (f->quantidade == MAX_FILA);
}

// ======================================
// ENQUEUE
// ======================================
void enqueue(Fila *f, Peca novaPeca) {

    if(filaCheia(f)) {

        return;
    }

    f->fim =
        (f->fim + 1) % MAX_FILA;

    f->fila[f->fim] = novaPeca;

    f->quantidade++;
}

// ======================================
// DEQUEUE
// ======================================
Peca dequeue(Fila *f) {

    Peca removida =
        f->fila[f->inicio];

    f->inicio =
        (f->inicio + 1) % MAX_FILA;

    f->quantidade--;

    return removida;
}

// ======================================
// MOSTRAR FILA
// ======================================
void mostrarFila(Fila *f) {

    printf("\nFila de pecas:\n");

    int indice = f->inicio;

    for(int i = 0;
        i < f->quantidade;
        i++) {

        printf(
            "[%s %d] ",
            f->fila[indice].tipo,
            f->fila[indice].id
        );

        indice =
            (indice + 1) % MAX_FILA;
    }

    printf("\n");
}

// ======================================
// INICIALIZAR PILHA
// ======================================
void inicializarPilha(Pilha *p) {

    p->topo = -1;
}

// ======================================
// PILHA VAZIA
// ======================================
int pilhaVazia(Pilha *p) {

    return (p->topo == -1);
}

// ======================================
// PILHA CHEIA
// ======================================
int pilhaCheia(Pilha *p) {

    return (p->topo == MAX_PILHA - 1);
}

// ======================================
// PUSH inserir topo
// ======================================
void push(Pilha *p, Peca novaPeca) {

    if(pilhaCheia(p)) {

        return;
    }

    p->topo++;

    p->pilha[p->topo] = novaPeca;
}

// ======================================
// POP excluir topo
// ======================================
Peca pop(Pilha *p) {

    Peca removida =
        p->pilha[p->topo];

    p->topo--;

    return removida;
}

// ======================================
// MOSTRAR PILHA
// ======================================
void mostrarPilha(Pilha *p) {

    printf("\nPilha reserva:\n");

    if(pilhaVazia(p)) {

        printf("[ VAZIA ]\n");

        return;
    }

    for(int i = p->topo;
        i >= 0;
        i--) {

        printf("[%s %d]\n", p->pilha[i].tipo, p->pilha[i].id);
    }

    printf("\n");
}

// ======================================
// GERAR PEÇA
// ======================================
Peca gerarPeca(int id) {

    Peca nova;

    char tipos[4][2] = {"I","O","T","L"};

    int sorteio = rand() % 4;

    strcpy(
        nova.tipo,
        tipos[sorteio]
    );

    nova.id = id;

    return nova;
}