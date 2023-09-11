package S4.Topicos_especiais_em_Programacao.Atividade03_2;

/*
* #1.  O IMC – Índice de Massa Corporal é um critério da Organização Mundial de Saúde para dar uma indicação
* sobre a condição de peso de uma pessoa adulta. A fórmula é IMC = peso / ( altura )2.
* Elabore um algoritmo que leia o nome, o peso e a altura de um adulto e mostre sua condição de acordo com a
* tabela abaixo. (Usar uma estrutura de seleção [simples/composta/encadeada])
    i) Abaixo de 18,5 Abaixo do peso;
    ii) Entre 18,5 e 24,9 Peso normal;
    iii) Entre 25 e 29,9 Acima do peso;
    iv) Entre 30 e 34,9  obesidade grau I;
    v) Entre 35 e 39,9 obesidade grau II;
    vi) Entre 40 e 49,9 obesidade grau III ou mórbida.
*/

import javax.swing.JOptionPane;

public class Questao01 {
    public static void imprimirAnaliseImc(double imc) {
        StringBuilder analiseImc = new StringBuilder();
        analiseImc.append(String.format("Com IMC = %.2f\nVocê está ", imc));

        if(imc < 18.5) analiseImc.append("abaixo do peso");
        else if(imc >= 18.5 && imc < 25.0) analiseImc.append("com peso normal");
        else if(imc >= 25.0 && imc < 30.0) analiseImc.append("acima do peso");
        else if(imc >= 30.0 && imc < 35.0) analiseImc.append("com obesidade grau I");
        else if(imc >= 35.0 && imc < 40.0) analiseImc.append("com obesidade grau II");
        else if(imc >= 40.0 && imc < 50.0) analiseImc.append("com obesidade grau III");

        JOptionPane.showMessageDialog(null,
                analiseImc,
                "Calculadora de IMC", JOptionPane.INFORMATION_MESSAGE);
    }

    public static void main(String[] args) {
        try {
            double peso, altura, imc;
            peso = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite seu peso:",
                    "Calculadora de IMC", JOptionPane.QUESTION_MESSAGE));

            altura = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite sua altura:",
                    "Calculadora de IMC", JOptionPane.QUESTION_MESSAGE));

            imc = peso / (altura * altura);

            imprimirAnaliseImc(imc);

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