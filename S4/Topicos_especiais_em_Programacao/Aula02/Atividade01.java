package S4.Topicos_especiais_em_Programacao.Aula02;

import java.util.Scanner;

public class Atividade01 {
    public static int verificarMaior(int num1, int num2) {
        if(num1 > num2) return num1;
        else return num2;
    }

    public static int verificarMenor(int num1, int num2) {
        if(num1 < num2) return num1;
        else return num2;
    }

    public static boolean verificarIgualdade(int num1, int num2) {
        if(num1 == num2) return true;
        else return false;
    }

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

        if(verificarIgualdade(numero1, numero2)) {
            System.out.println("\nMaior número: números iguais");
            System.out.println("Menor número: números iguais");
        } else {
            System.out.println("\nMaior número: " + verificarMaior(numero1, numero2));
            System.out.println("Menor número: " + verificarMenor(numero1, numero2));
        }
        System.out.println("São iguais? " + verificarIgualdade(numero1, numero2));
    }
}
