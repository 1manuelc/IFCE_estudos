/*
* #2. Construa um algoritmo que receba dois valores como entrada
*  e troque-os de posição, por fim informe o antes e o depois da troca.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02;

import java.util.Scanner;

public class Questao02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numero1, numero2, aux;

        System.out.print("Digite o primeiro número: ");
        numero1 = sc.nextInt();

        System.out.print("Digite o segundo número: ");
        numero2 = sc.nextInt();

        System.out.println("\nAntes da troca:\n\tnum1: " + numero1 + "\n\tnum2: " + numero2);
        aux = numero1;
        numero1 = numero2;
        numero2 = aux;
        System.out.println("\nDepois da troca:\n\tnum1: " + numero1 + "\n\tnum2: " + numero2);
    }
}
