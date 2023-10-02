package S4.Topicos_especiais_em_Programacao.Atividade05_1.Questao03;

import javax.swing.JOptionPane;

public class DadosAluno {
    String nomeAluno;
    double[] notasAluno = new double[3];
    double media = 0;

    public void preencherDadosAluno() {
        nomeAluno = JOptionPane.showInputDialog(null,
                "Digite o nome do aluno:",
                "Gerador de tabela bimestral",
                JOptionPane.QUESTION_MESSAGE);

        for(int i = 0; i < notasAluno.length; i++) {
            notasAluno[i] = Double.parseDouble(
                    JOptionPane.showInputDialog(null,
                            String.format("Digite a nota %d:", (i + 1)),
                            "Gerador de tabela bimestral",
                            JOptionPane.QUESTION_MESSAGE)
            );
            media += notasAluno[i];
        } media /= 3;
    }
}
