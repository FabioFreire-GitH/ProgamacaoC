/*ORGANIZAÇÃO IDEAL DO ARQUIVO
EXEMPLO
1. Includes
2. Defines
3. Structs
4. Protótipos
5. Funções auxiliares
6. Funções da árvore
7. Funções de Exploração
8. Funções de Pilha
9. Funçoes da Lista
10. Funções do Jogador
11. Função Main
*/

/////////////////////////////////////////////
// 1 - INCLUDES
/////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

/////////////////////////////////////////////
// 2 - DEFINES
/////////////////////////////////////////////

#define MAX_COMODOS 10
#define MAX_ITENS 2
#define MAX_ITENS_COMODO 3
#define MAX_MOEDAS 50
#define MAX_ITENS_BOLSA 10 

/////////////////////////////////////////////
// 3 - STRUCTS
/////////////////////////////////////////////
 
enum Qualidade {BAIXA, NORMAL, ALTA , RARA, TOTAL_QUALIDADE};

struct Item {
    char tipo[50];
    int valorBase;
    int quantidade;
    float peso;
    enum Qualidade qualidade;
    struct Item* proximo;
};

struct Comodo {
    char nome[50];
    struct Item* itens;
    struct Comodo* esquerda;
    struct Comodo* direita;
    
};

/////////////////////////////////////////////
// PILHA DE NAVEGACAO
/////////////////////////////////////////////

struct Pilha {
    struct Comodo* comodo;
    struct Pilha* proximo;
};

/////////////////////////////////////////////
// 4 - PROTOTIPOS DAS FUNCOES
/////////////////////////////////////////////

// Prototipos das Funcoes Auxiliares
char* gerarComodoAleatorio(int usados[],char comodos[][50]);
struct Item* gerarItemAleatorio(); //
void gerarItensComodo(struct Comodo* comodo);//
void limparTela();
const char* nomeQualidade(enum Qualidade qualidade);

// Prototipos das Funcoes da Arvore
struct Comodo* criarComodo(const char* nome);
struct Comodo* gerarCasa(int profundidade,int usados[],char comodos[][50]);
void liberarCasa(struct Comodo* raiz);
void preOrdem(struct Comodo* raiz);

// Prototipos das Funcoes de Exploracao
void explorarCasa(struct Comodo* raiz);

// Prototipos das funcoes de pilha
void empilhar(struct Pilha** topo, struct Comodo* comodo);
struct Comodo* desempilhar(struct Pilha** topo);
int pilhaVazia(struct Pilha** topo);
void liberarPilha();//

// Prototipos das Funções de Lista
struct Item* criarItem(const char* tipo, int valor, int quantidade, float peso, enum Qualidade qualidade);
void inserirItem(struct Item** inicio, struct Item* novo);
void listarItens(struct Item* inicio);
void removerItem(struct Item** inicio, char* tipo);
void liberarItens();

// Prototipos das Funcoes de jogador
void pegarItem(struct Comodo* comodo, struct Item** bolsa);
void mostrarBolsa(struct Item* bolsa);
int contarItens(struct Item* bolsa);
void procurarItensComodo(struct Comodo* comodo);
void menuJogador(struct Comodo* comodo, struct Item** bolsa);

/////////////////////////////////////////////
// 5 - FUNCOES AUXILIARES
/////////////////////////////////////////////

//gera os comodos de forma aleatoria
char* gerarComodoAleatorio(int usados[MAX_COMODOS], char comodos[MAX_COMODOS][50]) {
 
    int sorteio;

    do {

        sorteio = rand() % 10;

    } while (usados[sorteio] == 1);

    usados[sorteio] = 1;

    return comodos[sorteio];
}

void limparTela(){

    for (int i = 0; i < 30; i++){
        printf("\n");
    }
}

//Gerar Item Aleatorio
struct Item* gerarItemAleatorio(){

    char itemtipos[MAX_ITENS][50] = {"Moedas","Tapeçaria"};
    int itemvalores[MAX_ITENS] = {10, 500};
    float itempeso[MAX_ITENS] = {0.01, 8.5};
    int sorteio_item; 
    enum Qualidade sorteio_qualidade;
    int itemquantidade;
       
