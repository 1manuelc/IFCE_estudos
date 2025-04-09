package memento;

import java.util.ArrayList;
import java.util.List;

public class Caretaker {
    private final List<Memento> historico = new ArrayList<>();

    public void salvar(Memento memento) {
        historico.add(memento);
    }

    public Memento desfazer() {
        if (!historico.isEmpty()) {
            historico.remove(historico.size() - 1);
            return historico.isEmpty() ? new Memento(new ArrayList<>()) : historico.get(historico.size() - 1);
        }
        return new Memento(new ArrayList<>());
    }
}
