package S4.Topicos_especiais_em_Programacao.Atividade09_02etapa02.Questao02;

/*
 * #2.  Com base em um conjunto de dados, altura e sexo (masculino, feminino) de 10 pessoas. X
 * Fazer um algoritmo que calcule e escreva:
 * A). Função que retorne a maior e a menor altura do grupo;
 * B). Função que calcule a média de altura dos homens;
 * C). Função que informe o número de mulheres.
 */

/*
 * @author: 1manuelc
 * verificações inclusas:
 * altura válida (entre 0.01 e 2.50)
 * sexo válido (somente M ou F)
 */

import java.util.List;
import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Questao02 {
    public static double preencherAlturaValida(int i) {
        try {
            double alturaAtual;
            do 
                alturaAtual = Double.parseDouble(
                    JOptionPane.showInputDialog(
                        null,    
                        String.format("Digite uma altura p/ pessoa %d", (i + 1)),
                        "Preenchimento de Dados",
                        JOptionPane.QUESTION_MESSAGE
                    )
                );
            while (alturaAtual <= 0 || alturaAtual > 2.50);

            return alturaAtual;
        
        } catch(NumberFormatException e) {
            double alturaAtual;
            do 
                alturaAtual = Double.parseDouble(
                    JOptionPane.showInputDialog(
                        null,    
                        String.format("Digite uma altura válida p/ pessoa %d", (i + 1)),
                        "Preenchimento de Dados",
                        JOptionPane.QUESTION_MESSAGE
                    )
                );
            while (alturaAtual <= 0 || alturaAtual > 2.50);

            return alturaAtual;
        }
    }

    public static char preencherSexoValido(int i) {
        String sexoAtual;
        do {
            sexoAtual = JOptionPane.showInputDialog(
                null,
                String.format(
                    "Digite M ou F para o sexo da pessoa %d", (i + 1)
                ),
                "Preenchimento de Dados",
                JOptionPane.QUESTION_MESSAGE
            );
            
        } while (sexoAtual.length() != 1 || !("F".equalsIgnoreCase(sexoAtual)) && !("M".equalsIgnoreCase(sexoAtual)));

        if("m".equals(sexoAtual)) sexoAtual = "M";
        else if("f".equals(sexoAtual)) sexoAtual = "F";

        return sexoAtual.charAt(0);
    }

    public static List<Pessoa> preencherListaPessoas(int tamanho) {
        List<Pessoa> listaPessoas = new ArrayList<>();

        for(int i = 0; i < tamanho; i++) {
            double alturaAtual = preencherAlturaValida(i);    
            char sexoAtual = preencherSexoValido(i);
            Pessoa pessoaAtual = new Pessoa(alturaAtual, sexoAtual);
            listaPessoas.add(pessoaAtual);
        }

        return listaPessoas;
    }

    public static void exibirLimitesAltura(List<Pessoa> listaPessoas) {
        double maiorAltura = 0, menorAltura = listaPessoas.get(0).altura;
        int indiceMaior = 0, indiceMenor = 0;

        for (Pessoa pessoaAtual : listaPessoas) {
            if(pessoaAtual.altura > maiorAltura) {
                maiorAltura = pessoaAtual.altura; 
                indiceMaior = listaPessoas.indexOf(pessoaAtual);
            } if(pessoaAtual.altura < menorAltura) {
                menorAltura = pessoaAtual.altura;
                indiceMenor = listaPessoas.indexOf(pessoaAtual);
            }
        }

        JOptionPane.showMessageDialog(
            null, 
            String.format(
                "A maior altura (%.2fm) é da %dª pessoa da lista.\n" +
                "A menor altura (%.2fm) é da %dª pessoa da lista.\n",
                maiorAltura, indiceMaior + 1, menorAltura, indiceMenor + 1
            ), 
            "Análise de Altura", 
            JOptionPane.INFORMATION_MESSAGE
        );
    }

    public static void exibirMediaAlturaHomens(List<Pessoa> listaPessoas) {
        double mediaAlturas = 0;
        int contador = 0;

        for (Pessoa pessoaAtual : listaPessoas) {
            if("M".equals(String.format("%c", pessoaAtual.sexo))) {
                mediaAlturas += pessoaAtual.altura;
                contador++;
            }
        } mediaAlturas /= contador;

        JOptionPane.showMessageDialog(
            null, 
            String.format(
                "A média de altura entre os %d homens é: %.2fm", 
                contador, mediaAlturas
            ), 
            "Média de altura entre os homens", 
            JOptionPane.INFORMATION_MESSAGE
        );
    }

    public static void exibirNumeroMulheres(List<Pessoa> listaPessoas) {
        int contadorF = 0;
        for (Pessoa pessoaAtual : listaPessoas)
            if("F".equals(String.format("%c", pessoaAtual.sexo))) contadorF++;
        
        JOptionPane.showMessageDialog(
            null, 
            String.format("Há %d mulheres na lista.", contadorF), 
            "Quantidade de mulheres", 
            JOptionPane.INFORMATION_MESSAGE
        );
    }

    public static void main(String[] args) {
        try {
            List<Pessoa> listaPessoas = preencherListaPessoas(5);
            exibirLimitesAltura(listaPessoas);
            exibirMediaAlturaHomens(listaPessoas);
            exibirNumeroMulheres(listaPessoas);
            
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