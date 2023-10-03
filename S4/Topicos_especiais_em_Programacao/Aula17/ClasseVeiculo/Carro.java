package S4.Topicos_especiais_em_Programacao.Aula17.ClasseVeiculo;

import javax.swing.JOptionPane;

public class Carro extends Veiculo {
    int qtdPortas;

    public Carro(String modelo, int ano, int qtdRodas, int qtdPortas) {
        super(modelo, ano, qtdRodas);
        this.qtdPortas = qtdPortas;
    }

    @Override
    public void exibirDados() {
        JOptionPane.showMessageDialog(null,
                String.format(
                        "Modelo: %s\nAno: %s\nQtd de Rodas: %d\nQtd de Portas: %d",
                        super.modelo, super.ano, super.qtdRodas, qtdPortas),
                "Dados do Carro",
                JOptionPane.INFORMATION_MESSAGE
        );
    }
}
