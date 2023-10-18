package S4.Topicos_especiais_em_Programacao.Atividade07;
/*
* #4. Escreva uma função recursiva, mdc(x,y), que receba dois valores inteiros
* e que devolva o maior divisor comum aos dois valores recebidos.
*/

import javax.swing.JOptionPane;

public class Questao04 {
    public static int calcularMDC(int num1, int num2) {
        if(num2 == 0) return num1;
        else return calcularMDC(num2, num1 % num2);
    }

    public static void main(String[] args) {
        try {
            int num1 = Integer.parseInt(
                    JOptionPane.showInputDialog(
                            null,
                            "Digite um número inteiro:",
                            "Calculadora de MDC",
                            JOptionPane.QUESTION_MESSAGE
                    )
            );

            int num2 = Integer.parseInt(
                    JOptionPane.showInputDialog(
                            null,
                            "Digite outro número inteiro:",
                            "Calculadora de MDC",
                            JOptionPane.QUESTION_MESSAGE
                    )
            );

            JOptionPane.showMessageDialog(
                    null,
                    String.format("mdc(%d, %d) = %d", num1, num2, calcularMDC(num1, num2)),
                    "Calculadora de MDC",
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