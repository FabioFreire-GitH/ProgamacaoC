/*Nivel Novato: A Enigma Studios, desenvolvedora de jogos voltados para o ensino 
de lógica e programação, está desenvolvendo um novo título chamado 
Detective Quest, um jogo eletrônico em que o jogador precisa explorar 
uma mansão para encontrar o culpado.

Designado como desenvolvedor(a) técnico(a), você é responsável por 
implementar o sistema que controla o mapa da mansão, representado 
por uma árvore binária. O seu trabalho será garantir que o mapa seja 
criado com exatidão e que permita ao jogador explorá-lo a partir do 
Hall de entrada, escolhendo entre os caminhos à esquerda ou à direita 
em cada sala.

Você implementará um programa em C que simula o mapa da mansão como 
uma árvore binária com nome para cada cômodo. A árvore é montada de 
modo automático em alocação dinâmica, e o jogador poderá explorar 
esse mapa até chegar a um cômodo que não tenha mais caminhos.

Requisitos funcionais

Seu programa em C deverá:
    - Criar uma árvore binária para representar o mapa da mansão.
    - Permitir a exploração interativa da mansão a partir do Hall 
    de entrada, escolhendo ir para a esquerda (e) ou para a direita (d).

Além disso, a estrutura da mansão já vem definida no código, 
e não é necessário inseri-la manualmente — afinal, ela é criada 
de modo automático pela função main(), usando a função criarSala().

Seu programa em C ainda deverá viabilizar a exploração continua 
até o jogador alcançar um cômodo que não possua caminhos à esquerda 
nem à direita (isto é, um nó-folha na árvore). Por fim, o programa 
exibe o nome de cada sala visitada durante a exploração.

Cada cômodo possui:
- nome: uma string que identifica a sala 
(por exemplo: Sala de estar, Cozinha ou Jardim).

Requisitos não funcionais
    - Usabilidade: a saída do programa deve ser clara e direta, 
    guiando o jogador na exploração.
    - Legibilidade: o código deve estar bem-organizado, com nomes 
    intuitivos e identação apropriada.
    - Documentação: o código deve possuir comentários explicando 
    o propósito das funções, como:
        - criarSala() – cria, de forma dinâmica, uma sala com nome.
        - explorarSalas() – permite a navegação do jogador pela árvore.
        - main() – monta o mapa inicial e dá início à exploração.

Simplificações para o nível novato
    - Utiliza apenas árvore binária (sem busca, inserção dinâmica 
    ou remoção).
    - Há um menu de opções; a navegação acontece a partir das escolhas 
    do usuário (e - esquerda, d - direita ou s - para sair).
    - Cria-se a árvore de forma manual no código-fonte, e ela não é 
    modificada em tempo de execução.

Conceitos trabalhados
    - Árvore binária: estrutura de dados hierárquica com dois filhos 
    por nó.
    - Structs: Criação de um tipo personalizado (Sala) com campos para 
    nome e ponteiros.
    - Alocação dinâmica: uso de malloc para criação de nós da árvore.
    - Operadores condicionais: controle das decisões do jogador 
    (if, else).
    - Modularização: separação de funcionalidades em funções distintas, 
    com responsabilidades claras.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
struct No {
    char sala[50];
    struct No* esquerda;
    struct No* direita;
};

//Cria funçao nó tipo struct
struct No* criarNo(char* valor) {
    // Aloca dinamicamente memoria oara um novo nó e guarda o endereço em 'novo'
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    if (novo==NULL){
        printf("Erro ao alocar memória!\n");
        exit(1); // Encerra o programa em caso de erro de memoria
    }
    // Copia o valor passado como parametro (string) para o campo 'valor' do nó
    strcpy(novo->sala, valor);
    // Inicializa os ponteiros dos filhos como NULL (sem filhos ainda)
    novo->esquerda = NULL;
    novo->direita = NULL;
    // Retorna o endereço do novo nó criado
    return novo;
}

//Funçao que libera toda a memoria alocada para uma arvore
//binaria de forma recursiva.
void liberar(struct No* raiz) {
    // Se o nó existe
    if (raiz != NULL) {
        // Libera primeiro a subárvore esquerda
        liberar(raiz->esquerda);
        // Depois, libera a subárvore direita 
        liberar(raiz->direita);
        // Por ultimo, libera o próprio nó atual.
        free(raiz);
    }
}

void preOrdem(struct No* raiz) {
    if (raiz != NULL) {
        printf("- %s ", raiz->sala);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

//gera os comodos de forma aleatoria
char* gerarComodo(int usados[], char comodos[][50]) {
 
    int sorteio;

    do {

        sorteio = rand() % 10;

    } while (usados[sorteio] == 1);

    usados[sorteio] = 1;

    return comodos[sorteio];
}

struct No* gerarCasa(int profundidade, int usados[], char comodos[][50]) {

    // Caso base:
    // quando chegar a 0, para
    if (profundidade == 0) {
        return NULL;
    }

    // Cria um nó aleatório
    struct No* raiz = criarNo(
        gerarComodo(usados, comodos)
    );

    // Cria subárvore esquerda
    raiz->esquerda = gerarCasa(profundidade - 1, usados, comodos);

    // Cria subárvore direita
    raiz->direita = gerarCasa(profundidade - 1, usados, comodos);

    return raiz;
}

void explorarSalas(struct No* raiz) {

    // Ponteiro que representa
    // a posição atual do jogador
    struct No* atual = raiz;

    char opcao;

    // Continua enquanto existir sala
    while (atual != NULL) {

        printf("\nVocê esta: %s\n\n", atual->sala);

        // Verifica se é nó folha
        if (atual->esquerda == NULL &&
            atual->direita == NULL) {

            printf("Fim do caminho!\n");
            break;
        }

        printf("Opções de Caminhos\n\n");
        printf("(e) À Esquerda, leva ao(à) %s\n",atual->esquerda);
        printf("(d) À Direita segue para o(a) %s\n", atual->direita);
        printf("(s) Sair\n\n");
        printf("Escolha um caminho: ");
        scanf(" %c", &opcao);

        // Sai do jogo
        if (opcao == 's' || opcao == 'S') {

            printf("\nExploracao encerrada.\n\n");
            break;
        }

        // Vai para esquerda
        else if (opcao == 'e' || opcao == 'E') {

            if (atual->esquerda != NULL) {

                atual = atual->esquerda;

            } else {

                printf("Nao existe caminho a esquerda!\n");
            }
        }

        // Vai para direita
        else if (opcao == 'd' || opcao == 'D') {

            if (atual->direita != NULL) {

                atual = atual->direita;

            } else {

                printf("\nNao existe caminho a direita!\n");
            }
        }

        else {

            printf("Opcao invalida!\n");
        }
    }
}

int main() {

    srand(time(NULL));

    int usados[10] = {0};

    char comodos[10][50] = {"Sala de Estar","Cozinha","Banheiro","Quarto",
        "Garagem","Escritorio","Biblioteca","Lavanderia","Sala de Jantar",
        "Varanda"};

    // Gera árvore com profundidade 3 com hall de entrada fixo
    // E o restante automatico
    struct No* raiz = criarNo("Hall de Entrada");

    raiz->esquerda = gerarCasa(2, usados, comodos);
    raiz->direita =  gerarCasa(2, usados, comodos);

   explorarSalas(raiz);

    liberar(raiz);

    return 0;
}