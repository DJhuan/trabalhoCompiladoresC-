#ifndef SYMTABLE
#define SYMTABLE

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[10];
} TabDeSimbolos;

TabDeSimbolos* new_TabDeSimbolos(const char* nome_inicial);

void del_TabDeSimbolos(TabDeSimbolos* tab);

void printNome(const TabDeSimbolos *tab);

#endif // TabDeSimbolos