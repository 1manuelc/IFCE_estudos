/*
* #3.  Faça um algoritmo que calcule o IMC- (Índice de massa corporal) de uma pessoa.
* IMC: P/H2 . Onde: P é o peso e H a altura.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02_1;

import java.util.Scanner;

public class Questao03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double peso, altura, imc;

        System.out.println("Calculadora de IMC");
        System.out.print("Digite seu peso: ");
        peso = sc.nextDouble();

        System.out.print("Digite sua altura: ");
        altura = sc.nextDouble();

        imc = peso / Math.pow(altura, 2);
        System.out.println("Seu IMC é: " + imc);
        sc.close();
    }
}
