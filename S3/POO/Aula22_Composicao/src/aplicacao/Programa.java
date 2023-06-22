package S3.POO.Aula22_Composicao.src.aplicacao;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.Scanner;

import S3.POO.Aula22_Composicao.src.entidades.*;
import S3.POO.Aula22_Composicao.src.entidades.enums.*;

public class Programa {
    public static void main(String[] args) throws ParseException {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

        System.out.print("Entre com o nome do departamento: ");
        String nome = sc.nextLine();

        System.out.println("Entre com os dados do trabalhador:");

        System.out.print("Nome: ");
        String nomeTrabalhador = sc.nextLine();

        System.out.print("Nivel: ");
        String nivel = sc.nextLine();

        System.out.print("salarioBase: ");
        double salarioBase = sc.nextDouble();

        Trabalhador trabalhador = new Trabalhador(nomeTrabalhador, NivelTrabalhador.valueOf(nivel),
                                salarioBase, new Departamento(nome));

        System.out.print("Quantos contratos para este trabalhador? ");
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            System.out.println("Entre com o contrato:  #" + i);

            System.out.print("Data (DD/MM/YYYY): ");
            Date data = sdf.parse(sc.next());

            System.out.print("Valor da hora: ");
            double valorHora = sc.nextDouble();

            System.out.print("Quantidade de Horas: ");
            int horas = sc.nextInt();

            ContratoHora contrato = new ContratoHora(data, valorHora, horas);
            trabalhador.adicionarContrato(contrato);
        }

        System.out.println();
        System.out.print("Entre com o mês e ano para calcular o valor a receber (MM/YYYY): ");
        String mesAno = sc.next();

        int mes = Integer.parseInt(mesAno.substring(0, 2));
        int ano = Integer.parseInt(mesAno.substring(3));

        System.out.println("Nome: " + trabalhador.getNomeTrabalhador());
        System.out.println("Departmento: " + trabalhador.getDepartamento().getNome());
        System.out.println("Recebimento para " + mesAno + ": " + String.format("%.2f",
                            trabalhador.calcularRecebimento(ano, mes)));
        sc.close();
    }

}



