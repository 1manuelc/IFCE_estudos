package S4.Topicos_especiais_em_Programacao.Atividade04;

/*
* #8. Leia uma quantidade de valores X determinados pelo usuário
* (parar quando o valor  digitado pra X for igual a zero). Para cada valor lido,
* mostrar se este valor é divisível por 3 e  mostrar quantos são divisíveis por 3.
* Obs.: Usar  while
*/

import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.List;

public class Questao08 {
    public static List<Integer> preencherListaValores(int qtdValores) {
        List<Integer> listaValores = new ArrayList<>();
        int contadorValores = 0;

        while(contadorValores != qtdValores) {
            int entradaAtual = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                    String.format("Digite o %d valor:", contadorValores + 1),
                    "Analisador Numérico",
                    JOptionPane.QUESTION_MESSAGE)
            );

            if(entradaAtual != 0) {
                listaValores.add(entradaAtual);
                contadorValores++;
            } else break;
        }

        return listaValores;
    }

    public static StringBuilder analisarDivisiveisPorTres(List<Integer> listaValores) {
        StringBuilder relatorio = new StringBuilder();
        int acumuladorDivisiveisPorTres = 0;

        for(int i = 0; i < listaValores.size(); i++) {
            relatorio.append(String.format("%d ", listaValores.get(i)));

            if(listaValores.get(i) % 3 == 0) {
                relatorio.append("é divisível por 3\n");
                acumuladorDivisiveisPorTres++;

            } else relatorio.append("não é divisível por 3\n");
        }

        relatorio.append(String.format("No total, %d números são divisíveis por 3",
                acumuladorDivisiveisPorTres));

        return relatorio;
    }

    public static void main(String[] args) {
        try {
            int qtdValores = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                            "Digite a quantidade de valores a serem lidos",
                            "Analisador Numérico",
                            JOptionPane.QUESTION_MESSAGE)
            );

            List<Integer> listaValores = preencherListaValores(qtdValores);

            JOptionPane.showMessageDialog(null,
                    analisarDivisiveisPorTres(listaValores),
                    "Analisador Numérico",
                    JOptionPane.INFORMATION_MESSAGE);

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