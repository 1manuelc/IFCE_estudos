package S3.POO.Aula17exs.FormaGeometrica.src;

import java.util.Scanner;

public class TesteFormaGeometrica {
    public static void imprimirMenu() {
        System.out.println("// Cálculos Geométricos, digite: //");
        System.out.println("0 - Para finalizar o programa.");
        System.out.println("1 - Para círculo.");
        System.out.println("2 - Para quadrado");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int opcao;

        do {
            imprimirMenu();
            opcao = sc.nextInt();

            switch (opcao) {
                case 1 -> {
                    Circulo circ = new Circulo();
                    System.out.println("Digite o raio do círculo:");
                    circ.setRaio(sc.nextDouble());

                    System.out.println("\nCírculo de raio = " + circ.getRaio() + ":");
                    System.out.println("Área = " + circ.getArea());
                    System.out.println("Comprimento = " + circ.getComprimento());

                } case 2 -> {
                    Quadrado quad = new Quadrado();
                    System.out.println("Digite o lado do quadrado:");
                    quad.setLado(sc.nextDouble());

                    System.out.println("\nQuadrado de lado = " + quad.getLado() + ":");
                    System.out.println("Área = " + quad.getArea());
                    System.out.println("Perímetro = " + quad.getComprimento());

                } default -> {
                    if (opcao != 0) System.out.println("Opcão inválida, digite um número entre 0 e 2.");
                }
            }
        } while(opcao != 0);

        System.out.println("\nFinalizando o programa...");
        sc.close();
    }
}
