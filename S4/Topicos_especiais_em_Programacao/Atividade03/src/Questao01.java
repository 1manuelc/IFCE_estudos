package S4.Topicos_especiais_em_Programacao.Atividade03.src;/*
* #1.  Faça um programa que leia um valor representando o gasto realizado por um cliente do
* restaurante COMABEM e imprima o valor total a ser pago, considerando os 10% do garçom.
*/

import javax.swing.JOptionPane;

public class Questao01 {
    public static void main(String[] args) {
        double valorGasto, valorTotal;
        try {
            valorGasto = Double.parseDouble(JOptionPane.showInputDialog(
                    null,
                    "Digite o valor gasto:"));

            valorTotal = valorGasto + (valorGasto * 10/100);

            JOptionPane.showMessageDialog(null,
                    String.format("R$%.2f", valorTotal),
                    "Restaurante COMABEM - Valor total",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Valor inválido!",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
