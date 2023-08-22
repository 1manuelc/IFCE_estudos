package S4.Topicos_especiais_em_Programacao.Avaliacao01;
/*
* #3. Construa um algoritmo que leia dois números pontos
* flutuantes duplos (double) e forneça como saída o quadrado
* do primeiro número e a raíz décima quinta do segundo número.
* (2,0 pts)
*/

import javax.swing.JOptionPane;

public class Questao03 {
    public static double calcularQuadrado(double num) {
        return Math.pow(num, 2);
    }

    public static double calcularDecimaQuintaRaiz(double num) {
        return Math.pow(num, 1.0/15);
    }

    public static void main(String[] args) {
        try {
            double num1, num2;

            num1 = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite um número real:", "Calculadora de Quadrado e Raíz",
                    JOptionPane.QUESTION_MESSAGE));

            num2 = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite outro número real:", "Calculadora de Quadrado e Raíz",
                    JOptionPane.QUESTION_MESSAGE));

            JOptionPane.showMessageDialog(null,
                    num1 + "^2 = " + calcularQuadrado(num1) + "\n"
                            + num2 + "^1/15 = " + calcularDecimaQuintaRaiz(num2),
                    "Calculadora de Quadrado e Raíz", JOptionPane.INFORMATION_MESSAGE);

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite somente números reais", "Erro",
                    JOptionPane.ERROR_MESSAGE);
        }
    }
}