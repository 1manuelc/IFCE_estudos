package S4.Topicos_especiais_em_Programacao.Atividade04.Questao01;

import javax.swing.JOptionPane;

public class Turma {
    int qtdNotas, qtdAlunos;
    String[] nomeDosAlunos;
    double[][] notas;

    public Turma() {}
    public Turma(int qtdAlunos, int qtdNotas) {
        this.qtdAlunos = qtdAlunos;
        this.qtdNotas = qtdNotas;
        this.nomeDosAlunos = new String[qtdAlunos];
        this.notas = new double[qtdAlunos][qtdNotas + 1];
    }

    public void preencherTurma() {
        for(int i = 0; i < nomeDosAlunos.length; i++) {
            double acumuladorMedia = 0.0;

            nomeDosAlunos[i] = JOptionPane.showInputDialog(null,
                    String.format("Digite o nome do %d aluno:", (i + 1)),
                    "Analisador de Notas", JOptionPane.QUESTION_MESSAGE);

            for(int j = 0; j < qtdNotas; j++) {
                notas[i][j] = Double.parseDouble(JOptionPane.showInputDialog(null,
                        String.format("Digite a %d nota do aluno %s:", (j + 1), (i + 1)),
                        "Analisador de Notas", JOptionPane.QUESTION_MESSAGE));
                acumuladorMedia += notas[i][j];
            } notas[i][qtdNotas] = acumuladorMedia / qtdNotas;
        }
    }

    public StringBuilder retornarResultados() {
        StringBuilder resultadoDaTurma = new StringBuilder("Resultado da Turma:\n");
        for(int i = 0; i < nomeDosAlunos.length; i++) {
            resultadoDaTurma.append(String.format("Aluno/a: %s, média final: %.2f", nomeDosAlunos[i], notas[i][3]));
            if(i != nomeDosAlunos.length - 1) resultadoDaTurma.append("\n");
        }
        return resultadoDaTurma;
    }
}
