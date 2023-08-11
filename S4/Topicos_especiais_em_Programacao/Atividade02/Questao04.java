/*
* #4. Calcule o consumo em reais, da gasolina consumida em uma viagem
* de ida e volta para uma cidade vizinha.
* Obs.: Informações a serem consideradas: Km percorrido na viagem de ida
* e de volta; valor do litro de gasolina; km/l que o automóvel faz.
*/

package S4.Topicos_especiais_em_Programacao.Atividade02;

import java.util.Scanner;

public class Questao04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double valorDoLitro, kmPercorridoTotal, kmPorLitro;
        double consumoEmLitros, consumoEmReais;

        System.out.print("Digite o valor do litro de gasolina: ");
        valorDoLitro = sc.nextDouble();

        System.out.print("Digite a distância percorrida (ida e volta): ");
        kmPercorridoTotal = sc.nextDouble();

        System.out.print("Digite quantos km/litro seu automóvel faz: ");
        kmPorLitro = sc.nextDouble();

        consumoEmLitros = (kmPercorridoTotal / kmPorLitro);
        consumoEmReais = consumoEmLitros * valorDoLitro;

        System.out.println("Numa viagem de " + kmPercorridoTotal + "km, seu " +
                "automóvel consumiu R$" + consumoEmReais + " de gasolina");

        sc.close();
    }
}
