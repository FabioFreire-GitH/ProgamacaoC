// Operaçoes essenciais em filas
//First In First Out e Last In Last Out
//Inserir, retirar e verificar
/*
//Inserir(enqueue)
void inserir(Fila *f, Elemento e) {
    if (filaCheia(f)) // Impede inserção se estiver cheia - Apontando para uma função
        return;
    f->itens[f->fim] = e;            // Insere no final
    f->fim = (f->fim + 1) % MAX;     // Atualiza circularmente o índice
    f->total++;                      // Incrementa a contagem de elementos
}

//Remover(dequeue)
//Remover um item da fila, significa eliminar o primeiro elemento inserido(FiFo)
Elemento retirar(Fila *f) {
    Elemento vazio = {-1};               // Valor padrão caso a fila esteja vazia
    if (filaVazia(f)) 
        return vazio;      // Evita remoção se estiver vazia
    Elemento e = f->itens[f->inicio];    // Armazena o item a ser removido
    f->inicio = (f->inicio + 1) % MAX;   // Atualiza o índice de início
    f->total--;                          // Diminui o total
    return e;                            // Retorna o item removido
}
*/