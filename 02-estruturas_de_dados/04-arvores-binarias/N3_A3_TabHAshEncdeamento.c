//Tabela hash com encadeamento (chaining)
/*Encadeamento
Resolve colisões utilizando, em cada posição do vetor, uma lista ligada. Assim, 
quando várias chaves forem direcionadas ao mesmo índice, elas são adicionadas 
como nós dessa lista.

Vamos entender melhor! Imagine uma caixa de correio com várias cartas dentro. 
A "caixa" é a posição do vetor, e cada "carta" é um nó da lista com uma chave.*/

/*Implementação
Vamos implementar uma tabela hash simples que armazena nomes (strings). Para isso, 
começamos definindo nossas estruturas:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

// Estrutura de um nó da lista ligada
typedef struct Nodo {
    char nome[50];              // Armazena o nome
    struct Nodo* proximo;       // Ponteiro para o próximo nó
} Nodo;

// A tabela hash é um vetor de ponteiros para Nodo
Nodo* tabela_hash[TAMANHO_TABELA];

/*Função hash
Precisamos transformar uma string (nome) em um índice de vetor. Para isso, criamos 
uma função hash simples, que soma os valores dos caracteres e aplica o operador % para 
restringir ao tamanho da tabela.*/
int funcao_hash(const char* chave) {
        int soma = 0;
        for (int i = 0; chave[i] != '\0'; i++) {
            soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

/*Inserir um nome
Para inserir um nome, criamos um nó e o adicionamos ao início da lista ligada 
correspondente à posição gerada pela função hash*/
void inserir(const char* nome) {
    int indice = funcao_hash(nome); // Descobre onde armazenar
    // Cria um nó
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(novo->nome, nome);

    // Insere no início da lista (head)
    novo->proximo = tabela_hash[indice];
    tabela_hash[indice] = novo;
}

/*Buscar um nome
A procura percorre a lista da posição indicada pela função hash e compara nome 
por nome até encontrar o desejado*/
Nodo* buscar(const char* nome) {
        int indice = funcao_hash(nome);
        Nodo* atual = tabela_hash[indice];
    
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) {
                return atual; // Encontrou
        }
        atual = atual->proximo;
    }

    return NULL; // Não está na lista
}

/*Remover um nome
Excluir um item de uma lista ligada exige um pouco mais de cuidado. Assim, precisamos 
manter a referência do elemento anterior para reencadear a lista após a remoção*/
void remover(const char* nome) {
        int indice = funcao_hash(nome);
        Nodo* atual = tabela_hash[indice];
        Nodo* anterior = NULL;
    
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) {
                if (anterior == NULL) {
                    tabela_hash[indice] = atual->proximo; // Era o primeiro
            } else {
                    anterior->proximo = atual->proximo; // "Pula" o nó atual
            }
            free(atual);
            printf("'%s' removido.\n", nome);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("'%s' não encontrado.\n", nome);
}

//Função main – cadastro de nomes
int main() {
    inserir("Ana");
    inserir("Bruno");
    inserir("Carlos");
    inserir("Amanda"); // Pode colidir com "Ana"
 
    printf("Buscando 'Bruno': %s\n", buscar("Bruno") ? "Encontrado" : "Não encontrado");
    printf("Buscando 'João': %s\n", buscar("João") ? "Encontrado" : "Não encontrado");
 
    remover("Carlos");
    remover("João");
 
    return 0;
}

