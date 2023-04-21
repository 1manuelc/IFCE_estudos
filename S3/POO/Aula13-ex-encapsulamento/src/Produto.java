public class Produto {
    private String nome;
    private double precoCusto;
    private double precoVenda;

    public String getNome() {return nome;}
    public void setNome(String nome) {this.nome = nome;}

    public double getPrecoCusto() {return precoCusto;}
    public void setPrecoCusto(double precoCusto) {this.precoCusto = precoCusto;}

    public double getPrecoVenda() {return precoVenda;}
    public void setPrecoVenda(double precoVenda) {
        if(precoVenda < precoCusto)
            System.out.println("[ALERTA DE PREJUIZO] Preco de venda menor que o preco de custo");
        this.precoVenda = precoVenda;
    }

    public double calcularMargemLucro() {return (this.precoVenda - this.precoCusto);}
}