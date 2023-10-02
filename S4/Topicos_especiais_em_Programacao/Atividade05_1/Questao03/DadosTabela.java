package S4.Topicos_especiais_em_Programacao.Atividade05_1.Questao03;

import javax.swing.JOptionPane;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.FileWriter;

public class DadosTabela {
    DadosAluno aluno = new DadosAluno();
    String nomeDisciplina, nomeProfessor;
    int bimestre, ano;

    public void preencherDisciplina() {
        nomeDisciplina = JOptionPane.showInputDialog(null,
                "Digite o nome da disciplina:",
                "Gerador de tabela bimestral",
                JOptionPane.QUESTION_MESSAGE);

        nomeProfessor = JOptionPane.showInputDialog(null,
                "Digite o nome do professor:",
                "Gerador de tabela bimestral",
                JOptionPane.QUESTION_MESSAGE);

        bimestre = Integer.parseInt(JOptionPane.showInputDialog(null,
                "Digite o número do bimestre:",
                "Gerador de tabela bimestral",
                JOptionPane.QUESTION_MESSAGE)
        );

        ano = Integer.parseInt(JOptionPane.showInputDialog(null,
                "Digite o ano:",
                "Gerador de tabela bimestral",
                JOptionPane.QUESTION_MESSAGE)
        );
    }

    public void gerarTabela() throws IOException {
        FileWriter fonte = new FileWriter(String.format("%s_%.5s_%d_%d_notas.csv", nomeDisciplina, aluno.nomeAluno, bimestre, ano));
        PrintWriter escrita = new PrintWriter(fonte);

        escrita.print("nomeDisciplina;nomeProfessor;Bimestre;Ano\n");
        escrita.print(String.format("%s;%s;%d;%d\n", nomeDisciplina, nomeProfessor, bimestre, ano));
        escrita.print("nota01;nota02;nota03;media\n");
        for(int i = 0; i < 3; i++) escrita.print(String.format("%.2f;", aluno.notasAluno[i]));
        escrita.print(String.format("%.2f", aluno.media));

        escrita.close();
        fonte.close();

        JOptionPane.showMessageDialog(null,
                "Tabela gerada com sucesso!",
                "Gerador de tabela bimestral",
                JOptionPane.INFORMATION_MESSAGE);
    }
}
