from rply import LexerGenerator


class Lexer(object):
    def __init__(self):
        self.lg = LexerGenerator()
        self.tokens = []
        self._add_tokens()
        self.lexer = self.lg.build()

    def _add_tokens(self):
        # Números (float ou int)
        self.lg.add("NUMBER", r"\d+(\.\d+)?")
        self.tokens.append("NUMBER")

        # Operadores
        self.lg.add("PLUS", r"\+")
        self.tokens.append("PLUS")
        self.lg.add("MINUS", r"\-")
        self.tokens.append("MINUS")
        self.lg.add("TIMES", r"\*")
        self.tokens.append("TIMES")
        self.lg.add("DIVIDE", r"\/")
        self.tokens.append("DIVIDE")
        self.lg.add("POWER", r"\^")
        self.tokens.append("POWER")

        # Parenteses
        self.lg.add("LPAREN", r"\(")
        self.tokens.append("LPAREN")
        self.lg.add("RPAREN", r"\)")
        self.tokens.append("RPAREN")

        # Ignorar espacos em branco
        self.lg.ignore(r"\s+")

    def lex(self, text):
        return self.lexer.lex(text)
