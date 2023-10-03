package S4.Topicos_especiais_em_Programacao.Aula17.ClasseVeiculo;

public class Main {
    public static void main(String[] args) {
        Carro carroPopular = new Carro("Onix", 2015, 4, 5);
        Motocicleta motoPopular = new Motocicleta("XJ6", 2020, 2, "Esportiva Urbana");

        carroPopular.exibirDados();
        motoPopular.exibirDados();
    }
}
