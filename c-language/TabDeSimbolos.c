#include "TabDeSimbolos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Variáveis globais para controle da tabela e endereços
static int endereco_atual = 0;
static TabDeSimbolos *tabela_atual = NULL;

// Nome do arquivo de saída (pode alterar se quiser)
static const char TDS_saida_filename[] = "TabelasDeSimbolos.txt";

// Função hash djb2 para mapear lexemas em índices
static unsigned int get_hash(const char *key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;
    return hash % MAX_ENTRADAS;
}

// Converte TipoDado para string legível
const char *tipo_para_string(TipoDado tipo) {
    switch (tipo) {
        case TIPO_INT: return "INT";
        case TIPO_FLOAT: return "FLOAT";
        case TIPO_CHAR: return "CHAR";
        case TIPO_STRUCT: return "STRUCT";
        default: return "???";
    }
}

// Retorna tamanho em bytes do tipo (pode ajustar se precisar)
static int tamanho_tipo(TipoDado tipo) {
    switch (tipo) {
        case TIPO_INT: return 4;
        case TIPO_FLOAT: return 4;
        case TIPO_CHAR: return 1;
        case TIPO_STRUCT: return 0; 
        default: return 0;
    }
}

// Cria uma nova tabela de símbolos
TabDeSimbolos *new_TabDeSimbolos() {
    TabDeSimbolos *tds = (TabDeSimbolos *)malloc(sizeof(TabDeSimbolos));
    if (!tds) {
        perror("Falha ao alocar TabDeSimbolos");
        return NULL;
    }

    for (int i = 0; i < MAX_ENTRADAS; i++)
        tds->tabela[i] = NULL;

    tds->anterior = tabela_atual; // Guarda tabela anterior para escopos
    tabela_atual = tds;            // Atualiza para nova tabela
    endereco_atual = 0;            // Reinicia endereçamento
    return tds;
}

// Apaga a tabela atual e libera memória
void delete_TabDeSimbolos() {
    if (!tabela_atual) return;

    for (int i = 0; i < MAX_ENTRADAS; i++) {
        EntradaTDS *ent = tabela_atual->tabela[i];
        while (ent) {
            EntradaTDS *temp = ent;
            ent = ent->proximo;
            free(temp->lexema);
            free(temp);
        }
    }

    TabDeSimbolos *temp = tabela_atual;
    tabela_atual = tabela_atual->anterior;
    free(temp);
}

// Função interna para buscar símbolo na tabela atual
static EntradaTDS *TDS_buscarSimboloInterno(const char *lexema) {
    unsigned int i = get_hash(lexema);
    EntradaTDS *atual = tabela_atual->tabela[i];
    while (atual) {
        if (strcmp(atual->lexema, lexema) == 0)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

// Insere novo símbolo na tabela atual, retorna ponteiro para ele ou NULL se erro
EntradaTDS *TDS_novoSimbolo(const char *lexema, TipoDado tipo) {
    if (TDS_buscarSimboloInterno(lexema)) {
        fprintf(stderr, "Erro semântico: símbolo '%s' já declarado\n", lexema);
        return NULL;
    }

    EntradaTDS *nova = malloc(sizeof(EntradaTDS));
    if (!nova) {
        perror("Falha ao alocar entrada da tabela");
        return NULL;
    }

    nova->lexema = strdup(lexema);
    nova->tipo = tipo;
    nova->endereco = endereco_atual;
    endereco_atual += tamanho_tipo(tipo) > 0 ? tamanho_tipo(tipo) : 1;

    unsigned int i = get_hash(lexema);
    nova->proximo = tabela_atual->tabela[i];
    tabela_atual->tabela[i] = nova;

    return nova;
}

// Busca símbolo na tabela atual pelo lexema
EntradaTDS *TDS_encontrarSimbolo(const char *lexema) {
    return TDS_buscarSimboloInterno(lexema);
}

// Imprime a tabela de símbolos na saída padrão
void TDS_imprimir(const TabDeSimbolos *tds) {
    printf("=== Tabela de Símbolos ===\n");
    for (int i = 0; i < MAX_ENTRADAS; i++) {
        EntradaTDS *ent = tds->tabela[i];
        while (ent) {
            printf("Nome: %-15s Tipo: %-7s Endereço: %d\n",
                   ent->lexema, tipo_para_string(ent->tipo), ent->endereco);
            ent = ent->proximo;
        }
    }
    printf("==========================\n");
}
