package S3.POO.Aula13_ex_encapsulamento.src;

import java.util.Scanner;

public class TesteProduto {
    public static void main(String[] args) {
        Produto produto = new Produto();
        Scanner in = new Scanner(System.in);

        System.out.print("Informe o preco de custo do produto: ");
        double precoCusto = in.nextDouble();
        produto.setPrecoCusto(precoCusto);

        System.out.print("Informe o preco de venda do produto: ");
        double precoVenda = in.nextDouble();
        produto.setPrecoVenda(precoVenda);

        System.out.println("Preco de custo do produto: " + produto.getPrecoCusto());
        System.out.println("Preco de venda do produto: " + produto.getPrecoVenda());
        in.close();
    }
}
