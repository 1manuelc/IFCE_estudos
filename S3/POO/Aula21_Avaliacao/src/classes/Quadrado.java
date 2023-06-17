package S3.POO.Aula21_Avaliacao.src.classes;

import S3.POO.Aula21_Avaliacao.src.interfaces.FormaGeometrica;

public class Quadrado implements FormaGeometrica {
    private double lado;

    public Quadrado() {}
    public Quadrado(double lado) {this.lado = lado;}

    public double getLado() {return this.lado;}

    @Override
    public double area() {return Math.pow(getLado(), 2);}

    public double comprimento() {return getLado() * 4;}
}
