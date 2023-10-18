package S4.Topicos_especiais_em_Programacao.Atividade07;
/*
* #2. Construa um algoritmo recursivo que mostre a sequência de Fibonacci.
* Obs.: O algoritmo deve checar se é possível mostrar a sequência de
* Fibonacci do número informado que deve ser positivo.
*/

import javax.swing.JOptionPane;

public class Questao02 {
    public static int preencherNumeroValido() {
        int numero = Integer.parseInt(
                JOptionPane.showInputDialog(
                        null,
                        "Digite um número positivo:",
                        "Calculadora de Fibonacci",
                        JOptionPane.QUESTION_MESSAGE
                )
        );

        while(numero < 0) {
            numero = Integer.parseInt(
                    JOptionPane.showInputDialog(
                            null,
                            "Digite um número POSITIVO:",
                            "Calculadora de Fibonacci",
                            JOptionPane.QUESTION_MESSAGE
                    )
            );
        }

        return numero;
    }

    public static int calcularFibonacci(int numero) {
        if (numero == 0) return 0;
        else if (numero == 1) return 1;
        else return calcularFibonacci(numero - 1) + calcularFibonacci(numero - 2);
    }

    public static void main(String[] args) {
        try {
            int numero = preencherNumeroValido();
            JOptionPane.showMessageDialog(
                    null,
                    String.format("Fibonacci(%d) = %d", numero, calcularFibonacci(numero)),
                    "Calculadora de Fibonacci",
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