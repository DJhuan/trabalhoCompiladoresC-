%code requires {
    #include "TabDeSimbolos.h"
}

%{
#include <stdio.h>
#include <stdlib.h>
#include "TabDeSimbolos.h"

// Informações usadas pelo Bison que vem do Flex:
extern int line_number; // Número da linha do erro léxico;
extern int column_number; // Número de coluna do erro léxico;
extern int errors_count; // Contador de erros léxicos;
extern int yylex(); // Retorna os tokens para o parser;
extern int yyparse(); // Função principal para iniciar a análise léxica;
extern FILE *yyin; // Indica que a entrada do analisador léxico é um arquivo;

// Informações usadas na análise sintática:
int syntax_error_occurred = 0; // Contador de erro sintático;
void yyerror(const char *s); // Definição da função de erro (somente para o Bison não reclamar);
void print_error(const char *msg); // Nossa função de erro;
%}

%union {
    char *identifier;       // para armazenar lexemas (ID)
    TipoDado tipo;   // para tipos
    struct TabDeSimbolos* tds; // Novo campo!
}
// Tokens de tipos de dados, palavras-chave, operadores e símbolos
// Tokens com tipo
%token <identifier> ID
%token INT FLOAT CHAR VOID STRUCT
%token IF ELSE WHILE RETURN
%token SOMA 
%token MULT
%token EQ
%token RELOP
%token SEMICOLON COMMA
%token OCB CCB OP CP OB CB
%token NUM_INT NUM_FLOAT
%token CHARACTER

// Não-terminais com tipo
%type <tipo> tipo_especificador
%type <tds> composto_decl

// Precedência 
%left SOMA
%left MULT
%right EQ
%left RELOP
%%

// Programa principal: composto por uma lista de declarações
programa    :   decl_lista
                ;

// Declarações
decl_lista   :  decl decl_lista
                |decl
                |error decl_lista { print_error("Error in declaration list."); yyerrok; }
                ;

// Declaração: variável ou função
decl    :   var_decl
            |func_decl
            |error SEMICOLON { print_error("Invalid declaration."); yyerrok; }
            ;

// Declaração de variável: variável simples ou matriz
// trata o erro de identificador ausente
var_decl    :   tipo_especificador ID SEMICOLON {
                printf("Inserindo id %s do tipo %d\n", $2, $1);
                    TDS_novoSimbolo($2, $1); 
                }
                |tipo_especificador ID dimen_matriz SEMICOLON {
                printf("Inserindo id %s do tipo %d\n", $2, $1);
                    TDS_novoSimbolo($2, $1);
                } 
                ;

// Dimensão de matriz: unica ou múltipla
dimen_matriz    :   OB NUM_INT CB
                    | OB NUM_INT CB dimen_matriz
                    ;

// Tipos de dados
tipo_especificador: INT    { $$ = TIPO_INT; }
                    |FLOAT  { $$ = TIPO_FLOAT; }
                    |CHAR   { $$ = TIPO_CHAR; }
                    |VOID   { $$ = TIPO_VOID; }
                    |STRUCT ID OCB {
                        // Cria nova tabela para campos da struct e empilha
                        
                        TabDeSimbolos *escopo_struct = new_TabDeSimbolos();
                        TDS_empilhar(escopo_struct);
                    }
                    atributos_decl CCB {
                        // Após processar campos, imprime e desempilha
                        TDS_imprimir(TDS_topo(), "Campos da Struct");
                        TDS_desempilhar();

                        tipoStruct($2, TIPO_STRUCT_DEF);
                        $$ = TIPO_STRUCT_DEF;
                    }
                    ;

// Atributos de struct
atributos_decl  :   var_decl
                    |var_decl atributos_decl
                    ;

// Declaração de função: tipo, id, parâmetros e corpo
func_decl   :   tipo_especificador ID OP params CP composto_decl{
                    TDS_novoSimbolo($2, $1);
                }   
                ;

// Função com ou sem parâmetros
params  :   params_lista
            |VOID
            | error {print_error("Parâmetro inválido."); yyerrok;}
            ;

// Parâmetros
params_lista    :   param
                    |param COMMA params_lista
                    |param error COMMA params_lista { print_error("Invalid parameter. Skipping."); yyerrok; }
                    ;

// Parâmetros simples ou vetoriais
param   :   tipo_especificador ID {
                printf("Inserindo id %s do tipo %d\n", $2, $1);
                TDS_novoSimbolo($2, $1);
            }
            |tipo_especificador ID OB CB{
                printf("Inserindo id %s do tipo %d\n", $2, $1);
                TDS_novoSimbolo($2, $1);
            }
           // |tipo_especificador error {print_error("Wrong parameter"); yyerrok;} 
            |tipo_especificador ID error CB {print_error("Missing open bracket: '['"); yyerrok;} 
            ;

