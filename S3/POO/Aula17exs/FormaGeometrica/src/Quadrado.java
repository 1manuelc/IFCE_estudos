package S3.POO.Aula17exs.FormaGeometrica.src;

public class Quadrado extends FormaGeometrica {
    double lado;
    public void setLado(double lado) {this.lado = lado;}
    public double getLado() {return this.lado;}

    @Override
    public double getArea() {
        return this.lado * this.lado;
    }
    public double getComprimento() {
        return this.lado * 4;
    }
}
