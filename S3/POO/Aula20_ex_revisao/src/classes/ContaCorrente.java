package S3.POO.Aula20_ex_revisao.src.classes;

import S3.POO.Aula20_ex_revisao.src.interfaces.Tributavel;

public class ContaCorrente extends Conta implements Tributavel{
    public ContaCorrente(){}
    public ContaCorrente(double valor) {super(valor);}
    
    @Override
    public double calculaTributos() {return super.getSaldo() * 0.01;}
}
