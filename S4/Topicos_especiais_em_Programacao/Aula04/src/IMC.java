package S4.Topicos_especiais_em_Programacao.Aula04.src;

import javax.swing.JOptionPane;
import java.text.DecimalFormat;

public class IMC {
    public static void main(String[] args) {
        try {
            double peso, altura, imc;
            DecimalFormat fmt = new DecimalFormat("0.00");

            peso = Double.parseDouble(JOptionPane.showInputDialog("Digite seu peso:"));
            altura = Double.parseDouble(JOptionPane.showInputDialog("Digite sua altura:"));

            imc = peso / (altura * altura);

            JOptionPane.showMessageDialog(null, "Seu IMC é: " + fmt.format(imc));
        } catch(Exception e) {
            JOptionPane.showMessageDialog(null, "Valor inválido", "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }
}
