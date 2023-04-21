/*
    Crie um programa que leia um conjunto de notas, a quantidade de notas é
    determinada pelo usuário. Em seguida, calcule a média dessas notas. Ao final, exiba
    todas as notas maiores do que a média calculada. (5pt)
*/

import java.util.Scanner;
public class Questao02 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Digite a quantidade de notas: ");
        int qtdNotas = in.nextInt();

        double[] notas = new double[qtdNotas];
        double mediaNotas = 0;

        for(int i = 0; i < qtdNotas; i++) {
            System.out.printf("Nota %d: ", i + 1);
            notas[i] = in.nextDouble();
            mediaNotas += notas[i];
        } in.close();

        mediaNotas /= qtdNotas;

        System.out.println("Media = " + mediaNotas);
        for(double vetorNotas: notas) {
            if(vetorNotas > mediaNotas)
                System.out.println(vetorNotas);
        }
    }
}
