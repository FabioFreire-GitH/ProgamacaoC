/*HORA DE CODAR*/
/*Criaremos um Menu para o usuário;
Possuirá duas opcoes de Listas: Uma Estática e uma Encadeada;
Ambas terão suas respectivas funções de inserção, remoção, listar e busca;
Objetivo - Implementar um minissistema de gerenciamento de itens que utiliza:
Vetor (lista estática); Lista encadeada; inserção; remoção; busca linear; listagem de itens;
Comparação entre busca manual (humana) e busca automática (computacional) */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//Define uma constante para o comprimento maximo que cada texto pode ter.
#define MAX_STR_LEN 50 // Tamanho máximo da string

// =================================================================
//Parte 1 - Lista Estática
// =================================================================

//Define uma constante para o tamanho máximo da lista estática.
#define MAX_ITEMS 10 // Tamanho máximo da lista estática (quantidade máxima de itens que a lista pode conter)

//Estrutura para representar um item na lista estática
typedef struct {
    char nome[MAX_ITEMS][MAX_STR_LEN]; // Nome do item - Matriz 10 linhas e 50 colunas
    int quantidade; // Quantidade do item - Contador para o número de itens atualmente na lista
} ListaEstatica;

//Função para inicializar a lista estática
void inicializarListaEstatica(ListaEstatica *lista);
void inserirItemEstatica(ListaEstatica *lista, const char *texto);
void removerItemEstatica(ListaEstatica *lista, const char *texto);
void listarItensEstatica(const ListaEstatica *lista);

// =================================================================
//Parte 2 - Lista Encadeada
// =================================================================
//Tamanho dinamico; comopsta por nós; cada nó tem um valor e um ponteiro para o próximo nó;

//Estrutura para representar um nó da lista encadeada
typedef struct No {
    char *nome; // Valor do nó - Ponteiro para uma string (alocado dinamicamente)
    struct No* proximo; // Ponteiro para o próximo nó
} No;

typedef No* ListaEncadeada; // Define ListaEncadeada como um ponteiro para o tipo No, representando o início da lista encadeada

//Função para inicializar a lista encadeada
void inicializarListaEncadeada(ListaEncadeada *lista);
void inserirItemEncadeada(ListaEncadeada *lista, const char *texto);
void removerItemEncadeada(ListaEncadeada *lista, const char *texto);
void listarItensEncadeada(const ListaEncadeada *lista);
void liberarListaEncadeada(ListaEncadeada *lista);// Função para liberar a memória alocada para a lista encadeada

// =================================================================
//Parte 3 - FUNÇÃO PRINCIPAL E MENU
// =================================================================

void menuListaEstatica();
void menuListaEncadeada();

int main() {
    int opcao;
    do {
        printf("Menu Principal:\n");
        printf("1. Gerenciar Lista Estatica\n");
        printf("2. Gerenciar Lista Encadeada\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                menuListaEstatica();
                break;
            case 2:
                menuListaEncadeada();
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

// =================================================================
// IMPLEMENTACAO DAS FUNCOES PARA LISTA ESTATICA
// =================================================================

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0; // Inicializa a quantidade de itens como 0
}
    
void inserirItemEstatica(ListaEstatica *lista, const char *texto) {
    if (lista->quantidade < MAX_ITEMS) { // Verifica se há espaço para inserir um novo item
        strncpy(lista->nome[lista->quantidade], texto, MAX_STR_LEN - 1); // Copia o texto para a matriz, garantindo que não ultrapasse o limite
        lista->nome[lista->quantidade][MAX_STR_LEN - 1] = '\0'; // Garante que a string seja terminada com null
        lista->quantidade++; // Incrementa a quantidade de itens na lista
        printf("Item '%s' inserido com sucesso.\n", texto);
    } else {
        printf("Lista cheia. Nao e possivel inserir mais itens.\n");
    }
}

void removerItemEstatica(ListaEstatica *lista, const char *texto) {
    int pos = -1; // Variável para armazenar a posição do item a ser removido
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->nome[i], texto) == 0) { // Compara o nome do item com o texto fornecido
            pos = i; // Se encontrar o item, armazena a posição
            break;
        }
    }
    // Tratamento de erro caso o item não seja encontrado
    if (pos == -1) {
        printf("Item '%s' nao encontrado na lista.\n", texto);
        return; // Sai da função se o item não for encontrado
    }

    /* Item encontrado. Se removermos o item, criamos um "buraco" na lista. Para evitar isso, 
    movemos os itens seguintes para uma posição a anterior para preencher a lacuna */
    for (int i = pos; i < lista->quantidade - 1; i++) {
        strncpy(lista->nome[i], lista->nome[i + 1], MAX_STR_LEN - 1); // Move os itens seguintes para a posição anterior, garantindo que não ultrapasse o limite
        lista->nome[i][MAX_STR_LEN - 1] = '\0'; // Garante que a string seja terminada com null
    }  
    //atualiza a quantidade de itens na lista após a remoção
    lista->quantidade--; // Decrementa a quantidade de itens na lista
    printf("Item '%s' removido com sucesso.\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista) {
    if (lista->quantidade == 0) { // Verifica se a lista está vazia
        printf("A lista esta vazia.\n");
    } else {
        printf("Itens na lista:\n");
        for (int i = 0; i < lista->quantidade; i++) {
            printf("%d. %s\n", i + 1, lista->nome[i]); // Imprime cada item da lista com seu número correspondente
        }
    }
}

