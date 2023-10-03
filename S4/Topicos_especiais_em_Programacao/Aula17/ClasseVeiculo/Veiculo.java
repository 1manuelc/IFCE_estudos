package S4.Topicos_especiais_em_Programacao.Aula17.ClasseVeiculo;

abstract class Veiculo {
    String modelo;
    int ano, qtdRodas;

    public Veiculo(String modelo, int ano, int qtdRodas) {
        this.modelo = modelo;
        this.ano = ano;
        this.qtdRodas = qtdRodas;
    }

    public void exibirDados() {}
}
