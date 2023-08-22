package S4.Topicos_especiais_em_Programacao.Atividade03.src;/*
* #4. Faça um algoritmo que leia o tempo de duração de um evento em uma fábrica expresso
* em segundos e mostre-o expresso em horas e minutos.
*/

import javax.swing.JOptionPane;

public class Questao04 {
    public static void main(String[] args) {
        try {
            int segundos = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite a duração do evento em segundos:"));
            int horas = segundos / 3600, minutos = segundos % 3600 / 60;

            JOptionPane.showMessageDialog(null,
                    segundos + "s" + " = " + horas + "h " + minutos + "min",
                    "Conversor de duração de eventos",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Quantidade de segundos inválida", "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}