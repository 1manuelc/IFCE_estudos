package S3.POO.Aula21_Avaliacao3.src.aplicacao;

import S3.POO.Aula21_Avaliacao3.src.classes.*;

import java.util.Scanner;

public class Main {
    public static void imprimeMenu() {
        System.out.println();
        System.out.println("Calculadora de Formas Geométricas");
        System.out.println("Digite:");
        System.out.println("[0] para sair do programa");
        System.out.println("[1] para círculo");
        System.out.println("[2] para quadrado");
    }
    
    public static void main(String[] args) {
        int opcao = 0;
        Scanner scan = new Scanner(System.in);

        do {
            imprimeMenu();
            opcao = scan.nextInt();

            switch(opcao) {
                case 1:
                    System.out.println("Digite o valor do raio:");
                    double raio = scan.nextDouble();

                    Circulo circuloAtual = new Circulo(raio);
                    circuloAtual.imprimeDados();

                    break;

                case 2:
                    System.out.println("Digite o valor do lado:");
                    double lado = scan.nextDouble();

                    Quadrado quadradoAtual = new Quadrado(lado);
                    
                    // Exibição sem modularizacao por definicao do enunciado do exercício
                    System.out.println("Quadrado de lado = " + quadradoAtual.getLado());
                    System.out.println("Area = " + quadradoAtual.area());
                    System.out.println("Perímetro/Comprimento = " + quadradoAtual.comprimento());

                    break;

                default:
                    if(opcao > 2 || opcao < 0) System.out.println("Opção inválida!");
                    break;
            }
        } while (opcao != 0);
        scan.close();

        System.out.println("Finalizando programa...");
    }
}
