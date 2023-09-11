package S4.Topicos_especiais_em_Programacao.Atividade03_2;

/*
* #6. Escreva uma algoritmo que receba o nome e três notas de uma aluno com os respectivos pesos. A seguir ler a quantidade de faltas e a carga horária da disciplina.  Obs.: Utilizar qualquer estrutura de seleção.
Os seguintes dados devem ser retornados:
i) Nome e média do aluno com base nas três notas e seus respectivos pesos;
ii) Situação do aluno:
     ii.i) Aprovado por média e frequência; ou
     ii.ii) Reprovado por média [0 - 3,9];
     ii.iii) Reprovado por falta (>25% faltas); ou
     ii.iv) Recuperação final [4,0 - 6,9];
Obs1.: Para ser aprovador por média, a mesma deverá está no intervalo [7,0 - 10,0];
Obs2.: A frequência deverá ser de 75% em relação a quantidade aulas, ou seja, a carga horária da disciplina (40h, 60h, 80h, 120h).
Obs3.: Como carga horária o algoritmo só dever aceitar 40h, 60h, 80h ou 120h;
Obs4.: Para ser reprovado por falta o mesmo deverá ter acima de 25% de faltas; (>25% faltas)
Obs5.: Reprovado por média, a média deverá ser abaixo de 4,0; [0 - 3,9]
Obs6.: Recuperação, o aluno deverá ter média no intervalo [4,0 - 6,9].
*/

import javax.swing.JOptionPane;

public class Questao06 {
    public static double[] preencherNotas() throws NumberFormatException {
        double[] vetorNotas = new double[3];
        for(int i = 0; i < 3; i++)
            vetorNotas[i] = Double.parseDouble(JOptionPane.showInputDialog(null,
                    String.format("Digite a %dª nota:", (i + 1)),
                    "Calculadora Escolar", JOptionPane.QUESTION_MESSAGE));
        return vetorNotas;
    }

    public static int[] preencherPesos() throws NumberFormatException {
        int[] vetorPesos = new int[3];
        for(int i = 0; i < 3; i++)
            vetorPesos[i] = Integer.parseInt(JOptionPane.showInputDialog(null,
                    String.format("Digite o %dº peso:", (i + 1)),
                    "Calculadora Escolar", JOptionPane.QUESTION_MESSAGE));
        return vetorPesos;
    }

    public static double calcularMedia(int[] vetorPesos, double[] vetorNotas) {
        double acumuladorNotas = 0;
        int acumuladorPesos = 0;

        for(int i = 0; i < 3; i++) {
            acumuladorNotas += vetorPesos[i] * vetorNotas[i];
            acumuladorPesos += vetorPesos[i];
        } return (acumuladorNotas / acumuladorPesos);
    }

    public static void main(String[] args) {
        try {
            String nomeDoAluno = JOptionPane.showInputDialog(null,
                    "Digite o nome do aluno",
                    "Calculadora Escolar", JOptionPane.QUESTION_MESSAGE);

            double[] vetorNotas = preencherNotas();
            int[] vetorPesos = preencherPesos();

            int qtdeFaltas = Integer.parseInt(JOptionPane.showInputDialog(null,
                    "Digite a quantidade de faltas do aluno:",
                    "Calculadora Escolar", JOptionPane.QUESTION_MESSAGE));

            double cargaHoraria = Double.parseDouble(JOptionPane.showInputDialog(null,
                    "Digite a carga horária da disciplina:\n(40, 60, 80 ou 120h)",
                    "Calculadora Escolar", JOptionPane.QUESTION_MESSAGE));

            double mediaParcial = calcularMedia(vetorPesos, vetorNotas);

            // Ambas as variáveis funcionam como condições para o aluno passar no quesito,
            // onde 0 = reprovação, 1 = aprovação e 2 = status intermediário (recuperação p.ex.)
            int statusNotas, statusPresenca;

            if(mediaParcial < 4.0) statusNotas = 0;
            else if(mediaParcial < 7.0) statusNotas = 2;
            else statusNotas = 1;

            if(qtdeFaltas > (cargaHoraria * 25/100)) statusPresenca = 0;
            else statusPresenca = 1;

            if(statusNotas == 2)
                JOptionPane.showMessageDialog(null,
                        String.format("Aluno %s\nde recuperação com média %.2f", nomeDoAluno, mediaParcial),
                        "Calculadora Escolar", JOptionPane.INFORMATION_MESSAGE);
            else if(statusNotas == 0 && statusPresenca == 0)
                JOptionPane.showMessageDialog(null,
                        String.format("Aluno %s\nreprovado por média %.2f e %d faltas", nomeDoAluno, mediaParcial, qtdeFaltas),
                        "Calculadora Escolar", JOptionPane.INFORMATION_MESSAGE);
            else if(statusPresenca == 0)
                JOptionPane.showMessageDialog(null,
                        String.format("Aluno %s\nreprovado por %d faltas", nomeDoAluno, qtdeFaltas),
                        "Calculadora Escolar", JOptionPane.INFORMATION_MESSAGE);
            else
                JOptionPane.showMessageDialog(null,
                        String.format("Aluno %s\naprovado com média %.2f e %d faltas", nomeDoAluno, mediaParcial, qtdeFaltas),
                        "Calculadora Escolar", JOptionPane.INFORMATION_MESSAGE);

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