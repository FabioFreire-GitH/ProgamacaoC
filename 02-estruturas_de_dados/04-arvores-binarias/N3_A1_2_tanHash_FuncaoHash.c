// Tabela Hash
// Associação chave-valor e funções hash
// Função hash básica: soma dos caracteres e uso de módulo



int hash_simples(const char* str, int tamanho_tabela) {
        int soma = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            soma += str[i];
    }
    return soma % tamanho_tabela;
}

int hash_ponderado(const char* str, int tamanho_tabela) {
        int hash = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            hash += str[i] * (i + 1);
    }
    return hash % tamanho_tabela;
}

