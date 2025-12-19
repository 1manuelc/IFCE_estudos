from rply import ParserGenerator

from ..models.nodes import BinOpNode, NumberNode, UnaryOpNode


class Parser(object):
    def __init__(self, tokens):
        self.pg = ParserGenerator(
            tokens,
            precedence=[
                ("left", ["PLUS", "MINUS"]),  # menor precedencia
                ("left", ["TIMES", "DIVIDE"]),
                ("right", ["POWER"]),  # associa exponenciacao a direita
                ("right", ["UNARY_MINUS"]),  # maior precedencia
            ],
        )
        self.tokens = tokens
        self._add_rules()
        self.parser = self.pg.build()

    def _add_rules(self):

        @self.pg.production("expression : expression PLUS expression")
        @self.pg.production("expression : expression MINUS expression")
        @self.pg.production("expression : expression TIMES expression")
        @self.pg.production("expression : expression DIVIDE expression")
        @self.pg.production("expression : expression POWER expression")
        def expression_binop(p):
            op = p[1].getstr()
            left = p[0]
            right = p[2]
            return BinOpNode(op, left, right)

        @self.pg.production("expression : MINUS expression", precedence="UNARY_MINUS")
        def expression_unary_minus(p):
            op = p[0].getstr()
            operand = p[1]
            return UnaryOpNode(op, operand)

        @self.pg.production("expression : LPAREN expression RPAREN")
        def expression_group(p):
            return p[1]

        @self.pg.production("expression : NUMBER")
        def expression_number(p):
            value = p[0].getstr()
            if "." in value:
                return NumberNode(float(value))
            return NumberNode(int(value))

        @self.pg.error
        def error_handle(token):
            raise ValueError(
                f"Erro de sintaxe na posição {token.getsourcepos().idx} com o token {token.gettokentype()}"
            )
