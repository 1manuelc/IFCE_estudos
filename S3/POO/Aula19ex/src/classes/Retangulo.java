package S3.POO.Aula19ex.src.classes;

import S3.POO.Aula19ex.src.interfaces.FormaGeometrica;

public class Retangulo implements FormaGeometrica {
    private double base, altura;
    public double getBase() {return base;}
    public double getAltura() {return altura;}

    public Retangulo(){}
    public Retangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double area() {return getBase() * getAltura();}
    public double perimetro() {return (getBase() * 2) + (getAltura() * 2);}
}
