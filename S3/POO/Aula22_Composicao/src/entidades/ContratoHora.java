package S3.POO.Aula22_Composicao.src.entidades;

import java.util.Date;

public class ContratoHora {
    private Date data;
    private double valorHora;
    private int horas;

    public Date getData() {return data;}

    public ContratoHora() {}
    public ContratoHora(Date data, double valorHora, int horas) {
        this.data = data;
        this.valorHora = valorHora;
        this.horas = horas;
    }

    public double valorTotal() {return valorHora * horas;}
}
