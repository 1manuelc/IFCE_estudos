package S4.Topicos_especiais_em_Programacao.Atividade09_02etapa02.Questao01;

/*
 * #1. Construa um algoritmo que possua uma função que calcule a temperatura em 
 * Fahreinheit, Kelvin, Reaumur e Rankine. A função deverá possuir passagem de 
 * parâmentro sem retorno.
 */

import javax.swing.JOptionPane;

public class Questao01 {
    public static void converterTemperaturas(double tempCelsius) {
        double tempFahrenheit = (tempCelsius * 1.8) + 32;
        double tempKelvin = tempCelsius + 273.0;
        double tempReaumur = (tempCelsius * 4) / 5;
        double tempRankine = tempCelsius * 1.8 + 491.67;

        JOptionPane.showMessageDialog(
            null, 
            String.format(
                "(ºC) = %.2f\n" +
                "(ºF) = %.2f\n" +
                "(K) = %.2f\n" +
                "(ºRe) = %.2f\n" +
                "(ºRa) = %.2f",
                tempCelsius, tempFahrenheit, tempKelvin, tempReaumur, tempRankine
            ), 
            "Conversor de Temperaturas", 
            JOptionPane.INFORMATION_MESSAGE);
    }

    public static void main(String[] args) {
        try {
            double tempCelsius = Double.parseDouble(
                JOptionPane.showInputDialog(
                    null,
                    "Digite a temperatura em Celsius:",
                    "Conversor de Temperaturas",
                    JOptionPane.QUESTION_MESSAGE
                )
            );

            converterTemperaturas(tempCelsius);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(
                null, 
                "Digite um número válido", 
                "Exceção", 
                JOptionPane.WARNING_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(
                null, 
                "Execução cancelada", 
                "Exceção", 
                JOptionPane.WARNING_MESSAGE);
        } catch(Exception e) {
            JOptionPane.showMessageDialog(
                null, 
                "Interrupção da execução", 
                "Exceção", 
                JOptionPane.WARNING_MESSAGE);
        }
    }
}