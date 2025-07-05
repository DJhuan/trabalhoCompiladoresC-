#ifndef SYMTABLE
#define SYMTABLE

#include <stdio.h>

#define MAX_ENTRADAS 127

// Define os tipos de dados possíveis
typedef enum {
    TIPO_FLOAT,
    TIPO_INT,
    TIPO_CHAR,
    TIPO_STRUCT,
    TIPO_VOID,
    TIPO_STRUCT_DEF 
} TipoDado;

typedef struct EntradaTDS EntradaTDS;
typedef struct TabDeSimbolos TabDeSimbolos;

struct EntradaTDS
{ // Define uma entrada na tabela de símbolos;
    char *lexema;
    TipoDado tipo;
    int endereco;
    EntradaTDS *proximo; // Próxima entrada na lista da tabela (para colisões)
    struct TabDeSimbolos *tabela_campos;
    char *nomeStruct;
};


struct TabDeSimbolos
{ // Define a tabela de símbolos;
    EntradaTDS *tabela[MAX_ENTRADAS];
    TabDeSimbolos *anterior; // Tabela anterior (para escopos aninhados)
};

// Protótipos das funções públicas:
const char* tipo_para_string(TipoDado tipo, EntradaTDS *ent);
void tipoStruct(char* nome, TipoDado tipo);
TabDeSimbolos* new_TabDeSimbolos();
void delete_TabDeSimbolos();
EntradaTDS* TDS_novoSimbolo(const char* lexema, TipoDado tipo);
EntradaTDS* TDS_encontrarSimbolo(const char* lexema);
void TDS_imprimir(const TabDeSimbolos* tds,const char* tipoTab);
// Pilha de escopos
void TDS_empilhar(TabDeSimbolos *nova);
void TDS_desempilhar();
TabDeSimbolos* TDS_topo();
#endif // SYMTABLE
