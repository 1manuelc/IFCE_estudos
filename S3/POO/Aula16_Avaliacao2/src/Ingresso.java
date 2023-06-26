package S3.POO.Aula16_Avaliacao2.src;

public abstract class Ingresso {
    private double valor;
    public double getValor() {return valor;}
    public void setValor(double valor) {this.valor = valor;}
    public void imprimeValor() {System.out.println("Valor do Ingresso: R$" + getValor());}
}
