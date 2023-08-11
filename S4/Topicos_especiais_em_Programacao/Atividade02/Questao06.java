/*
* #6. Elabore um algoritmo que receba o nome de um produto e devolva
* o valor de venda acrescido de 15%, tomando como base o valor de compra
* de um produto.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02;

import java.util.Scanner;

public class Questao06 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String nomeProduto;
        double precoDeCompra, precoDeVenda;

        System.out.print("Digite o nome do produto: ");
        nomeProduto = sc.nextLine();

        System.out.print("Digite o valor de compra do produto: ");
        precoDeCompra = sc.nextDouble();

        precoDeVenda = precoDeCompra + (0.15 * precoDeCompra);
        System.out.println("Preço de venda do produto: R$" + precoDeVenda);

        sc.close();
    }
}
