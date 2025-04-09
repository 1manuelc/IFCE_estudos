package modules;

public class Assentos {
    public boolean verificarDisponibilidade(int assento) {
        System.out.println("Assento " + assento + " está disponível.");
        return true;
    }

    public void reservarAssento(int assento) {
        System.out.println("Assento " + assento + " reservado!");
    }
}
