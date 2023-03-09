public class Exemplo5 {

    public static void main(String[] args) {
        String semaforo [] = {"Vermelho","Amarelo","Verde"};

        System.out.println("Ordem de um semáfaro: ");

        for(String sinal: semaforo) {
            System.out.printf("%s\n", sinal);
        }
    }
}