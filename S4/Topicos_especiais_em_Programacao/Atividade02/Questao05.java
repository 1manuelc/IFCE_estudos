/*
* #5. Construa um programa que leia a temperatura de um objeto em graus
* Celsius e converta em graus Fahrenheit e em seguida em Kelvin.
* Obs.: Informar o nome do objeto e a temperatura.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02;

import java.util.Scanner;

public class Questao05 {
    public static double converterCelsiusParaFahrenheit(double tempCelsius) {
        return (tempCelsius * 1.8) + 32;
    }

    public static double converterCelsiusParaKelvin(double tempCelsius) {
        return tempCelsius + 273;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String nomeObjeto;
        double temperaturaEmCelsius;

        System.out.println("Conversor de temperatura de objetos");
        System.out.print("Digite o nome do objeto: ");
        nomeObjeto = sc.nextLine();

        System.out.print("Digite a temperatura em Celsius: ");
        temperaturaEmCelsius = sc.nextDouble();

        System.out.println("\nTemperatura do/a " + nomeObjeto);
        System.out.println(temperaturaEmCelsius + "ºC");
        System.out.println(converterCelsiusParaFahrenheit(temperaturaEmCelsius) + "ºF");
        System.out.println(converterCelsiusParaKelvin(temperaturaEmCelsius) + "K");

        sc.close();
    }
}
