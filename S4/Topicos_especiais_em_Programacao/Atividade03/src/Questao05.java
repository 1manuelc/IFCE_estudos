package S4.Topicos_especiais_em_Programacao.Atividade03.src;/*
* #5. Faça um algoritmo que calcule o IMC- (Índice de massa corporal) de uma pessoa.
* IMC: P/H*H . Onde: P é o peso e H a altura.
*/

import javax.swing.JOptionPane;

public class Questao05 {
    public static void main(String[] args) {
        try {
            double peso = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite seu peso:", "Calculadora de IMC",
                    JOptionPane.QUESTION_MESSAGE));

            double altura = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite sua altura:", "Calculadora de IMC",
                    JOptionPane.QUESTION_MESSAGE));

            double imc = peso / (Math.pow(altura, 2));

            JOptionPane.showMessageDialog(null,
                    String.format("Seu IMC: %.2f.", imc), "Calculadora de IMC",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Formato inválido", "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}