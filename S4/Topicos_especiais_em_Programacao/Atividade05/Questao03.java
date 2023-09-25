/*
 * #3. Desenvolva um algoritmo que gere aleatoriamente valores para uma matriz LxC e escreva
 * as coordenadas (linha x coluna) do maior e do menor elemento. Os valores aleatórios devem
 * ser do tipo ponto flutuante duplo e gerados no intervalo [0,1].
 * Obs1.: Para gerar os valores aleatórios pesquisar alguma função.
 * Obs2.: Usar o laço de repetição for.
 * Obs3.: O usuário deve informar a quantidade de linhas e colunas.
 */

import javax.swing.JOptionPane;
import java.util.Random;

public class Questao03 {
    public static double[][] preencherMatrizNumeros(int linhas, int colunas) {
        double[][] vetorNumeros = new double[linhas][colunas];
        Random gerador = new Random();

        for(int i = 0; i < vetorNumeros.length; i++) {
            for(int j = 0; j < vetorNumeros[i].length; j++)
                vetorNumeros[i][j] = gerador.nextDouble(1.0);
        } return vetorNumeros;
    }

    public static int[][] analisarLimitesDaMatriz(double[][] matriz) {
        /* A primeira linha da matriz "limites" recebe os índices do maior número
        enquanto a segunda linha recebe os índices do menor número. */
        int[][] limites = new int[2][2];
        double maiorNumero = 0, menorNumero = matriz[0][0];

        for(int i = 0; i < matriz.length; i++) {
            for(int j = 0; j < matriz[i].length; j++){
                if(matriz[i][j] > maiorNumero) {
                    maiorNumero = matriz[i][j];
                    limites[0][0] = i;
                    limites[0][1] = j;
                }

                if(matriz[i][j] < menorNumero) {
                    menorNumero = matriz[i][j];
                    limites[1][0] = i;
                    limites[1][1] = j;
                }
            }
        } return limites;
    }

    public static void exibirLimitesDaMatriz(int[][] limites, double[][] matriz) {
        JOptionPane.showMessageDialog(null,
                String.format(
                        "O maior número da matriz está em: [%d][%d] = %.5f\n" +
                                "O menor número da matriz está em: [%d][%d] = %.5f",
                        limites[0][0], limites[0][1], matriz[limites[0][0]][limites[0][1]],
                        limites[1][0], limites[1][1], matriz[limites[1][0]][limites[1][1]]
                ),
                "Gerador de Números",
                JOptionPane.INFORMATION_MESSAGE);
    }

    public static void main(String[] args) {
        try {
            int numLinhas = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                    "Digite o número de linhas:",
                    "Gerador de Números",
                    JOptionPane.QUESTION_MESSAGE)
            );

            int numColunas = Integer.parseInt(
                    JOptionPane.showInputDialog(null,
                            "Digite o número de colunas:",
                            "Gerador de Números",
                            JOptionPane.QUESTION_MESSAGE)
            );

            double[][] matrizNumeros = preencherMatrizNumeros(numLinhas, numColunas);
            int[][] limites = analisarLimitesDaMatriz(matrizNumeros);
            exibirLimitesDaMatriz(limites, matrizNumeros);

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