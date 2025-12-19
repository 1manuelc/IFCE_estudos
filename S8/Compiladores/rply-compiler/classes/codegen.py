class CodeGenerator:
    def __init__(self):
        self.code = []
        self.temp_count = 0
        self.expr_map = {}  # temp -> expressão parentizada
        self.debug = False

    def new_temp(self):
        t = f"t{self.temp_count}"
        self.temp_count += 1
        return t

    def _as_literal(self, value):
        return str(value)

    def _resolve(self, operand):
        if isinstance(operand, str) and operand in self.expr_map:
            return self.expr_map[operand]
        return self._as_literal(operand)

    def emit_bin(self, left, op, right):
        t = self.new_temp()
        self.code.append(f"{t} = {left} {op} {right}")
        left_expr = self._resolve(left)
        right_expr = self._resolve(right)
        self.expr_map[t] = f"({left_expr} {op} {right_expr})"
        if self.debug:
            print(f"[debug] emit_bin: {self.code[-1]} -> {t} => {self.expr_map[t]}")
        return t

    def emit_unary(self, operand, op):
        t = self.new_temp()
        self.code.append(f"{t} = {op} {operand}")
        operand_expr = self._resolve(operand)
        self.expr_map[t] = f"({op}{operand_expr})"
        if self.debug:
            print(f"[debug] emit_unary: {self.code[-1]} -> {t} => {self.expr_map[t]}")
        return t

    def generate(self, node):
        if not hasattr(node, "generate"):
            return self._as_literal(node)
        return node.generate(self)