/*
 * #4. Construa uma tela de cadastro com nome, idade, sexo e endereço 
 * (em um container com borda título: Dados Básico); a seguir insira 
 * outro container de título (Cálculo do Salário), para o cálculo do 
 * salário inserir os campos: valor da hora trabalhada (não exceder 200,00), 
 * quantidade de hora trabalhada (não exceder 40hs) e o campos desconto de INSS 
 * e por fim o campo Salário liquido. 
 * Observações complementares:
 * R$ 1.320,00 (salário-mínimo) – 7,5% 
 * Entre R$ 1.320,01 e R$ 2.571,29 – 9% 
 * Entre R$ 2.571,30 e R$ 3.856,94 – 12% 
 * Entre R$ 3.856,95 e R$ 7.507,49– 14%
 */

package S4.Topicos_especiais_em_Programacao.Atividade10_04etapa02.Questao04;

/**
 *
 * @author 1manuelc
 */
public class Questao04 {
    public static void main(String[] args) {
        new CalculadoraINSS().setVisible(true);
    }
}
