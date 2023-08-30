/*
* Leia um número inteiro e imprima se ele é positivo ou não */

package S4.Topicos_especiais_em_Programacao.Aula06.src;

import javax.swing.JOptionPane;

public class Questao01 {
    public static void main(String[] args) {
        try {
            double numero = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite um número:",
                    "Analisador de números", JOptionPane.QUESTION_MESSAGE));

            boolean statusNumero = !(numero < 0);

            if(numero != 0) {
                if (statusNumero) JOptionPane.showMessageDialog(null,
                        "Seu número é positivo",
                        "Analisador de números",
                        JOptionPane.INFORMATION_MESSAGE);
                else JOptionPane.showMessageDialog(null,
                        "Seu número é negativo",
                        "Analisador de números",
                        JOptionPane.INFORMATION_MESSAGE);

            } else JOptionPane.showMessageDialog(null,
                    "Seu número é neutro",
                    "Analisador de números",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número real",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
