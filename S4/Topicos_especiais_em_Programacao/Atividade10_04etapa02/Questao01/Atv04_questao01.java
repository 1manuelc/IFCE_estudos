package S4.Topicos_especiais_em_Programacao.Atividade10_04etapa02.Questao01;

/*
 * #1. Construa uma aplicação que receba um valor em graus: Celsius, Kelvin ou 
 * Fahrenheit e faça a conversão por exemplo: (i) se escolher Celsius converter e 
 * mostrar em Kelvin e Fahreinheit; (ii) se escolher Kelvin converter e mostrar em 
 * Celsius e Fahreinheit; (iii)  se escolher Fahreinheit converter e mostrar em 
 * Kelvin e Celsius. Obs1.: A aplicação deve possuir pelo menos os botões 
 * (calcular e limpar).
 */

public class Atv04_questao01 {
    public static void main(String[] args) {
        ConversorTemperatura conversor = new ConversorTemperatura();
        conversor.setVisible(true);
    }
}
