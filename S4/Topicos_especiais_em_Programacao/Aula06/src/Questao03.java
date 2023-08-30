/*
* Elabore um algoritmo que verifique se um número é par ou ímpar (somente)
*/

package S4.Topicos_especiais_em_Programacao.Aula06.src;

import javax.swing.JOptionPane;

public class Questao03 {
    public static String analisarParidade(int numero) {
        if(numero == 0) return "neutro";
        else if(numero % 2 == 0) return "par";
        else return "impar";
    }

    public static void main(String[] args) {
        try {
            int numero = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite um número", "Analisador de números",
                    JOptionPane.QUESTION_MESSAGE));

            String paridade = analisarParidade(numero);

            JOptionPane.showMessageDialog(null,
                    String.format("Seu número, %d, é %s", numero, paridade),
                    "Analisador de números", JOptionPane.INFORMATION_MESSAGE);

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número inteiro",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
