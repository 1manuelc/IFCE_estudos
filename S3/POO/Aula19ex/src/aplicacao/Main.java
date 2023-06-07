package S3.POO.Aula19ex.src.aplicacao;
import S3.POO.Aula19ex.src.classes.Circulo;
import S3.POO.Aula19ex.src.classes.Quadrado;
import S3.POO.Aula19ex.src.classes.Retangulo;

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void imprimirMenu(int i) {
        System.out.println("(" + (i + 1) + ") Qual forma você deseja criar? Digite:");
        System.out.println("1 para Círculo");
        System.out.println("2 para Quadrado");
        System.out.println("3 para Retângulo");
    }

    public static void imprimirLista(List<Object> vetorObj) {
        System.out.println("\nExibição das formas criadas:");
        
        for(int k = 0; k < vetorObj.size(); k++) {  
            if(vetorObj.get(k) instanceof Circulo) {
                Circulo circAtual = (Circulo) vetorObj.get(k);

                System.out.println("Circulo de raio = " + circAtual.getRaio());
                System.out.println("Area = " + circAtual.area());
                System.out.println("Comprimento = " + circAtual.perimetro());

            } else if(vetorObj.get(k) instanceof Quadrado) {
                Quadrado quadAtual = (Quadrado) vetorObj.get(k);

                    System.out.println("Quadrado de lado = " + quadAtual.getLado());
                System.out.println("Area = " + quadAtual.area());
                System.out.println("Perímetro = " + quadAtual.perimetro());

            } else if(vetorObj.get(k) instanceof Retangulo) {
                Retangulo retAtual = (Retangulo) vetorObj.get(k);

                System.out.println("Retangulo de base = " + retAtual.getBase() + " e altura = " + retAtual.getAltura());
                System.out.println("Area = " + retAtual.area());
                System.out.println("Perímetro = " + retAtual.perimetro());
            }
            
            System.out.println();
        }
    }

    public static List<Object> povoarLista(int qtdObj, List<Object> vetorObj) {
        Scanner scanner = new Scanner(System.in);
        int i = 0;

        while(i < qtdObj) {
            int opcao;
            imprimirMenu(i);
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    double raio;
                    System.out.println("Digite o raio desejado para o círculo: ");
                    raio = scanner.nextDouble();

                    Circulo circ = new Circulo(raio);
                    vetorObj.add(circ);
                    break;
                    
                case 2:
                    double lado;
                    System.out.println("Digite o lado desejado para o quadrado: ");
                    lado = scanner.nextDouble();

                    Quadrado quad = new Quadrado(lado);
                    vetorObj.add(quad);
                    break;
                    
                case 3:
                    double base, altura;
                    System.out.println("Digite a base desejada para o retângulo: ");
                    base = scanner.nextDouble();

                    System.out.println("Digite a altura desejada para o retângulo: ");
                    altura = scanner.nextDouble();

                    Retangulo retan = new Retangulo(base, altura);
                    vetorObj.add(retan);
                    break;

                default:
                    while (opcao < 0 || opcao > 3) {
                        System.out.println("Opção inválida, digite novamente");
                        opcao = scanner.nextInt();
                    }
            }
            i++;
        }

        scanner.close();
        return vetorObj;
    }

    public static void main(String[] args) {
        int qtdeFormas;
        Scanner scanner = new Scanner(System.in);
        List<Object> vetorObjetos = new ArrayList<>();

        System.out.println("Digite a quantidade de formas que deseja criar: ");
        qtdeFormas = scanner.nextInt();
        scanner.close();

        vetorObjetos = povoarLista(qtdeFormas, vetorObjetos);
        imprimirLista(vetorObjetos);
    }
}
