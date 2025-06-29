#include "TabDeSimbolos.h"
#include <stdlib.h>

TabDeSimbolos* new_TabDeSimbolos(const char* nome_inicial) {
    TabDeSimbolos* nova_tab = (TabDeSimbolos*) malloc(sizeof(TabDeSimbolos));

    if (nova_tab == NULL) {
        perror("Falha ao alocar memória para TabDeSimbolos");
        return NULL;
    }

    strncpy(nova_tab->nome, nome_inicial, sizeof(nova_tab->nome) - 1);
    nova_tab->nome[sizeof(nova_tab->nome) - 1] = '\0';

    return nova_tab;
}

void del_TabDeSimbolos(TabDeSimbolos* tab) {
    if (tab != NULL) {
        free(tab);
    }
}

void printNome(const TabDeSimbolos *tab)
{
    printf("%s\n", tab->nome);
}