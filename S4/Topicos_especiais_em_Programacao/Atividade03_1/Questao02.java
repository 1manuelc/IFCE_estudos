package S4.Topicos_especiais_em_Programacao.Atividade03_1;/*
 * #2.  Faça um algoritmo que leia os valores A, B, C e diga se
 * a média dos números é maior ou igual que um deles.
*/

import javax.swing.JOptionPane;

public class Questao02 {
    public static double[] povoarVetorNumeros(int qtdNumeros) {
        double[] vetorNumeros = new double[qtdNumeros];

        for(int i = 0; i < vetorNumeros.length; i++)
            vetorNumeros[i] = Double.parseDouble(JOptionPane.showInputDialog(null,
                    String.format("Digite o %dº número:", (i + 1)),
                    "Analisador Numérico", JOptionPane.QUESTION_MESSAGE));

        return vetorNumeros;
    }

    public static double calcularMedia(double[] vetorNumeros) {
        double acumuladorMedia = 0;
        for(double num : vetorNumeros) acumuladorMedia += num;
        acumuladorMedia /= 3;
        return acumuladorMedia;
    }

    public static int[] analisarMaiorOuIgual(double media, double[] vetorNumeros) {
        int[] vetorMaiores = new int[3];
        for(int i = 0; i < vetorNumeros.length; i++) {
            if (media >= vetorNumeros[i]) vetorMaiores[i] = i;
            else vetorMaiores[i] = -1;
        }
        return vetorMaiores;
    }

    public static StringBuilder construirStringMaiores(double[] vetorNumeros, int[] vetorMaiorOuIgual, double media) {
        StringBuilder numerosMaiores = new StringBuilder();

        numerosMaiores.append(String.format("Sua média %.2f é maior ou igual á:\n", media));

        for(int i = 0; i < vetorMaiorOuIgual.length; i++) {
            if(vetorNumeros[0] == -1 && vetorNumeros[1] == -1 && vetorNumeros[2] == -1)
                numerosMaiores.append("Nenhum dos números");

            else if (i == vetorMaiorOuIgual[i]) {
                numerosMaiores.append(String.format("%.2f", vetorNumeros[i]));

                if((i != vetorMaiorOuIgual.length - 1) && ((i + 1) == vetorMaiorOuIgual[i + 1]))
                    numerosMaiores.append(", ");
            }
        }
        numerosMaiores.append(".");

        return numerosMaiores;
    }

    public static void main(String[] args) {
        try {
            double[] vetorNumeros = povoarVetorNumeros(3);
            double media = calcularMedia(vetorNumeros);
            int[] vetorMaiorOuIgual = analisarMaiorOuIgual(media, vetorNumeros);
            StringBuilder numerosMaiores = construirStringMaiores(vetorNumeros,
                    vetorMaiorOuIgual, media);

            JOptionPane.showMessageDialog(null,
                    String.format("Sua média é %.2f", media),
                    "Analisador Numérico", JOptionPane.INFORMATION_MESSAGE);

            JOptionPane.showMessageDialog(null,
                    numerosMaiores, "Analisador numérico",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número real",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}