/*
* Elabore um algoritmo que receba dois números inteiros e verifique
* qual é o maior entre eles
*/

package S4.Topicos_especiais_em_Programacao.Aula06.src;

import javax.swing.JOptionPane;

public class Questao04 {
    public static int retornarMaior(double[] vetorNumeros) {
        if(vetorNumeros[0] == vetorNumeros[1]) return -1;
        else {
            if (vetorNumeros[0] > vetorNumeros[1]) return 0;
            else return 1;
        }
    }

    public static void main(String[] args) {
        try {
            double[] vetorNumeros = new double[2];
            vetorNumeros[0] = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite um número:", "Analisador de números",
                    JOptionPane.QUESTION_MESSAGE));
            vetorNumeros[1] = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite outro número:", "Analisador de números",
                    JOptionPane.QUESTION_MESSAGE));

            int maior = retornarMaior(vetorNumeros);

            switch(maior) {
                case -1: JOptionPane.showMessageDialog(null,
                        "Os números são iguais", "Analisador de números",
                        JOptionPane.INFORMATION_MESSAGE); break;
                case 0: JOptionPane.showMessageDialog(null,
                        String.format("O número %.1f é maior que %.1f", vetorNumeros[0], vetorNumeros[1]),
                        "Analisador de números", JOptionPane.INFORMATION_MESSAGE); break;
                case 1: JOptionPane.showMessageDialog(null,
                        String.format("O número %.1f é maior que %.1f", vetorNumeros[1], vetorNumeros[0]),
                        "Analisador de números", JOptionPane.INFORMATION_MESSAGE); break;
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número real",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
