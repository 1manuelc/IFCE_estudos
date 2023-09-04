package S4.Topicos_especiais_em_Programacao.Atividade03_1;/*
* #5. Elabore um algoritmo utilizando o case no Java para que sejam
* verificadas as faixas etárias onde de:
* 0 .. 3 (bebê);
* 4 .. 10 (criança);
* 11 ..17 (adolescente),
* e acima de 17 anos adulto,
* de modo que o usuário digitará o nome e a idade de uma pessoa qualquer.
* Obs.: Utilizar estrutura de múltipla escolha (switch-case)
* e estrutura de seleção simples ou composta.
*/

import javax.swing.JOptionPane;

public class Questao05 {
    public static int analisarIdade(int idade) {
        if(idade < 4) return 0;
        else if(idade < 11) return 1;
        else if(idade < 18) return 2;
        else return 3;
    }

    public static void imprimirIdade(String nome, int idade, int idadeAtual) {
        switch(idadeAtual) {
            case 0:
                JOptionPane.showMessageDialog(null,
                        String.format("%s, sua idade é %d e você é bebê", nome, idade));
                break;
            case 1:
                JOptionPane.showMessageDialog(null,
                        String.format("%s, sua idade é %d e você é criança", nome, idade));
                break;
            case 2:
                JOptionPane.showMessageDialog(null,
                        String.format("%s, sua idade é %d e você é adolescente", nome, idade));
                break;
            case 3:
                JOptionPane.showMessageDialog(null,
                        String.format("%s, sua idade é %d e você é adulto/a", nome, idade));
                break;
        }
    }

    public static void main(String[] args) {
        try {
            String nome = JOptionPane.showInputDialog(null,
                    "Digite seu nome:", "Analisador de idade",
                    JOptionPane.QUESTION_MESSAGE);

            int idade = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite sua idade:", "Analisador de idade",
                    JOptionPane.QUESTION_MESSAGE));

            int idadeAtual = analisarIdade(idade);
            imprimirIdade(nome, idade, idadeAtual);

        } catch(NumberFormatException e) {
                JOptionPane.showMessageDialog(null,
                        "Entrada inválida, digite um número inteiro",
                        "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}