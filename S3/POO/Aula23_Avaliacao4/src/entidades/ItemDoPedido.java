package S3.POO.Aula23_Avaliacao4.src.entidades;

public class ItemDoPedido extends Produto {
    private Integer quantidade;
    private Double preco;

    public ItemDoPedido() {}
    public ItemDoPedido(String nomeProduto, Integer quantidade, Double preco) {
        super(nomeProduto, preco);
        this.quantidade = quantidade;
        this.preco = preco;
    }

    public Integer getQuantidade() {return quantidade;}
    public Double getPreco() {return preco;}

    public double subTotal() {return getPrecoProduto() * getQuantidade();}
}
