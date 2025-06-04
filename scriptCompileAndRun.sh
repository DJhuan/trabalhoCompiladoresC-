#!/bin/bash

# Verifica se todos os parâmetros foram passados
if [ $# -lt 3 ]; then
  echo "Uso: $0 <arquivo_do_yacc.y> <arquivo_do_lex.l> <arquivo_de_teste.txt>"
  exit 1
fi

echo "--== SCRIPT FUNCIONANDO ==--"

ARQ_YACC="$1"
ARQ_LEX="$2"
ARQ_TESTE="$3"

cd "c-language"

BISON_OPT=""
for arg in "$@"; do
  if [ "$arg" = "-d" ]; then
    echo "Modo debug ativado."
    BISON_OPT="$BISON_OPT --debug"
  elif [ "$arg" = "-cep" ]; then
    echo "Contraexemplos ativados."
    BISON_OPT="$BISON_OPT -Wcounterexamples"
  fi
done

echo "Compilando arquivo .y."
bison $BISON_OPT -d -o parser.tab.c c-language.y

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
gcc scanner.yy.c parser.tab.c -o analise-sintatica -lfl

if [ ! -f "analise-sintatica" ]; then
  echo "Erro na compilação do analisador sintático!"
  exit 1
fi

echo "Iniciando analisador sintático. Compilando o arquivo: $ARQ_TESTE"
echo
./analise-sintatica ../"$ARQ_TESTE"

echo "--== FIM DA EXECUÇÃO ==--"
