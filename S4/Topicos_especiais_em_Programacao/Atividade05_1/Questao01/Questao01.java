package S4.Topicos_especiais_em_Programacao.Atividade05_1.Questao01;/*
* #1 - O gerente de vendas do supermercado FastExtra precisa de uma tabela em ordem decrescente dos preços dos
* produtos da seção de frios associados á seus nomes, visando analisar quais dos produtos serão contemplados na
* promoção semanal.
* Faça um programa em Java capaz de receber o nome e preço de cada produto da seção (no máximo 20), para que o
* estagiário possa preencher e exportar um arquivo .csv pronto para o gerente analisar.
*/

import javax.swing.JOptionPane;
import java.io.IOException;

public class Questao01 {
    public static void main(String[] args) {
       try {
           TabelaProdutos produtos = new TabelaProdutos(5);
           produtos.preencherProdutos();
           produtos.organizarProdutosEmPrecoDecrescente();
           produtos.exportarTabelaProdutos();

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