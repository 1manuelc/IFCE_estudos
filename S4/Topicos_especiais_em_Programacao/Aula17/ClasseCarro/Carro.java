package S4.Topicos_especiais_em_Programacao.Aula17.ClasseCarro;
import javax.swing.JOptionPane;

public class Carro {
    String modelo, marca;
    int ano;

    public Carro(String modelo, String marca, int ano) {
        this.modelo = modelo;
        this.marca = marca;
        this.ano = ano;
    }

    public void exibirDados() {
        JOptionPane.showMessageDialog(null,
                String.format(
                        "Modelo: %s\n" +
                        "Marca: %s\n" +
                        "Ano: %d", modelo, marca, ano),
                String.format("Dados %s", modelo),
                JOptionPane.INFORMATION_MESSAGE
        );
    }
}
