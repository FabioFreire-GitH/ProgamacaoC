/* Sistema istema para armazenar e consultar os jogadores de um campeonato 
on-line. Os jogadores são organizados em um ranking baseado em pontuação 
(ordem decrescente).


O objetivo é desenvolver um sistema que gerencie pontuações de jogadores
em um ranking, permitindo: 

Inserção e remoção de jogadores. 
Visualização do ranking.
Busca por jogador (nome). 
Comparação entre vetores e listas encadeadas. 
Teste prático entre busca sequencial e binária (iterativa e recursiva).

O sistema deve aceitar:
Cadastro e remoção de jogadores.
Visualização do ranking.
Busca por nome (com diferentes algoritmos).
Análise comparativa do desempenho das estruturas.
*/

#include <stdio.h>
#include <stdlib.h> // Essencial para comparar strings (strcmp)
#include <string.h> //Para funcao exit, caso a lista não esteja ordenada para busca binaria.

//Definicao das Funcoes (Prototipos)

//1. Busca Sequencial 
int buscaSequencialIterativa(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecuirsiva_aux(const char* lista[], int tamanho, const char* item, int indice);

//2. Busca Binaria

int buscaBinariaIterativa(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecuirsiva_aux(const char* lista[], const char* item, int inicio, int fim);

//Função para imprimir os resultados de forma organizada
void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado);

// Função principal
//Programa começa a ser executado aqui.
int main (){
    //IMPORTANTE: Para a busca BINARIA, a lista deve estar ordenada alfabeticamente.
    const char* listaDeCompras[] = {"arroz","batata","cenola","detergente","feijao","leite","macarrao","oleo","sal","tomate"};

//calcula o numero de Itens da lista.
int tamanhoDaLista = sizeof(listaDeCompras) / sizeof(listaDeCompras[0]);    

//Itens que vamos Procurar (demostraçao dos algoritmos)
const char* itemExistente = "leite";
const char* itemInexistente = "queijo";

printf("--- DEMOSTRAÇÃO DE ALGORITMO DE BUSCA EM LISTA DE TEXTO ---\n");
printf("Lista utilizada: [arroz,batata,cenola,detergente,feijao,leite,macarrao,oleo,sal,tomate]\n");
printf("-------------------------------------------------------------\n\n");

// Teste busca Sequencial
printf("--- 1. BUSCA SEQUENCIAL ---\n");
// a - versão Iterativa 
int res1 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
imprimirResultado("Sequencia Iterativa", itemExistente, res1);

int res2 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
imprimirResultado("Sequencia Iterativa", itemInexistente, res2);
printf("\n");

// b - versao Recursiva
int res3 = buscaSequencialRecursiva(listaDeCompras,tamanhoDaLista,itemExistente);
imprimirResultado("Sequencial Recursiva",itemExistente, res3);

int res4 = buscaSequencialRecursiva(listaDeCompras,tamanhoDaLista,itemInexistente);
imprimirResultado("Sequencial Recursiva",itemInexistente, res4);
printf("-------------------------------------------------------------\n\n");

// Teste busca Binaria
printf("--- 1. BUSCA BINARIA (requer lista ordenada) ---\n");
// a - versão Iterativa 
int res5 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
imprimirResultado("Binaria Iterativa", itemExistente, res5);

int res6 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemInexistente);
imprimirResultado("Binaria Iterativa", itemInexistente, res6);
printf("\n");

// b - versao Recursiva
int res7 = buscaBinariaRecursiva(listaDeCompras,tamanhoDaLista,itemExistente);
imprimirResultado("Binaria Recursiva",itemExistente, res7);

int res8 = buscaBinariaRecursiva(listaDeCompras,tamanhoDaLista,itemInexistente);
imprimirResultado("Binaria Recursiva",itemInexistente, res8);
printf("-------------------------------------------------------------\n\n");

return 0; // Fim de Programa

}

//IMPLEMENTANDO FUNCOES
//BUSCA SEQUENCIAL

int buscaSequencialIterativa(const char* lista[], int tamanho, const char* item){
    for (int i=0; i < tamanho; i++) {
        if (strcmp(lista[i], item) == 0){
            return i;
        }
    }

    return -1;
}

int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item){
    // A logica recursiva real esta na função auxiliar
    // Começamos a busca a partir do indice 0.
    return buscaSequencialRecuirsiva_aux(lista,tamanho,item,0);
}

int buscaSequencialRecuirsiva_aux(const char* lista[], int tamanho, const char* item, int indice){
    // 1 - FALHA. Fim da Lista.
    // Indice atual maior ou igual que o tamanho da lista
    // Significa que ja percorremos todos os elementos
    if (indice >= tamanho) {
        return -1; // Item nao encontrado
    }
    // 2. SUCESSO
    // Compara o Item na posicao indice atual com o produto procurado.
    if (strcmp(lista[indice], item) == 0){
        return indice; // Item encontrado
    }
    // PASSO RECURSIVO
    // Se não form nenhum dos casos 1 e 2 acima, o item ainda pode estar no resto da lista.
    // Chamamos a função novamente, mas com indice (indice + 1)
    return buscaSequencialRecuirsiva_aux(lista,tamanho,item,indice + 1);

}

// BUSCA BINARIA

int buscaBinariaIterativa(const char* lista[], int tamanho, const char* item){
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim){
        meio = inicio + (fim-inicio) /2; // Evita overflow para listas muito grandes.
        int comparacao = strcmp(lista[meio],item);

        if (comparacao == 0){
            return meio;
        } else if (comparacao > 0) {
            //item do meio vem depois do item procurado
            // antes do meio, a esquerda do meio
            fim = meio -1;
            } else { //comparacao < 0 , Item do meio antes do Procurado, depois do meio, a direita
                inicio = meio + 1;
            }

    }

    return -1;

}

int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item) {

    return buscaBinariaRecuirsiva_aux(lista, item, 0, tamanho -1);
}

int buscaBinariaRecuirsiva_aux(const char* lista[], const char* item, int inicio, int fim) {
    // 1 - FALHA
    if (inicio > fim) {
        return -1;
    }
    // PASSO RECURSIVO E CASO BASE DE SUCESSO
    int meio = inicio + (fim - inicio) / 2;
    int comparacao = strcmp(lista[meio], item);

    if (comparacao == 0) {
        return meio;
    } else if (comparacao > 0){
        return buscaBinariaRecuirsiva_aux(lista, item, inicio, meio -1);
        } else { //comparacao < 0
            return buscaBinariaRecuirsiva_aux(lista, item, meio+1,fim);
        }


}

void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado) {
    printf("[%s] Buscando por \"%s\"...\n", nomeDaBusca, item);
    if (resultado != -1) {
        printf ("Item encontrado na lista %d.\n", resultado);

    } else {
        printf ("Item NÃO encontrado na lista.\n");
    }

}



