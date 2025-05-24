#!/bin/bash

# Verifica se todos os parâmetros foram passados
if [ $# -ne 3 ]; then
  echo "Uso: $0 <arquivo_do_yacc.y> <arquivo_do_lex.l> <arquivo_de_teste.txt>"
  exit 1
fi

ARQ_YACC="$1"
ARQ_LEX="$2"
ARQ_TESTE="$3"

cd "c-language"

echo "Compilando arquivo .y."
bison -d -o parser.tab.c c-language.y

if [ ! -f "parser.tab.c" ]; then
  echo "Erro na compilação do arquivo '.y'!"
  exit 1
fi

echo "Compilando arquivo .l."
flex -o scanner.yy.c c-language.l

if [ ! -f "scanner.yy.c" ]; then
  echo "Erro na compilação do arquivo '.l'!"
  exit 1
fi

echo "Compilando analisador sintático."
gcc -o analise-sintatica scanner.yy.c parser.tab.c -lfl

if [ ! -f "analise-sintatica" ]; then
  echo "Erro na compilação do analisador sintático!"
  exit 1
fi

./analise-sintatica ../"$ARQ_TESTE"
