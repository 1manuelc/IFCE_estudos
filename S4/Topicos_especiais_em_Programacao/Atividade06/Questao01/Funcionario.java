package S4.Topicos_especiais_em_Programacao.Atividade06.Questao01;
/*
* #1. Observe a figura abaixo e implementa a classe do diagrama em seguida crie um
* método sem passagem de parâmetros e sem retorno para imprimir todos os atributos.
*/

public class Funcionario {
    String nome, funcao, endereco;
    int idade;
    double salario, numDep;

    public Funcionario(String nome, String funcao, String endereco,
                       int idade, double salario, double numDep) {
        this.nome = nome;
        this.funcao = funcao;
        this.endereco = endereco;
        this.idade = idade;
        this.salario = salario;
        this.numDep = numDep;
    }

    public void imprimirDados() {
        System.out.printf(
                "Nome: %s\nFunção: %s\nEndereço: %s\nIdade: %d\nSalário: R$ %.2f\nNúmero do Departamento: %.2f",
                nome, funcao, endereco, idade, salario, numDep
        );
    }
}
