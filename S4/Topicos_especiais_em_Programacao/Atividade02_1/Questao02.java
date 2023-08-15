/*
* #2. Faça uma algoritmo que calcule a média ponderada entre dois valores, de forma
* que seja indicado os valores e os pesos pelo usuário do sistema, ao final imprima
* o resultado na tela.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02_1;

import java.util.Scanner;

public class Questao02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int qtdNotas = 2;
        int[] vetorPesos = new int[qtdNotas];
        int somatorioPesos = 0;

        double[] vetorNotas = new double[qtdNotas];
        double notaFinal = 0;

        System.out.println("Calculadora de Média Ponderada de Duas Notas");
        System.out.println("Digite as notas primeiro.");

        for(int i = 0; i < qtdNotas; i++) {
            System.out.print("Nota " + (i + 1) + ": ");
            vetorNotas[i] = sc.nextDouble();
        }

        System.out.println("\nAgora digite os pesos.");

        for(int i = 0; i < qtdNotas; i++) {
            System.out.print("Peso " + (i + 1) + ": ");
            vetorPesos[i] = sc.nextInt();
        }

        for(int i = 0; i < qtdNotas; i++) {
            notaFinal += vetorPesos[i] * vetorNotas[i];
            somatorioPesos += vetorPesos[i];
        }

        notaFinal /= somatorioPesos;
        System.out.println("\nSua nota final é: " + notaFinal);

        sc.close();
    }
}
