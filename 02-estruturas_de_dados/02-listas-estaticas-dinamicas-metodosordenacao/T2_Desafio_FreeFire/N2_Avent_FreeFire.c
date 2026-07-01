/*DESAFIO AVENTUREIRO - FREE FIRE
REQUISITOS:
1 - Busca Sequencial (Vetor)
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
int buscarItens(Item mochila[], int tamanho, char *nomeBusca);
void imprimirResultado(const char* item, int resultado); 

int main() {
    Item mochila[MAX_ITEMS]; // Declaração da mochila como um array de Item com capacidade para MAX_ITEMS
    int contador = 0; // Variável contadora para controlar a quantidade de itens na mochila
    int opcao; 

    int tamanhoDaMochila = sizeof(mochila) / sizeof(mochila[0]);
    char nomeBusca[MAX_STR_NOME]; //buscar Item (Sequencial)

    do {
        printf("\n");
        printf("==============================");
        printf("\nMOCHILA DO SOBREVIVENTE:\n");
        printf("==============================\n");
        printf("Itens na mochila: %d/%d\n\n", contador, MAX_ITEMS); // Exibe a quantidade atual de itens na mochila e a capacidade máxima

        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("4. Buscar Itens (Sequencial)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");
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
            case 4: {
                int res = buscarItens(mochila, contador, nomeBusca);

                imprimirResultado(nomeBusca, res);

    break;
}
                
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
        
        printf("\n");
        printf("==============================");
        printf("\nADICIONAR ITEM:\n");
        printf("==============================\n");
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
    printf("\n");
    printf("==============================");
    printf("\nREMOVER ITEM:\n");
    printf("==============================\n");
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
    printf("\n");
    printf("==============================");
    printf("\nLISTAR ITEM:\n");
    printf("==============================\n");
    if (contador == 0) { // Verifica se a mochila está vazia
        printf("A mochila esta vazia.\n");
        return;
    }

    printf("Itens na mochila:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

int buscarItens(Item mochila[], int tamanho, char* nomeBusca) {
    

                printf("Digite o nome do item: ");
                fgets(nomeBusca, MAX_STR_NOME, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
      
    for(int i = 0; i < tamanho; i++){
        if(strcmp(mochila[i].nome, nomeBusca) ==0) {
            return i;
        }
    }
    return -1;

}
void imprimirResultado(const char* item, int resultado) {
    printf("\nBuscando por \"%s\"...\n", item);
    if (resultado != -1) {
        printf ("Item encontrado na lista %d.\n", resultado+1);

    } else {
        printf ("Item NÃO encontrado na lista.\n");
    }

}

// =================================================================
// Fim do código para gerenciar a mochila
// =================================================================
