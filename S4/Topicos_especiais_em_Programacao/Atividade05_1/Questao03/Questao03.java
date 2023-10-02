package S4.Topicos_especiais_em_Programacao.Atividade05_1.Questao03;/*
* #3 - Você foi designado para criar um programa que permita aos professores gerar uma
* tabela de informações do boletim bimestral de um aluno na sua disciplina.
*
* Essa tabela é destinada ao sistema escolar, que vai gerar automaticamente um boletim
* impresso através de um modelo, sendo preenchido com: nome da disciplina, nome do
* professor, data de emissão, nome do aluno, 3 notas e média calculada á partir das notas.
*
* Utilize objetos e vetores para preencher e exportar a tabela em extensão csv.
* Obs: lide com exceções no programa, como entradas de formato errôneo e notas inválidas.*/

import javax.swing.JOptionPane;
import java.io.IOException;

public class Questao03 {
    public static void main(String[] args) {
        try {
            DadosTabela dados = new DadosTabela();
            dados.preencherDisciplina();
            dados.aluno.preencherDadosAluno();
            dados.gerarTabela();

        } catch(ArrayIndexOutOfBoundsException e) {
            JOptionPane.showMessageDialog(null,
                    "Índice fora do limite do array",
                    "Erro",
                    JOptionPane.ERROR_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número válido",
                    "Erro",
                    JOptionPane.ERROR_MESSAGE);

        } catch(NullPointerException | IOException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso",
                    JOptionPane.WARNING_MESSAGE);
        }
    }
}