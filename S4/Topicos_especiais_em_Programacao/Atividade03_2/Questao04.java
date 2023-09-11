package S4.Topicos_especiais_em_Programacao.Atividade03_2;

/*
* #4. Construa um algoritmo que simule uma calculadora.
* O mesmo deverá receber um valor, um operador (+, -, *, /) e por fim outro valor,
* ao final o sistema deverá retornar o resultado. Vale lembrar que o algoritmo deverá
* validar situações como por exemplo: não existe divisão de número por Zero.
* (Utilizar  estrutura de múltipla escolha e caso necessite uma estrutura de seleção
* [simples/composta].)
*/

import javax.swing.JOptionPane;
import java.util.Objects;

public class Questao04 {
    public static double operar(double operando1, String operador, double operando2) {
        switch(operador) {
            case "+": return operando1 + operando2;
            case "-": return operando1 - operando2;
            case "*": return operando1 * operando2;
            case "/": return operando1 / operando2;
            case "^": return Math.pow(operando1, operando2);
        } return 0;
    }

    public static void main(String[] args) {
        try {
            double operando1, operando2;
            String operador;

            operando1 = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite o primeiro operando:",
                    "Calculadora básica", JOptionPane.QUESTION_MESSAGE));

            operador = JOptionPane.showInputDialog(null,
                    "Digite o operador:",
                    "Calculadora básica", JOptionPane.QUESTION_MESSAGE);

            operando2 = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite o segundo operando:",
                    "Calculadora básica", JOptionPane.QUESTION_MESSAGE));

            if(operando1 == 0 && Objects.equals(operador, "/") && operando2 == 0)
                JOptionPane.showMessageDialog(null,
                        "Impossível dividir 0 por 0\nResultado Indeterminado",
                        "Calculadora básica", JOptionPane.WARNING_MESSAGE);
            else if(operando1 == 0 && Objects.equals(operador, "^") && operando2 == 0)
                JOptionPane.showMessageDialog(null,
                        "Impossível elevar 0 á 0\nResultado Indeterminado",
                        "Calculadora básica", JOptionPane.WARNING_MESSAGE);
            else JOptionPane.showMessageDialog(null,
                        String.format("%.2f %s %.2f = %.2f", operando1, operador, operando2,
                                operar(operando1, operador, operando2)));

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número real",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
        }
    }
}