package S4.Topicos_especiais_em_Programacao.Aula05.src;

import javax.swing.JOptionPane;

public class OptionPaneEx {
    public static void main(String[] args) {
        String nome = JOptionPane.showInputDialog(null, "Qual seu nome?");
        Integer resposta = JOptionPane.showConfirmDialog(null, "Seu nome é " + nome + "?");

        switch (resposta) {
            case JOptionPane.YES_OPTION: JOptionPane.showMessageDialog(null, "Seu nome é " + nome); break;
            case JOptionPane.NO_OPTION: JOptionPane.showMessageDialog(null, "Seu nome não é " + nome); break;
            case JOptionPane.CANCEL_OPTION: JOptionPane.showMessageDialog(null, "OK!"); break;
        }
    }
}
