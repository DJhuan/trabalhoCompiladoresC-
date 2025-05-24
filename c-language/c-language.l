%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
#include<string.h>
#include "parser.tab.h"

int line_number = 1;
int column_number = 1;
int errors_count = 0;
%}


delim                   [ \t]
ws                      {delim}+
letter                  [a-zA-Z]
digit                   [0-9]
error_id                {digit}({letter}|{digit})*
num_int                 {digit}+
character               \'.\'
id                      {letter}({letter}|{digit})*
num_float               {digit}+(\.{digit}+)?([Ee][+-]?{digit}+)?
comment                 "#".|"/"(.|\n)"*/"
error_comment           \/.*\*\/|\/\*.*\/
other                   .

%%

"if"        { column_number += yyleng; return IF; }
"else"      { column_number += yyleng; return ELSE; }
"while"     { column_number += yyleng; return WHILE; }
"return"    { column_number += yyleng; return RETURN; }
"struct"    { column_number += yyleng; return STRUCT; }
"void"      { column_number += yyleng; return VOID; }

"int"       { column_number += yyleng; return INT; }
"float"     { column_number += yyleng; return FLOAT; }
"char"      { column_number += yyleng; return CHAR; }

"+"         { column_number += yyleng; return SOMA; }
"*"         { column_number += yyleng; return MULT; }
"-"         { column_number += yyleng; return SOMA; }
"/"         { column_number += yyleng; return MULT; }

"="         { column_number += yyleng; return EQ; }
"=="        { column_number += yyleng; return RELOP; }
"!="        { column_number += yyleng; return RELOP; }
"<"         { column_number += yyleng; return RELOP; }
"<="        { column_number += yyleng; return RELOP; }
">"         { column_number += yyleng; return RELOP; }
">="        { column_number += yyleng; return RELOP; }

";"         { column_number += yyleng; return SEMICOLON; }
","         { column_number += yyleng; return COLON; }
"{"         { column_number += yyleng; return OCB; }
"}"         { column_number += yyleng; return CCB; }
"("         { column_number += yyleng; return OP; }
")"         { column_number += yyleng; return CP; }
"["         { column_number += yyleng; return OB; }
"]"         { column_number += yyleng; return CB; }


{ws}        { column_number += yyleng; }
"\n"        { line_number++; column_number = 1; }
{comment}   { column_number += yyleng; }

{id}        { column_number += yyleng; return ID; }
{num_int}   { column_number += yyleng; return NUM_INT; }
{num_float} { column_number += yyleng; return NUM_FLOAT; }
{character} { column_number += yyleng; return CHARACTER; }



%%
%{
/*----------------------------- Rules -----------------------------*/
%}
{error_comment}         { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n Your comment is missing a delimiter \n", ++errors_count, line_number, column_number, yytext); }

{error_id}              { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n Maybe you want an id, if so, the id cannot start with a number \n", ++errors_count, line_number, column_number, yytext); }

{other}                 { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n", ++errors_count, line_number, column_number, yytext); }


%%
/*------------------------ User subrotines ------------------------*/

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Erro ao abrir arquivo.\n");
        return 1;
    }
    yyout = stdout;
    yyparse();  // chama o parser
    fclose(yyin);
    return 0;
}