import os
from typing import Iterable

from .models.nodes import Node


def ast_to_lines(node, indent=0, prefix=""):
    lines = []

    def _rec(n, indent, prefix):
        if isinstance(n, Node):
            lines.append(" " * indent + prefix + str(n))
            children = n.get_children()
            for i, (label, child) in enumerate(children):
                is_last = i == len(children) - 1
                new_prefix = "└─ " if is_last else "├─ "
                new_indent = indent + 4

                if label:
                    new_prefix = new_prefix + label + ": "

                if indent > 0:
                    new_indent_str = "│   " if not is_last else "    "
                    _rec(child, new_indent, new_indent_str + new_prefix)
                else:
                    _rec(child, new_indent, new_prefix)
        else:
            lines.append(" " * indent + prefix + str(n))

    _rec(node, indent, prefix)
    return lines


def save_clean_report(path: str, lines: Iterable[str]):
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        for line in lines:
            f.write(line + "\n")
