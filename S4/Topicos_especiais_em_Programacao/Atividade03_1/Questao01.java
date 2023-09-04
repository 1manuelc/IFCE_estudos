package S4.Topicos_especiais_em_Programacao.Atividade03_1;/*
* #1.  Faça um algoritmo para ler dois números é imprimir se eles são iguais,
* caso contrário, imprimir a mensagem: “os números são diferentes”.
*/

import javax.swing.JOptionPane;

public class Questao01 {
    public static void main(String[] args) {
        try {
            double num1, num2;

            num1 = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite um número:",
                    "Analisador de Igualdade Numérica", JOptionPane.QUESTION_MESSAGE));

            num2 = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite outro número:",
                    "Analisador de Igualdade Numérica", JOptionPane.QUESTION_MESSAGE));

            if(num1 == num2) JOptionPane.showMessageDialog(null,
                    "Os números são iguais",
                    "Analisador de Igualdade Numérica", JOptionPane.INFORMATION_MESSAGE);
            else JOptionPane.showMessageDialog(null,
                    "Os números são diferentes",
                    "Analisador de Igualdade Numérica", JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número real",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}