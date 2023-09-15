package S4.Topicos_especiais_em_Programacao.Atividade04;

/* #3.  Construa um algoritmo que receba 100 números reais e informe qual deles
* é o maior.
* Obs.: Usar do while
*/

import javax.swing.JOptionPane;

public class Questao03 {
    public static void main(String[] args) {
        try {
            int i = 0, qtdNumeros = 100;
            double maiorNumero = 0;

            do {
                double numeroAtual =
                        Double.parseDouble(
                        JOptionPane.showInputDialog(null,
                                String.format("Digite um número real (%d/%d):", (i + 1), qtdNumeros),
                                "Analisador de Maior Número",
                                JOptionPane.QUESTION_MESSAGE)
                        );
                if(numeroAtual > maiorNumero) maiorNumero = numeroAtual;
                i++;
            } while(i < qtdNumeros);

            JOptionPane.showMessageDialog(null,
                    String.format("O maior número digitado foi %.2f", maiorNumero),
                    "Analisador de Maior Número",
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