package client;

import modules.Assentos;
import modules.Autenticacao;
import modules.Confirmacao;
import modules.Pagamento;

public class ClienteSemFacade {
    public static void main(String[] args) {
        Autenticacao autenticacao = new Autenticacao();
        Assentos assentos = new Assentos();
        Pagamento pagamento = new Pagamento();
        Confirmacao confirmacao = new Confirmacao();

        if (autenticacao.autenticarUsuario("usuario123", "senha456")) {
            if (assentos.verificarDisponibilidade(10)) {
                if (pagamento.processarPagamento("Cartão de Crédito")) {
                    assentos.reservarAssento(10);
                    confirmacao.enviarConfirmacao("usuario@email.com");
                    System.out.println("Reserva concluída!");
                }
            }
        }
    }
}
