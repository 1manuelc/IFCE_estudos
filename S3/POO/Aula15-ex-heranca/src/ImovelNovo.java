public class ImovelNovo extends Imovel {
    private double adicional;
    public double getAdicional() {return adicional;}
    public void setAdicional(double adicional) {this.adicional = adicional;}

    @Override
    public double getPreco() {return super.getPreco() + this.adicional;}
    public void imprimirPreco() {System.out.println("Preco do Imovel Novo: R$" + (super.getPreco() + this.adicional));}
}
