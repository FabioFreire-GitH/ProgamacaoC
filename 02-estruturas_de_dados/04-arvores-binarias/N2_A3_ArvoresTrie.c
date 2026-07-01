/* # Árvores Trie

 - É uma "arvore de letras"
 - Serve para guardar muitas palavras, aproveitando prefixos em comum.
 - Cada caminho do topo até o nó final forma uma palavra.
   
*/

/*Estrutura do nó
Para construir uma Trie, cada nó precisa representar possíveis 
ramificações para os próximos caracteres. Em geral, utilizamos 
um array de ponteiros (por exemplo, 26 para letras minúsculas 
de 'a' a 'z') e um indicador booleano que mostra se um caminho 
forma uma palavra completa. Veja!*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
#define TAMANHO_ALFABETO 26
 
struct NoTrie {
    struct NoTrie* filhos[TAMANHO_ALFABETO];
    bool ehFimDePalavra;
};

/*Criação de um nó
Ao iniciarmos a Trie, precisaremos de um nó raiz vazio. Cada novo 
caractere inserido será conectado de modo dinâmico, conforme a palavra 
for processada.*/
struct NoTrie* criarNo() { 
    struct NoTrie* novoNo = (struct NoTrie*) malloc(sizeof(struct NoTrie));
    novoNo->ehFimDePalavra = false;
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
            novoNo->filhos[i] = NULL;
    }

    return novoNo;
}

/*Inserção de palavras na Trie
Percorremos caractere por caractere e criamos os nós intermediários 
se eles ainda não existirem. A marcação de fim de palavra é essencial 
para distinguir palavras completas de simples prefixos.*/
void inserir(struct NoTrie* raiz, const char* palavra) {
    struct NoTrie* atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNo();
        }
        atual = atual->filhos[indice];
    }
    atual->ehFimDePalavra = true;
}

/*Busca de palavras
É muito parecida com a inserção, ou seja, percorremos os nós 
conforme os caracteres da palavra. Se em algum momento o caminho 
não existir, significa que a palavra não está presente. E, mesmo
se todos os caracteres forem encontrados, o nó final precisa estar 
marcado como fim de palavra*/
bool buscar(struct NoTrie* raiz, const char* palavra) {
    struct NoTrie* atual = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';

        if (atual->filhos[indice] == NULL)
            return false;

        atual = atual->filhos[indice];
    }
    return atual != NULL && atual->ehFimDePalavra;
}

/*Ordenação lexicográfica e normalização
Como a Trie armazena os caracteres em ramos que seguem a ordem do 
alfabeto (de ‘a’ a ‘z’), podemos percorrê-la em pré-ordem alfabética 
para imprimir todas as palavras de forma ordenada. Esse percurso pode 
ser feito de modo recurso.*/
void listarPalavras(struct NoTrie* no, char* buffer, int nivel) {
    if (no->ehFimDePalavra) {
        buffer[nivel] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL) {
            buffer[nivel] = 'a' + i;
            listarPalavras(no->filhos[i], buffer, nivel + 1);
        }
    }
}

void normalizar(const char* entrada, char* saida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        char c = entrada[i];
        if (c >= 'A' && c <= 'Z') c += 32; // Converte para minúsculo
        if (c >= 'a' && c <= 'z') saida[j++] = c; // Mantém apenas letras
    }
    saida[j] = '\0';
}

int main() {
    struct NoTrie* raiz = criarNo();
    char normalizada[100];
 
    normalizar("Pegadas de Lama", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Chave perdida", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Livro com página faltando", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Lençol manchado", normalizada);
    inserir(raiz, normalizada);
 
    normalizar("Gaveta perdida", normalizada);
    inserir(raiz, normalizada);

    char buffer[100]; // Tamanho máximo de palavra suportado
    listarPalavras(raiz, buffer, 0);

    return 0;
}