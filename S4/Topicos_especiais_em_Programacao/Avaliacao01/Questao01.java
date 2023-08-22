package S4.Topicos_especiais_em_Programacao.Avaliacao01;
/*
* #1. Escreva um algoritmo para criar um programa de ajuda para vendedores.
* A partir de um valor total recebido pelo teclado, o programa deverá mostrar:
* I)  O total a pagar com desconto de 10% (pagamento à vista);
*
* II) (Informar o valor com os juros de 10% ), o valor de cada parcela, no parcelamento de 3x já com juros de 10% ;
*
* III) A comissão do vendedor, (comissão do vendedor será de 5% sobre o valor total a pagar). (3,0 pts)
*/

import javax.swing.JOptionPane;

public class Questao01 {
    public static void main(String[] args) {
        try {
            double valorTotal = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite o valor total da compra:", "Calculadora de Venda", JOptionPane.QUESTION_MESSAGE));

            double valorAVista = valorTotal - (valorTotal * 10/100),
                    valorParcelado = valorTotal + (valorTotal * 10/100),
                    valorDaParcela = valorParcelado / 3,
                    comissaoDoVendedor = valorTotal * 5/100;

            JOptionPane.showMessageDialog(null,
                    String.format("Valor total da compra: R$%.2f\n" +
                            "Valor á vista: R$%.2f\n" +
                            "Valor á prazo: R$%.2f, 3x de R$%.2f\n" +
                            "Comissão do vendedor: R$%.2f", valorTotal, valorAVista, valorParcelado,
                            valorDaParcela, comissaoDoVendedor),
                    "Calculadora de Venda", JOptionPane.INFORMATION_MESSAGE);

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Formato de entrada inválido, digite apenas números.", "Erro",
                    JOptionPane.ERROR_MESSAGE);
        }
    }
}
