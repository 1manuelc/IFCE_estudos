package aulas.poo;

public class Circulo {
    private double raio, pi = 3.1415, area;

    public void setRaio(double raio) {
        this.raio = raio;
    }

    public double getArea() {
        return (this.pi * (raio * raio));
    }
}
