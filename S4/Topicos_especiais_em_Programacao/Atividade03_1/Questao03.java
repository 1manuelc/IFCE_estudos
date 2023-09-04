package S4.Topicos_especiais_em_Programacao.Atividade03_1;/*
* #3. Faça um algoritmo para verificar se o ano lido é bissexto.
* Obs.: O ano bissexto é divisível por 4.;
* Ano bissexto não pode ser divisível por 100;
* O Ano bissexto pode ser divisível por 400.
*/

import javax.swing.JOptionPane;

public class Questao03 {
    public static String analisarAno(int ano) {
        if((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0)))
            return "é";
        else return "não é";
    }

    public static void main(String[] args) {
        try {
            int ano = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite um ano:", "Verificador de Ano Bissexto",
                    JOptionPane.INFORMATION_MESSAGE));

            JOptionPane.showMessageDialog(null,
                    String.format("O ano %d %s bissexto", ano, analisarAno(ano)),
                    "Verificador de Ano Bissexto", JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número inteiro",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}