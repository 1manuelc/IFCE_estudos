package S4.Topicos_especiais_em_Programacao.Atividade04;

/*
* #10. Leia 1 variável X inúmeras vezes (parar quando o valor digitado for <= 0).
* Para cada valor lido mostre a sequência de 1 até o valor lido.
* Obs.: Usar while.
*/

import javax.swing.JOptionPane;

public class Questao10 {
    public static void main(String[] args) {
        try {
            int valor = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                            "Digite um número inteiro:",
                            "Sequência Numérica",
                            JOptionPane.QUESTION_MESSAGE)
            );

            while(valor > 0) {
                StringBuilder stringSequencia = new StringBuilder();
                for(int i = 1; i <= valor; i++) {
                    stringSequencia.append(i);
                    if(i != valor) stringSequencia.append(", ");
                    if(i % 10 == 0) stringSequencia.append("\n");
                }

                JOptionPane.showMessageDialog(null,
                        stringSequencia,
                        "Sequência Numérica",
                        JOptionPane.INFORMATION_MESSAGE
                );

                valor = Integer.parseInt(
                        JOptionPane.showInputDialog(null,
                                "Digite um número inteiro:",
                                "Sequência Numérica",
                                JOptionPane.QUESTION_MESSAGE)
                );
            }

            JOptionPane.showMessageDialog(null,
                    "Fim da Execução",
                    "Sequência Numérica",
                    JOptionPane.INFORMATION_MESSAGE
            );

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número inteiro",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
        }
    }
}
