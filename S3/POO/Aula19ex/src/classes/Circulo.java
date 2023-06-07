package S3.POO.Aula19ex.src.classes;

import S3.POO.Aula19ex.src.interfaces.FormaGeometrica;

public class Circulo implements FormaGeometrica {
    private double raio;
    public double getRaio() {return raio;}

    public Circulo(){}
    public Circulo(double raio) {this.raio = raio;}

    @Override
    public double area() {
        return 3.14 * (this.raio * this.raio);
    }

    public double perimetro() {
        return 2 * 3.14 * this.raio;
    }
}
