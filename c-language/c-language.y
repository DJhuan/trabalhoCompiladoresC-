%{
    #include <stdio.h>
    #include <stdlib.h>

    /*Compatibilidade com FLEX*/
    int yylex(void);
    void yyerror(const char *s);
%}

%token CHAR
%token COMMA
%token FLOAT
%token ID
%token INT
%token SEMI

%%
decl    :   type ID list             { printf("Sucesso!\n"); }
            ;

list    :   COMMA ID list
            | SEMI
            ;

type    :   INT
            | CHAR
            | FLOAT
            ;
%%