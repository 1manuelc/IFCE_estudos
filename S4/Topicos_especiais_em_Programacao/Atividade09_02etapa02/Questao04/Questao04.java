package S4.Topicos_especiais_em_Programacao.Atividade09_02etapa02.Questao04;

/*
 * @author: 1manuelc
 * #4. Implemente um programa para a classe abaixo, baseado nas características 
 * apresentadas no diagrama de classe.
 * 
 * Classe: Conta;
 * 
 * Atributos:
 *  +saldo: double
 *  +limite: double
 *  +dono: Cliente
 *  +numero: int
 * 
 * Métodos:
 *  +saca(valor:double) : boolean
 *  +deposita(valor:double)
 *  +transfere(destino:Conta, valor:double)
 */

import javax.swing.JOptionPane;

public class Questao04 {
    public static void main(String[] args) {
        try {
            Conta contaTiago = new Conta(5000, 9500, 51, "Tiago Leifert", "123.456.789-10");
            Conta contaMauro = new Conta(10000, 12000, 75, "Mauro Beting", "987.654.321-01");

            contaMauro.exibeConta();
            contaMauro.transfere(contaTiago, 2500);
            contaMauro.exibeExtrato();

            contaTiago.exibeConta();
            contaTiago.saca(7700);
            contaTiago.exibeExtrato();

         } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(
                null, 
                "Execução cancelada", 
                "Exceção", 
                JOptionPane.WARNING_MESSAGE);
        } catch(Exception e) {
            JOptionPane.showMessageDialog(
                null, 
                "Interrupção da execução", 
                "Exceção", 
                JOptionPane.WARNING_MESSAGE);
        }
    }
}