package S3.POO.Aula18_interface.src.modelos;
import S3.POO.Aula18_interface.src.operacoes.AreaCalculavel;
import S3.POO.Aula18_interface.src.operacoes.VolumeCalculavel;
import java.lang.Math;

public class Quadrado implements AreaCalculavel, VolumeCalculavel {
    double lado;
    public Quadrado(){}
    public Quadrado(double lado) {this.lado = lado;}
    public double getLado() {return this.lado;}

    public double calcularArea() {return Math.pow(this.lado, 2);}
    public double calcularVolume() {return Math.pow(this.lado, 3);}
}