// Corpo da função: declarações locais e comandos
composto_decl : OCB {
                    TabDeSimbolos *nova = new_TabDeSimbolos();
                    TDS_empilhar(nova);
                }
                local_decl comando_lista CCB {
                    TDS_imprimir(TDS_topo(), "De Escopo"); // imprime antes de destruir
                    TDS_desempilhar();       // sai do escopo
                }
                ;

// Declarações locais
local_decl  :   var_decl local_decl
                | /* vazio */
                ;

// Lista de comandos
comando_lista   :   comando comando_lista
                    | /* vazio */
                    ;

// Distingue if-else casado e não casado
comando :   comando_casado
            |comando_singular
            | error SEMICOLON { print_error("Invalid command."); yyerrok; }
            ;

// Neste caso, TODO IF está associado com um ELSE;
comando_casado  :   expressao_decl
                    |composto_decl
                    |iteracao_decl
                    |retorno_decl
                    |IF OP expressao CP comando_casado ELSE comando_casado
                    ;

// Neste caso, pode haver um IF sem ELSE
comando_singular    :   IF OP expressao CP comando
                        |IF OP expressao CP comando_casado ELSE comando_singular
                        ;

// Comando de expressão
expressao_decl  :   expressao SEMICOLON
                    |SEMICOLON
                    ;

// Estrutura WHILE
iteracao_decl   :   WHILE OP expressao CP comando_casado
                    ;

// Retorno de função: simples ou com valor
retorno_decl    :   RETURN SEMICOLON 
                    | RETURN expressao SEMICOLON
                    ;

// Expressão: atribuição ou expressão simples
expressao   :   var EQ expressao 
                |expressao_simples
                | error { print_error("Invalid expression."); yyerrok; }
                ;
// Variável
var    :    ID  {
                if (TDS_encontrarSimbolo($1) == NULL) {
                    print_error("Variável usada mas não declarada.");
                }
            }
            |ID var_aux {
                if (TDS_encontrarSimbolo($1) == NULL) {
                    print_error("Variável usada mas não declarada.");
                }
            }
            ;

// Acesso aos elementos do vetor/matriz
var_aux :   OB expressao CB
            |OB expressao CB var_aux
            ;

// Expressão simples: aritmética ou relacional
expressao_simples   :   expressao_soma RELOP expressao_soma 
                        |expressao_soma
                        ;

expressao_soma  :   termo
                    |termo expressao_somatorio
                    ;

// Operações de soma e subtração
expressao_somatorio :   SOMA termo 
                        | SOMA termo expressao_somatorio
                        ;

termo   :   fator 
            | fator termo_aux
            ;

// Operações de multiplicação e divisão
termo_aux   :   MULT fator 
                |MULT fator termo_aux
                ;

// Operandos básicos
fator   :   OP expressao CP
            |var
            |ativacao
            |NUM_FLOAT
            |NUM_INT
            ;

// Chamada da função 
ativacao    :   ID OP args CP
                ;

args    :   arg_list
            | /* vazio */
            ;

// Lista de argumentos passados para a função
arg_list   :    expressao
                |expressao COMMA arg_list
                |error COMMA arg_list { print_error("Invalid argument. Skipping."); yyerrok; }
                ;
%%

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

void yyerror(const char *s) {
    fprintf(stderr, RED "!SYNTATIC ERROR ocurred at (%d, %d):\n" RESET,
                    line_number, column_number);
    syntax_error_occurred++;
}

void print_error(const char *msg) {
    fprintf(stderr, BLUE "Message:" RESET " %s\n\n", msg);
}

int main(int argc, char **argv) {

    TabDeSimbolos* global = new_TabDeSimbolos();
    TDS_empilhar(global);

    if (argc < 2){
        printf("Please provide an input file.");
        return -1;
    }
    FILE *arq_compilado = fopen(argv[1], "r");
    if (!arq_compilado) {
        printf("The input file provided is not recognizeble.");
        return -2;
    }

    yyin = arq_compilado;
    yyparse(); // Chamada para iniciar a análise sintática;

    
    TDS_imprimir(global, "Global");
    // Verifica se houve erros léxicos OU sintáticos
    if (errors_count > 0 || syntax_error_occurred) {
        printf(RED "*-------------------------------------------------*\n");
        printf("| !!! Syntatic analysis concluded with ERRORS !!! |\n");
        printf(RED "*-------------------------------------------------*\n" RESET);
    } else {
        printf(GREEN"*------------------------------------------------------*\n");
        printf("| !!! Syntatic analysis was successfully concluded !!! |\n");
        printf("*------------------------------------------------------*\n"RESET);
    }

    fclose(arq_compilado); // Fecha o arquivo utilizado na análise;


    return 0;
}

