/* Existem diversos algoritmos que realizam a tarefa de ordenar dados. 
Os tipos mais básicos são:
Bubble sort
Insertion sort
Selection sort
*/
#include<stdio.h>

/*A função trocar apresentada no código é uma função auxiliar em 
linguagem C utilizada para trocar os valores de duas variáveis inteiras.*/
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} 

//Método de ordenação bubble sort
void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {        // aqui a troca acontece (verifica e aciona a funcao troca)
                trocar(&vetor[j], &vetor[j + 1]); // pega o endereco dos vetores
            }
        }
    }
} 

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

// Funçao insertion sort
void insertionSort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i]; // Pega o dado da vez e guarda
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
} 

// Função selection sort

void selectionSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            trocar(&vetor[i], &vetor[indiceMenor]);
        }
    }
} 

int main() {

    int numeros[] = {64, 34, 25, 12, 22, 11, 90};

    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    printf("Vetor original:\n");
    imprimirVetor(numeros, tamanho);

    // Ordena o vetor
    bubbleSort(numeros, tamanho);

    printf("\nVetor ordenado:\n");
    imprimirVetor(numeros, tamanho);

    return 0;
}
