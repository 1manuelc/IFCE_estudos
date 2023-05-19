package S3.POO.Aula15_ex_heranca.src;

public class ImovelVelho extends Imovel {
    private double desconto;
    public double getDesconto() {return desconto;}
    public void setDesconto(double desconto) {this.desconto = desconto;}

    @Override
    public double getPreco() {return super.getPreco() - this.desconto;}
    public void imprimirPreco() {System.out.println("Preco do Imovel Velho: R$" + (super.getPreco() - this.desconto));}
}
