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
"=="                    { fprintf(yyout,"%d(%d): %s (RELOP)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"!="                    { fprintf(yyout,"%d(%d): %s (RELOP)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"=!"                    { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\". Did you mean != ?\n", ++errors_count, line_number, column_number, yytext); }
"<="                    { fprintf(yyout,"%d(%d): %s (RELOP)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
">="                    { fprintf(yyout,"%d(%d): %s (RELOP)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"=>"                    { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\". Did you mean >= ?\n", ++errors_count, line_number, column_number, yytext); }
">"                     { fprintf(yyout,"%d(%d): %s (RELOP)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"<"                     { fprintf(yyout,"%d(%d): %s (RELOP)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"+"                     { fprintf(yyout,"%d(%d): %s (OPERATOR)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"-"                     { fprintf(yyout,"%d(%d): %s (OPERATOR)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }

";"                     { fprintf(yyout,"%d(%d): %s (SEMICOLON)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"{"                     { fprintf(yyout,"%d(%d): %s (O CURLY BRACES)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"}"                     { fprintf(yyout,"%d(%d): %s (C CURLY BRACES)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"["                     { fprintf(yyout,"%d(%d): %s (O BRACKET)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"]"                     { fprintf(yyout,"%d(%d): %s (C BRACKET)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"("                     { fprintf(yyout,"%d(%d): %s (O PARENTHESIS)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
")"                     { fprintf(yyout,"%d(%d): %s (C PARENTHESIS)\n",line_number,column_number,yytext);
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