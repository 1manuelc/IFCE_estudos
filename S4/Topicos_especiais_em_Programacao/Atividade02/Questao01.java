/*
* #1. Construa um algoritmo que receba o nome e a idade de uma pessoa
* em anos e retorne como saída a idade em dias, horas, minutos e segundos.
* Obs.: Considerar para 1 ano = 365 dias.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02;

import java.util.Scanner;

public class Questao01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String nome;
        int idadeEmAnos, idadeEmDias, idadeEmHoras, idadeEmMinutos, idadeEmSegundos;

        System.out.print("Digite seu nome: ");
        nome = sc.nextLine();

        System.out.print("Digite sua idade (em anos): ");
        idadeEmAnos = sc.nextInt();

        idadeEmDias = idadeEmAnos * 365;
        idadeEmHoras = idadeEmDias * 24;
        idadeEmMinutos = idadeEmHoras * 60;
        idadeEmSegundos = idadeEmMinutos * 60;

        System.out.println("\nIdade de: " + nome);
        System.out.println("Em anos " + idadeEmAnos);
        System.out.println("Em dias: " + idadeEmDias);
        System.out.println("Em horas: " + idadeEmHoras);
        System.out.println("Em minutos: " + idadeEmMinutos);
        System.out.println("Em segundos: " + idadeEmSegundos);

        sc.close();
    }
}
