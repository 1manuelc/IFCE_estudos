package S3.POO.Aula18_interface.src.modelos;

public class Cubo {
    double aresta;
    public Cubo(){}
    public Cubo(double aresta) {this.aresta = aresta;}
    public double getAresta() {return this.aresta;}

    public double calcularArea() {return (6 * Math.pow(this.aresta, 2));}
    public double calcularVolume() {return Math.pow(this.aresta, 3);}
}
