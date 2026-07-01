/* Listas Lineares : Estatica e Dinamica */
/* Listas encadedas simples e listas duplamente encadedas */
/* Lista circular simples e Lista circular duplamente encadeda */
/* Busca Linear */

#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* proximo;
};

// A sua Função para inserir um novo nó no início da lista

void inserirNoInicio(struct No** inicio, int valor) {
    // 1. Alocar memória para o novo nó
    struct No* novo = (struct No*) malloc(sizeof(struct No)); 
    // 2. Verificar se a alocação foi bem-sucedida
    if (novo == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }

    // 3. Atribuir o valor ao novo nó (Valor dentro dele)
    novo->dado = valor;

    // 4. Apontar o próximo do novo nó para o início atual da lista
    novo->proximo = *inicio;
    // 5. Atualizar o início da lista para o novo nó
    *inicio = novo;
} 

// Função para remoção de um nó do início da lista
void removerNo(struct No** inicio) {
    //1.Checar se a lista está vazia
    if (*inicio == NULL || *inicio == NULL) {
        printf("A lista está vazia. Não há nós para remover.\n");
        return;
    }
    // 2. Armazenar o nó a ser removido
    struct No* noparaRemover = *inicio;
    // 3. Atualizar o início da lista para o próximo nó
    *inicio = (*inicio)->proximo;
    // 4. Liberar a memória do nó removido
    free(noparaRemover);
}

// Função percorrer a lista e imprimir os valores dos nós
void imprimirLista(struct No* inicio) {
    // 1. Criar um ponteiro para percorrer a lista
    struct No* atual = inicio;
    // 2. Verificar se a lista está vazia
    if (atual == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    printf("Lista: ");
    // 3. Percorrer a lista até o final 
    while (atual != NULL) {
        // 4. Imprimir o valor do nó atual
        printf("%d ", atual->dado);
        // 5. Mover para o próximo nó
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para realizar a busca linear em um array
int buscaLinear(int lista[], int tamanho, int valor) {
    // 1. Percorrer o array do início ao fim
    for (int i = 0; i < tamanho; i++) {
        // 2. Verificar se o valor atual é igual ao valor buscado
        if (lista[i] == valor) {
            return i; // Retorna o índice do valor encontrado
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

// Função para realizar a busca linear em uma lista encadeada
int buscaLinearLista(struct No* inicio, int valor) {
    int posicao = 0; // Variável para rastrear a posição atual
    struct No* atual = inicio; // Ponteiro para percorrer a lista

    //Enquanto nao chegar ao final da lista
    while (atual != NULL) {
        // Verificar se o valor do nó atual é igual ao valor buscado
        if (atual->dado == valor) {
            return posicao; // Retorna a posição do valor encontrado
        }
        atual = atual->proximo; // Move para o próximo nó
        posicao++; // Incrementa a posição
    }
    return -1; // Retorna -1 se o valor não for encontrado
}


int main() {
    struct No* inicio = NULL; // Inicializa a lista vazia

    // Inserir alguns valores na lista
    inserirNoInicio(&inicio, 10);
    inserirNoInicio(&inicio, 20);
    inserirNoInicio(&inicio, 30);

    // Imprimir a lista
    imprimirLista(inicio);

    // Remover um nó do início da lista
    removerNo(&inicio);

    // Imprimir a lista após a remoção
    imprimirLista(inicio);

    // Exemplo de busca linear
    int array[] = {5, 10, 15, 20, 25};
    int valorBuscado = 15;
    int resultado = buscaLinear(array, sizeof(array) / sizeof(array[0]), valorBuscado);
    if (resultado != -1) {
        printf("Valor %d encontrado no índice %d.\n", valorBuscado, resultado);
    } else {
        printf("Valor %d não encontrado no array.\n", valorBuscado);
    }

    // Exemplo de busca linear em lista encadeada
    valorBuscado = 20;
    resultado = buscaLinearLista(inicio, valorBuscado);
    if (resultado != -1) {
        printf("Valor %d encontrado na posição %d da lista.\n", valorBuscado, resultado);
    } else {
        printf("Valor %d não encontrado na lista.\n", valorBuscado);
    }

}






