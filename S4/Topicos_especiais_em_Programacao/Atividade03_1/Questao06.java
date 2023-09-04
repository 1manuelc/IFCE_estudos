package S4.Topicos_especiais_em_Programacao.Atividade03_1;/*
* #6. Construa um algoritmo que receba uma palavra e informe como
* retorno se o primeiro caracter dessa palavra é uma vogal.
* Obs.: Considerar a possibilidade desse caracter ser maiúsculo ou minúsculo.
* (DESAFIO!)
*/

import javax.swing.JOptionPane;

public class Questao06 {
    public static String iniciaComVogal(String texto) {
        char[] vetorVogais = new char[] {'a', 'A', 'e', 'E', 'i', 'I',
        'o', 'O', 'u', 'U'};

        for(char letra : vetorVogais)
            if(texto.startsWith(String.valueOf(letra))) return "inicia";
        return "não inicia";
    }

    public static void main(String[] args) {
        try {
            String texto = JOptionPane.showInputDialog(null,
                    "Digite um texto", "Analisador de caractere",
                    JOptionPane.QUESTION_MESSAGE);

            JOptionPane.showMessageDialog(null,
                    String.format("Seu texto %s com vogal", iniciaComVogal(texto)),
                    "Analisador de caractere", JOptionPane.INFORMATION_MESSAGE);

        } catch(Exception e) {
            JOptionPane.showMessageDialog(null,
                    "Erro inesperado", "Error",
                    JOptionPane.ERROR_MESSAGE);
        }
    }
}