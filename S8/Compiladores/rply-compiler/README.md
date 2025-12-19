# Compilador de Expressões Matemáticas

Geração de AST, Código de Três Endereços (TAC) e expressão reconstruída mostrando a ordem de resolução.

Este projeto implementa um pequeno compilador para expressões aritméticas usando rply (lexer/parser), geração de AST e um CodeGenerator capaz de produzir TAC e reconstruir a expressão totalmente parentizada seguindo a ordem de avaliação.

# Requisitos

* `Python 3.8+`
* `pip`
* `venv` (módulo padrão do Python)
* Arquivo requirements.txt contendo: `rply`

# Criando e ativando um ambiente virtual

Recomenda-se utilizar ambiente virtual isolado.

## Linux / macOS
```bash
python3 -m venv venv
source venv/bin/activate
```

## Windows
```bash
python -m venv venv
venv\Scripts\activate
```

# Instalando dependências

Com o ambiente virtual ativado:
```bash
pip install -r requirements.txt
```

Isso instalará o rply, que é necessário para o lexer e parser.

# Estrutura do Projeto
```
.
├── codegen.py          # Geração de TAC e reconstrução da expressão
├── lexer.py            # Analisador léxico (tokens)
├── parser.py           # Parser usando rply
├── nodes.py            # Nós da AST
├── utils.py            # Utilitários para AST e salvamento
├── main.py             # Entrada principal: compila expressões
├── requirements.txt
├── outputs/            # Onde relatórios são salvos
└── tests.txt           # Arquivo com expressões para compilar em lote
```

# Executando o projeto

Adicione sua(s) expressão(ões) no arquivo `tests.txt`. Caso queira adicionar mais de uma, separe por enter.

Execute o compilador com:
`python main.py`

Cada linha de `tests.txt` será compilada e gerará um arquivo txt como relatório para cada expressão em `outputs/`.

O arquivo contém:
* Análise léxica
* AST textual
* Código de três endereços
* Expressão reconstruída

# Exemplo de Saída

Para a expressão: `3 + 4 * 2`

O relatório conterá:
```
EXPRESSÃO ORIGINAL: 3 + 4 * 2

=== ANÁLISE LÉXICA ===
NUMBER     3          0         
PLUS       +          2         
NUMBER     4          4         
TIMES      *          6         
NUMBER     2          8         

=== AST ===
BINOP('+')
    ├─ esq: NUMBER(3)
    └─ dir: BINOP('*')
        │   ├─ esq: NUMBER(4)
            └─ dir: NUMBER(2)

=== CÓDIGO DE TRÊS ENDEREÇOS ===
t0 = 4 * 2
t1 = 3 + t0

Resultado final: t1

=== EXPRESSÃO RECONSTRUÍDA ===
(3 + (4 * 2))
```

# Como contribuir com o compilador

Você pode:
* Adicionar novos operadores em `lexer.py`
* Estender precedência em `parser.py`
* Criar novos tipos de nó em `nodes.py`
* Implementar otimizações no `codegen.py`