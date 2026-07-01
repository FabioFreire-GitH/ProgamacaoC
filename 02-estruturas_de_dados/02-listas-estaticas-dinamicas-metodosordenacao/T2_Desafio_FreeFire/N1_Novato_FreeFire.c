/*DESAFIO NOVATO - FREE FIRE
REQUISITOS:
 1 - Criar uma mochila de Itens de sobrevivencia (para coletar, organizar e usar os itens);
 2 - Mochila com capacidade limitada (quantidade de itens que pode ser carregada - 10 itens);
 3 - Se um decimo primeiro item for adicionado, o programa deve informar que a mochila esta cheia e nao permitir e solicitar a remoção de um item para adicionar outro;
 4 - O programa deve permitir a remoção de itens da mochila;
 5 - Os itens devem possui tipos diferentes (ex: Arma, Municao, Cura, etc) e o programa deve permitir a listagem dos itens por tipo;
 6 - Dependendo o tipo de item, limitar a quantidade de itens do mesmo tipo (ex: no maximo 2 armas, 5 munições, 3 itens de cura, etc);
 7 - Agrupar essas informacoes, nome, tipo e quantidade em um unico pacote usando uma struct;
 8 - Struct como um molde, de nome Item, com 3 campos, nome com 30 caracteres, tipo como texto de ate 20 caracteres e quantidade tipo inteiro;
 9 - Guardaremos os itens em uma lista Linear, ou seja, uma lista estatica (Vetor) em uma Mochila com capacidade para 10 itens;
 10 - Usar uma variavel contadora para controlar a quantidade de itens na mochila, e garantir que nao ultrapasse o limite de 10 itens;
 11 - Menu como um Loop para o usuario escolher as opcoes de adicionar, remover, listar itens e sair do programa;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define uma constante para o tamanho máximo da mochila (quantidade máxima de itens que a mochila pode conter)
#define MAX_ITEMS 10
//Define uma constante para o comprimento máximo que cada texto pode ter.
#define MAX_STR_NOME 30 // Tamanho máximo do nome do item
#define MAX_STR_TIPO 20 // Tamanho máximo do tipo do item

typedef struct {
    char nome[MAX_STR_NOME]; // Nome do item - String de até 30 caracteres
    char tipo[MAX_STR_TIPO]; // Tipo do item - String de até 20 caracteres
    int quantidade; // Quantidade do item - Inteiro representando a quantidade do item
} Item;

// Prototipos das funcoes para gerenciar a mochila
void adicionarItem(Item mochila[], int *contador);
void removerItem(Item mochila[], int *contador);
void listarItens(const Item mochila[], int contador);

int main() {
    Item mochila[MAX_ITEMS]; // Declaração da mochila como um array de Item com capacidade para MAX_ITEMS
    int contador = 0; // Variável contadora para controlar a quantidade de itens na mochila
    int opcao; 

    do {
        printf("==============================\n");
        printf("\nMOCHILA DO SOBREVIVENTE:\n");
        printf("==============================\n");
        printf("Itens na mochila: %d/%d\n\n", contador, MAX_ITEMS); // Exibe a quantidade atual de itens na mochila e a capacidade máxima

        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                adicionarItem(mochila, &contador); // Chama a função para adicionar um item à mochila
                break;
            case 2:
                removerItem(mochila, &contador); // Chama a função para remover um item da mochila
                break;
            case 3:
                listarItens(mochila, contador); // Chama a função para listar os itens da mochila
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void adicionarItem(Item mochila[], int *contador) {
    if (*contador < MAX_ITEMS) { // Verifica se há espaço para adicionar um novo item
        Item novoItem; // Declaração de uma variável do tipo Item para armazenar as informações do novo item

        printf("Digite o nome do item: ");
        fgets(novoItem.nome, MAX_STR_NOME, stdin); // Lê o nome do item
        novoItem.nome[strcspn(novoItem.nome, "\n")] = '\0'; // Remove a nova linha do final da string

        printf("Digite o tipo do item: ");
        fgets(novoItem.tipo, MAX_STR_TIPO, stdin); // Lê o tipo do item
        novoItem.tipo[strcspn(novoItem.tipo, "\n")] = '\0'; // Remove a nova linha do final da string

        printf("Digite a quantidade do item: ");
        scanf("%d", &novoItem.quantidade); // Lê a quantidade do item
        getchar(); // Limpar o buffer de entrada

        mochila[*contador] = novoItem; // Adiciona o novo item à mochila na posição indicada pelo contador
        (*contador)++; // Incrementa o contador de itens na mochila
        printf("Item '%s' adicionado com sucesso!\n", novoItem.nome);
    } else {
        printf("Mochila cheia. Nao e possivel adicionar mais itens.\n");
    }
}

void removerItem(Item mochila[], int *contador) {
    int pos = -1; // Variável para armazenar a posição do item a ser removido
    char nomeItem[MAX_STR_NOME]; // Variável para armazenar o nome do item a ser removido
    printf("Digite o nome do item para remover: ");
    fgets(nomeItem, MAX_STR_NOME, stdin); // Lê o nome do item a ser removido
    nomeItem[strcspn(nomeItem, "\n")] = '\0'; // Remove a nova linha do final da string 
    for (int i = 0; i < *contador; i++) {
        if (strcmp(mochila[i].nome, nomeItem) == 0) { // Compara o nome do item com o nome fornecido
            pos = i; // Se encontrar o item, armazena a posição
            break;
        }
    }

    if (pos == -1) { // Verifica se o item foi encontrado
        printf("Item '%s' nao encontrado na mochila.\n", nomeItem);
        return;
    }

    // Remover o item da mochila 
    for (int i = pos; i < *contador - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    (*contador)--; // Decrementa o contador de itens na mochila
    printf("Item '%s' removido com sucesso!\n", nomeItem);

 

}

void listarItens(const Item mochila[], int contador) {
    if (contador == 0) { // Verifica se a mochila está vazia
        printf("A mochila esta vazia.\n");
        return;
    }

    printf("Itens na mochila:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// =================================================================
// Fim do código para gerenciar a mochila
// =================================================================
