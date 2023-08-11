/*
* #3. Construa um algoritmo que calcule o preço de venda de um produto,
* sabendo que o lucro dever ser de 27,50% em relação ao preço de venda.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02;

import java.util.Scanner;

public class Questao03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double precoDeCompra, precoDeVenda;

        System.out.print("Digite o preço de compra do produto: ");
        precoDeCompra = sc.nextDouble();

        precoDeVenda = precoDeCompra + (precoDeCompra * 27.50/100);
        System.out.println("Preço de venda do produto: R$" + precoDeVenda);
        sc.close();
    }
}
