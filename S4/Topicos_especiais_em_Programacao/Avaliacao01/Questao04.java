package S4.Topicos_especiais_em_Programacao.Avaliacao01;
/*
* #4. Faça um algoritmo que calcule o IMC- (Índice de massa corporal)
* de uma pessoa. Obs.: O algoritmo deverá fornecer como saída o nome
* completo, o peso, a altura e o IMC da pessoa.
* Obs.: Formatar os dados com 2 casas decimais. (2,0 pts)
*/

import javax.swing.JOptionPane;

public class Questao04 {
    public static void main(String[] args) {
        try {
            String nome = JOptionPane.showInputDialog(null,
                    "Digite seu nome:", "Calculadora de IMC",
                    JOptionPane.QUESTION_MESSAGE);

            double peso = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite seu peso:", "Calculadora de IMC",
                    JOptionPane.QUESTION_MESSAGE));

            double altura = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite sua altura:", "Calculadora de IMC",
                    JOptionPane.QUESTION_MESSAGE));

            double imc = peso / (Math.pow(altura, 2));

            JOptionPane.showMessageDialog(null,
                    String.format("Nome: %s\nPeso: %.2fkg\nAltura: %.2fm\nIMC = %.2f", nome, peso, altura, imc),
                    "Calculadora de IMC", JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Formato inválido.\nDigite números nos campos peso e altura.",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}