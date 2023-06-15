package S3.POO.Aula20_ex_revisao.src.classes;

abstract class Conta {
    private double saldo;

    public double getSaldo() {return this.saldo;}
    public void setSaldo(double valor) {this.saldo = valor;}

    public Conta(){}
    public Conta(double saldo) {setSaldo(saldo);}

    public double sacar(double valor) {
        if(valor > getSaldo()) {
            System.out.println("Impossível sacar, saldo insuficiente");
            return 0;
        } else {
            setSaldo(getSaldo() - valor);
            return valor;
        }
    }
    public void depositar(double valor) {setSaldo(getSaldo() + valor);}
    public double obterSaldo() {return getSaldo();}
}
