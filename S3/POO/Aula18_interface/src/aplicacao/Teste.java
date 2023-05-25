package S3.POO.Aula18_interface.src.aplicacao;
import S3.POO.Aula18_interface.src.modelos.Quadrado;
import S3.POO.Aula18_interface.src.modelos.Cubo;

public class Teste {
    public static void main(String[] args) {
        Quadrado quad = new Quadrado(4);
        Cubo cub = new Cubo(4);

        System.out.println("Quadrado de lado: " + quad.getLado());
        System.out.println("Area: " + quad.calcularArea() + "\n" +
                           "Volume: " + quad.calcularVolume());

        System.out.println();

        System.out.println("Cubo de aresta: " + cub.getAresta());
        System.out.println("Area: " + cub.calcularArea() + "\n" +
                           "Volume: " + cub.calcularVolume());
    }
}
