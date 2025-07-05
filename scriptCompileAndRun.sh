#!/bin/bash

# Verifica se todos os parâmetros foram passados
if [ $# -lt 1 ]; then
  echo "Uso: $0 <arquivo_de_teste.txt>"
  exit 1
fi

echo "--== SCRIPT FUNCIONANDO ==--"

ARQ_YACC="c-language.l"
ARQ_LEX="c-language.y"
ARQ_TESTE="$1"
NOME_COMPILADOR="gcm"

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

echo "Compilando o $NOME_COMPILADOR."
gcc scanner.yy.c parser.tab.c TabDeSimbolos.c -o $NOME_COMPILADOR -lfl

if [ ! -f $NOME_COMPILADOR ]; then
  echo "Erro na compilação do analisador sintático!"
  exit 1
fi

echo "Limpando arquivos temporários."
rm -f scanner.yy.c parser.tab.c parser.tab.h c-language.tab.h c-language.tab.c

echo "Iniciando analisador sintático. Compilando o arquivo: $ARQ_TESTE"
./"$NOME_COMPILADOR" ../"$ARQ_TESTE"

echo "--== FIM DA EXECUÇÃO ==--"
