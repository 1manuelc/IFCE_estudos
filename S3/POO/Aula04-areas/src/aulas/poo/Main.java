package aulas.poo;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int opcao;
        Scanner sc = new Scanner(System.in);
        Cabecalho cabecalho = new Cabecalho();

        do {
            cabecalho.imprimirCabecalho();
            opcao = sc.nextInt();

            if(opcao < 4 && opcao > 0) {
                double base, altura;

                System.out.println("Digite a base: ");
                base = sc.nextDouble();
                System.out.println("Digite a altura: ");
                altura = sc.nextDouble();

                if(opcao == 1 || opcao == 2) {
                    Quadrado_Retangulo qr = new Quadrado_Retangulo();
                    qr.setBase(base);
                    qr.setAltura(altura);

                    if (opcao == 1) {
                        System.out.println("Area do quadrado = " + qr.getArea());
                    } else {
                        System.out.println("Area do retangulo = " + qr.getArea());
                    }
                } else {
                        Triangulo tr = new Triangulo();
                        tr.setBase(base);
                        tr.setAltura(altura);

                        System.out.println("Area do triangulo = " + tr.getArea());
                }
            } else if(opcao == 4) {
                double raio;
                Circulo cc = new Circulo();

                System.out.println("Digite o raio: ");
                raio = sc.nextDouble();
                cc.setRaio(raio);

                System.out.printf("Area do circulo = %.2f\n", cc.getArea());
            }
        } while(opcao != 0);
        sc.close();
    }
}
