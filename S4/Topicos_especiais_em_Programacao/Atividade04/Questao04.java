package S4.Topicos_especiais_em_Programacao.Atividade04;

/*
* #4. Faça um algoritmo para ler um número e
* retornar como resultado o fatorial desse número.
* Obs.: Usar for
*/

import javax.swing.JOptionPane;

public class Questao04 {
    public static void main(String[] args) {
        try {
            int numero = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                            "Digite um número:",
                            "Calculadora de Fatorial",
                            JOptionPane.QUESTION_MESSAGE)
            );

            int acumuladorFatorial = 1;
            for(int i = numero; i > 0; i--)
                acumuladorFatorial *= i;

            JOptionPane.showMessageDialog(null,
                    String.format("!%d = %d", numero, acumuladorFatorial),
                    "Calculadora de Fatorial",
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