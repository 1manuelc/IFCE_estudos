package S3.POO.Aula21_Avaliacao3.src.classes;

import S3.POO.Aula21_Avaliacao3.src.interfaces.*;

public class Circulo implements FormaGeometrica, Impressao {
    private double raio;
    
    public Circulo() {}
    public Circulo(double raio) {this.raio = raio;}

    public double getRaio() {return this.raio;}

    @Override
    public double area() {return 3.14 * Math.pow(getRaio(), 2);}

    public double comprimento() {return 2 * 3.14 * getRaio();}

    public void imprimeDados() {
        System.out.println("Círculo de raio = " + getRaio());
        System.out.println("Area = " + area());
        System.out.println("Comprimento = " + comprimento());
    }
}
