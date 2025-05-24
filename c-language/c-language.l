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
letter                  [a-zA-Z]
digit                   [0-9]
error_id                {digit}({letter}|{digit})*
num_int                 {digit}+
type                    int|float|char
character               \'.\'
id                      {letter}({letter}|{digit})*
num_float               {digit}+(\.{digit}+)?([Ee][+-]?{digit}+)?
comment                 "#".|"/"(.|\n)"*/"
error_comment           \/.*\*\/|\/\*.*\/
other                   .


%%
%{
/*----------------------------- Rules -----------------------------*/
%}
{comment}               { column_number+=yyleng; }
{error_comment}         { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n Your comment is missing a delimiter \n", ++errors_count, line_number, column_number, yytext); }

"=="                    { fprintf(yyout,"%d(%d): %s (RELOP, EQ)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"!="                    { fprintf(yyout,"%d(%d): %s (RELOP, NE)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"if"                    { fprintf(yyout,"%d(%d): %s (IF)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }   
"else"                  { fprintf(yyout,"%d(%d): %s (ELSE)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"while"                 { fprintf(yyout,"%d(%d): %s (WHILE)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }      
"struct"                { fprintf(yyout,"%d(%d): %s (STRUCT)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }         
"void"                  { fprintf(yyout,"%d(%d): %s (VOID)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }   
"return"                { fprintf(yyout,"%d(%d): %s (RETURN)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }  
"cin"                   { fprintf(yyout,"%d(%d): %s (INPUT)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }    
"cout"                  { fprintf(yyout,"%d(%d): %s (OUTPUT)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }  
{type}                  { fprintf(yyout,"%d(%d): %s (TYPE)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }    
{id}                    { fprintf(yyout,"%d(%d): %s (ID)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
{character}             { fprintf(yyout,"%d(%d): %s (CHARACTER)\n",line_number,column_number,yytext);
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
"+"                     { fprintf(yyout,"%d(%d): %s (SOMA, +)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"-"                     { fprintf(yyout,"%d(%d): %s (SOMA, -)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"*"                     { fprintf(yyout,"%d(%d): %s (MULT, *)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"/"                     { fprintf(yyout,"%d(%d): %s (MULT, /)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
";"                     { fprintf(yyout,"%d(%d): %s (SEMICOLON)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
","                     { fprintf(yyout,"%d(%d): %s (COLON)\n",line_number,column_number,yytext);
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

{num_int}               { fprintf(yyout,"%d(%d): %s (INT)\n",line_number,column_number,yytext); column_number+=yyleng; }
{num_float}             { fprintf(yyout,"%d(%d): %s (FLOAT)\n",line_number,column_number,yytext); column_number+=yyleng; }
{error_id}              { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n Maybe you want an id, if so, the id cannot start with a number \n", ++errors_count, line_number, column_number, yytext); }
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