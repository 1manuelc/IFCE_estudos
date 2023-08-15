/*
* #1. Escreva um algoritmo para criar um programa de ajuda para vendedores.  A partir de um
*  valor total recebido do teclado, mostrar:
    - O total a pagar com desconto de 10%;
    - O valor de cada parcela, no parcelamento de 3x sem juros;
    - A comissão do vendedor, no caso da venda ser a vista (5% sobre o valor com desconto)
    - A comissão do vendedor, no caso da venda ser parcelada (5% sobre o valor total)
*/

package S4.Topicos_especiais_em_Programacao.Atividade02_1;

import java.util.Scanner;

public class Questao01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double valorDaCompra, valorAVista, valorParcelado;

        System.out.println("Calculadora dos vendedores");
        System.out.print("Digite o valor da compra: ");
        valorDaCompra = sc.nextDouble();

        valorAVista = valorDaCompra - (valorDaCompra * 10/100);
        valorParcelado = valorDaCompra / 3;

        System.out.println();
        System.out.println("Valor á vista com 10% de desconto: R$" + valorAVista);
        System.out.println("Valor parcelado em 3x sem juros: R$" + valorParcelado);

        System.out.println();
        System.out.println("Comissão para valor á vista: R$" + (valorAVista * 5/100));
        System.out.println("Comissão para valor á prazo: R$" + (valorDaCompra * 5/100));

        sc.close();
    }
}
