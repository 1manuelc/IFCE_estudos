/*
* #1. Construa um vetor de 10 posições preencha-os com nomes de pessoas com a entrada
* de dados via formulários e exibí-los. Obs1.: Utilizar o laço de repetição for
* (inicializador;condicao; incremento) {...};
*/

import javax.swing.JOptionPane;

public class Questao01 {
    public static void main(String[] args) {
        try {
            String[] nomes = new String[10];
            StringBuilder todosOsNomes = new StringBuilder();

            for(int i = 0; i < 10; i++)
                nomes[i] = JOptionPane.showInputDialog(null,
                        String.format("Digite o %d nome:", (i + 1)),
                        "Armazenamento de nomes",
                        JOptionPane.QUESTION_MESSAGE);

            for(int i = 0; i < 10; i++) {
                todosOsNomes.append(String.format("Nome %d: %s", (i + 1), nomes[i]));
                if(i != (10 - 1)) todosOsNomes.append("\n");
            }

            JOptionPane.showMessageDialog(null,
                    "Nomes armazenados:\n" + todosOsNomes,
                    "Armazenamento de nomes",
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