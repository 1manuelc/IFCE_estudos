package S4.Topicos_especiais_em_Programacao.Atividade03.src;/*
* #3. Faça um algoritmo que leia as 3 notas de um aluno e calcule a média final deste aluno.
* Considerar que a média é ponderada e que o peso das notas são: 2,3 e 5, respectivamente.
*/

import javax.swing.JOptionPane;

public class Questao03 {
    public static double[] povoarNotas(int qtdeNotas) throws NumberFormatException {
        double[] vetorNotas = new double[qtdeNotas];
        for(int i = 0; i < vetorNotas.length; i++)
            vetorNotas[i] = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite a " + (i + 1) + "ª nota:"));
        return vetorNotas;
    }

    public static double calcularMediaPonderada(double[] vetorNotas) {
        double mediaPonderada = 0;
        for(int i = 0; i < vetorNotas.length; i++) {
            switch(i) {
                case 0: mediaPonderada += (2 * vetorNotas[i]); break;
                case 1: mediaPonderada += (3 * vetorNotas[i]); break;
                case 2: mediaPonderada += (5 * vetorNotas[i]); break;
            }
        }
        return (mediaPonderada /= 10);
    }

    public static void main(String[] args) {
        try {
            int qtdeNotas = 3;
            double[] vetorNotas = povoarNotas(qtdeNotas);
            double mediaFinal = calcularMediaPonderada(vetorNotas);

            JOptionPane.showMessageDialog(null,
                    String.format("Média final: %.2f", mediaFinal), "Calculadora de Média Ponderada",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Formato inválido de nota", "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}