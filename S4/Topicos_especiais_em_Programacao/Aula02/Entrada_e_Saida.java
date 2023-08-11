package S4.Topicos_especiais_em_Programacao.Aula02;
import java.util.Scanner;

public class Entrada_e_Saida {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite seu nome: ");
        String nome = sc.nextLine();

        System.out.print("Digite sua idade: ");
        int idade = sc.nextInt();
        sc.close();

        System.out.println("Seu nome é " + nome);
        System.out.println("Sua idade é " + idade + " anos");
    }
}
