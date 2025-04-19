%{
/*-------------------------- Definitions --------------------------*/
#include<stdio.h>
#include<string.h>

int line_number = 1;
int column_number = 1;
int errors_count = 0;
%}

delim                   [ \t]
ws                      {delim}+
letter                  [a-z]
digit                   [0-9]
number                  {digit}+
comment                 "/*".*"*/"
other                   .


%%
%{
/*----------------------------- Rules -----------------------------*/
%}
{comment}               { column_number+=yyleng; }

/* Operadores relacionais */
"=="                    { fprintf(yyout,"%d(%d): %s (RELOP, EQ)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"!="                    { fprintf(yyout,"%d(%d): %s (RELOP, NE)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"=!"                    { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\". Did you mean != ?\n", ++errors_count, line_number, column_number, yytext); }
"<="                    { fprintf(yyout,"%d(%d): %s (RELOP, LE)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
">="                    { fprintf(yyout,"%d(%d): %s (RELOP, GE)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"=>"                    { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\". Did you mean >= ?\n", ++errors_count, line_number, column_number, yytext); }
">"                     { fprintf(yyout,"%d(%d): %s (RELOP, GT)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"<"                     { fprintf(yyout,"%d(%d): %s (RELOP, LT)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }

/* Operadores aritméticos */
"+"                     { fprintf(yyout,"%d(%d): %s (SOMA, +)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"-"                     { fprintf(yyout,"%d(%d): %s (SOMA, -)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"*"                     { fprintf(yyout,"%d(%d): %s (MULT, *)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"/"                     { fprintf(yyout,"%d(%d): %s (MULT, /)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }

/* Pontuações */
";"                     { fprintf(yyout,"%d(%d): %s (SEMICOLON)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"{"                     { fprintf(yyout,"%d(%d): %s (OCB)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"}"                     { fprintf(yyout,"%d(%d): %s (CCB)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"["                     { fprintf(yyout,"%d(%d): %s (OB)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"]"                     { fprintf(yyout,"%d(%d): %s (CB)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"("                     { fprintf(yyout,"%d(%d): %s (OP)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
")"                     { fprintf(yyout,"%d(%d): %s (CP)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }

"\n"                    { line_number++; column_number=1; }

{number}                { fprintf(yyout,"%d(%d): %s (NUMBER) \n",line_number,column_number,yytext); column_number+=yyleng; }
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