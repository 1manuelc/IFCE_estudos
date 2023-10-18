package S4.Topicos_especiais_em_Programacao.Atividade07;
/*
* #1. Construa um algoritmo recursivo que receba um número e informe seu fatorial.
* Obs1.: O mesmo não deve aceitar número negativo.
* Obs2.: A recursividade deve fazer o acumulo de forma regressiva.
*/

import javax.swing.JOptionPane;

public class Questao01 {
    public static int calcularFatorial(int numero) {
        if(numero == 1) return 1;
        else return numero * calcularFatorial(numero - 1);
    }

    public static int preencherNumeroValido() {
        int numero = Integer.parseInt(
                JOptionPane.showInputDialog(
                        null,
                        "Digite um número:",
                        "Calculadora de Fatorial",
                        JOptionPane.QUESTION_MESSAGE
                )
        );

        while(numero <= 0) {
            numero = Integer.parseInt(
                    JOptionPane.showInputDialog(
                            null,
                            "Digite um número VÁLIDO (maior que zero):",
                            "Calculadora de Fatorial",
                            JOptionPane.QUESTION_MESSAGE
                    )
            );
        }

        return numero;
    }

    public static void main(String[] args) {
        try {
            int numero = preencherNumeroValido();
            JOptionPane.showMessageDialog(
                    null,
                    String.format("!%d = %d", numero, calcularFatorial(numero)),
                    "Calculadora de Fatorial",
                    JOptionPane.INFORMATION_MESSAGE
            );

        } catch(ArrayIndexOutOfBoundsException e) {
            JOptionPane.showMessageDialog(null,
                    "Índice fora do limite do array",
                    "Erro",
                    JOptionPane.ERROR_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número válido",
                    "Erro",
                    JOptionPane.ERROR_MESSAGE);

        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso",
                    JOptionPane.WARNING_MESSAGE);
        }
    }
}