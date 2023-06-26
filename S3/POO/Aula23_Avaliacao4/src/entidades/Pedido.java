package S3.POO.Aula23_Avaliacao4.src.entidades;

import S3.POO.Aula23_Avaliacao4.src.enums.StatusDoPedido;

import java.util.Date;
import java.util.List;
import java.util.ArrayList;

public class Pedido {
    private Date instante;
    private StatusDoPedido status;
    private List<ItemDoPedido> itensDoPedido = new ArrayList<>();

    public Pedido() {}
    public Pedido(Date instante, StatusDoPedido status, List<ItemDoPedido> itensDoPedido) {
        this.instante = instante;
        this.status = status;
        this.itensDoPedido = itensDoPedido;
    }

    public Date getInstante() {return instante;}
    public StatusDoPedido getStatus() {return status;}
    public List<ItemDoPedido> getItensDoPedido() {
        return itensDoPedido;
    }

    public void adicionarItem(ItemDoPedido item) {
        getItensDoPedido().add(item);
    }
    public void removerItem(ItemDoPedido item) {
        getItensDoPedido().remove(item);
    }

    public Double total() {
        Double valorTotal = 0.0;
        for(ItemDoPedido itens : getItensDoPedido())
            valorTotal += itens.subTotal();
        return valorTotal;
    }
}
