package S4.Topicos_especiais_em_Programacao.Atividade04;

/*
* #9. Escrever um algoritmo que leia um valor qualquer. A seguir, mostre se
* o valor lido é primo ou não é primo.
* Obs.: Usar for
*/

import javax.swing.JOptionPane;

public class Questao09 {
    public static String validarPrimo(int numero) {
        boolean statusPrimo = true;
        for(int i = 2; i < numero; i++)
            if (numero % i == 0) {
                statusPrimo = false;
                break;
            }
        return (statusPrimo) ? "é" : "não é";
    }

    public static void main(String[] args) {
        try {
            int valor = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                    "Digite um número:",
                    "Analisador de Número Primo",
                    JOptionPane.QUESTION_MESSAGE)
            );

            JOptionPane.showMessageDialog(null,
                    String.format("O número %d %s primo", valor, validarPrimo(valor)),
                    "Analisador de Número Primo",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número real",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
        }
    }
}