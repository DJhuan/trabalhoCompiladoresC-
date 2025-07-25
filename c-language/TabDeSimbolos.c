#include "TabDeSimbolos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

// Variáveis globais para controle da tabela e endereços
static int endereco_atual = 0;
char *tipoStructVar = "";

// Garda o número variáveis temporárias criadas;
static int cont_temporarias = 0;

// Nome do arquivo de saída (pode alterar se quiser)
FILE *c3eFileStream = NULL;
const char *TDS_saida_filename = "c3e_output";

// Retorna uma string com nome de temporaria;
char *new_nomeTemporaria()
{
    char *t_name = malloc(20);
    if (!t_name)
    {
        perror("Falha ao alocar nome de temporária");
        return NULL;
    }
    snprintf(t_name, 20, "t%d", cont_temporarias++);
    return t_name;
}

// Função hash djb2 para mapear lexemas em índices
static unsigned int get_hash(const char *key)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;
    return hash % MAX_ENTRADAS;
}

// Converte TipoDado para string legível
const char *tipo_para_string(TipoDado tipo, EntradaTDS *ent)
{
    switch (tipo)
    {
    case TIPO_INT:
        return "INT";
    case TIPO_FLOAT:
        return "FLOAT";
    case TIPO_CHAR:
        return "CHAR";
    case TIPO_STRUCT_DEF:
        return ent->nomeStruct;
    default:
        return "???";
    }
}

// Retorna tamanho em bytes do tipo (pode ajustar se precisar)
static int tamanho_tipo(TipoDado tipo)
{
    switch (tipo)
    {
    case TIPO_INT:
        return 4;
    case TIPO_FLOAT:
        return 8;
    case TIPO_CHAR:
        return 1;
    case TIPO_STRUCT:
        return 1;
    default:
        return 0;
    }
}

// Cria uma nova tabela de símbolos
TabDeSimbolos *new_TabDeSimbolos()
{
    TabDeSimbolos *tds = (TabDeSimbolos *)malloc(sizeof(TabDeSimbolos));
    if (!tds)
    {
        perror("Falha ao alocar TabDeSimbolos");
        return NULL;
    }

    for (int i = 0; i < MAX_ENTRADAS; i++)
        tds->tabela[i] = NULL;

    tds->anterior = NULL; // Será definido ao empilhar
    return tds;
}

// Apaga uma tabela de símbolos e libera memória
void delete_TabDeSimbolos(TabDeSimbolos *tds)
{
    if (!tds)
        return;

    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        EntradaTDS *ent = tds->tabela[i];
        while (ent)
        {
            EntradaTDS *temp = ent;
            ent = ent->proximo;
            free(temp->lexema);
            free(temp);
        }
    }

    free(tds);
}

// Função interna para buscar símbolo na tabela atual
static EntradaTDS *TDS_buscarSimboloInterno(const char *lexema)
{
    TabDeSimbolos *atual = TDS_topo();
    if (!atual)
        return NULL;

    unsigned int i = get_hash(lexema);
    EntradaTDS *entrada = atual->tabela[i];
    while (entrada)
    {
        if (strcmp(entrada->lexema, lexema) == 0)
            return entrada;
        entrada = entrada->proximo;
    }
    return NULL;
}
// Pilha de escopos (topo da pilha)
static TabDeSimbolos *topo_pilha = NULL;

// Empilha uma nova tabela de símbolos
void TDS_empilhar(TabDeSimbolos *nova)
{
    nova->anterior = topo_pilha;
    topo_pilha = nova;
}

// Remove o escopo atual
void TDS_desempilhar()
{
    if (topo_pilha != NULL)
    {
        TabDeSimbolos *temp = topo_pilha;
        topo_pilha = topo_pilha->anterior;
        delete_TabDeSimbolos(temp);
    }
}

void tipoStruct(char *nome, TipoDado tipo)
{
    if (tipo == TIPO_STRUCT_DEF)
    {
        tipoStructVar = nome;
    }
}

// Acessa o topo da pilha (escopo atual)
TabDeSimbolos *TDS_topo()
{
    return topo_pilha;
}

