// SISTEMA DE BIBLIOTECA - T1 PRÁTICA 
// OBJETIVOs
// Parte 1 : Criar um sistema de biblioteca simples que permita aos usuários adicionar livros, 
// listar livros disponíveis e buscar por títulos específicos. 
// Foco em structs, array estaticos e funções para manipulação de dados.    
// Parte 2 : Adcionar a funcionalidade emprestimo e introduzir alocacao dinamica para armazenar os livros, permitindo um numero ilimitado de livros.
// - os arrays de livros e emprestimos sao alocados com malloc / calloc.
// - Nova struct para Emprestimo.
// - Liberar a memoria alocada com free().
/*Parte 3: Modularizar o codigo com funcoes especializadas.
- Passagem por valor para exibicao e por referencia para modificação.
- Funções para cada funcionalidade principal do sistema 
(adicionar livro, listar livros, emprestar livro, listar emprestimos).
- A funcao main() se torna um orquestrador, chamando as ourtas funções.
*/



#include <stdio.h>
#include <string.h> // Para strspn()
#include <stdlib.h> // Para system("clear") e malloc/free

// Constantes globais
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100 // Parte 2 - definir um limite para emprestimos

// Definição da struct Livro - Parte 1 
typedef struct {
    char titulo[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int ano;
    int disponivel; // Parte 2 - campo para indicar se o livro está disponível para empréstimo (1 - disponível, 0 - emprestado)
} Livro;

//nova struct para Emprestimo - Parte 2
typedef struct {
        int idLivro; // ID do livro emprestado
        char nomeUsuario[TAM_STRING]; // Nome do usuário que fez o empréstimo
} Emprestimo;

//parte 3 - modularizacao do codigo com funcoes especializadas
// prototipos das funcoes
void limparBuffer();
void exibirMenu();
void adicionarLivro(Livro *biblioteca, int *numlivros);
void listarLivros(Livro *biblioteca, int numlivros); 
void emprestarLivro(Livro *biblioteca, Emprestimo *emprestimos, int *numEmprestimos, int numlivros);
void listarEmprestimos(Emprestimo *emprestimos, int numEmprestimos, Livro *biblioteca);
void liberarMemoria(Livro *biblioteca, Emprestimo *emprestimos);
//void esperarEnter();


// Funcao principal
/* Agora a funcao main() se torna um orquestrador, 
chamando as outras funcoes especializadas para cada 
funcionalidade do sistema, tornando o codigo mais organizado 
e facil de manter. 
Cada funcao tem uma responsabilidade clara, seja para 
adicionar livros, listar livros, emprestar livros ou listar 
emprestimos, seguindo o principio de responsabilidade unica.
*/
int main() {
    //usamos calloc para array de livros.
    Livro *biblioteca = (Livro *)calloc(MAX_LIVROS, sizeof(Livro));
    //usamos malloc para array de emprestimos.
    Emprestimo *emprestimos = (Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(Emprestimo));

    // Verificar se a alocação de memória foi bem-sucedida
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1; // Encerrar o programa com código de erro
    }

    int numlivros = 0; // Contador de livros cadastrados - Parte 1
    int numEmprestimos = 0; // Contador de empréstimos realizados - Parte 2
    int opcao;

    // Laço principal do Menu - Parte 1 e Parte 2
    do {
        // Exibir o Menu - Parte3
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer(); // Limpar o buffer de entrada

            // Processar a opção escolhida - Parte 3
            switch (opcao) {
                case 1 : // Adicionar Livro
                    adicionarLivro(biblioteca, &numlivros);
                    break;

                case 2 : // Listar Livros Disponíveis
                    listarLivros(biblioteca, numlivros);
                    break;

                case 3 : // Emprestar Livro - Parte 2
                    emprestarLivro(biblioteca, emprestimos, &numEmprestimos, numlivros);
                    break;

                case 4 : // Listar Empréstimos - Parte 2
                    listarEmprestimos(emprestimos, numEmprestimos, biblioteca);
                    break;

                case 0 : // Sair
                    printf("Saindo do sistema. Até mais!\n");
                    break;

                default : // Opção inválida
                    printf("Opção inválida. Por favor, escolha uma opção válida.\n");   
                    printf("\nPressione Enter para continuar...");
                    getchar(); // Esperar o usuário pressionar Enter
                    break;
            }
        }while (opcao !=0); // Continuar até o usuário escolher sair

    // Liberar a memória alocada - Parte 2
    liberarMemoria(biblioteca, emprestimos);

    return 0;
}

// Implementacao das funcoes especializadas - Parte 3

// Funcao para limpar buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para exibir o menu principal
void exibirMenu() {
        printf("==========================================\n");
        printf("SISTEMA DE BIBLIOTECA - MENU PRINCIPAL\n");
        printf("==========================================\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Todos os Livros\n");
        printf("3. Emprestar Livro\n"); // Parte 2 - nova opção para empréstimo
        printf("4. Listar Empréstimos\n"); // Parte 2 - nova opção para listar empréstimos
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
}

