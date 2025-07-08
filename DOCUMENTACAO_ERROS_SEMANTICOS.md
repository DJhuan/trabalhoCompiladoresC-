# Verificações de Erros Semânticos Implementadas com Modo Pânico

## 10 Verificações de Erros Semânticos Principais

### 1. **Variável usada mas não declarada** (regra `var`)
- **Localização**: Regra `var` nas linhas 264-275
- **Mensagem**: "Variável usada mas não declarada."
- **Descrição**: Verifica se uma variável foi declarada antes de ser usada

### 2. **Símbolo já declarado no escopo** (função `TDS_novoSimbolo`)
- **Localização**: `TabDeSimbolos.c` linha 177
- **Mensagem**: "Erro semântico: símbolo '%s' já declarado neste escopo"
- **Descrição**: Impede redeclaração de símbolos no mesmo escopo

### 3. **Função já declarada** (regra `func_decl`)
- **Localização**: Regra `func_decl` linhas 137-145
- **Mensagem**: "Função já declarada."
- **Descrição**: Verifica se uma função já foi declarada antes

### 4. **Dimensão de array inválida** (regra `var_decl`)
- **Localização**: Regra `var_decl` linhas 89-91
- **Mensagem**: "Invalid array dimension."
- **Descrição**: Verifica se a dimensão do array é maior que zero

### 5. **Incompatibilidade de tipos na atribuição** (regra `expressao`)
- **Localização**: Regra `expressao` linhas 260-270
- **Mensagens**: 
  - "Não é possível atribuir valor a variável do tipo void."
  - "Incompatibilidade de tipos na atribuição."
- **Descrição**: Verifica compatibilidade entre tipos na atribuição

### 6. **Retorno de valor void** (regra `retorno_decl`)
- **Localização**: Regra `retorno_decl` linha 263
- **Mensagem**: "Não é possível retornar valor void."
- **Descrição**: Impede retorno de valores void

### 7. **Operação relacional com tipos incompatíveis** (regra `expressao_simples`)
- **Localização**: Regra `expressao_simples` linhas 288-292
- **Mensagem**: "Operação relacional inválida entre tipos incompatíveis."
- **Descrição**: Verifica compatibilidade de tipos em operações relacionais

### 8. **Operação aritmética com tipo struct** (regras `expressao_soma` e `termo`)
- **Localização**: Regras `expressao_soma` (linhas 299-303) e `termo` (linhas 323-327)
- **Mensagem**: "Operação aritmética inválida com tipo struct."
- **Descrição**: Impede operações aritméticas com estruturas

### 9. **Função chamada mas não declarada** (regra `ativacao`)
- **Localização**: Regra `ativacao` linhas 360-365
- **Mensagem**: "Função chamada mas não declarada."
- **Descrição**: Verifica se a função foi declarada antes de ser chamada

### 10. **Condição void em estruturas de controle** (regras `cabecalho_if` e `iteracao_decl`)
- **Localização**: `cabecalho_if` (linha 226) e `iteracao_decl` (linha 248)
- **Mensagens**: 
  - "Condição do if não pode ser do tipo void."
  - "Condição do while não pode ser do tipo void."
- **Descrição**: Impede uso de expressões void como condição

## Regras de Modo Pânico Implementadas

### 1. **Declaração de Variáveis** (regra `var_decl`)
```yacc
|error ID SEMICOLON {
    print_error("Erro semântico: tipo de dados inválido ou não declarado.");
    yyerrok; // Modo pânico - tipo inválido
}
|tipo_especificador ID error {
    print_error("Erro semântico: ponto e vírgula esperado na declaração de variável.");
    yyerrok; // Modo pânico - falta ;
}
```

### 2. **Declaração de Funções** (regra `func_decl`)
```yacc
|error ID OP params CP composto_decl {
    print_error("Erro semântico: tipo de retorno inválido na função.");
    yyerrok; // Modo pânico - tipo de retorno inválido
}
|tipo_especificador error OP params CP composto_decl {
    print_error("Erro semântico: nome da função inválido.");
    yyerrok; // Modo pânico - nome de função inválido
}
```

### 3. **Expressões e Atribuições** (regra `expressao`)
```yacc
|error EQ expressao {
    print_error("Erro semântico: lado esquerdo da atribuição inválido.");
    yyerrok; // Modo pânico - variável inválida na atribuição
}
|var EQ error {
    print_error("Erro semântico: expressão inválida na atribuição.");
    yyerrok; // Modo pânico - expressão inválida
}
```

### 4. **Acesso a Arrays** (regra `var_aux`)
```yacc
|OB error CB {
    print_error("Erro semântico: índice de array inválido.");
    yyerrok; // Modo pânico - índice inválido
}
|OB expressao error {
    print_error("Erro semântico: colchete direito esperado no acesso ao array.");
    yyerrok; // Modo pânico - falta ]
}
```

### 5. **Chamadas de Função** (regra `ativacao`)
```yacc
|error OP args CP {
    print_error("Erro semântico: nome de função inválido na chamada.");
    yyerrok; // Modo pânico - nome de função inválido
}
|ID OP args error {
    print_error("Erro semântico: parêntese direito esperado na chamada de função.");
    yyerrok; // Modo pânico - falta )
}
```

### 6. **Estruturas de Controle**

#### While (regra `iteracao_decl`)
```yacc
|WHILE OP error CP comando_casado {
    print_error("Erro semântico: condição inválida no while.");
    yyerrok; // Modo pânico - condição inválida
}
|WHILE error expressao CP comando_casado {
    print_error("Erro semântico: parêntese esquerdo esperado no while.");
    yyerrok; // Modo pânico - falta (
}
```

#### If (regra `cabecalho_if`)
```yacc
|IF error expressao CP {
    print_error("Erro semântico: parêntese esquerdo esperado no if.");
    yyerrok; // Modo pânico - falta (
}
|IF OP expressao error {
    print_error("Erro semântico: parêntese direito esperado no if.");
    yyerrok; // Modo pânico - falta )
}
```

### 7. **Return** (regra `retorno_decl`)
```yacc
|RETURN expressao error {
    print_error("Erro semântico: ponto e vírgula esperado após return.");
    yyerrok; // Modo pânico - falta ;
}
```

## Como Funciona o Modo Pânico

1. **Token `error`**: Representa qualquer sequência de tokens inválidos
2. **`yyerrok`**: Reseta o estado de erro do parser, permitindo continuar a análise
3. **Recuperação**: O parser descarta tokens até encontrar um ponto de sincronização (geralmente `;`, `}`, etc.)
4. **Continuação**: Após encontrar o ponto de sincronização, a análise continua normalmente

## Benefícios Implementados

- **Detecção múltipla**: Encontra vários erros em uma única execução
- **Mensagens específicas**: Cada erro tem uma mensagem descritiva
- **Recuperação robusta**: O compilador não para no primeiro erro
- **Modo pânico eficiente**: Descarta tokens inválidos e continua a análise
