package S4.Topicos_especiais_em_Programacao.Atividade04;

/*
* #7. Escrever um algoritmo que leia um valor para X e calcule e
* mostre sua multiplicação pelos seu 10 primeiros termos que o sucedem.
* Por exemplo: número 2, os 10 termos que o sucedem são 3,4,5,6,7,8,9,10,11,12,
* sua soma seria: 75.
* Obs.: Usar while
*/

import javax.swing.JOptionPane;

public class Questao07 {
    public static StringBuilder construirStringSucessores(int numero) {
        StringBuilder stringSucessores = new StringBuilder();
        int acumuladorSoma = -numero, i = numero;
        stringSucessores.append(String.format("Multiplicação pelos 10 primeiros sucessores de %d", numero));

        while(i <= (numero + 10)) {
            stringSucessores.append(String.format("%d x %d = %d\n", numero, i, numero * i));
            acumuladorSoma += i;
            i++;
        }

        return (stringSucessores.append(String.format("Soma: %d", acumuladorSoma)));
    }
    public static void main(String[] args) {
        try {
            int numero = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                            "Digite um número inteiro:",
                            "Analisador de Sucessão",
                            JOptionPane.QUESTION_MESSAGE)
            );

            JOptionPane.showMessageDialog(null,
                    construirStringSucessores(numero),
                    "Analisador de Sucessão",
                    JOptionPane.INFORMATION_MESSAGE);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número inteiro",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
        }
    }
}