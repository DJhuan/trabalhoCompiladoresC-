%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

/* Tokens esperados do analisador léxico */
%token ID
%token INT FLOAT CHAR
%token IF ELSE WHILE RETURN
%token SOMA 
%token MULT
%token EQ
%token RELOP
%token SEMICOLON COLON
%token OCB CCB OP CP OB CB
%token NUM_INT NUM_FLOAT
%token CHARACTER
%token STRUCT 
%token VOID

%%

programa    :   decl_lista
                ;

decl_lista   :  decl decl_lista 
                |decl
                ;

decl    :   var_decl
            |func_decl
            ;

var_decl    :   tipo_especificador ID SEMICOLON
                |tipo_especificador ID dimen_matriz SEMICOLON
                ;

dimen_matriz    :   OB NUM_INT CB | OB NUM_INT CB dimen_matriz
                    ;

tipo_especificador  :   INT
                        |FLOAT
                        |CHAR
                        |VOID
                        |STRUCT ID OCB atributos_decl CCB 
                        ;

atributos_decl  :   var_decl
                    |var_decl atributos_decl
                    ;

func_decl   :   tipo_especificador ID OP params CP composto_decl
                ;


params  :   params_lista
            |VOID
            ;

params_lista    :   param
                    |param COLON params_lista
                    ;

param   :   tipo_especificador ID 
            |tipo_especificador ID OB CB
            ;

composto_decl   :   OCB local_decl comando_lista CCB 
                    ;

local_decl  :   var_decl
                |
                ;

comando_lista   :   comando
                    |
                    ;

comando     :   expressao_decl
                |composto_decl
                |selecao_decl
                |iteracao_decl
                |retorno_decl
                ;

expressao_decl  :   expressao SEMICOLON
                    |SEMICOLON
                    ;

selecao_decl    :   IF OP expressao CP comando
                    |IF OP expressao CP comando ELSE comando 
                    ;

iteracao_decl   :   WHILE OP expressao CP comando
                    ;

retorno_decl    :   RETURN SEMICOLON 
                    | RETURN expressao SEMICOLON
                    ;

expressao   :   var EQ expressao 
                |expressao_simples
                ;

var    :    ID
            |ID var_aux
            ;

var_aux :   OB expressao CB
            |OB expressao CB var_aux
            ;

expressao_simples   :   expressao_soma RELOP expressao_soma 
                        |expressao_soma
                        ;

expressao_soma  :   termo 
                    |termo expressao_somatorio
                    ;

expressao_somatorio :   SOMA termo 
                        | SOMA termo expressao_somatorio
                        ;

termo   :   fator 
            | fator termo_aux
            ;

termo_aux   :   MULT fator 
                |MULT fator termo_aux
                ;

fator   :   OP expressao CP 
            |var
            |ativacao
            |NUM_FLOAT
            |NUM_INT
            ;

ativacao    :   ID OP args CP       
                ;

args    :   arg_list
            |
            ;

arg_list   :    expressao
                |expressao arg_list_aux
                ;


arg_list_aux    :   COLON expressao
                    |
                    ;


%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}

int main(void) {
    return yyparse();
}
