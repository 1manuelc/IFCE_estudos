package S3.POO.Aula17exs.OperacaoMatematica.src;

import java.util.Scanner;

public class TesteOperacao {    
    public static void imprimirMenu() {
        System.out.println("// Operações Matemáticas, digite: //");
        System.out.println("0 - Para finalizar o programa.");
        System.out.println("1 - Para somar dois números.");
        System.out.println("2 - Para subtrair dois números.");
        System.out.println("3 - Para multiplicar dois números.");
        System.out.println("4 - Para dividir dois números.");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int opcao;

        do {
            imprimirMenu();
            opcao = sc.nextInt();
            double x = 0, y = 0;

            if(opcao > 0 && opcao < 5) {
                System.out.println("Digite o primeiro valor:");
                x = sc.nextDouble();
                System.out.println("Digite o segundo valor:");
                y = sc.nextDouble();
            }

            switch (opcao) {
                case 1 -> {
                    Soma add = new Soma();
                    System.out.println(x + " + " + y + " = " + add.calcula(x, y));

                } case 2 -> {
                    Subtracao sub = new Subtracao();
                    System.out.println(x + " - " + y + " = " + sub.calcula(x, y));

                } case 3 -> {
                    Multiplicacao mult = new Multiplicacao();
                    System.out.println(x + " * " + y + " = " + mult.calcula(x, y));

                } case 4 -> {
                    Divisao div = new Divisao();
                    System.out.println(x + " / " + y + " = " + div.calcula(x, y));

                } default -> {
                    if (opcao != 0) System.out.println("Opcão inválida, digite um número entre 0 e 4.");
                }
            }
        } while(opcao != 0);
        
        System.out.println("\nFinalizando o programa...");
        sc.close();
    }
}
