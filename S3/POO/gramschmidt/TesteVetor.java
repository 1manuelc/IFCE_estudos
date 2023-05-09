package S3.POO.gramschmidt;

import java.util.Scanner;

public class TesteVetor {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int espacoVetorial;
        System.out.print("Digite a dimensão do espaço vetorial desejado: ");
        espacoVetorial = in.nextInt();

        Vetor v1 = new Vetor();
        v1.preencherVetor(v1.coord, espacoVetorial);
        v1.exibirVetor(v1.coord, espacoVetorial);
        
        in.close();
    }
}
