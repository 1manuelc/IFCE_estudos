package S4.Topicos_especiais_em_Programacao.Atividade03.src;/*
* #6. Faça um programa que receba o número de lados de um polígono convexo,
* calcule e mostre o número de diagonais desse polígono.
* Sabe-se que ND = N * (N – 3)/2, onde N é o número de lados do polígono.
*/

import javax.swing.JOptionPane;

public class Questao06 {
    public static void main(String[] args) {
        try {
            int numeroDeLados = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite o número de lados do polígono:",
                    "Calculadora de Diagonais Poligonais",
                    JOptionPane.QUESTION_MESSAGE));

            int numeroDeDiagonais = (numeroDeLados * (numeroDeLados - 3)) / 2;

            JOptionPane.showMessageDialog(null,
                    "Polígono de " + numeroDeLados + " lados = " + numeroDeDiagonais + " diagonais",
                    "Calculadora de Diagonais Poligonais",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Formato inválido de entrada.\nDigite um número inteiro.",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}