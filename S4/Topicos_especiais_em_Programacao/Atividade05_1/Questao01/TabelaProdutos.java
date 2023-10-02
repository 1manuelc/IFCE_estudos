package S4.Topicos_especiais_em_Programacao.Atividade05_1.Questao01;

import javax.swing.JOptionPane;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class TabelaProdutos {
    String[] nomeProdutos;
    double[] precoProdutos;

    public TabelaProdutos(){}
    public TabelaProdutos(int numProdutos) {
        this.nomeProdutos = new String[numProdutos];
        this.precoProdutos = new double[numProdutos];
    }

    public void preencherProdutos() {
        int i = 0;
        while(i < nomeProdutos.length) {
            this.nomeProdutos[i] = JOptionPane.showInputDialog(null,
                    String.format("Digite o nome do produto (%d/%d):", (i + 1), nomeProdutos.length),
                    "Organizador de Produtos",
                    JOptionPane.QUESTION_MESSAGE);
            this.precoProdutos[i] = Double.parseDouble(
                    JOptionPane.showInputDialog(null,
                            String.format("Digite o preço do produto (%d/%d):", (i + 1), nomeProdutos.length),
                            "Organizador de Produtos",
                            JOptionPane.QUESTION_MESSAGE)
            );
            i++;
        }
    }

    public void organizarProdutosEmPrecoDecrescente() {
        double precoAux;
        String nomeAux;

        for(int i = 0; i < nomeProdutos.length; i++) {
            for(int j = 0; j < nomeProdutos.length; j++) {
                if(precoProdutos[i] > precoProdutos[j]) {
                    precoAux = precoProdutos[i];
                    precoProdutos[i] = precoProdutos[j];
                    precoProdutos[j] = precoAux;

                    nomeAux = nomeProdutos[i];
                    nomeProdutos[i] = nomeProdutos[j];
                    nomeProdutos[j] = nomeAux;
                }
            }
        }
    }

    public void exportarTabelaProdutos() throws IOException {
        FileWriter fonte = new FileWriter("export.csv");
        PrintWriter escrita = new PrintWriter(fonte);

        escrita.println("NomeProduto;PrecoProduto");
        for(int i = 0; i < nomeProdutos.length; i++) {
            escrita.print(String.format("%s;%.2f", nomeProdutos[i], precoProdutos[i]));
            if(i != (nomeProdutos.length) - 1) escrita.print("\n");
        }

        escrita.close();
        fonte.close();
        JOptionPane.showMessageDialog(null,
                "Tabela exportada com sucesso em \"export.csv\"",
                "Organizador de Produtos",
                JOptionPane.INFORMATION_MESSAGE);
    }
}
