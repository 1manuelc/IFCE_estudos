package S4.Topicos_especiais_em_Programacao.Atividade03_2;

/*
* #2.  Escreva um algoritmo que leia três valores inteiros e mostre-os em ordem crescente e decrescente.
* (Usar estrutura de seleção encadeada)
*/

import javax.swing.JOptionPane;
import java.util.Arrays;

public class Questao02 {
    public static int[] colocarEmOrdemCrescente(int[] vetor) {
        int aux;
        for(int i = 0; i < vetor.length; i++) {
            for(int j = 0; j < vetor.length; j++) {
                if(vetor[i] < vetor[j]) {
                    aux = vetor[j];
                    vetor[j] = vetor[i];
                    vetor[i] = aux;
                }
            }
        } return vetor;
    }

    public static int[] colocarEmOrdemDecrescente(int[] vetor) {
        int aux;
        for(int i = 0; i < vetor.length; i++) {
            for(int j = 0; j < vetor.length; j++) {
                if(vetor[i] > vetor[j]) {
                    aux = vetor[j];
                    vetor[j] = vetor[i];
                    vetor[i] = aux;
                }
            }
        } return vetor;
    }

    public static void main(String[] args) {
        try {
            int[] vetorNumeros = new int[3];
            for(int i = 0; i < vetorNumeros.length; i++)
                vetorNumeros[i] = Integer.parseInt(JOptionPane.showInputDialog(null,
                    String.format("Digite o %dº número:", (i + 1)),
                    "Analisador Numérico", JOptionPane.QUESTION_MESSAGE));

            JOptionPane.showMessageDialog(null,
                    String.format(
                            "Números iniciais: %s\n" +
                            "Ordem Crescente: %s\n" +
                            "Ordem Decrescente: %s", Arrays.toString(vetorNumeros),
                            Arrays.toString(colocarEmOrdemCrescente(vetorNumeros)),
                            Arrays.toString(colocarEmOrdemDecrescente(vetorNumeros))
                    ), "Ordenador de Números", JOptionPane.INFORMATION_MESSAGE);

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