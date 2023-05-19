/* AtivadeDeReposicao - 09/03/22
 *
 * 2) Escreva um programa que receba do usuário um vetor com 20 valores inteiros e
    apresente o maior, o menor e suas respectivas posições em que os mesmos foram
    informados. Caso existam números iguais mostre a posição da primeira ocorrência.
 *
 */
package S3.POO.Aula09_exs.src;

import java.util.Scanner;

public class Exercicio02 {
    public static void main(String[] args) {
        int vetor[] = new int[20];
        int indiceMaior = 0, indiceMenor = 0;
        Scanner in = new Scanner(System.in);

        System.out.println("Digite os valores desejados no vetor:");

        for(int i = 0; i < 20; i++) {
            System.out.printf("v[" + i + "] = ");
            vetor[i] = in.nextInt();

            if(vetor[i] > vetor[indiceMaior])
                indiceMaior = i;
                
            if(vetor[i] < vetor[indiceMenor])
                indiceMenor = i;
        } in.close();

        System.out.println("\nVetor");
        for(int i = 0; i < 20; i++) {
            System.out.printf("v[" + i + "] = " + vetor[i]);

            if(i == indiceMaior)
                System.out.println(" --> Maior valor");
            else if(i == indiceMenor)
                System.out.println(" --> Menor valor");
            else
                System.out.println("");
        }
    }
}
