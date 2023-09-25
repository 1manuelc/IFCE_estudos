/* #2. Construa uma matriz 2x2x2 e preencha com nomes de animais via teclado
* em seguida exiba-os. Obs1. Utilizar o laço de repetição While(condicao){...};
*/

import javax.swing.JOptionPane;

public class Questao02 {
    public static String[][][] preencherVetorNomes(int lin, int col, int prof) {
        String[][][] nomesAnimais = new String[lin][col][prof];
        int i = 0, contadorNomes = 0, totalElementos = lin * col * prof;

        while(i < nomesAnimais.length) {
            int j = 0;
            while(j < nomesAnimais[i].length) {
                int k = 0;
                while(k < nomesAnimais[i][j].length) {
                    contadorNomes++;
                    nomesAnimais[i][j][k] = JOptionPane.showInputDialog(null,
                            String.format("Digite o %dº nome de animal (%d/%d):", contadorNomes, contadorNomes, totalElementos),
                            "Armazenamento de Nomes",
                            JOptionPane.QUESTION_MESSAGE);
                    k++;
                } j++;
            } i++;
        }

        return nomesAnimais;
    }

    public static void exibirVetorNomes(String[][][] nomesDeAnimais) {
        int i = 0;
        StringBuilder stringNomes = new StringBuilder("Nomes armazenados:\n");

        while(i < nomesDeAnimais.length) {
            int j = 0;
            while(j < nomesDeAnimais[i].length) {
                int k = 0;
                while(k < nomesDeAnimais[i][j].length) {
                    stringNomes.append(nomesDeAnimais[i][j][k]);
                    stringNomes.append("\n");
                    k++;
                } j++;
            } i++;
        }

        JOptionPane.showMessageDialog(null,
                stringNomes,
                "Armazenador de Nomes",
                JOptionPane.INFORMATION_MESSAGE);
    }

    public static void main(String[] args) {
       try {
           String[][][] nomesDeAnimais = preencherVetorNomes(2, 2, 2);
           exibirVetorNomes(nomesDeAnimais);

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