package S4.Topicos_especiais_em_Programacao.Avaliacao01;
/*
* #2. Construa um algoritmo que receba o número de horas trabalhadas
* por uma pessoa e o valor do salário mínimo e mostre o salário a
* receber baseado nas seguintes regras:
*   I) O valor da hora trabalhada equivale a 2% do salário informado;
*
*   II) O salário bruto é dado pelo número de horas trabalhadas
*   multiplicado pelo valor de cada hora;
*
*   III)  O salário a receber é equivalente ao salário bruto subtraído do
*   imposto pago (4,5% sobre o valor do salário informado). (3,0 pts)
*/

import javax.swing.JOptionPane;

public class Questao02 {
    public static void main(String[] args) {
        try {
            int horasTrabalhadas = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite a quantidade de horas trabalhadas (número inteiro):",
                    "Calculadora de Salário", JOptionPane.QUESTION_MESSAGE));

            double valorSalarioMinimo = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite o valor do salário mínimo:",
                    "Calculadora de Salário", JOptionPane.QUESTION_MESSAGE));

            double valorDaHora = (valorSalarioMinimo * 2/100),
                    salarioBruto = horasTrabalhadas * valorDaHora,
                    salarioAReceber = salarioBruto - (salarioBruto * 4.5/100);

            JOptionPane.showMessageDialog(null,
                    String.format("Salário a receber: R$%.2f", salarioAReceber),
                    "Calculadora de Salário", JOptionPane.INFORMATION_MESSAGE);

        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Formato de entrada inválida, digite apenas números", "Erro",
                    JOptionPane.ERROR_MESSAGE);
        }
    }
}