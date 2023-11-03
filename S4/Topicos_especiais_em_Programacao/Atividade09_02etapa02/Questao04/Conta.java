package S4.Topicos_especiais_em_Programacao.Atividade09_02etapa02.Questao04;

import javax.swing.JOptionPane;

public class Conta {
  double saldo, limite;
  int numero;
  Cliente dono;

  public Conta(double saldo, double limite, int numero, String nome, String cpf) {
    this.dono = new Cliente(nome, cpf);
    this.saldo = saldo;
    this.limite = limite;
    this.numero = numero;
  }

  public void exibeConta() {
    JOptionPane.showMessageDialog(
      null, 
      String.format(
        "Titularidade da Conta:\n\n" +
        "Nome: %s\n" +
        "CPF: %s\n" +
        "Número: %d\n" +
        "Limite: R$ %.2f",
        dono.nome, dono.cpf, numero, limite
      ), 
      "Informações da Conta",
      JOptionPane.INFORMATION_MESSAGE 
    );
  }

  public void exibeExtrato() {
    JOptionPane.showMessageDialog(
      null, 
      String.format(
        "Seu extrato atual é de R$ %.2f", saldo
      ), 
      "Extrato",
      JOptionPane.INFORMATION_MESSAGE 
    );
  }

  public boolean saca(double valor) {
    if (valor > saldo || valor <= 0) {
      JOptionPane.showMessageDialog(
        null, 
        String.format(
          "Sua conta tem R$ %.2f de saldo\nImpossível sacar R$ %.2f",
          saldo, valor
        ),
        "Transação mal-sucedida",
        JOptionPane.WARNING_MESSAGE
      );
      
      return false;
    
    } else {
      saldo -= valor;

      JOptionPane.showMessageDialog(
        null, 
        "Saque realizado! Contando cédulas e/ou moedas...",
        "Transação bem-sucedida",
        JOptionPane.INFORMATION_MESSAGE
      );

      return true;
    }
  }

  public void deposita(double valor) {
    if(valor <= 0) {
      JOptionPane.showMessageDialog(
        null, 
        "Valor impossível de depósito",
        "Transação mal-sucedida",
        JOptionPane.WARNING_MESSAGE
      );

    } else {
      saldo += valor;

      JOptionPane.showMessageDialog(
        null, 
        String.format("Depósito realizado na conta de %s!", dono.nome),
        "Transação bem-sucedida",
        JOptionPane.INFORMATION_MESSAGE
      );
    }
  }

  public void transfere(Conta destino, double valor) {
    if(destino == this) {
      JOptionPane.showMessageDialog(
          null, 
          "Não é possível transferir para si mesmo!\n(Considerando a mesma modalidade de conta)",
          "Transação mal-sucedida",
          JOptionPane.WARNING_MESSAGE
      );

    } else if(valor > saldo) {
      JOptionPane.showMessageDialog(
        null, 
        String.format(
          "Sua conta tem R$ %.2f de saldo\nImpossível transferir R$ %.2f",
          saldo, valor
        ),
        "Transação mal-sucedida",
        JOptionPane.WARNING_MESSAGE
      );

    } else {
      destino.deposita(valor);
      saldo -= valor;

      JOptionPane.showMessageDialog(
        null, 
        String.format(
          "Transferência de R$ %.2f\n para %s realizada!", 
          valor, destino.dono.nome
        ),
        "Transação bem-sucedida",
        JOptionPane.INFORMATION_MESSAGE
      );
    }
  }
}
