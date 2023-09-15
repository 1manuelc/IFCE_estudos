package S4.Topicos_especiais_em_Programacao.Atividade04;

/*
* #5. Faça um algoritmo que leia um valor caractere e
* só pare quando esse valor for  a “fim” ou “f”.
* Obs.: Usar while
*/

import javax.swing.JOptionPane;

public class Questao05 {
    public static void main(String[] args) {
        try {
            String leitura = JOptionPane.showInputDialog(null,
                    "Digite um caractere:\nPara sair use 'f' ou 'fim'",
                    "Questao05", JOptionPane.QUESTION_MESSAGE);

            while(!(leitura.equals("f") || leitura.equals("fim")))
                leitura = JOptionPane.showInputDialog(null,
                        "Digite um caractere:\nPara sair use 'f' ou 'fim'",
                        "Questao05", JOptionPane.QUESTION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número real",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
        }
    }
}