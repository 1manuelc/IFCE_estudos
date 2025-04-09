package memento;

import java.util.ArrayList;
import java.util.List;

// Originator
public class SistemaReservas {
    private List<String> assentosReservados = new ArrayList<>();

    public void reservarAssento(String assento) {
        assentosReservados.add(assento);
        System.out.println("Assento " + assento + " reservado.");
    }

    public void cancelarUltimaReserva() {
        if (!assentosReservados.isEmpty()) {
            String assentoRemovido = assentosReservados.remove(assentosReservados.size() - 1);
            System.out.println("Reserva do assento " + assentoRemovido + " cancelada.");
        }
    }

    public Memento salvarEstado() {
        return new Memento(assentosReservados);
    }

    public void restaurarEstado(Memento memento) {
        assentosReservados = new ArrayList<>(memento.getEstado());
        System.out.println("Estado da reserva restaurado: " + assentosReservados);
    }
}
