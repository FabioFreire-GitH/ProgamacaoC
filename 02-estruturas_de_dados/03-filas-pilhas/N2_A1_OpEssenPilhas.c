/*
LIFO - PILHAS
Ultimo a entrar é o primeiro a sair.

Principais Funções que compoe a pilha são:
    - Inserir (push);
    - Remover (pop);
    - Cosultar o topo (peek);
    - Liberar (free)

//Adiciona um novo elemento no topo da pilha
void push(Pilha *p, Elemento e) {
    if (pilhaCheia(p)) {
        printf("Erro: pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;              // Avança o topo
    p->itens[p->topo] = e;  // Insere o novo elemento
}

//Remevo o elemento do topo da pilha.
void pop(Pilha *p, Elemento *e) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há elementos para remover.\n");
        e->valor = -1;  // Define um valor padrão para indicar falha
        return;
    }

    *e = p->itens[p->topo];  // Copia o valor do topo
    p->topo--;               // Decrementa o topo
}

//Consultar o elemento do topo da pilha.
void peek(Pilha *p, Elemento *e) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há elementos no topo.\n");
        e->valor = -1;  // Valor padrão para indicar erro
        return;
    }

    *e = p->itens[p->topo];  // Copia o elemento do topo sem alterar a pilha
}

// Esvazia a pilha: reinicia o topo
void liberarPilha(Pilha *p) {
    p->topo = -1;  // Define a pilha como vazia novamente
}

// Libera todos os nós da pilha dinâmica
void liberarPilha(Pilha *p) {
    while (p->topo != NULL) {
        No *remover = p->topo;
        p->topo = p->topo->prox;
        free(remover);  // Libera a memória alocada
    }
}



*/