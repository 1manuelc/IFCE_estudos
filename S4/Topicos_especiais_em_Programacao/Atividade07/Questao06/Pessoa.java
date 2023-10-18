package S4.Topicos_especiais_em_Programacao.Atividade07.Questao06;

import javax.swing.JOptionPane;

public class Pessoa {
    String nome;
    int idade, dia, mes, anoNascimento;

    public Pessoa(String nome, int diaNasc, int mesNasc, int anoNasc) {
        this.nome = nome;
        this.dia = diaNasc;
        this.mes = mesNasc;
        this.anoNascimento = anoNasc;
        calcularIdade(2023);
    }

    public String obterNome() {return nome;}
    public int obterIdade() {return idade;}
    public void calcularIdade(int anoAtual) {idade = anoAtual - anoNascimento;}
    public void exibirInformacoes() {
        JOptionPane.showMessageDialog(
                null,
                String.format("%s tem %d anos", obterNome(), obterIdade()),
                String.format("Dados de %s", obterNome()),
                JOptionPane.INFORMATION_MESSAGE
        );
    }
}
