package S4.Topicos_especiais_em_Programacao.Aula17.ClasseSocio;

import javax.swing.JOptionPane;

public class Socio {
    String nome;
    String endereco;
    String telefone;
    String cpf;

    public Socio(){}
    public Socio(String nome, String endereco, String telefone, String cpf) {
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.cpf = cpf;
    }

    public void preencherDadosSocio() {
        this.nome = JOptionPane.showInputDialog(null,
                "Digite o nome do Sócio:",
                "Novo Sócio",
                JOptionPane.QUESTION_MESSAGE);

        this.endereco = JOptionPane.showInputDialog(null,
                "Digite o endereço do Sócio:",
                "Novo Sócio",
                JOptionPane.QUESTION_MESSAGE);

        this.telefone = JOptionPane.showInputDialog(null,
                "Digite o número de telefone do Sócio:",
                "Novo Sócio",
                JOptionPane.QUESTION_MESSAGE);

        this.cpf = JOptionPane.showInputDialog(null,
                        "Digite o número de CPF do Sócio:",
                        "Novo Sócio",
                        JOptionPane.QUESTION_MESSAGE);
    }

    public void exibirDadosSocio() {
        JOptionPane.showMessageDialog(null,
                String.format("Nome: %s\nEndereço: %s\nTelefone: %s\nCPF: %s",
                        this.nome, this.endereco, this.telefone, this.cpf),
                "Dados do Sócio",
                JOptionPane.INFORMATION_MESSAGE);
    }
}
