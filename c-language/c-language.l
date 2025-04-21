%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
#include<string.h>

int line_number = 1;
int column_number = 1;
int errors_count = 0;
%}

delim                   [ \t\n]
ws                      {delim}+
letter                  [a-z]
digit                   [0-9]
num_int                 {digit}+
float_error             {digit}+","{digit}*
num_float               {digit}+\.{digit}+([Ee][+-]?{digit}+)?
comment                 "/*".*"*/"
other                   .


%%
%{
/*----------------------------- Rules -----------------------------*/
%}
{comment}               { column_number+=yyleng; }
"+"                     { fprintf(yyout,"%d(%d): %s (PLUS)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"-"                     { fprintf(yyout,"%d(%d): %s (MINUS)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"\n"                    { line_number++; column_number=1; }
{float_error}           { fprintf(yyout, "(%d) Lexical error in line %d and col %d Do you mean '.' for float? Input -> \"%s\"\n", ++errors_count, line_number, column_number, yytext); }
{num_int}               { fprintf(yyout,"%d(%d): %s (INT)\n",line_number,column_number,yytext); column_number+=yyleng; }
{num_float}             { fprintf(yyout,"%d(%d): %s (FLOAT)\n",line_number,column_number,yytext); column_number+=yyleng; }
{ws}                    { column_number+=yyleng; }
{other}                 { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n", ++errors_count, line_number, column_number, yytext); }


%%
/*------------------------ User subrotines ------------------------*/
int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yyout=stdout;
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap(){
    return 0;
}