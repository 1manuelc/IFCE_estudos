package S4.Topicos_especiais_em_Programacao.Atividade06.Questao03;
/*
* #3.  Observe a figura abaixo e implementa a classe do diagrama em seguida crie um
* método com passagem de parâmetros e sem retorno para imprimir todos os atributos.
* */

import javax.swing.JOptionPane;
public class Prontuario {
    String nome, sexo, fatorRH;
    int idade;
    double peso, altura;

    public void imprimirPaciente(String nome, String sexo, String fatorRH,
                                          int idade, double peso, double altura) {
        this.nome = nome;
        this.sexo = sexo;
        this.fatorRH = fatorRH;
        this.idade = idade;
        this.peso = peso;
        this.altura = altura;

        JOptionPane.showMessageDialog(
                null,
                String.format(
                        "Nome do paciente: %s\nSexo: %s\nFator RH: %s\nIdade: %d\nPeso: %.2f\nAltura: %.2f",
                        nome, sexo, fatorRH, idade, peso, altura
                ),
                "Dados do Paciente",
                JOptionPane.INFORMATION_MESSAGE
        );
    }
}