    sorteio_item = rand () % MAX_ITENS;

    if (strcmp(itemtipos[sorteio_item],"Moedas")==0){
        itemquantidade = rand () % MAX_MOEDAS + 1;
    }
    else {
        itemquantidade = 1;
    }

    sorteio_qualidade = rand () % TOTAL_QUALIDADE;

    return criarItem(itemtipos[sorteio_item],itemvalores[sorteio_item] ,itemquantidade,itempeso[sorteio_item] ,sorteio_qualidade);
    
}

//Gerar Itens nos Comodos
void gerarItensComodo(struct Comodo* comodo){
    if (comodo == NULL){
        return;
    }
    int qtd_itens;
    qtd_itens = rand() % MAX_ITENS_COMODO; // maximo 2 itens -  minino 0

        if (qtd_itens == 0){
            printf ("Não há Objetos interessantes nesta sala!\n");
            } else for (int i=1; i <= qtd_itens;i++){
                    struct Item* gerado = gerarItemAleatorio();
                    inserirItem(&comodo->itens, gerado);
            }
    gerarItensComodo(comodo->esquerda);
    gerarItensComodo(comodo->direita);
}

// Converte enum Qualidade em TEXTO
const char* nomeQualidade(enum Qualidade qualidade)
{
    switch (qualidade)
    {
        case BAIXA:
            return "BAIXA";

        case NORMAL:
            return "NORMAL";

        case ALTA:
            return "ALTA";

        case RARA:
            return "RARA";

        default:
            return "DESCONHECIDA";
    }
}

/////////////////////////////////////////////
// 6 - FUNCOES DA ARVORE
/////////////////////////////////////////////

// Cria dinamicamente um novo cômodo da casa
struct Comodo* criarComodo(const char* nome) {
    // Copia o nome recebido para o campo 'nome' do cômodo
    struct Comodo* novo = (struct Comodo*) malloc(sizeof(struct Comodo));
    if (novo==NULL){
        printf("Erro ao alocar memória!\n");
        exit(1); // Encerra o programa em caso de erro de memoria
    }
    // Copia o valor passado como parametro (string) para o campo 'valor' do nó
    strcpy(novo->nome, nome);
    // Inicializa os ponteiros dos filhos como NULL (sem filhos ainda)
    novo->itens = NULL;
    novo->esquerda = NULL;
    novo->direita = NULL;
    // Retorna o endereço do novo nó criado
    return novo;
}

struct Comodo* gerarCasa(int profundidade, int usados[MAX_COMODOS], char comodos[MAX_COMODOS][50]) {

    // Caso base:
    // quando chegar a 0, para
    if (profundidade == 0) {
        return NULL;
    }

    // Cria um nó aleatório
    struct Comodo* raiz = criarComodo(gerarComodoAleatorio(usados, comodos));

    // Cria subárvore esquerda
    raiz->esquerda = gerarCasa(profundidade - 1, usados, comodos);

    // Cria subárvore direita
    raiz->direita = gerarCasa(profundidade - 1, usados, comodos);

    return raiz;
}

//Funçao que libera toda a memoria alocada para uma arvore
//binaria de forma recursiva.
void liberarCasa(struct Comodo* raiz) {
    // Se o nó existe
    if (raiz != NULL) {
        // Libera primeiro a subárvore esquerda
        liberarCasa(raiz->esquerda);
        // Depois, libera a subárvore direita 
        liberarCasa(raiz->direita);
        // Por ultimo, libera o próprio nó atual.
        free(raiz);
    }
}

