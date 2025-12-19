class Node:
    def get_children(self):
        raise NotImplementedError

    def generate(self, codegen):
        raise NotImplementedError


class NumberNode(Node):
    def __init__(self, value):
        self.value = value

    def __repr__(self):
        return f"NUMBER({self.value})"

    def get_children(self):
        return []

    def generate(self, codegen):
        return self.value


class BinOpNode(Node):
    def __init__(self, op, left, right):
        self.op = op
        self.left = left
        self.right = right

    def __repr__(self):
        return f"BINOP('{self.op}')"

    def get_children(self):
        return [("esq", self.left), ("dir", self.right)]

    def generate(self, codegen):
        left_temp = codegen.generate(self.left)
        right_temp = codegen.generate(self.right)
        return codegen.emit_bin(left_temp, self.op, right_temp)


class UnaryOpNode(Node):
    def __init__(self, op, operand):
        self.op = op
        self.operand = operand

    def __repr__(self):
        return f"UNARY('{self.op}')"

    def get_children(self):
        return [("", self.operand)]

    def generate(self, codegen):
        operand_temp = codegen.generate(self.operand)
        return codegen.emit_unary(operand_temp, self.op)
