package aulas.poo;

public class Triangulo {
    private double base, altura;

    public void setBase(double base) {this.base = base;}

    public void setAltura(double altura) {this.altura = altura;}

    public double getArea() {
        return (base * altura) / 2;
    }
}
