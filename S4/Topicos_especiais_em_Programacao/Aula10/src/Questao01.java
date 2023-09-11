/*
* Construa um algoritmo que receba 5 nomes de pessoas e suas respectivas
idades e retorne os nomes e as idades dos mesmos.
Obs1.: Utilizar caixas de diálogo (JOptionPane)
Obs2.: try...catch para validação.
Obs3.: Validar a idade, não aceitar idade <=0 anos ou >125 anos.
*/

package S4.Topicos_especiais_em_Programacao.Aula10.src;

import javax.swing.JOptionPane;

public class Questao01 {
    public static void main(String[] args) {
        try {
            String[] vetorNomes = new String[5];
            int[] vetorIdades = new int[5];

            for(int i = 0; i < 5; i++) {
                vetorNomes[i] = JOptionPane.showInputDialog(null,
                        String.format("Digite o %dº nome:", (i + 1)),
                        "Prática de laços de repetição", JOptionPane.QUESTION_MESSAGE);

                vetorIdades[i] = Integer.parseInt(JOptionPane.showInputDialog(null,
                        "Digite a idade correspondente ao nome:",
                        "Prática de laços de repetição", JOptionPane.QUESTION_MESSAGE));

                while(vetorIdades[i] <= 0 || vetorIdades[i] > 125) {
                    vetorIdades[i] = Integer.parseInt(JOptionPane.showInputDialog(null,
                            String.format("Digite uma idade válida para o nome %s:", vetorNomes[i]),
                            "Prática de laços de repetição", JOptionPane.QUESTION_MESSAGE));
                }
            }

            for(int i = 0; i < 5; i++) {
                JOptionPane.showMessageDialog(null,
                        String.format("Nome: %s\nIdade: %d", vetorNomes[i], vetorIdades[i]),
                        "Prática de laços de repetição", JOptionPane.QUESTION_MESSAGE);
            }

        } catch (NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Erro desconhecido na execução",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch (NumberFormatException e) {
        JOptionPane.showMessageDialog(null,
                "Entrada inválida, digite números inteiros",
                "Erro", JOptionPane.ERROR_MESSAGE);
    }
    }
}
