/*
* #4. Construa um algoritmo que implemente um vetor de 15 posições de inteiros.
* A seguir construa outro vetor de 5 posições onde em cada posição será armazenado o MMC (Mínimo Múltiplo Comum)
* de cada 3 valores armazenados, partindo do índice 0 até o indice 14.
* Obs1.: Os valores informados devem estar dentro do intervalo de 1 a 20 somente.
*/

import javax.swing.JOptionPane;
import java.util.Arrays;
import java.util.Random;

public class Questao04 {
    public static int gerarInteiroAleatorio() {
        Random gerador = new Random();
        return gerador.nextInt(21);
    }

    public static int[] preencherVetorNumeros(int qtdNumeros) {
        int[] vetorNumeros = new int[qtdNumeros];
        for(int i = 0; i < vetorNumeros.length; i++) {
                vetorNumeros[i] = Integer.parseInt(
                        JOptionPane.showInputDialog(null,
                                String.format("Digite o %d número (%d/15):", (i + 1), (i + 1)),
                                "Calculadora de MMC em Lote",
                                JOptionPane.QUESTION_MESSAGE)
                );
            // vetorNumeros[i] = gerarInteiroAleatorio();
        } return vetorNumeros;
    }

    public static int[] calcularMMCVetor(int[] vetorNumeros) {
        int[] sequenciaAtual = new int[3];
        int[] vetorMMC = new int[5];
        Arrays.fill(vetorMMC, 1);

        for(int i = 0; i <= 12; i += 3) {
            System.arraycopy(vetorNumeros, i, sequenciaAtual, 0, 3);

            while (!(Arrays.stream(sequenciaAtual).allMatch(num -> num == 1))) {
                for (int k = 2; k <= sequenciaAtual[0]; k++) {
                    while (sequenciaAtual[0] % k == 0) {
                        if(sequenciaAtual[1] % k == 0) sequenciaAtual[1] /= k;
                        if(sequenciaAtual[2] % k == 0) sequenciaAtual[2] /= k;
                        sequenciaAtual[0] /= k;
                        vetorMMC[i / 3] *= k;
                    }
                }

                for (int k = 2; k <= sequenciaAtual[1]; k++) {
                    while (sequenciaAtual[1] % k == 0) {
                        if(sequenciaAtual[2] % k == 0) sequenciaAtual[2] /= k;
                        sequenciaAtual[1] /= k;
                        vetorMMC[i / 3] *= k;
                    }
                }

                for (int k = 2; k <= sequenciaAtual[2]; k++) {
                    while (sequenciaAtual[2] % k == 0) {
                        sequenciaAtual[2] /= k;
                        vetorMMC[i / 3] *= k;
                    }
                }
            }
        } return vetorMMC;
    }

    public static void imprimirResultados(int[] vetorNumeros, int[] vetorMMC) {
        StringBuilder stringResultado = new StringBuilder("MMC de:\n");
        int[] sequenciaAtual = new int[3];

        for(int i = 0; i <= 12; i += 3) {
            System.arraycopy(vetorNumeros, i, sequenciaAtual, 0, 3);
            stringResultado.append(String.format("%s\n", Arrays.toString(sequenciaAtual)));
        }

        stringResultado.append(String.format("Equivale a: %s", Arrays.toString(vetorMMC)));
        JOptionPane.showMessageDialog(null,
                stringResultado,
                "Calculadora de MMC em Lote",
                JOptionPane.INFORMATION_MESSAGE);
    }

    public static void main(String[] args) {
        try {
            int[] vetorNumeros = preencherVetorNumeros(15);
            int[] vetorMMC = calcularMMCVetor(vetorNumeros);
            imprimirResultados(vetorNumeros, vetorMMC);

        } catch(ArrayIndexOutOfBoundsException e) {
            JOptionPane.showMessageDialog(null,
                    "Índice fora do limite do array",
                    "Erro",
                    JOptionPane.ERROR_MESSAGE);
        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número válido",
                    "Erro",
                    JOptionPane.ERROR_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso",
                    JOptionPane.WARNING_MESSAGE);
        }
    }
}