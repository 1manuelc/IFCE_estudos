package S3.POO.Aula23_Avaliacao4.src.entidades;

public class Produto {
    private String nomeProduto;
    private Double precoProduto;

    public Produto() {}
    public Produto(String nomeProduto, Double precoProduto) {
        this.nomeProduto = nomeProduto;
        this.precoProduto = precoProduto;
    }

    public String getNomeProduto() {return nomeProduto;}
    public Double getPrecoProduto() {return precoProduto;}
}
