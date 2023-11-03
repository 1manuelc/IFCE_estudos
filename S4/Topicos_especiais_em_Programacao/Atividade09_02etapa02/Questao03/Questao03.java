package S4.Topicos_especiais_em_Programacao.Atividade09_02etapa02.Questao03;

/*
 * @author 1manuelc
 * #3. Escreva um programa que possua uma função que receberá 10 nomes 
 * e em seguida imprimirá os mesmos que invertidos.
 * Obs.: Usar estrutura de dados homogênea.
 */

import javax.swing.JOptionPane;

public class Questao03 {
    public static String[] preencherVetorNomes(int tamanho) {
        String[] vetorNovo = new String[tamanho];
        
        for (int i = 0; i < tamanho; i++) {
            vetorNovo[i] = JOptionPane.showInputDialog(
                null,
                String.format("Digite o [%dº/ %d] nome:", (i + 1), vetorNovo.length),
                "Preenchimento de nomes",
                JOptionPane.QUESTION_MESSAGE
            );
        } 
        
        return vetorNovo;
    }
    
    public static String inverterString(String nome) {
        char[] vetorBase = nome.toCharArray();
        char[] vetorNovo = new char[nome.length()];

        for(int i = 0; i < nome.length(); i++) {
            char aux1 = vetorBase[i];
            char aux2 = vetorBase[nome.length() - i - 1];
            vetorNovo[i] = aux2;
            vetorNovo[nome.length() - i - 1] = aux1;
        }

        String nomeInvertido = "";
        for (char charAtual : vetorNovo) nomeInvertido += charAtual;

        return nomeInvertido;
    }

    public static String[] inverterVetorNomes(String[] vetorBase) {
        String[] vetorInvertido = new String[vetorBase.length];

        for (int i = 0; i < vetorBase.length; i++)
            vetorInvertido[i] = inverterString(vetorBase[i]);

        return vetorInvertido;
    }

    public static void exibirComparacaoVetores(String[] vetorAntigo, String[] vetorNovo) {
        String saida = "Inversão de Nomes:\n";
        
        for (int i = 0; i < vetorAntigo.length; i++) {
            if(i != vetorAntigo.length - 1)
                saida += String.format("%s    ->    %s\n", vetorAntigo[i], vetorNovo[i]);
            else
                saida += String.format("%s    ->    %s", vetorAntigo[i], vetorNovo[i]);
        }

        JOptionPane.showMessageDialog(
            null, 
            saida, 
            "Exibição de Resultados", 
            JOptionPane.INFORMATION_MESSAGE
        );
    }

    public static void main(String[] args) {
        try {
            String[] vetorNomes = preencherVetorNomes(5);
            String[] vetorNomesInvertido = inverterVetorNomes(vetorNomes);
            exibirComparacaoVetores(vetorNomes, vetorNomesInvertido);
            
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