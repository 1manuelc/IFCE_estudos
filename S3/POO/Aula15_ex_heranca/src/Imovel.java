package S3.POO.Aula15_ex_heranca.src;

public class Imovel {
    private String endereco;
    private double preco;

    public String getEndereco() {return endereco;}
    public void setEndereco(String endereco) {this.endereco = endereco;}
    public double getPreco() {return preco;}
    public void setPreco(double preco) {this.preco = preco;}
    public void imprimirPreco() {System.out.println("Preco do Imovel: R$" + this.preco);}
}