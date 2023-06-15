package S3.POO.Aula20_ex_revisao.src.aplicacao;

import S3.POO.Aula20_ex_revisao.src.classes.ContaCorrente;
import S3.POO.Aula20_ex_revisao.src.classes.ContaPoupanca;
import S3.POO.Aula20_ex_revisao.src.classes.SeguroDeVida;

public class TestaTributavel {
    public static void main(String[] args) {
        ContaCorrente corrente = new ContaCorrente(500);
        ContaPoupanca poupanca = new ContaPoupanca(200);
        SeguroDeVida seguro = new SeguroDeVida();
        
        System.out.println("Saldo da conta corrente: R$" + corrente.obterSaldo());
        System.out.println("Tributo da conta corrente: R$" + corrente.calculaTributos());

        System.out.println("Saldo da conta poupança: R$" + poupanca.getSaldo());

        System.out.println("Tributo do seguro de vida: R$" + seguro.calculaTributos());
    }
}
