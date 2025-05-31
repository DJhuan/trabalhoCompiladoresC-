%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
extern int line_number;
extern int column_number;
int syntax_error_occurred = 0; 
extern int errors_count;


// Informações usadas pelo Bison que vem do Flex:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
 
void yyerror(const char *s);
%}

%token ID
%token INT FLOAT CHAR
%token IF ELSE WHILE RETURN
%token SOMA 
%token MULT
%token EQ
%token RELOP
%token SEMICOLON COMMA
%token OCB CCB OP CP OB CB
%token NUM_INT NUM_FLOAT
%token CHARACTER
%token STRUCT 
%token VOID


%left SOMA 
%left MULT      
%right EQ       
%left RELOP 
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
                |error SEMICOLON { yyerror("Missing identifier.\nIgnoring inputs untill the next semicolon"); yyerrok; }
                ;

dimen_matriz    :   OB NUM_INT CB
                    | OB NUM_INT CB dimen_matriz
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
                    |param COMMA params_lista
                    ;

param   :   tipo_especificador ID 
            |tipo_especificador ID OB CB
            ;

composto_decl   :   OCB local_decl comando_lista CCB 
                    ;

local_decl  :   var_decl local_decl
                | /* vazio */
                ;

comando_lista   :   comando comando_lista
                    | /* vazio */
                    ;

comando :   comando_casado
            |comando_singular
            ;

/* Neste caso, TODO IF está associado com um ELSE; */
comando_casado  :   expressao_decl
                    |composto_decl
                    |iteracao_decl
                    |retorno_decl
                    |IF OP expressao CP comando_casado ELSE comando_casado
                    ;

/* Neste caso, pode haver um IF sem ELSE */
comando_singular    :   IF OP expressao CP comando
                        |IF OP expressao CP comando_casado ELSE comando_singular
                        ;

expressao_decl  :   expressao SEMICOLON
                    |SEMICOLON
                    ;

iteracao_decl   :   WHILE OP expressao CP comando_casado
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
            | /* vazio */
            ;

arg_list   :    expressao
                |expressao COMMA arg_list
                ;


%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error ocurred at (line,column):(%d, %d):\n"
                    "Message: %s\n\n", 
                    line_number, column_number, s);
    syntax_error_occurred = 1; // Seta a flag quando um erro sintático ocorre
}


int main(int argc, char **argv) {
    if (argc < 2){
        printf("Você deve prover um arquivo de entrada para o compilador.");
        return -1;
    }
    FILE *arq_compilado = fopen(argv[1], "r");
    if (!arq_compilado) {
        printf("O arquivo fornecido para compilação não é válido.");
        return -2;
    }

    yyin = arq_compilado;
    yyparse(); // Esta chamada tentará analisar o arquivo

    // Verifica se houve erros léxicos OU sintáticos
    if (errors_count > 0 || syntax_error_occurred) {
        printf("!!! Análise do arquivo concluída com ERROS !!!\n");
    } else {
        printf("!!! Análise sintática bem sucedida no arquivo !!!\n");
    }

    fclose(arq_compilado);
    return 0;
}

