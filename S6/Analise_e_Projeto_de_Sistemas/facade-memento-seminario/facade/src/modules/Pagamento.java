package modules;

public class Pagamento {
    public boolean processarPagamento(String metodoPagamento) {
        System.out.println("Pagamento com " + metodoPagamento + " aprovado!");
        return true;
    }
}
