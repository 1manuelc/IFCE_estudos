package S4.Topicos_especiais_em_Programacao.Atividade03.src;/*
* #7. Escreva um algoritmo que leia a distância percorrida por uma automóvel (em km)
* e o intervalo de tempo correspondente (em horas) e a seguir calcule e imprima a sua velocidade
* média no percurso em km/h e em m/s.
*/

import javax.swing.JOptionPane;

public class Questao07 {
    public static void main(String[] args) {
        try {
            double kmTotais = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite a quantidade de KM percorrida:", "Calculadora de Velocidade",
                    JOptionPane.QUESTION_MESSAGE));

            int horasTotais = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite a duração da viagem em horas:", "Calculadora de Velocidade",
                    JOptionPane.QUESTION_MESSAGE));

            double mediaKmH = kmTotais / horasTotais, mediaMs = mediaKmH / 3.6;

            JOptionPane.showMessageDialog(null,
                    String.format("Sua média foi de:\n %.2fkm/h ou %.2fm/s", mediaKmH, mediaMs),
                    "Calculadora de Velocidade", JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showInputDialog(null,
                    "Formato de entrada inválido",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}