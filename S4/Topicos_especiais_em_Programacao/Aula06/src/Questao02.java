/*
* Faça um algoritmo que receba um número e diga qual mês do ano ele representa
* caso contrário retorne uma mensagem de erro
*/

package S4.Topicos_especiais_em_Programacao.Aula06.src;

import javax.swing.JOptionPane;

public class Questao02 {
    public static void main(String[] args) {
        try {
            int numeroDoMes = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite um número:",
                    "Associador de meses", JOptionPane.QUESTION_MESSAGE));
            String[] meses = new String[] {"Janeiro", "Fevereiro", "Março", "Abril", "Maio",
                    "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

            if(numeroDoMes < 1 || numeroDoMes > 12) {
                JOptionPane.showMessageDialog(null,
                        "Seu número não representa um mês",
                        "Associador de meses", JOptionPane.INFORMATION_MESSAGE);
            } else {
                JOptionPane.showMessageDialog(null,
                        String.format("O numero %d representa o mês %s", numeroDoMes, meses[numeroDoMes - 1]),
                        "Associador de meses", JOptionPane.INFORMATION_MESSAGE);
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número inteiro",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
