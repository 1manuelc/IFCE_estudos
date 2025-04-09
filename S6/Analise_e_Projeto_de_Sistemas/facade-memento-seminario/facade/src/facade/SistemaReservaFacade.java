package facade;

import modules.Assentos;
import modules.Autenticacao;
import modules.Confirmacao;
import modules.Pagamento;

public class SistemaReservaFacade {
    private Autenticacao autenticacao;
    private Assentos assentos;
    private Pagamento pagamento;
    private Confirmacao confirmacao;

    public SistemaReservaFacade() {
        this.autenticacao = new Autenticacao();
        this.assentos = new Assentos();
        this.pagamento = new Pagamento();
        this.confirmacao = new Confirmacao();
    }

    public void reservarIngresso(String usuario, String senha, int assento, String metodoPagamento, String email) {
        if (autenticacao.autenticarUsuario(usuario, senha) &&
                assentos.verificarDisponibilidade(assento) &&
                pagamento.processarPagamento(metodoPagamento)) {

            assentos.reservarAssento(assento);
            confirmacao.enviarConfirmacao(email);
            System.out.println("Reserva concluída com sucesso!");
        } else {
            System.out.println("Falha na reserva.");
        }
    }
}