package memento;

import java.util.ArrayList;
import java.util.List;

public class Memento {
    private final List<String> assentosReservados;

    public Memento(List<String> estado) {
        this.assentosReservados = new ArrayList<>(estado);
    }

    public List<String> getEstado() {
        return assentosReservados;
    }
}
