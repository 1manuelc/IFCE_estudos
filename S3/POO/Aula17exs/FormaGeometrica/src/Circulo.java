package S3.POO.Aula17exs.FormaGeometrica.src;

public class Circulo extends FormaGeometrica {
    double raio;

    public void setRaio(double raio) {this.raio = raio;}
    public double getRaio() {return this.raio;}

    @Override
    public double getArea() {
        return 3.14 * (this.raio * this.raio);
    }

    public double getComprimento() {
        return 2 * 3.14 * this.raio;
    }
}
