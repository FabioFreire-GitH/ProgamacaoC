#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Struct da fila
typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
    int quantidade;
} Fila;

// =====================================================
// Inicializar fila
// =====================================================

void inicializarFila(Fila *f) {

    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

// =====================================================
// Verificar se a fila está vazia
// =====================================================

int filaVazia(Fila *f) {

    return (f->quantidade == 0);
}

// =====================================================
// Verificar se a fila está cheia
// =====================================================

int filaCheia(Fila *f) {

    return (f->quantidade == MAX);
}

// =====================================================
// Inserir elemento na fila (enqueue)
// =====================================================

void inserirFila(Fila *f, int valor) {

    // Verifica se a fila está cheia
    if (filaCheia(f)) {

        printf("Fila cheia!\n");
        return;
    }

    // Insere o valor na posição do fim
    f->itens[f->fim] = valor;

    // Avança o fim circularmente
    f->fim = (f->fim + 1) % MAX;

    // Incrementa quantidade
    f->quantidade++;

    printf("Valor %d inserido na fila.\n", valor);
}

// =====================================================
// Retirar elemento da fila (dequeue)
// =====================================================

int retirarFila(Fila *f) {

    // Verifica se a fila está vazia
    if (filaVazia(f)) {

        printf("Fila vazia!\n");
        return -1;
    }

    // Guarda o valor removido
    int valorRemovido = f->itens[f->inicio];

    // Avança o início circularmente
    f->inicio = (f->inicio + 1) % MAX;

    // Decrementa quantidade
    f->quantidade--;

    return valorRemovido;
}

// =====================================================
// Exibir fila
// =====================================================

void exibirFila(Fila *f) {

    if (filaVazia(f)) {

        printf("Fila vazia.\n");
        return;
    }

    printf("\nFila:\n");

    int i = f->inicio;

    for (int cont = 0; cont < f->quantidade; cont++) {

        printf("%d ", f->itens[i]);

        // Avança circularmente
        i = (i + 1) % MAX;
    }

    printf("\n");
}

// =====================================================
// MAIN
// =====================================================

int main() {

    Fila fila;

    inicializarFila(&fila);

    inserirFila(&fila, 10);
    inserirFila(&fila, 20);
    inserirFila(&fila, 30);

    exibirFila(&fila);

    printf("\nRemovido: %d\n", retirarFila(&fila));

    exibirFila(&fila);

    inserirFila(&fila, 40);
    inserirFila(&fila, 50);
    inserirFila(&fila, 60);

    exibirFila(&fila);

    return 0;
}