void preOrdem(struct Comodo* raiz) {
    if (raiz != NULL) {
        printf("- %s ", raiz->nome);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

/////////////////////////////////////////////
// 7 - FUNCOES DA EXPLORACAO
/////////////////////////////////////////////

void explorarCasa(struct Comodo* raiz) {

    // Ponteiro que representa
    // a posição atual do jogador
    struct Comodo* atual = raiz;
    struct Pilha* historico = NULL;

    char opcao;

    // Continua enquanto existir um cômodo válido
    while (atual != NULL) {
        
        //limparTela();

        printf("\n================================\n");
        printf("\nVocê esta: %s\n", atual->nome);
        printf("\n================================\n");
       
        printf("Opções de Caminhos:\n\n");

        if (atual->esquerda != NULL) {
            printf("(e) À Esquerda, leva ao(à) %s\n", atual->esquerda->nome);
        } else
            printf("Não há caminhos à esquerda!\n"); 

        if (atual->direita != NULL) {
            printf("(d) À Direita segue para o(a) %s\n", atual->direita->nome);
        } else 
            printf("Não há caminhos à direita!\n");
            
        printf("(a) Ações do Jogador\n");
        printf("(v) Voltar\n");
        printf("(s) Sair\n\n");
        printf("Escolha um caminho: ");
        scanf(" %c", &opcao);

        printf("\nPressione ENTER para continuar...");
        getchar();
        getchar();

               
        switch (opcao)
        {
            case 'E':// Vai para esquerda
            case 'e':
                if (atual->esquerda != NULL) {
                    empilhar(&historico, atual);
                    atual = atual->esquerda;
                    }  else {
                        printf("Nao existe caminho a esquerda!\n");
                        }
                break;

            case 'D':// Vai para direita
            case 'd':
                if (atual->direita != NULL) {
                    empilhar(&historico, atual);
                    atual = atual->direita;
                    } else {
                        printf ("Não existe caminho a direita!\n");
                        }
                break;

            case 'V'://voltar
            case 'v':
                if (!pilhaVazia(&historico)) {
                    atual = desempilhar(&historico);
                    } else {
                        printf("Nao existe comodo anterior!\n");
                        }
                break;

            case 's':// Sair
            case 'S':
                printf("\nExploracao encerrada.\n\n");
                return;

            case 'a':// Sair
            case 'A':
                   listarItens(atual->itens);
                   
                break;

            default:
                printf("Opção Invalida!\n");
        }

    }
}

/////////////////////////////////////////////
// 8 - FUNCOES DE PILHA
/////////////////////////////////////////////

//Empilhar
void empilhar(struct Pilha** topo, struct Comodo* comodo) {
    // cria novo nó na pilha
    struct Pilha* novo = (struct Pilha*)malloc(sizeof(struct Pilha));

    novo->comodo = comodo;

    //Novo aponta para antigo topo
    novo->proximo = *topo;

    //Atualiza o topo
    *topo = novo;
}

//desempilhar
struct Comodo* desempilhar(struct Pilha** topo){
    // Verifica se a pilha esta vazia
    if (*topo == NULL){
        return NULL;
    }
    //Guarda topo atual
    struct Pilha* temp = *topo;

    //Guarda comodo
    struct Comodo* comodo = temp->comodo;

     // Move topo
    *topo = temp->proximo;

    // Libera nó da pilha
    free(temp);

    // Retorna cômodo anterior
    return comodo;

}

// verificar se a pilha esta vazia
int pilhaVazia(struct Pilha** topo){

    return *topo == NULL;
}

/////////////////////////////////////////////
// 9 - FUNCOES DA LISTA
/////////////////////////////////////////////

////////////////////////////////////////
// Criar Item - Criar item dinamicamente 
struct Item* criarItem(const char* tipo, int valor, int quantidade, float peso, enum Qualidade qualidade) {
    // Copia o nome recebido para o campo 'nome' do cômodo
    struct Item* novo = (struct Item*) malloc(sizeof(struct Item));
    if (novo==NULL){
        printf("Erro ao alocar memória!\n");
        exit(1); // Encerra o programa em caso de erro de memoria
    }
    // Copia o valor passado como parametro (string) para o campo 'valor' do nó
    strcpy(novo->tipo, tipo);

    novo->valorBase = valor;

    novo->quantidade = quantidade;

    novo->peso = peso;

    novo->qualidade = qualidade;

    novo->proximo = NULL;
    // Retorna o endereço do novo nó criado
    return novo;
}

////////////////////////////////////////////////////////
// Inserir Itens - Adicionar itens no inicio de uma lista.
void inserirItem(struct Item** inicio, struct Item* novo){
   
    // Apontar o próximo do novo nó para o início atual da lista
    novo->proximo = *inicio;
    // Atualizar o início da lista para o novo nó
    *inicio = novo;
} 

//////////////////////////////////////////
//Listar Itens e numerar itens encontrados
void listarItens(struct Item* inicio){
    struct Item* atual = inicio;
    int i = 1;
    while (atual != NULL){
        printf ("%d - %s | Qtd: %d | Qualidade: %s\n", i, atual->tipo, atual->quantidade, nomeQualidade(atual->qualidade));
        atual = atual->proximo;
        i++;
    }
}

/////////////////////////////////////////
// remover item da lista
void removerItem(struct Item** inicio, char* tipo){
    struct Item* atual = *inicio;
    struct Item* anterior = NULL;

    while (atual != NULL){
        if (strcmp(atual->tipo, tipo) == 0){
            if (anterior == NULL){
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

/////////////////////////////////////////////
// 10 - FUNCOES DO JOGADOR
/////////////////////////////////////////////

// Pegar item do cômodo e colocar na bolsa
void pegarItem(struct Comodo* comodo, struct Item** bolsa)
{
    if (comodo->itens == NULL) {
        printf("Não há itens para pegar neste cômodo!\n");
        return;
    }
    if (contarItens(*bolsa) >= MAX_ITENS_BOLSA){
        printf("A bolsa está cheia! Não é possível pegar mais itens.\n");
        return;
    }

    // listar os itens disponíveis no cômodo
    printf("Itens disponíveis para pegar:\n");
    listarItens(comodo->itens);

    // Escolher o item a ser pego por numero
    int escolha;
    printf("Digite o número do item que deseja pegar: ");
    scanf("%d", &escolha);
    getchar(); // Limpar o buffer de entrada
    if (escolha <= 0) {
        printf("Escolha inválida!\n");
        return;
    }

     
    struct Item* atual = comodo->itens;
    struct Item* anterior = NULL;

    int i = 1;
    // percorre até encontrar o item escolhido
    while (atual != NULL && i < escolha) {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }
    // se não encontrou
    if (atual == NULL) {
        printf("Item não encontrado!\n");
        return;
    }


    // remove da lista do cômodo
    if (anterior == NULL) {
        // primeiro item
        comodo->itens = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

     
    // insere na bolsa
    inserirItem(bolsa, atual);

    printf("Você pegou: %s\n", atual->tipo);

}

// Contar itens na bolsa
int contarItens(struct Item* bolsa){
    int contador = 0;
    struct Item* atual = bolsa;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

// Menu do jogador para interagir com os itens do cômodo e da bolsa
// Opcao de pegar item ou nao
void menuJogador(struct Comodo* comodo, struct Item** bolsa){


}

// Procurar itens no cômodo
void procurarItensComodo(struct Comodo* comodo){}

// Mostrar itens na bolsa
void mostrarBolsa(struct Item* bolsa){}

/////////////////////////////////////////////
// 11 - FUNCAO MAIN
/////////////////////////////////////////////
int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    int usados[MAX_COMODOS] = {0};

    char comodos[MAX_COMODOS][50] = {"Sala de Estar","Cozinha","Banheiro","Quarto",
        "Garagem","Escritorio","Biblioteca","Lavanderia","Sala de Jantar",
        "Varanda"};

    // Gera árvore com profundidade 3 com hall de entrada fixo
    // E o restante automatico
    struct Comodo* raiz = criarComodo("Hall de Entrada");

    raiz->esquerda = gerarCasa(2, usados, comodos);
    raiz->direita =  gerarCasa(2, usados, comodos);
    
    // Gerar itens aleatórios para cada cômodo da casa
    gerarItensComodo(raiz);

    struct Item* bolsa = NULL; // Variável para representar a bolsa do jogador
  
    explorarCasa(raiz);

    liberarCasa(raiz);

    return 0;
}

