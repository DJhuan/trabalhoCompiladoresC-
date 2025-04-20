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
error_id                {number}({letter}|{number})*
number                  {digit}+
type                    int|float|char
id                      {letter}({letter}|{number})*
comment                 "/*".*"*/"
error_comment           \/.*\*\/|\/\*.*\/
other                   .


%%
%{
/*----------------------------- Rules -----------------------------*/
%}
{comment}               { column_number+=yyleng; }
{error_id}              { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n Maybe you want an id, if so, the id cannot start with a number \n", ++errors_count, line_number, column_number, yytext); }
{error_comment}         { fprintf(yyout, "(%d) Lexical error in line %d and col %d. Input -> \"%s\"\n Your comment is missing a delimiter \n", ++errors_count, line_number, column_number, yytext); }

"+"                     { fprintf(yyout,"%d(%d): %s (PLUS)\n",line_number,column_number,yytext);
                          column_number+=yyleng; }
"-"                     { fprintf(yyout,"%d(%d): %s (MINUS)\n",line_number,column_number,yytext);
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