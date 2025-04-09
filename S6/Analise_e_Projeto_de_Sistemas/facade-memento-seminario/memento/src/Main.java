import memento.Caretaker;
import memento.SistemaReservas;

public class Main {
    public static void main(String[] args) {
        SistemaReservas sistema = new SistemaReservas();
        Caretaker caretaker = new Caretaker();

        sistema.reservarAssento("A1");
        caretaker.salvar(sistema.salvarEstado());

        sistema.reservarAssento("B2");
        caretaker.salvar(sistema.salvarEstado());

        sistema.reservarAssento("C3");
        caretaker.salvar(sistema.salvarEstado());

        System.out.println("Desfazendo última ação...");
        sistema.restaurarEstado(caretaker.desfazer());

        System.out.println("Desfazendo última ação...");
        sistema.restaurarEstado(caretaker.desfazer());
    }
}
