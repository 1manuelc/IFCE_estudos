package S3.POO.Aula23_Avaliacao.src.aplicacao;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.text.DecimalFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.Calendar;
import java.util.List;
import java.util.ArrayList;

import S3.POO.Aula23_Avaliacao.src.entidades.*;
import S3.POO.Aula23_Avaliacao.src.enums.*;

public class Aplicacao {
    public static Cliente criarCliente() throws ParseException {
        Scanner scan = new Scanner(System.in);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        SimpleDateFormat sdfHora = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");

        System.out.println("Insira os dados do cliente:\n");

        System.out.print("Nome: ");
        String nomeAtual = scan.nextLine();

        System.out.print("Email: ");
        String emailAtual = scan.nextLine();

        System.out.print("Data de Nascimento (DD/MM/YYYY): ");
        Date dataNascimentoAtual = sdf.parse(scan.nextLine());

        System.out.println("Insira os dados do pedido: ");

        System.out.print("Status: ");
        String statusAtual = scan.nextLine();

        String dataAtual = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss")
                .format(Calendar.getInstance().getTime());
        Date dataFormatada = sdfHora.parse(dataAtual);

        List<ItemDoPedido> itensDoPedido = new ArrayList<>();

        Pedido pedido = new Pedido(dataFormatada, StatusDoPedido.valueOf(statusAtual), itensDoPedido);

        return new Cliente(nomeAtual, emailAtual, dataNascimentoAtual, pedido);
    }

    public static void criarPedido(Cliente cliente) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Quantos itens cabem nesse pedido?: ");
        int qtdItensNoPedido = sc.nextInt();

        for(int i = 0; i < qtdItensNoPedido; i++) {
            sc.nextLine();
            System.out.println("Digite os dados do item nº " + (i + 1));

            System.out.print("Nome do produto: ");
            String nomeProdutoAtual = sc.nextLine();

            System.out.print("Preço do produto: ");
            Double precoProdutoAtual = sc.nextDouble();

            System.out.print("Quantidade do produto: ");
            Integer qtdProdutoAtual = sc.nextInt();

            ItemDoPedido itemAtual = new ItemDoPedido(nomeProdutoAtual, qtdProdutoAtual, precoProdutoAtual);
            cliente.adicionarItem(itemAtual);
        }

        sc.close();
    }

    public static void exibirPedido(Cliente cliente) {
        DecimalFormat df = new DecimalFormat("#0.00");

        System.out.println("\nRESUMO DO PEDIDO");

        System.out.println("Momento do pedido: " + Cliente.formatarDataHora(cliente.getInstante()));
        System.out.println("Status do pedido: " + cliente.getStatus());
        System.out.println("Cliente: " + cliente.getNomeCliente() + " (" +
                Cliente.formatarData(cliente.getDataNascimento()) + ") - " + cliente.getEmail());

        System.out.println("Itens do pedido:");

        for(ItemDoPedido item: cliente.getItensDoPedido())
            System.out.println(item.getNomeProduto() + " R$ " + df.format(item.getPreco()) +
                    ", Quantidade: " + item.getQuantidade() + ", Subtotal: R$ " + df.format(item.subTotal()));

        System.out.println("Preço total: R$ " + df.format(cliente.total()));
    }

    public static void main(String[] args) throws ParseException {
        Cliente cliente = criarCliente();
        criarPedido(cliente);
        exibirPedido(cliente);
    }
}
