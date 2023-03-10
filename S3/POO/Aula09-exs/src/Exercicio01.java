/* AtivadeDeReposicao - 09/03/22
 *
 * 1) Escreva um programa que leia dois vetores com 10 elementos cada e gere um
    terceiro vetor de 20 elementos, cujos valores deverão ser compostos pelos
    elementos intercalados dos dois outros vetores. Ao final o programa deverá mostrar
    os dois vetores originais e o terceiro vetor com os valores intercalados.
 *
 */

import java.util.Scanner;

public class Exercicio01 {
    public static void main(String[] args) {
        int vetor1[] = new int[10];
        int vetor2[] = new int[10];
        int vetor3[] = new int[20];

        Scanner in = new Scanner(System.in); {
            System.out.println("Digite os valores desejados p/ cada vetor:");
            for(int i = 0; i < 10; i++) {
                System.out.printf("vetor1[" + i + "] = ");
                vetor1[i] = in.nextInt();
            }

            for(int i = 0; i < 10; i++) {
                System.out.printf("vetor2[" + i + "] = ");
                vetor2[i] = in.nextInt();
            }
        } in.close();

        for(int i = 0; i < 20; i++) {
            if(i < 10)
                vetor3[i] = vetor1[i];
            else
                vetor3[i] = vetor2[i - 10];
        }

        System.out.println("\nPrimeiro vetor");
        for(int i = 0; i < 10; i++) {
            System.out.println("v1[" + i + "] = " + vetor1[i]);
        }

        System.out.println("\nSegundo vetor");
        for(int i = 0; i < 10; i++) {
            System.out.println("v2[" + i + "] = " + vetor2[i]);
        }

        System.out.println("\nTerceiro vetor");
        for(int i = 0; i < 20; i++) {
            System.out.println("v3[" + i + "] = " + vetor3[i]);
        }
    }
}