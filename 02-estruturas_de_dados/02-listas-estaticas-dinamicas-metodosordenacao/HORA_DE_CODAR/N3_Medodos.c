/*Você é responsável por desenvolver um módulo de ordenação para um 
sistema educacional que precisa organizar listas de dados pequenos e 
médios, como notas de alunos, tempos em corridas escolares ou nomes 
por ordem alfabética. O desafio é escolher qual método de ordenação 
simples oferece melhor desempenho e clareza para ser utilizado nesse 
contexto.

Antes de tomar a decisão final, você deverá implementar três algoritmos
clássicos de ordenação: 

Bubble sort
 
Insertion sort
 
Selection sort

Além disso, você também deverá avaliar o comportamento de cada um em listas com diferentes padrões de entrada:

Lista já ordenada (melhor caso).
 
Lista em ordem inversa (pior caso).
 
Lista em ordem aleatória (caso médio).*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAMANHO 10

//Declaracao das Funcoes Prototipos
void bubbleSort(int vetor[], int tamanho);
void insertionSort(int vetor[], int tamanho);
void selectionSort(int vetor[], int tamanho);

void imprimirVetor(int vetor[], int tamanho);
void copiarVetor(int origem[], int destino[], int tamanho);

// ================= BUBBLE SORT =================
void bubbleSort(int vetor[], int tamanho) {

    for(int i = 0; i < tamanho - 1; i++) {

        for(int j = 0; j < tamanho - 1 - i; j++) {

            if(vetor[j] > vetor[j + 1]) {

                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// ================= INSERTION SORT =================
void insertionSort(int vetor[], int tamanho) {

    for(int i = 1; i < tamanho; i++) {

        int chave = vetor[i];
        int j = i - 1;

        while(j >= 0 && vetor[j] > chave) {

            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

// ================= SELECTION SORT =================
void selectionSort(int vetor[], int tamanho) {

    for(int i = 0; i < tamanho - 1; i++) {

        int menor = i;

        for(int j = i + 1; j < tamanho; j++) {

            if(vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        int temp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = temp;
    }
}

// ================= IMPRIMIR =================
void imprimirVetor(int vetor[], int tamanho) {

    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

// ================= COPIAR =================
void copiarVetor(int origem[], int destino[], int tamanho) {

    for(int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// ================= MAIN =================
int main() {

    srand(time(NULL));

    // Melhor caso (já ordenado)
    int ordenado[TAMANHO] = {1,2,3,4,5,6,7,8,9,10};

    // Pior caso (ordem inversa)
    int inverso[TAMANHO] = {10,9,8,7,6,5,4,3,2,1};

    // Caso médio (aleatório)
    int aleatorio[TAMANHO];

    for(int i = 0; i < TAMANHO; i++) {
        aleatorio[i] = rand() % 100;
    }

    int copia[TAMANHO];

    // ================= TESTE BUBBLE =================
    printf("===== BUBBLE SORT =====\n");

    copiarVetor(aleatorio, copia, TAMANHO);

    printf("Antes: ");
    imprimirVetor(copia, TAMANHO);

    bubbleSort(copia, TAMANHO);

    printf("Depois: ");
    imprimirVetor(copia, TAMANHO);

    // ================= TESTE INSERTION =================
    printf("\n===== INSERTION SORT =====\n");

    copiarVetor(aleatorio, copia, TAMANHO);

    printf("Antes: ");
    imprimirVetor(copia, TAMANHO);

    insertionSort(copia, TAMANHO);

    printf("Depois: ");
    imprimirVetor(copia, TAMANHO);

    // ================= TESTE SELECTION =================
    printf("\n===== SELECTION SORT =====\n");

    copiarVetor(aleatorio, copia, TAMANHO);

    printf("Antes: ");
    imprimirVetor(copia, TAMANHO);

    selectionSort(copia, TAMANHO);

    printf("Depois: ");
    imprimirVetor(copia, TAMANHO);

    return 0;
}
/*O que cada algoritmo faz
Bubble Sort

Compara elementos vizinhos e vai “empurrando” os maiores para o final.

Exemplo:

5 2 8 1

5 e 2 → troca
2 5 8 1

8 e 1 → troca
2 5 1 8
Insertion Sort

Funciona como organizar cartas na mão.

Ele pega um elemento e insere na posição correta.

Selection Sort

Procura o menor elemento e coloca na primeira posição.

Depois procura o segundo menor, e assim por diante.

Comparação dos algoritmos
Algoritmo	Melhor Caso	Pior Caso	Característica
Bubble Sort	Bom	Ruim	Fácil de entender
Insertion Sort	Muito bom	Médio	Excelente para listas pequenas
Selection Sort	Médio	Médio	Poucas trocas
Conclusão para o trabalho

Você pode concluir algo como:

Para listas pequenas, o Insertion Sort geralmente apresenta melhor desempenho.
O Bubble Sort é o mais simples de entender, porém menos eficiente.
O Selection Sort realiza menos trocas, mas ainda faz muitas comparações.
Em listas já ordenadas, o Insertion Sort costuma ser o mais rápido.

Para esse contexto educacional, o Insertion Sort costuma ser a melhor escolha entre os três.*/