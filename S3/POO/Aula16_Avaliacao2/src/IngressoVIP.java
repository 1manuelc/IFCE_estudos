package S3.POO.Aula16_Avaliacao2.src;

public class IngressoVIP extends Ingresso {
    private double valorAdicional;
    public double getValorAdicional() {return valorAdicional;}
    public void setValorAdicional(double valorAdicional) {this.valorAdicional = valorAdicional;}

    @Override
    public double getValor() {return super.getValor() + getValorAdicional();}
    public void imprimeValor() {System.out.println("Valor do Ingresso VIP: R$" + getValor());}
}
