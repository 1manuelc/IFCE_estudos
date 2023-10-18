package S4.Topicos_especiais_em_Programacao.Atividade07;
/*
* #3. Escreva uma função recursiva, potencia(x,y),
* que devolva x elevado a potência y, para y ≥ 0.
*/

import javax.swing.JOptionPane;

public class Questao03 {
    public static int calcularPotencia(int base, int expoente) {
        if(expoente == 1) return base;
        else return base * calcularPotencia(base, expoente - 1);
    }

    public static void main(String[] args) {
        try {
            int base = Integer.parseInt(
                    JOptionPane.showInputDialog(
                            null,
                            "Digite a base:",
                            "Calculadora de Potência",
                            JOptionPane.QUESTION_MESSAGE
                    )
            );

            int expoente = Integer.parseInt(
                    JOptionPane.showInputDialog(
                            null,
                            "Digite o expoente:",
                            "Calculadora de Potência",
                            JOptionPane.QUESTION_MESSAGE
                    )
            );

            JOptionPane.showMessageDialog(
                    null,
                    String.format("%d^%d = %d", base, expoente, calcularPotencia(base, expoente)),
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