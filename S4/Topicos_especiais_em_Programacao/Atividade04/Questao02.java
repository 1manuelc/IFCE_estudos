package S4.Topicos_especiais_em_Programacao.Atividade04;

/*
* #2. Faça um algoritmos que leia um número e diga se ele é perfeito ou não.
* Um número é perfeito se ele for igual a soma de seus divisores.
* Por exemplo: 1+2+3 = 6 ou 1+2+3+4+7 = 28, etc...
* Obs.: Usar do while
*/

import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;

public class Questao02 {
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

            do {
                if(numero % i == 0) {
                    listaDivisores.add(i);
                    somatorioDivisores += i;
                    if(somatorioDivisores == numero) break;
                } i++;
            } while(i < numero);

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