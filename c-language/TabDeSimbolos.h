#ifndef SYMTABLE
#define SYMTABLE

#include <stdio.h>

#define MAX_ENTRADAS 127

typedef enum
{ // Define os tipos de dados possíveis;
    FLOAT,
    INT,
    CHAR,
    STRUCT
} TipoDado;

typedef struct EntradaTDS EntradaTDS;

struct EntradaTDS
{ // Define uma entrada na tabela de símbolos;
    char *lexema;
    TipoDado tipo;
    int endereco;
    EntradaTDS *proximo; // Marca quem é a próxima entrada da tabela;
};

typedef struct TabDeSimbolos TabDeSimbolos;

struct TabDeSimbolos
{ // Define a tabela de símbolos;
    EntradaTDS *tabela[MAX_ENTRADAS];
    TabDeSimbolos *anterior;
};

// Retorna uma nova tabela de símbolos;
TabDeSimbolos *new_TabDeSimbolos();

// Deleta uma tabela de símbolos;
void delete_TabDeSimbolos();

// Insere um novo símbolo na tabela de símbolos;
EntradaTDS *TDS_novoSimbolo(const char *lexema, TipoDado tipo);

// Encontra um símbolo na tabela de símbolos pelo nome;
EntradaTDS *TDS_encontrarSimbolo(const char *lexema);

// Imprime a tabela de símbolos;
void TDS_imprimir(const TabDeSimbolos *tds);

#endif // TabDeSimbolos