// =================================================================
// IMPLEMENTACAO DAS FUNCOES PARA LISTA ENCADEADA
// =================================================================

//Lista encadeada Vazia representada po um ponteiro nulo (NULL) - indica que a lista não contém nenhum nó.
void inicializarListaEncadeada(ListaEncadeada *lista) {
    *lista = NULL; // Inicializa a lista encadeada como vazia (ponteiro nulo)
}

// Função para inserir um item na lista encadeada
void inserirItemEncadeada(ListaEncadeada *Lista, const char *texto){
    No* novoNo = (No*)malloc(sizeof(No)); // Aloca memória para um novo nó
    if (novoNo == NULL) { // Verifica se a alocação de memória foi bem-sucedida
        printf("Erro ao alocar memoria para o novo item.\n");
        return; // Sai da função se a alocação falhar
    }
    novoNo->nome = strdup(texto); // Duplica a string e atribui ao campo nome do nó
    if (novoNo->nome == NULL) { // Verifica se a duplicação da string foi bem-sucedida
        printf("Erro ao alocar memoria para o nome do item.\n");
        free(novoNo); // Libera a memória do nó se a duplicação falhar
        return; // Sai da função se a duplicação falhar
    }
       
    novoNo->proximo = *Lista; // O próximo nó do novo nó aponta para o início atual da lista
    *Lista = novoNo; // O início da lista agora é o novo nó
    printf("Item '%s' inserido com sucesso.\n", texto);
  
}

// Função para remover um item da lista encadeada
void removerItemEncadeada(ListaEncadeada *Lista, const char *texto) {
    No* atual = *Lista; // Ponteiro para percorrer a lista
    No* anterior = NULL; // Ponteiro para manter o nó anterior durante a busca

    while (atual != NULL && strcmp(atual->nome, texto) != 0) { // Percorre a lista até encontrar o item ou chegar ao final
        anterior = atual; // Atualiza o nó anterior
        atual = atual->proximo; // Move para o próximo nó
    }

    if (atual == NULL) { // Verifica se o item foi encontrado
        printf("Item '%s' nao encontrado na lista.\n", texto);
        return; // Sai da função se o item não for encontrado
    }

    if (anterior == NULL) { // O item a ser removido é o primeiro nó da lista
        *Lista = atual->proximo; // Atualiza o início da lista para o próximo nó
    } else { // O item a ser removido está no meio ou no final da lista
        anterior->proximo = atual->proximo; // Atualiza o próximo do nó anterior para pular o nó a ser removido
    }
    free(atual->nome); // Libera a memória alocada para o nome do item
    free(atual); // Libera a memória alocada para o nó
    printf("Item '%s' removido com sucesso.\n", texto);

}

