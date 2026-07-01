/* Desafio Mestre: Jogo Tetris Stack 
- Criar um sistema de reversão de ordem entre a fila e pilha de reservas

- As peças tem tipos: "I","O","T"e"L".
    - Essas "Letras" representam as formas das peças.

- Cada peça terá:
    - Seu tipo (como nome);
    - Numero ID (exclusivo).

## Requisitos funcionais

Seu programa em C deverá:

- Inicializar a fila de peças com um número fixo de elementos (por exemplo, 5).
 
- Inicializar uma pilha de peças reservadas com capacidade limitada (por exemplo, 3).
 
- Permitir as seguintes ações:

    - Jogar uma peça: remove a peça da frente da fila (dequeue).
 
    - Reservar uma peça: move a peça da frente da fila para o topo da pilha, se houver espaço.
 
    - Usar uma peça reservada: remove a peça do topo da pilha, simulando seu uso.
 
    - Exibir o estado atual: mostra as peças na fila e na pilha após cada ação.
 
    - Trocar peça atual: substitui a peça da frente da fila com o topo da pilha.
 
    - Troca múltipla: alterna as três primeiras peças da fila com as três peças da pilha (caso ambas tenham, pelo menos, 3 peças).
 
    - Visualizar o estado atual da fila e da pilha.
 
- Gerar uma nova peça de forma automática a cada remoção ou envio à pilha, a fim de manter a fila sempre cheia (quando possível).
 
- Encerrar o programa.
 
- Lembre-se: as peças removidas da fila ou da pilha não voltam para o jogo.

## Atributos das peças

Cada peça possui:

- nome: caractere que representa o tipo da peça ('I', 'O', 'T', 'L').
 
- id: número inteiro único que representa a ordem de criação da peça.
 
- As peças são geradas automaticamente por uma função chamada gerarPeca.

** Exemplo de saída

Estado atual:

Fila de peças	[I 0] [L 1] [T 2] [O 3] [I 4] 
Pilha de reserva	(Topo -> base): [O 8] [L 7] [T 6]
Tabela: Visualização atual da fila de peças e da pilha de reserva.

Opções disponíveis:

Código	Ação
1	Jogar peça da frente da fila
2	Enviar peça da fila para a pilha de reserva
3	Usar peça da pilha de reserva
4	Trocar peça da frente da fila com o topo da pilha
5	Trocar os 3 primeiros da fila com as 3 peças da pilha
0	Sair
Tabela: Comandos para movimentar peças entre a fila e a pilha de reserva.

Opção escolhida: 5

Ação: troca realizada entre os 3 primeiros da fila e os 3 da pilha.

Novo estado:

Fila de peças	[O 8] [L 7] [T 6] [O 3] [I 4] 
Pilha de reserva	(Topo -> base): [T 2] [L 1] [I 0]

## Simplificações para o nível avançado  

- O foco é o uso combinado da fila e da pilha. Algumas limitações são:

- O jogador não pode escolher o tipo da peça, pois elas são sempre geradas de forma aleatória.
 
- Possibilidade de trocar diretamente a peça da fila com a da pilha.
 
- A fila sempre mantém o tamanho, e a pilha tem um tamanho máximo fixo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILA 5
#define MAX_PILHA 3

// =====================================
// STRUCT DA PEÇA
// =====================================
typedef struct {

    int id;
    char tipo[2];

} Peca;

// =====================================
// STRUCT FILA
// =====================================
typedef struct {

    Peca fila[MAX_FILA];

    int inicio;
    int fim;
    int quantidade;

} Fila;

// =====================================
// STRUCT PILHA
// =====================================
typedef struct {

    Peca pilha[MAX_PILHA];

    int topo;

} Pilha;

// =====================================
// PROTÓTIPOS FILA
// =====================================
void inicializarFila(Fila *f);

int filaVazia(Fila *f);

int filaCheia(Fila *f);

void enqueue(Fila *f, Peca novaPeca);

Peca dequeue(Fila *f);

void mostrarFila(Fila *f);

// =====================================
// PROTÓTIPOS PILHA
// =====================================
void inicializarPilha(Pilha *p);

int pilhaVazia(Pilha *p);

int pilhaCheia(Pilha *p);

void push(Pilha *p, Peca novaPeca);

Peca pop(Pilha *p);

void mostrarPilha(Pilha *p);

// =====================================
// NOVAS FUNÇÕES
// =====================================
void trocarPecaAtual(Fila *fila, Pilha *pilha);

void trocaMultipla(Fila *fila, Pilha *pilha);

// =====================================
// OUTRAS FUNÇÕES
// =====================================
Peca gerarPeca(int id);

void mostrarEstado(Fila *fila, Pilha *pilha);

// =====================================
// MAIN
// =====================================
int main() {

    srand(time(NULL));

    Fila fila;
    Pilha reserva;

    inicializarFila(&fila);
    inicializarPilha(&reserva);

    int proximoID = 0;

    // =====================================
    // FILA INICIAL
    // =====================================
    for(int i = 0; i < MAX_FILA; i++) {

        enqueue(&fila, gerarPeca(proximoID));

        proximoID++;
    }

    int opcao;

    do {

        mostrarEstado(&fila, &reserva);

        printf("\nOpcoes disponiveis:\n\n");

        printf("1 - Jogar peca da frente da fila\n");

        printf("2 - Enviar peca da fila para pilha\n");

        printf("3 - Usar peca da pilha reserva\n");

        printf("4 - Trocar frente da fila com topo da pilha\n");

        printf("5 - Troca multipla (3 pecas)\n");

        printf("0 - Sair\n");

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            // =====================================
            // JOGAR PEÇA
            // =====================================
            case 1: {

                if(filaVazia(&fila)) {

                    printf("\nFila vazia!\n");

                    break;
                }

                Peca removida = dequeue(&fila);

                printf("\nPeca [%s %d] jogada!\n", removida.tipo, removida.id);

                // Mantém fila cheia
                enqueue(&fila, gerarPeca(proximoID));

                proximoID++;

                break;
            }

            // =====================================
            // RESERVAR PEÇA
            // =====================================
            case 2: {

                if(pilhaCheia(&reserva)) {

                    printf("\nPilha cheia!\n");

                    break;
                }

                Peca reservada = dequeue(&fila);

                push(&reserva, reservada);

                printf("\nPeca [%s %d] reservada!\n", reservada.tipo, reservada.id);

                // Mantém fila cheia
                enqueue(&fila,gerarPeca(proximoID));

                proximoID++;

                break;
            }

            // =====================================
            // USAR RESERVA
            // =====================================
            case 3: {

                if(pilhaVazia(&reserva)) {

                    printf("\nPilha vazia!\n");

                    break;
                }

                Peca usada = pop(&reserva);

                printf("\nPeca [%s %d] utilizada!\n", usada.tipo, usada.id);

                break;
            }

            // =====================================
            // TROCAR PEÇA ATUAL
            // =====================================
            case 4:

                trocarPecaAtual(&fila, &reserva);

                break;

            // =====================================
            // TROCA MÚLTIPLA
            // =====================================
            case 5:

                trocaMultipla(&fila, &reserva);

                break;

            case 0:

                printf("\nEncerrando jogo...\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

// =====================================
// INICIALIZAR FILA
// =====================================
void inicializarFila(Fila *f) {

    f->inicio = 0;

    f->fim = -1;

    f->quantidade = 0;
}

// =====================================
// FILA VAZIA
// =====================================
int filaVazia(Fila *f) {

    return (f->quantidade == 0);
}

// =====================================
// FILA CHEIA
// =====================================
int filaCheia(Fila *f) {

    return (f->quantidade == MAX_FILA);
}

// =====================================
// ENQUEUE
// =====================================
void enqueue(Fila *f, Peca novaPeca) {

    if(filaCheia(f)) {

        return;
    }

    f->fim = (f->fim + 1) % MAX_FILA;

    f->fila[f->fim] = novaPeca;

    f->quantidade++;
}

// =====================================
// DEQUEUE
// =====================================
Peca dequeue(Fila *f) {

    Peca removida = f->fila[f->inicio];

    f->inicio = (f->inicio + 1) % MAX_FILA;

    f->quantidade--;

    return removida;
}

// =====================================
// MOSTRAR FILA
// =====================================
void mostrarFila(Fila *f) {

    int indice = f->inicio;

    for(int i = 0; i < f->quantidade; i++) {

        printf("[%s %d] ", f->fila[indice].tipo, f->fila[indice].id);

        indice = (indice + 1) % MAX_FILA;
    }
}

// =====================================
// INICIALIZAR PILHA
// =====================================
void inicializarPilha(Pilha *p) {

    p->topo = -1;
}

// =====================================
// PILHA VAZIA
// =====================================
int pilhaVazia(Pilha *p) {

    return (p->topo == -1);
}

// =====================================
// PILHA CHEIA
// =====================================
int pilhaCheia(Pilha *p) {

    return (p->topo == MAX_PILHA - 1);
}

// =====================================
// PUSH
// =====================================
void push( Pilha *p, Peca novaPeca) {

    if(pilhaCheia(p)) {

        return;
    }

    p->topo++;

    p->pilha[p->topo] = novaPeca;
}

// =====================================
// POP
// =====================================
Peca pop(Pilha *p) {

    Peca removida = p->pilha[p->topo];

    p->topo--;

    return removida;
}

// =====================================
// MOSTRAR PILHA
// =====================================
void mostrarPilha(Pilha *p) {

    if(pilhaVazia(p)) {

        printf("[ VAZIA ]");

        return;
    }

    for(int i = p->topo; i >= 0; i--) {

        printf("[%s %d] ", p->pilha[i].tipo, p->pilha[i].id);
    }
}

// =====================================
// TROCAR PEÇA ATUAL
// =====================================
void trocarPecaAtual( Fila *fila, Pilha *pilha) {

    if( filaVazia(fila) || pilhaVazia(pilha)) {

        printf("\nTroca impossivel!\n");

        return;
    }

    Peca temp = fila->fila[fila->inicio];

    fila->fila[fila->inicio] = pilha->pilha[pilha->topo];

    pilha->pilha[pilha->topo] = temp;

    printf("\nTroca realizada!\n");
}

// =====================================
// TROCA MÚLTIPLA
// =====================================
void trocaMultipla(Fila *fila,Pilha *pilha) {

    if(fila->quantidade < 3 || pilha->topo < 2) {

        printf("\nNao ha pecas suficientes!\n");

        return;
    }

    for(int i = 0; i < 3; i++) {

        int indiceFila = (fila->inicio + i)% MAX_FILA;

        int indicePilha = pilha->topo - i;

        Peca temp = fila->fila[indiceFila];

        fila->fila[indiceFila] = pilha->pilha[indicePilha];

        pilha->pilha[indicePilha] = temp;
    }

    printf("\nTroca multipla realizada!\n");
}

// =====================================
// GERAR PEÇA
// =====================================
Peca gerarPeca(int id) {

    Peca nova;

    char tipos[4][2] = {"I","O","T","L"};

    int sorteio = rand() % 4;

    strcpy(nova.tipo, tipos[sorteio]);

    nova.id = id;

    return nova;
}

// =====================================
// MOSTRAR ESTADO
// =====================================
void mostrarEstado(Fila *fila, Pilha *pilha) {

    printf("\n=====================================\n");

    printf(" ESTADO ATUAL:\n\n");

    printf("Fila de pecas: " );

    mostrarFila(fila); 
    
    printf("\nPilha reserva (Topo -> base): ");

    mostrarPilha(pilha);

    printf("\n=====================================\n");
}