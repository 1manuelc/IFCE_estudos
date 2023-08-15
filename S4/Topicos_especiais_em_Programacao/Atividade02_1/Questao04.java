/*
* #4. Construa um algoritmo que receba três notas e calcule a média ponderada das notas.
* Obs.: As notas devem ser insiradas via teclado e logo após os pesos de cada nota também
* devem ser informados pelo usuário.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02_1;

import java.util.Scanner;

public class Questao04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int qtdNotas = 3;
        int[] vetorPesos = new int[qtdNotas];
        int somatorioPesos = 0;

        double[] vetorNotas = new double[qtdNotas];
        double notaFinal = 0;

        System.out.println("Calculadora de Média Ponderada de Três Notas");
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
