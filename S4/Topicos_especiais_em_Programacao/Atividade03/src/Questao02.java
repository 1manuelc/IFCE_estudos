package S4.Topicos_especiais_em_Programacao.Atividade03.src;/*
* #2.  Faça um programa que leia 2 números inteiros de entrada e imprima
* o resto da divisão inteira de um pelo outro.
*/

import javax.swing.JOptionPane;

public class Questao02 {
    public static void main(String[] args) {
        try {
            int num1, num2, resultado;

            num1 = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite um número inteiro:"));

            num2 = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite outro número inteiro:"));

            resultado = num1 % num2;

            JOptionPane.showMessageDialog(null,
                    "O resto da divisão inteira de " + num1 + " por " + num2 + " = " + resultado);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Número inválido", "Erro",
                    JOptionPane.ERROR_MESSAGE);
        }
    }
}