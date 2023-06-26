/*
    Elabore um programa que leia 10 salários. Após toda a entrada ter sido realizada,
    reajuste todos os salários em 10%. Em seguida, exiba todos os salários já
    reajustados. Utilize vetor para armazenar os salários. (5pt)
*/
package S3.POO.Aula11_Avaliacao1.src;

import java.util.Scanner;

public class Questao01 {
    public static void main(String[] args) {
        double[] salarios = new double[10];
        Scanner in = new Scanner(System.in);

        for(int i = 0; i < 10; i++) {
            System.out.printf("Salario %d: ", i);
            salarios[i] = in.nextDouble();
        } in.close();

        for(int j = 0; j < 10; j++)
            salarios[j] += (salarios[j] * 10/100);

        System.out.println("Salarios reajustados");
        for(int k = 0; k < 10; k++)
            System.out.println("Salario " + k + " = " + salarios[k]);
    }
}