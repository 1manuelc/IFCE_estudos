package S4.Topicos_especiais_em_Programacao.Atividade04;

/*
* #6. Escreva um algoritmo que leia um número e diga se este número é perfeito ou não.
* Um número perfeito é aquele que é igual à soma de seus divisores.
* Ex: 6 =1+2+3,  28=1+2+4+7, etc..
* Obs.: Usar While
*/

import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;

public class Questao06 {
    public static StringBuilder construirStringSoma(List<Integer> listaDivisores) {
        StringBuilder stringDivisores = new StringBuilder();

        for(int j = 0; j < listaDivisores.size(); j++) {
            stringDivisores.append(listaDivisores.get(j));
            if(j != listaDivisores.size() - 1) stringDivisores.append(" + ");
        }

        return stringDivisores;
    }

    public static void main(String[] args) {
        try {
            List<Integer> listaDivisores = new ArrayList<>();
            int somatorioDivisores = 0, i = 1;
            int numero = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite um número inteiro:",
                    "Analisador de Número Perfeito", JOptionPane.QUESTION_MESSAGE));

            while(i < numero) {
                if (numero % i == 0) {
                    listaDivisores.add(i);
                    somatorioDivisores += i;
                    if (somatorioDivisores == numero) break;
                }
                i++;
            }

            if(somatorioDivisores == numero) {
                JOptionPane.showMessageDialog(null,
                        String.format("Os divisores de %d são %s = %d\n" +
                                        "O que o torna um número perfeito", numero,
                                construirStringSoma(listaDivisores), numero));
            } else {
                JOptionPane.showMessageDialog(null,
                        String.format("Os divisores de %d são %s != %d\n" +
                                        "O que não o torna um número perfeito", numero,
                                construirStringSoma(listaDivisores), numero));
            }

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número inteiro válido",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
        }
    }
}