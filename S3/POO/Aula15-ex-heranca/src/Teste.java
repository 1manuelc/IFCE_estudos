public class Teste {
    public static void main(String[] args) {
        ImovelNovo imovelnovo = new ImovelNovo();
        ImovelVelho imovelvelho = new ImovelVelho();

        imovelnovo.setPreco(100000);
        imovelnovo.setAdicional(50000);
        imovelnovo.imprimirPreco();

        imovelvelho.setPreco(100000);
        imovelvelho.setDesconto(50000);
        imovelvelho.imprimirPreco();
    }
}
