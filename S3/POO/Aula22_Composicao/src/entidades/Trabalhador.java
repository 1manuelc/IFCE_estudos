package S3.POO.Aula22_Composicao.src.entidades;

import S3.POO.Aula22_Composicao.src.entidades.enums.*;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class Trabalhador {
    private String nomeTrabalhador;
    private NivelTrabalhador nivel;
    private Double salarioBase;
    private Departamento departamento;
    private List<ContratoHora> contratos = new ArrayList<>();

    public Trabalhador() {}
    public Trabalhador(String nomeTrabalhador, NivelTrabalhador nivel, Double salarioBase,
                       Departamento departamento) {
        this.nomeTrabalhador = nomeTrabalhador;
        this.nivel = nivel;
        this.salarioBase = salarioBase;
        this.departamento = departamento;
    }

    public String getNomeTrabalhador() {return nomeTrabalhador;}
    public Departamento getDepartamento() {return departamento;}

    public void adicionarContrato(ContratoHora contrato) {contratos.add(contrato);}
    public void removerContrato(ContratoHora contrato) {contratos.remove(contrato);}

    public double calcularRecebimento (int ano, int mes) {
        double soma = salarioBase;
        Calendar cal = Calendar.getInstance();

        for(ContratoHora c : contratos) {
            cal.setTime(c.getData());

            int c_ano = cal.get(Calendar.YEAR);
            int c_mes = 1 + cal.get(Calendar.MONTH);

            if (ano == c_ano && mes == c_mes) soma += c.valorTotal();
        }
        return soma;
    }
}