// Função para listar os itens da lista encadeada
void listarItensEncadeada(const ListaEncadeada *Lista) {
    if (*Lista == NULL) { // Verifica se a lista está vazia
        printf("A lista esta vazia.\n");
        return; // Sai da função se a lista estiver vazia
    }
    printf("Itens na lista encadeada:\n");
    No* atual = *Lista; // Ponteiro para percorrer a lista
    int contador = 1; // Contador para numerar os itens
    while (atual != NULL) { // Percorre a lista até o final
        printf("%d. %s\n", contador, atual->nome); // Imprime o item atual com seu número correspondente
        atual = atual->proximo; // Move para o próximo nó
        contador++; // Incrementa o contador
    }
}

// Função para liberar a memória alocada para a lista encadeada
// Apaga tudo da lista, liberando a memória alocada para cada nó e para os nomes dos itens, garantindo que não haja vazamento de memória.
void liberarListaEncadeada(ListaEncadeada *Lista) {
    No* atual = *Lista; // Ponteiro para percorrer a lista
    while (atual != NULL) { // Percorre a lista até o final
        No* temp = atual; // Armazena o nó atual em uma variável temporária
        atual = atual->proximo; // Move para o próximo nó
        free(temp->nome); // Libera a memória alocada para o nome do item
        free(temp); // Libera a memória alocada para o nó
    }
    *Lista = NULL; // Define o início da lista como nulo após liberar toda a memória
}

// =================================================================
// IMPLEMENTACAO DOS MENUS PARA AS LISTAS   
// =================================================================
void menuListaEstatica() {
    ListaEstatica lista; // Declaração de uma variável do tipo ListaEstatica
    inicializarListaEstatica(&lista); // Inicializa a lista estática
    int opcao;
    char texto[MAX_STR_LEN]; // Variável para armazenar o texto do item

    do {
        printf("\nMenu Lista Estatica:\n");
        printf("1. Inserir Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                printf("Digite o nome do item para inserir: ");
                fgets(texto, MAX_STR_LEN, stdin); // Lê o texto do item
                texto[strcspn(texto, "\n")] = '\0'; // Remove a nova linha do final da string
                inserirItemEstatica(&lista, texto); // Chama a função para inserir o item na lista estática
                break;
            case 2:
                printf("Digite o nome do item para remover: ");
                fgets(texto, MAX_STR_LEN, stdin); // Lê o texto do item
                texto[strcspn(texto, "\n")] = '\0'; // Remove a nova linha do final da string
                removerItemEstatica(&lista, texto); // Chama a função para remover o item da lista estática
                break;
            case 3:
                listarListaEstatica(&lista); // Chama a função para listar os itens da lista estática
                break;
            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Menu para gerenciar a lista encadeada
void menuListaEncadeada() {
    ListaEncadeada lista; // Declaração de uma variável do tipo ListaEncadeada
    inicializarListaEncadeada(&lista); // Inicializa a lista encadeada
    int opcao;
    char texto[MAX_STR_LEN]; // Variável para armazenar o texto do item

    do {
        printf("\nMenu Lista Encadeada:\n");
        printf("1. Inserir Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                printf("Digite o nome do item para inserir: ");
                fgets(texto, MAX_STR_LEN, stdin); // Lê o texto do item
                texto[strcspn(texto, "\n")] = '\0'; // Remove a nova linha do final da string
                inserirItemEncadeada(&lista, texto); // Chama a função para inserir o item na lista encadeada
                break;
            case 2:
                printf("Digite o nome do item para remover: ");
                fgets(texto, MAX_STR_LEN, stdin); // Lê o texto do item
                texto[strcspn(texto, "\n")] = '\0'; // Remove a nova linha do final da string
                removerItemEncadeada(&lista, texto); // Chama a função para remover o item da lista encadeada
                break;
            case 3:
                listarItensEncadeada(&lista); // Chama a função para listar os itens da lista encadeada
                break;
            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarListaEncadeada(&lista); // Libera a memória alocada para a lista encadeada antes de sair do menu
}

// =================================================================
// FIM DO CÓDIGO
// =================================================================



     



