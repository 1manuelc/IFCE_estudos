package S4.Topicos_especiais_em_Programacao.Atividade07;
/*
* #5.  Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N.
*/

import javax.swing.JOptionPane;

public class Questao05 {
    public static int calcularSomatorio(int num) {
        if(num == 1) return 1;
        else return num + calcularSomatorio(num - 1);
    }

    public static int preencherNumeroValido() {
        int num = Integer.parseInt(
                JOptionPane.showInputDialog(
                        null,
                        "Digite um número inteiro positivo:",
                        "Calculadora de Somatório",
                        JOptionPane.QUESTION_MESSAGE
                )
        );

        while(num <= 1)
            num = Integer.parseInt(
                    JOptionPane.showInputDialog(
                            null,
                            "Digite um válido número inteiro positivo:",
                            "Calculadora de Somatório",
                            JOptionPane.QUESTION_MESSAGE
                    )
            );

        return num;
    }

    public static void main(String[] args) {
        try {
            int numero = preencherNumeroValido();
            JOptionPane.showMessageDialog(
                    null,
                    String.format("O somatório de 1 até %d = %d", numero, calcularSomatorio(numero)),
                    "Calculadora de Somatório",
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