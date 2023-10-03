package S4.Topicos_especiais_em_Programacao.Atividade06.Questao04;
/*
* #4.  Observe a figura abaixo e implementa a classe do diagrama em seguida
* crie um método sem passagem de parâmetros e sem retorno para imprimir todos atributos.
*/

import javax.swing.JOptionPane;

public class Cliente {
    String nome, endereco, cpf;
    int telefone, rg;

    public Cliente(String nome, String endereco, String cpf,
                   int telefone, int rg) {
        this.nome = nome;
        this.endereco = endereco;
        this.cpf = cpf;
        this.telefone = telefone;
        this.rg = rg;
    }

    public void imprimirCliente() {
        JOptionPane.showMessageDialog(
                null,
                String.format(
                        "Nome do Cliente: %s\nEndereço: %s\nTelefone: %d\nRG: %d\nCPF: %s",
                        nome, endereco, telefone, rg, cpf
                ),
                "Dados do Cliente",
                JOptionPane.INFORMATION_MESSAGE
        );
    }
}
