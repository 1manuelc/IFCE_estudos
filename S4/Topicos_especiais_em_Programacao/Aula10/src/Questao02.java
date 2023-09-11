/* Construa um algoritmo que receba
um número positivo > 1 e <=10 e em seguida retorne
a tabuada com 10 multiplicações sucessivas.
Obs1.: Utilizar {try... catch para validação e caixas d e diálogo}
Obs2.: Realizar demais validações para os valores i nseridos.
*/
package S4.Topicos_especiais_em_Programacao.Aula10.src;

import javax.swing.JOptionPane;

public class Questao02 {
    public static StringBuilder construirString(int numero) {
        StringBuilder tabuadaDoNumero = new StringBuilder (
                String.format("Tabuada do %d:\n", numero)
        );

        for(int i = 0; i < 11; i++) {
            tabuadaDoNumero.append(String.format("%d * %d = %d", numero, i, numero * i));
            if(i != 10) tabuadaDoNumero.append("\n");
        }

        return tabuadaDoNumero;
    }

    public static void main(String[] args) {
        try {
            int numero = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                    "Digite um número inteiro entre 2 e 10",
                    "Tabuada de valor", JOptionPane.QUESTION_MESSAGE)
            );

            while(numero < 2 || numero > 10) numero = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                    "Digite um número inteiro VÁLIDO entre 2 e 10",
                    "Tabuada de valor", JOptionPane.QUESTION_MESSAGE)
            );

            JOptionPane.showMessageDialog(null,
                    construirString(numero),
                    "Tabuada de valor", JOptionPane.INFORMATION_MESSAGE);

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Digite um número inteiro",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
