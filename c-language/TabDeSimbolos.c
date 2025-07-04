#include "TabDeSimbolos.h"
#include <stdlib.h>
#include <string.h>

// Marca o último endereço de memória utilizado;
static int endereco_atual = 0;
static TabDeSimbolos *tabela_atual = NULL;

static char TDS_saida_filename[] = "TabelasDeSimbolos.txt";

// Gera um hash para alocar entradas na tabela de símbolos;
// Na prática é uma função de hash simples que usa o algoritmo djb2;
static unsigned int get_hash(const char *key)
{
    unsigned long hash_value = 5381;
    int c;
    // Enquanto houver caracteres na chave, calcula o hash;
    while ((c = *key++))
    {
        // hash * 33 + c
        hash_value = ((hash_value << 5) + hash_value) + c;
    }
    return hash_value % MAX_ENTRADAS;
}

const char *tipo_para_string(TipoDado tipo)
{
    switch (tipo)
    {
    case INT:
        return "INT";
    case FLOAT:
        return "FLOATt";
    case CHAR:
        return "CHAR";
    case STRUCT:
        return "STRUCT";
    default:
        return "??????";
    }
}

// Retorna uma nova tabela de símbolos;
TabDeSimbolos *new_TabDeSimbolos()
{
    // Aloca memória para a estrutura da tabela
    TabDeSimbolos *tds = (TabDeSimbolos *)malloc(sizeof(TabDeSimbolos));
    if (tds == NULL)
    {
        perror("Falha ao alocar memória para TabDeSimbolos");
        return NULL;
    }

    // Incilmente, todas as posições sao vazias;
    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        tds->tabela[i] = NULL;
    }

    tds->anterior = tabela_atual; // Marca a tabela anterior;
    tabela_atual = tds;           // Atualiza a tabela atual;

    return tds;
}

// Deleta uma tabela de símbolos;
void delete_TabDeSimbolos()
{
    TabDeSimbolos *tds = tabela_atual;
    tabela_atual = tds->anterior; // Restaura a tabela anterior;

    if (tds == NULL)
        return;

    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        EntradaTDS *entradaAtual = tds->tabela[i];

        // Libera nós e colisões;
        while (entradaAtual != NULL)
        {
            EntradaTDS *temp = entradaAtual;
            entradaAtual = entradaAtual->proximo;

            free(temp->lexema);

            free(temp);
        }
    }

    // Destrói a tabela de símbolos;
    free(tds);
    tds = NULL;
}

#warning "Implementar uma função de busca para ser usada internamente pelas nossas classes com intuito de evitar a duplicação de código.";

// Insere um novo símbolo na tabela de símbolos;
EntradaTDS *TDS_novoSimbolo(const char *lexema, TipoDado tipo)
{
    // Encontra a posição do ssímbolo;
    unsigned int i = get_hash(lexema);

    // Caso o símbolo já esteja presente, evita a redeclaração;
    EntradaTDS *atual = tabela_atual->tabela[i];
    while (atual != NULL)
    {
        if (strcmp(atual->lexema, lexema) == 0)
        {
#warning "Erro semântico: Símbolo já declarado";
            return atual;
        }
        atual = atual->proximo;
    }

// Símbolo não encontrado, criamos uma nova entrada;
#warning "Convém chamar a função para encontrar simbolo ao invés de criar uma nova entrada, para evitar duplicação.";
    EntradaTDS *novaEntrada = (EntradaTDS *)malloc(sizeof(EntradaTDS));
    if (novaEntrada == NULL)
    {
        perror("Falha ao alocar memória para Entrada da tabela de símbolos.");
        return NULL;
    }

    // Configura o novo símbolo inserido;
    novaEntrada->lexema = strdup(lexema);
    novaEntrada->tipo = tipo;
#warning "Endereço de memória não está sendo calculado corretamente, deve ser ajustado para o tipo de dado correto.";
    novaEntrada->endereco = endereco_atual++;

    novaEntrada->proximo = tabela_atual->tabela[i];
    tabela_atual->tabela[i] = novaEntrada;

    return novaEntrada;
}

// Encontra um símbolo na tabela de símbolos pelo nome;
EntradaTDS *TDS_encontrarSimbolo(const char *lexema)
{
    unsigned int i = get_hash(lexema);
    EntradaTDS *atual = tabela_atual->tabela[i];

    while (atual != NULL)
    {
        if (strcmp(atual->lexema, lexema) == 0)
        {
            return atual; // Encontramos o símbolo;
        }
        atual = atual->proximo;
    }

    return NULL; // Nada feito, feijoada;
}

// Imprime a tabela de símbolos;
void TDS_imprimir(const TabDeSimbolos *tds)
{
    FILE *saida = fopen(TDS_saida_filename, "a");
    if (saida == NULL)
    {
        perror("Nao foi possivel abrir o arquivo de saida para a tabela de simbolos");
        return;
    }

    fprintf(saida, "\n--- Tabelas de símbolos ---\n");
    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        EntradaTDS *atual = tds->tabela[i];
        if (atual != NULL)
        {
            fprintf(saida, "Entrada[%3d]:\n", i);
            while (atual != NULL)
            {
                // Formata tudo bonitinho;
                fprintf(saida, "  -> { Nome: %-15s, Tipo: %-10s, Endr: %d }\n",
                        atual->lexema, tipo_para_string(atual->tipo), atual->endereco);
                atual = atual->proximo;
            }
        }
    }
    fprintf(saida, "-------------------------------------\n");

    fclose(saida);
}