package S4.Topicos_especiais_em_Programacao.Atividade03_1;/*
* #4. Elabore um algoritmo que verifique se um número é par ou ímpar.
* Obs.: Utilizar operador ternário.
*/

import javax.swing.JOptionPane;

public class Questao04 {
    public static String analisarParidade(int num) {
        return (num % 2 == 0) ? "par" : "ímpar";
    }

    public static void main(String[] args) {
        try {
            int numero = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite um número real:", "Analisador de Paridade",
                    JOptionPane.QUESTION_MESSAGE));

            JOptionPane.showMessageDialog(null,
                    String.format("%d é %s", numero, analisarParidade(numero)),
                    "Analisador de Paridade", JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número inteiro",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}