// Ao inserir símbolo, use o topo
EntradaTDS *TDS_novoSimbolo(const char *lexema, TipoDado tipo, int multiplicador)
{
    TabDeSimbolos *atual = TDS_topo();
    if (!atual)
        return NULL;

    // Verifica se o símbolo já existe no escopo atual
    if (TDS_buscarSimboloInterno(lexema))
    {
        fprintf(stderr, "Erro semântico: símbolo '%s' já declarado neste escopo\n", lexema);
        return NULL;
    }

    // Criação do novo símbolo
    EntradaTDS *nova = malloc(sizeof(EntradaTDS));
    if (!nova)
    {
        perror("Falha ao alocar entrada da tabela");
        return NULL;
    }

    nova->lexema = strdup(lexema);
    nova->tipo = tipo;

    if (strcmp(tipoStructVar, "") != 0)
    {
        nova->nomeStruct = strdup(tipoStructVar);
        tipoStructVar = "";
    }

    // Endereço sequencial global
    nova->endereco = endereco_atual;
    endereco_atual += tamanho_tipo(tipo) * multiplicador > 0 ? tamanho_tipo(tipo) * multiplicador : 1;

    // Inserção na tabela (hash por djb2)
    int hash = get_hash(lexema);
    nova->proximo = atual->tabela[hash];
    atual->tabela[hash] = nova;

    return nova;
}

// Busca percorre todos os escopos
EntradaTDS *TDS_encontrarSimbolo(const char *lexema)
{
    TabDeSimbolos *atual = topo_pilha;
    while (atual != NULL)
    {
        int hash = get_hash(lexema);
        EntradaTDS *e = atual->tabela[hash];
        while (e != NULL)
        {
            if (strcmp(e->lexema, lexema) == 0)
            {
                return e;
            }
            e = e->proximo;
        }
        atual = atual->anterior; // sobe para o escopo anterior
    }
    return NULL;
}

void TDS_imprimirEntrada(const EntradaTDS *ent)
{
    if (!ent)
        return;
    printf("\x1b[33mNome: %-15s Tipo: %-7s Endereço: %d\n\x1b[0m",
           ent->lexema, tipo_para_string(ent->tipo, (EntradaTDS *)ent), ent->endereco);
}

void TDS_imprimir(const TabDeSimbolos *tds, const char *tipoTab)
{
    printf("\x1b[33m=== Tabela de Símbolos (%s) ===\n", tipoTab);
    for (int i = 0; i < MAX_ENTRADAS; i++)
    {
        EntradaTDS *ent = tds->tabela[i];
        while (ent)
        {
            TDS_imprimirEntrada(ent);
            ent = ent->proximo;
        }
    }
    printf("==========================\n\x1b[0m");
}

TipoDado *max_type(TipoDado t, TipoDado w)
{
    // Se os tipos são iguais, retorna qualquer um deles
    if (t == w)
    {
        TipoDado *resultado = malloc(sizeof(TipoDado));
        *resultado = t;
        return resultado;
    }

    // Se qualquer um for VOID, retorna o outro
    if (t == TIPO_VOID)
    {
        TipoDado *resultado = malloc(sizeof(TipoDado));
        *resultado = w;
        return resultado;
    }
    if (w == TIPO_VOID)
    {
        TipoDado *resultado = malloc(sizeof(TipoDado));
        *resultado = t;
        return resultado;
    }

    // Structs não podem ser comparados com outros tipos
    if (t == TIPO_STRUCT || w == TIPO_STRUCT ||
        t == TIPO_STRUCT_DEF || w == TIPO_STRUCT_DEF)
    {
        return NULL; // Tipos incompatíveis
    }

    // Hierarquia de tipos: CHAR < INT < FLOAT
    TipoDado maior;

    if (t == TIPO_FLOAT || w == TIPO_FLOAT)
    {
        maior = TIPO_FLOAT;
    }
    else if (t == TIPO_INT || w == TIPO_INT)
    {
        maior = TIPO_INT;
    }
    else
    {
        maior = TIPO_CHAR;
    }

    TipoDado *resultado = malloc(sizeof(TipoDado));
    *resultado = maior;
    return resultado;
}

void c3e_init(const char *filename)
{
    if (filename)
    {
        TDS_saida_filename = filename;
    }

    c3eFileStream = fopen(TDS_saida_filename, "w");
    if (!c3eFileStream)
    {
        perror("Erro ao abrir arquivo de saída para código 3 endereços.");
        return;
    }
}

void c3e_gen(const char *s)
{
    if (!c3eFileStream)
    {
        fprintf(stderr, "Erro: arquivo de saída não inicializado.\n");
        return;
    }

    if (s == NULL)
        return; // Sem string, sem impressão;

    fprintf(c3eFileStream, "%s\n", s);
}

void c3e_close()
{
    if (c3eFileStream)
    {
        fclose(c3eFileStream);
        c3eFileStream = NULL;
    }
}

/*
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
}*/

// Imprime a tabela de símbolos na saída padrão
