#!/bin/bash
# Script criado por Ricardo Terra
# Modificado por Jhuan Carlos

# Verifica se os parâmetros foram passados
if [ $# -ne 2 ]; then
  echo "Uso: $0 <nome_compilacao> <arquivo_txt>"
  exit 1
fi

NOME_COMPILACAO="$1"
ARQUIVO_TEXTO="$2"

# Verifica se o arquivo existe
if [ ! -f "$ARQUIVO_TEXTO" ]; then
  echo "Erro: Arquivo '$ARQUIVO_TEXTO' não encontrado."
  exit 1
fi


cd "$NOME_COMPILACAO"

# Remove o executável anterior
if [ ! -f "$NOME COMPILACAO" ]; then
  echo "Apagando executável '$NOME_COMPILACAO'."
  rm $NOME_COMPILACAO
fi

# Gera o analisador léxico com flex
echo # Nove linha
echo "#  Executando o Flex  #"
echo flex "$NOME_COMPILACAO.l"
echo "##### Output Flex #####"
echo # Nova linha
flex "$NOME_COMPILACAO.l"
echo # Nova linha
echo "#######################"

if [ ! -f "lex.yy.c" ]; then
  echo "Erro na geração do analisador léxico."
  exit 1
fi

# Compila o código gerado
echo # Nove linha
echo "#  Executando o GCC  #"
echo gcc lex.yy.c -o "$NOME_COMPILACAO"
gcc lex.yy.c -o "$NOME_COMPILACAO"

if [ ! -f "$NOME_COMPILACAO" ]; then
  echo "Erro na compilação do analisador léxico."
  exit 1
fi

# Executa o programa com o arquivo de entrada
echo # Nova linha
echo "############## Sucesso! ##############"
echo ./"$NOME_COMPILACAO" ../"$ARQUIVO_TEXTO"
./"$NOME_COMPILACAO" ../"$ARQUIVO_TEXTO"


%flex ${1}
%yacc -d ${2} -r 'all'
%gcc y.tab.c lex.yy.c -o ${3} -lfl -ly
%echo "Run "${3}
%./${3} ${4}
