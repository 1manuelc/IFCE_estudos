package S3.POO.Aula23_Avaliacao4.src.entidades;

import java.util.Date;

public class Cliente extends Pedido{
    private String nomeCliente;
    private String email;
    private Date dataNascimento;

    public String getNomeCliente() {return nomeCliente;}
    public String getEmail() {return email;}
    public Date getDataNascimento() {return dataNascimento;}

    public Cliente() {}
    public Cliente(String nomeCliente, String email, Date dataNascimento, Pedido pedido) {
        super(pedido.getInstante(), pedido.getStatus(), pedido.getItensDoPedido());
        this.nomeCliente = nomeCliente;
        this.email = email;
        this.dataNascimento = dataNascimento;
    }

    public static String formatarData(Date data) {
        String dataFormatada = "";
        int dia = data.getDate();
        int mes = data.getMonth() + 1;
        int ano = data.getYear() + 1900;

        if(dia < 10) dataFormatada += "0" + dia;
        else dataFormatada += dia;

        if(mes < 10) dataFormatada += "/0" + mes;
        else dataFormatada += "/" + mes;

        dataFormatada += "/" + ano;

        return dataFormatada;
    }

    public static String formatarDataHora(Date data) {
        String dataHoraFormatada = formatarData(data);
        int hora = data.getHours(), min = data.getMinutes(), seg = data.getSeconds();

        dataHoraFormatada += " ";

        if(hora < 10) dataHoraFormatada += "0" + hora;
        else dataHoraFormatada += hora;

        if(min < 10) dataHoraFormatada += ":0" + min;
        else dataHoraFormatada += ":" + min;

        if(seg < 10) dataHoraFormatada += ":0" + seg;
        else dataHoraFormatada += ":" + seg;

        return dataHoraFormatada;
    }
}
