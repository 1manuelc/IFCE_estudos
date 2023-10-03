package S4.Topicos_especiais_em_Programacao.Atividade06.Questao02;
/*
 * #2.  Observe a figura abaixo e implemente a classe do diagrama, em seguida
 * crie um método com passagem de parâmetros e com retorno para cada um dos
 * atributos em seguida imprimi-los.
 */

import javax.swing.JOptionPane;

public class Produto {
    String nome, tipoProd;
    int quant;
    double valUnit;

    public void preencher_e_imprimir_valores() {
        nome = JOptionPane.showInputDialog(
                null,
                "Digite o nome do produto:",
                "Preenchimento de produto",
                JOptionPane.QUESTION_MESSAGE
        );

        tipoProd = JOptionPane.showInputDialog(
                null,
                "Digite o tipo do produto:",
                "Preenchimento de produto",
                JOptionPane.QUESTION_MESSAGE
        );

        quant = Integer.parseInt(
                JOptionPane.showInputDialog(
                    null,
                    "Digite a quantidade do produto:",
                    "Preenchimento de produto",
                    JOptionPane.QUESTION_MESSAGE
                )
        );

        valUnit = Double.parseDouble(
                JOptionPane.showInputDialog(
                        null,
                        "Digite o valor do produto:",
                        "Preenchimento de produto",
                        JOptionPane.QUESTION_MESSAGE
                )
        );

        JOptionPane.showMessageDialog(
                null,
                String.format(
                        "Nome do produto: %s\nTipo do Produto: %s\nQuantidade: %d\nValor da Unidade: R$ %.2f",
                        nome, tipoProd, quant, valUnit
                ),
                "Exibição de Produto",
                JOptionPane.INFORMATION_MESSAGE
        );
    }
}
