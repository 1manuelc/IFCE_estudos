package S4.Topicos_especiais_em_Programacao.Aula17.ClasseVeiculo;

import javax.swing.JOptionPane;

public class Motocicleta extends Veiculo {
    String tipoDeMotocicleta;

    public Motocicleta(String modelo, int ano, int qtdRodas, String tipoDeMotocicleta) {
        super(modelo, ano, qtdRodas);
        this.tipoDeMotocicleta = tipoDeMotocicleta;
    }

    @Override
    public void exibirDados() {
        JOptionPane.showMessageDialog(null,
                String.format(
                        "Modelo: %s\nAno: %s\nQtd de Rodas: %d\nTipo de Motocicleta: %s",
                        super.modelo, super.ano, super.qtdRodas, tipoDeMotocicleta),
                "Dados do Carro",
                JOptionPane.INFORMATION_MESSAGE
        );
    }
}
