package S3.POO.Aula17exs.OperacaoMatematica.src;

import java.util.Scanner;

public class TesteOperacao {    
    public static void imprimirMenu() {
        System.out.println("// Operações Matemáticas, digite: //");
        System.out.println("\t0 - Para finalizar o programa.");
        System.out.println("\t1 - Para somar dois números.");
        System.out.println("\t2 - Para subtrair dois números.");
        System.out.println("\t3 - Para multiplicar dois números.");
        System.out.println("\t4 - Para dividir dois números.");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int opcao;

        do {
            imprimirMenu();
            opcao = sc.nextInt();

            System.out.println("Digite o primeiro valor:");
            double x = sc.nextDouble();
            System.out.println("Digite o segundo valor:");
            double y = sc.nextDouble();

            switch(opcao) {
                case 1:
                    Soma add = new Soma();
                    System.out.println("O resultado é:" + add.calcula(x, y));
                    break;
                case 2:
                    Subtracao sub = new Subtracao();
                    System.out.println("O resultado é:" + sub.calcula(x, y));
                    break;
                case 3:
                    Multiplicacao mult = new Multiplicacao();
                    System.out.println("O resultado é:" + mult.calcula(x, y));
                    break;
                case 4:
                    Divisao div = new Divisao();
                    System.out.println("O resultado é:" + div.calcula(x, y));
                    break;
                default:
                    if(opcao != 0)
                        System.out.println("Opcão inválida, digite um número entre 0 e 4.");
            }

        } while(opcao != 0);
        
        System.out.println("\nFinalizando o programa...");
        sc.close();
    }
}
