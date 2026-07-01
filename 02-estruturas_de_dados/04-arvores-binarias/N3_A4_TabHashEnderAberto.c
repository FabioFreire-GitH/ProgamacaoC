/*Tabela hash com endereçamento aberto
    - É um vetor com espaços numerados (índices), onde cada palvra é transformada
    em um número (indice) usando uma função hash.
    - Se o espaço está ocupado, você "anda" para o próximo até achar um livre (sondagem
    linear). 
*/



/*Estrutura de dados
Vamos armazenar nomes em uma tabela hash simples. Primeiro, criamos uma struct 
para representar uma entrada da tabela.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

typedef struct {
    char nome[50];
    int ocupado; // 0 = vazio, 1 = ocupado, -1 = removido
} Entrada;

Entrada tabela_hash[TAMANHO_TABELA];
/*Explicando:
    - Cada posição do vetor contém uma Entrada, que armazena um nome e um indicador 
    de estado (ocupado).
    - Usamos -1 para sinalizar que ali já houve algo, mas foi removido. Isso é importante 
    para manter a busca funcionando de maneira correta.*/

/*Função hash
Usamos a mesma função simples para transformar a chave (nome) em um índice do vetor:*/
int funcao_hash(const char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

/*Inserção com sondagem linear
Agora vamos à função de inserir nomes. Se a posição estiver ocupada, seguimos 
procurando a próxima vaga.*/
void inserir(const char* nome) { 
    int indice = funcao_hash(nome);
    for (int i = 0; i < TAMANHO_TABELA; i++) {
                int pos = (indice + i) % TAMANHO_TABELA;
        
                if (tabela_hash[pos].ocupado == 0 || tabela_hash[pos].ocupado == -1) {
                    strcpy(tabela_hash[pos].nome, nome);
                    tabela_hash[pos].ocupado = 1;
                    return;
            }
    }
        printf("Tabela cheia. Não foi possível inserir '%s'.\n", nome);
}

/*Buscar um nome
A procura também segue o mesmo padrão de sondagem linear:*/
int buscar(const char* nome) { 
    int indice = funcao_hash(nome);
    
        for (int i = 0; i < TAMANHO_TABELA; i++) {
                int pos = (indice + i) % TAMANHO_TABELA;
        
                if (tabela_hash[pos].ocupado == 0) {
                    return -1; // Paramos: posição nunca foi usada
            }
    
            if (tabela_hash[pos].ocupado == 1 && strcmp(tabela_hash[pos].nome, nome) == 0) {
                    return pos;
            }
    }
    
        return -1; // Não encontrou
}

/*Remover um nome
Para retirar, procuramos pelo nome e marcamos a posição como removida (-1):*/
void remover(const char* nome) {
    int pos = buscar(nome);
    if (pos == -1) {
        printf("'%s' não encontrado.\n", nome);
        return;
    }
 
    tabela_hash[pos].ocupado = -1;
    printf("'%s' removido da tabela.\n", nome);
}

/*Função main
A seguir, temos um exemplo prático mais completo em C, que ilustra o uso de uma 
tabela hash com operações de inserção, busca e remoção. Esse trecho permite observar 
como a estrutura se comporta em situações reais, incluindo casos de colisão e 
tentativas de remoção de elementos inexistentes.*/
int main() {
    // Inicializa a tabela
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela_hash[i].ocupado = 0;
    }
 
    inserir("Ana");
    inserir("Bruno");
    inserir("Carlos");
    inserir("Amanda"); // Pode colidir com Ana
 
    printf("Buscando 'Bruno': %s\n", buscar("Bruno") != -1 ? "Encontrado" : "Não encontrado");
    printf("Buscando 'João': %s\n", buscar("João") != -1 ? "Encontrado" : "Não encontrado");
 
    remover("Carlos");
    remover("João");
 
    return 0;
}