// Funcao para adicionar um livro à biblioteca
void adicionarLivro(Livro *biblioteca, int *numlivros) {
        printf("\n--- Adicionar Novo Livro ---\n\n");
            
        if (*numlivros < MAX_LIVROS) {
            int indice = *numlivros; // Índice para o próximo livro a ser adicionado

            printf("Digite o título do livro: ");
            fgets(biblioteca[indice].titulo, TAM_STRING, stdin);
            printf("Digite o autor do livro: ");
            fgets(biblioteca[indice].autor, TAM_STRING, stdin);
            printf("Digite a editora do livro: ");
            fgets(biblioteca[indice].editora, TAM_STRING, stdin);
            
            biblioteca[indice].titulo[strcspn(biblioteca[indice].titulo, "\n")] = '\0'; // Remover o \n
            biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0'; // Remover o \n
            biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0'; // Remover o \n

            printf("Digite o ano de publicação: ");
            scanf("%d", &biblioteca[indice].ano);
            limparBuffer(); // Limpar o buffer de entrada

            //Ao cadastrar o livro, definimos o campo 'disponivel' como 1 (disponível) para indicar que o livro está disponível para empréstimo.
            biblioteca[indice].disponivel = 1; 

            (*numlivros)++; // Incrementar o contador de livros
            printf("Livro adicionado com sucesso!\n");
            } else {
                printf("Capacidade máxima de livros atingida. Não é possível adicionar mais livros.\n");
                }
            printf("\nPressione Enter para continuar...");  
            getchar(); // Esperar o usuário pressionar Enter
}

// Funcao para listar os livros disponíveis na biblioteca
void listarLivros(Livro *biblioteca, int numlivros) {
        printf("\n--- Livros Disponíveis ---\n");

        if (numlivros > 0) {
            for (int i = 0; i < numlivros; i++) {
                printf("Título: %s\n", biblioteca[i].titulo);
                printf("Autor: %s\n", biblioteca[i].autor);
                printf("Editora: %s\n", biblioteca[i].editora);
                printf("Ano: %d\n", biblioteca[i].ano);
                //Mostrar o status de disponibilidade do livro
                printf("Status: %s\n", biblioteca[i].disponivel ? "Disponível" : "Emprestado");
                printf("-----------------------------------\n");
                }
            } else {
                printf("Nenhum livro disponível no momento.\n");
            }
            printf("\nPressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter
}

// Funcao para emprestar um livro - Parte 2
void emprestarLivro(Livro *biblioteca, Emprestimo *emprestimos, int *numEmprestimos, int numlivros) {
        printf("\n--- Emprestar Livro ---\n");
                
        if (*numEmprestimos >= MAX_EMPRESTIMOS) {
                printf("Limite de empréstimos atingido!\n");
            } else {
                printf("Livros disponíveis para empréstimo:\n");
                int disponiveis = 0;
                for (int i = 0; i < numlivros; i++) {
                    if (biblioteca[i].disponivel) {
                        printf("%d. %s\n", i + 1, biblioteca[i].titulo);
                        disponiveis++;
                    }
                }
                if (disponiveis == 0) {
                    printf("Nenhum livro disponivel para emprestimo.\n");
                } else {
                        printf("Digite o número do livro que deseja emprestar: ");
                        int escolha;
                        scanf("%d", &escolha);
                        limparBuffer(); // Limpar o buffer de entrada

                        int indice  = escolha - 1; // Ajustar para índice do array   

                        //Validacao da escolha do livro
                        if (indice >= 0 && indice < numlivros && biblioteca[indice].disponivel) {
                            printf("Digite o nome do usuário que fará o empréstimo: ");
                            fgets(emprestimos[*numEmprestimos].nomeUsuario, TAM_STRING, stdin);
                            emprestimos[*numEmprestimos].nomeUsuario[strcspn(emprestimos[*numEmprestimos].nomeUsuario, "\n")] = '\0'; // Remover o \n
                            
                            emprestimos[*numEmprestimos].idLivro = indice; // Armazenar o ID do livro emprestado
                            biblioteca[indice].disponivel = 0; //Marcar o livro como emprestado

                            (*numEmprestimos)++; // Incrementar o contador de empréstimos
                            printf("Empréstimo realizado com sucesso!\n");
                        } else {
                            printf("Escolha inválida ou livro não disponível para empréstimo.\n");
                        }

                }
            }
            
            printf("\nPressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter
}

// Funcao para listar os empréstimos realizados - Parte 2
void listarEmprestimos(Emprestimo *emprestimos, int numEmprestimos, Livro *biblioteca) {
    printf("\n--- Empréstimos Realizados ---\n");
    if (numEmprestimos > 0) {
        for (int i = 0; i < numEmprestimos; i++) {
            int idLivro = emprestimos[i].idLivro;
                        printf("Usuário: %s | Livro: %s\n", emprestimos[i].nomeUsuario, biblioteca[idLivro].titulo);
            }
        } else {
            printf("Nenhum empréstimo realizado até o momento.\n");
            }
            printf("\nPressione Enter para continuar...");
            getchar(); // Esperar o usuário pressionar Enter    
}

// Funcao para liberar a memória alocada - Parte 2
void liberarMemoria(Livro *biblioteca, Emprestimo *emprestimos) {
    free(biblioteca); // Liberar a memória alocada para os livros
    free(emprestimos); // Liberar a memória alocada para os empréstimos
}


       





