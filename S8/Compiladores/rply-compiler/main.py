import os

from classes.analysis.lexer import Lexer
from classes.analysis.parser import Parser
from classes.codegen import CodeGenerator
from classes.utils import ast_to_lines, save_clean_report

expr_counter = 1


def compile_expression(text, save_report=True, report_dir="outputs"):
    try:
        # 1. LEXING
        lexer_instance = Lexer()
        tokens = list(lexer_instance.lex(text))

        lex_lines = []
        for token in tokens:
            source_pos = token.getsourcepos()
            pos = source_pos.idx if source_pos else "N/A"
            lex_lines.append(
                f"{token.gettokentype():<10} {token.getstr():<10} {pos:<10}"
            )

        # 2. PARSING
        parser_instance = Parser(lexer_instance.tokens)
        ast = parser_instance.parser.parse(iter(tokens))

        # 3. CODEGEN
        codegen = CodeGenerator()
        final_temp = codegen.generate(ast)

        tac_lines = [line for line in codegen.code]
        reconstructed = codegen.expr_map.get(final_temp, final_temp)

        ast_lines = ast_to_lines(ast)

        if save_report:
            os.makedirs(report_dir, exist_ok=True)

            global expr_counter
            current = expr_counter
            outpath = os.path.join(report_dir, f"expr_{current:03d}.txt")
            expr_counter += 1

            report_lines = []

            report_lines.append("EXPRESSÃO ORIGINAL: " + text.strip())
            report_lines.append("")

            report_lines.append("=== ANÁLISE LÉXICA ===")
            report_lines.extend(lex_lines)
            report_lines.append("")

            report_lines.append("=== AST ===")
            report_lines.extend(ast_lines)
            report_lines.append("")

            report_lines.append("=== CÓDIGO DE TRÊS ENDEREÇOS ===")
            report_lines.extend(tac_lines)
            report_lines.append("")

            report_lines.append("Resultado final: " + str(final_temp))
            report_lines.append("")

            report_lines.append("=== EXPRESSÃO RECONSTRUÍDA ===")
            report_lines.append(str(reconstructed))

            save_clean_report(outpath, report_lines)
            print("Relatório salvo em:", outpath)

    except Exception as e:
        print(f'Erro ao compilar expressão "{text}": {str(e)}')


if __name__ == "__main__":
    with open("tests.txt", "r") as test_file:
        lines = test_file.readlines()
        for expr in lines:
            try:
                compile_expression(expr)
            except Exception as e:
                print(f"Ocorreu um erro ao compilar '{expr}': {e}")
