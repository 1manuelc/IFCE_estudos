package S3.POO.Aula19ex.src.classes;

import S3.POO.Aula19ex.src.interfaces.FormaGeometrica;

public class Quadrado implements FormaGeometrica {
    private double lado;
    public double getLado() {return lado;}

    public Quadrado(){}
    public Quadrado(double lado) {this.lado = lado;}

    @Override
    public double area() {return Math.pow(getLado(), 2);}
    public double perimetro() {return getLado() * 4;}
}
