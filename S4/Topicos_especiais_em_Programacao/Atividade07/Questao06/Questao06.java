package S4.Topicos_especiais_em_Programacao.Atividade07.Questao06;
/*
* #6. Crie uma estrutura conforme a figura abaixo:
Métodos:
1-) calcularIdade(), que recebe a data atual em dias, mês e anos e calcula e  armazena no atributo idade a idade atual da pessoa;
2-) exibirIdade(), que retorna o valor da idade;
3-) exibirNome(), que retorna o nome da pessoa;
_________________________________________________
Obs1.:  Criar dois objetos a partir da classe Pessoa.
Obs2.:  Fazer uma classe principal que instancie os objetos, inicialize e mostre quais seriam as idades de Nicolau Copérnico e Galileu Galilei caso estivessem vivos.
*/

import javax.swing.JOptionPane;

public class Questao06 {
    public static void main(String[] args) {
        try {
            Pessoa nicolauCop = new Pessoa("Nicolau Copérnico", 19, 2, 1473);
            Pessoa galileuGal = new Pessoa("Galileu Galilei", 15, 2, 1564);

            nicolauCop.exibirInformacoes();
            galileuGal.exibirInformacoes();

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

        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso",
                    JOptionPane.WARNING_MESSAGE);
        }
    }
}