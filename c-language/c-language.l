%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
#include<string.h>
#include "c-language.tab.h"
#include "parser.tab.h"

int line_number = 1;
int column_number = 1;
int errors_count = 0;
%}

%option noyywrap

delim                   [ \t\r]
ws                      {delim}+
letter                  [a-zA-Z]
digit                   [0-9]
error_id                {digit}({letter}|{digit})*
num_int                 {digit}+
character               \'.\'
id                      {letter}({letter}|{digit})*
num_float               {digit}+(\.{digit}+)?([Ee][+-]?{digit}+)?
comment                 \/\*([^*]|\*+[^/])*\*+\/
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
","         { column_number += yyleng; return COMMA; }
"{"         { column_number += yyleng; return OCB; }
"}"         { column_number += yyleng; return CCB; }
"("         { column_number += yyleng; return OP; }
")"         { column_number += yyleng; return CP; }
"["         { column_number += yyleng; return OB; }
"]"         { column_number += yyleng; return CB; }

{ws}        { column_number += yyleng; }
"\n"        { line_number++; column_number = 1; }
{comment} {
    for (int i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') {
            line_number++;
            column_number = 1;
        } else {
            column_number++;
        }
    }
}

{id}        { yylval.identifier = strdup(yytext); column_number += yyleng; return ID; }
{num_int}   { column_number += yyleng; return NUM_INT; }
{num_float} { column_number += yyleng; return NUM_FLOAT; }
{character} { column_number += yyleng; return CHARACTER; }


{error_id} { 
    fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n Maybe you want an id, if so, the id cannot start with a number \n", 
        ++errors_count, line_number, column_number, yytext); 
    //input();
}

"=!" {
    fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\". Did you mean != ?\n", 
        ++errors_count, line_number, column_number, yytext);
        column_number += yyleng;
}
"=>" {
    fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\". Did you mean >= ?\n",
        ++errors_count, line_number, column_number, yytext); 
        column_number += yyleng;
}
"=<" {
    fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\". Did you mean <= ?\n",
        ++errors_count, line_number, column_number, yytext); 
        column_number += yyleng;
}

{other} { 
    fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n", 
        ++errors_count, line_number, column_number, yytext);
        column_number += yyleng; 
}

%%

/*------------------------ User subroutines ------------------------*/