package S3.POO.Aula20_ex_revisao.src.classes;

import S3.POO.Aula20_ex_revisao.src.interfaces.Tributavel;

public class SeguroDeVida implements Tributavel{
    @Override
    public double calculaTributos() {return 42.00;}
}
