package S4.Topicos_especiais_em_Programacao.Atividade04.Questao01;

/*
* #1. Construa um algoritmo que receba as 3 notas e o nome de 20 alunos
* e por fim informe o nome a média de cada um deles.
* Obs.: Usar for
*/

// uso do laço de repetição está dentro do método "preencherTurma" na classe "Turma"

import javax.swing.JOptionPane;

public class Main {
    public static void main(String[] args) {
        try {
            Turma turmaAtual = new Turma(5, 3);
            turmaAtual.preencherTurma();

            JOptionPane.showMessageDialog(null,
                    turmaAtual.retornarResultados(),
                    "Analisador de Notas", JOptionPane.INFORMATION_MESSAGE);

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