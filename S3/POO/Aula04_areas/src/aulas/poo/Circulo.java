package S3.POO.Aula04_areas.src.aulas.poo;

public class Circulo {
    private double raio, pi = 3.1415;

    public void setRaio(double raio) {
        this.raio = raio;
    }

    public double getArea() {
        return (this.pi * (raio * raio));
    }
}
