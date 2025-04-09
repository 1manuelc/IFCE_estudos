package client;

import facade.SistemaReservaFacade;

public class ClienteComFacade {
    public static void main(String[] args) {
        SistemaReservaFacade reservaFacade = new SistemaReservaFacade();
        reservaFacade.reservarIngresso("usuario123", "senha456", 10, "Cartão de Crédito", "usuario@email.com");
    }
}